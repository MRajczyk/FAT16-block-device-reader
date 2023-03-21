#include "file_reader.h"
#include "tested_declarations.h"
#include "rdebug.h"
#include "tested_declarations.h"
#include "rdebug.h"

struct disk_t* disk_open_from_file(const char* volume_file_name)
{
    if(!volume_file_name)
    {
        errno = EFAULT;
        return NULL;
    }

    struct disk_t *disk = (struct disk_t*)calloc(sizeof(struct disk_t), 1);
    if (!disk)
    {
        errno = ENOMEM;
        return NULL;
    }

    disk->disk_image = fopen(volume_file_name, "rb");
    if(!disk->disk_image)
    {
        free(disk);
        errno = ENOENT;
        return NULL;
    }

    return disk;
}

int disk_read(struct disk_t* pdisk, int32_t first_sector, void* buffer, int32_t sectors_to_read)
{
    if(!pdisk || !buffer)
    {
        errno = EFAULT;
        return -1;
    }

    if(first_sector < 0 || sectors_to_read < 0)
    {
        errno = ERANGE;
        return -1;
    }

    fseek(pdisk->disk_image, first_sector * SIZE_SECTOR, SEEK_SET);

    int sectors_read = (int)fread(buffer, SIZE_SECTOR, sectors_to_read, pdisk->disk_image);
    if(sectors_read != sectors_to_read)
    {
        errno = ERANGE;
        return -1;
    }

    return sectors_read;
}

int disk_close(struct disk_t* pdisk)
{
    if(!pdisk || !pdisk->disk_image)
    {
        errno = EFAULT;
        return -1;
    }

    fclose(pdisk->disk_image);
    free(pdisk);

    return 0;
}

int validate_supersector(struct fat_super_t* FAT_BS)
{
    if(FAT_BS->reserved_sectors == 0  ||
       FAT_BS->sectors_per_fat == 0   ||
       FAT_BS->bytes_per_sector < 512 ||
       FAT_BS->signature != 0x29      || //fat12/16 sig value is 0x29
       FAT_BS->magic_sig != 0xAA55)
        return 0;

    if(!(FAT_BS->logical_sectors_count16 == 0 ^ FAT_BS->logical_sectors_count32 == 0) ||
       (FAT_BS->logical_sectors_count32 == 0 && FAT_BS->logical_sectors_count16 == 0)    ||
       (FAT_BS->logical_sectors_count16 == 0 && FAT_BS->logical_sectors_count32 < 65536))
        return 0;


    uint8_t ctr = 0;
    const uint8_t possible_sectors_per_cluster[] = {1, 2, 4, 8, 16, 32, 64};

    while(FAT_BS->sectors_per_cluster != possible_sectors_per_cluster[ctr])
    {
        ++ctr;
        if(ctr == sizeof(possible_sectors_per_cluster))
            return 0;
    }

    return 1;
}

int load_fat(struct volume_t* volume)
{
    uint8_t** fats = calloc(2, sizeof(uint8_t*));
    if (!fats)
    {
        errno = ENOMEM;
        return 0;
    }

    fats[0] = calloc(1, volume->fat_size * volume->super->bytes_per_sector);
    if(!fats[0])
    {
        free(fats);
        errno = ENOMEM;
        return 0;
    }
    int sectors_read = disk_read(volume->disk, volume->first_fat_sector, fats[0], volume->super->sectors_per_fat);
    if(sectors_read != volume->super->sectors_per_fat)
    {
        errno = ERANGE;
        free(fats[0]);
        free(fats);
        return 0;
    }

    for(int i = 1; i < volume->super->fat_count; ++i)
    {
        fats[1] = calloc(1, volume->fat_size * volume->super->bytes_per_sector);
        if(!fats[1])
        {
            free(fats[0]);
            free(fats);
            errno = ENOMEM;
            return 0;
        }

        sectors_read = disk_read(volume->disk, volume->first_fat_sector + volume->fat_size * i, fats[1], volume->super->sectors_per_fat);
        if (sectors_read != volume->super->sectors_per_fat)
        {
            free(fats[0]);
            free(fats[1]);
            free(fats);
            errno = ENOMEM;
            return 0;
        }

        if(memcmp(fats[0], fats[1], volume->super->sectors_per_fat * volume->super->bytes_per_sector) != 0)
        {
            free(fats[0]);
            free(fats[1]);
            free(fats);
            errno = EINVAL;
            return 0;
        }
        free(fats[1]);
    }
    free(fats[0]);
    free(fats);

    volume->fat = calloc(1, volume->fat_size * volume->super->bytes_per_sector);
    sectors_read = disk_read(volume->disk, volume->first_fat_sector + volume->fat_size, volume->fat, volume->super->sectors_per_fat);

    if (sectors_read != volume->super->sectors_per_fat)
    {
        errno = ERANGE;
        return 0;
    }

    return 1;
}

struct volume_t* fat_open(struct disk_t* pdisk, uint32_t first_sector)
{
    if(!pdisk)
    {
        errno = EFAULT;
        return NULL;
    }

    struct volume_t *volume = calloc(1, sizeof(struct volume_t));
    if (!volume)
    {
        errno = ENOMEM;
        return NULL;
    }

    volume->super = malloc(sizeof(struct fat_super_t));
    if(!volume->super)
    {
        free(volume);
        errno = ENOMEM;
        return NULL;
    }

    if(disk_read(pdisk, first_sector, volume->super, 1) == -1)
    {
        free(volume->super);
        free(volume);
        errno = EINVAL;
        return NULL;
    }

    if(validate_supersector(volume->super) == 0)
    {
        free(volume->super);
        free(volume);
        errno = EINVAL;
        return NULL;
    }

    volume->disk = pdisk;
    volume->total_sectors = (volume->super->logical_sectors_count16 == 0) ? volume->super->logical_sectors_count32 : volume->super->logical_sectors_count16;
    volume->fat_size = volume->super->sectors_per_fat;
    volume->root_dir_sectors = ((volume->super->max_root_dir_entries * DIR_ENTRY_SIZE) + (volume->super->bytes_per_sector - 1)) / volume->super->bytes_per_sector;
    volume->first_data_sector = volume->super->reserved_sectors + (volume->super->fat_count * volume->fat_size) + volume->root_dir_sectors;
    volume->first_fat_sector = volume->super->reserved_sectors;
    volume->data_sectors = volume->total_sectors - (volume->super->reserved_sectors + (volume->super->fat_count * volume->fat_size) + volume->root_dir_sectors);

    if(!load_fat(volume))
    {
        free(volume->super);
        free(volume);
        volume = NULL;
        return NULL;
    }

    return volume;
}

int fat_close(struct volume_t* pvolume)
{
    if(!pvolume || !pvolume->super || !pvolume->fat)
    {
        errno = EFAULT;
        return -1;
    }

    free(pvolume->fat);
    free(pvolume->super);
    free(pvolume);

    return 0;
}

void get_filename(struct fat_entry_t* file, char* to)
{
    char filename[8 + 1] = {0};
    char extension[3 + 1] = {0};

    for(int i = 7; i >= 0; --i)
    {
        if(file->name[i] == ' ')
            continue;
        else
        {
            for(; i >= 0; --i)
                filename[i] = file->name[i];
            break;
        }
    }

    for(int i = 2; i >= 0; --i)
    {
        if(file->extension[i] == ' ')
            continue;
        else
        {
            for(; i >= 0; --i)
                extension[i] = file->extension[i];
            break;
        }
    }

    if(strlen(extension))
        sprintf(to, "%s.%s", filename, extension);
    else
        sprintf(to, "%s", filename);
}

int file_search(struct dir_t* directory, const char* filename)
{
    struct dir_entry_t dir_entry;
    while(dir_read(directory, &dir_entry) == 0)
    {
        if(dir_entry.name[0] == '\0') //empty file == no more entries in the directory, return -1 as an indicator of search_fail
            return -1;

        if(*dir_entry.name == '.' && filename[0] == '.')
        {
            if(dir_entry.name[1] == '.' && filename[1] == '.')
            {
                if(dir_entry.name[2] == '\0' && filename[2] == '\0')
                    return 1;
            }
            else if(dir_entry.name[1] == '\0' && filename[1] == '\0')
                return 0;
            continue;
        }

        if(dir_entry.has_long_name == 1)
        {
            _Bool diff = 0;
            unsigned long len_filename = strlen(filename);
            unsigned long len_dir_entry = 0;
            while(*(dir_entry.long_name + len_dir_entry + 1))
                ++len_dir_entry;
            for(unsigned int j = 0; j < (len_dir_entry * (len_dir_entry <= len_filename) + len_filename * (len_filename < len_dir_entry)); ++j) //if buffer is shorter, then iterate to the end of buffer, otherwise to the end of filename
            {
                if(toupper(dir_entry.long_name[j]) != toupper(filename[j]))
                {
                    diff = 1;
                    break;
                }
            }
            if(diff == 0)
                return --directory->curr_entry;
        }
        else
        {
            unsigned long len_filename = strlen(filename);
            unsigned long len_dir_entry = strlen(dir_entry.name);
            _Bool diff = 0;
            for(unsigned int j = 0; j < (len_dir_entry * (len_dir_entry <= len_filename) + len_filename * (len_filename < len_dir_entry)); ++j) //if buffer is shorter, then iterate to the end of buffer, otherwise to the end of filename
            {
                if(toupper(dir_entry.name[j]) != toupper(filename[j]))
                {
                    diff = 1;
                    break;
                }
            }
            if(diff == 0)
                return --directory->curr_entry;
        }

    }
    return -1;
}

//vvv is supposed to return the folder in which the file is located vvv
struct dir_t* dir_open_file(struct volume_t* pvolume, const char* dir_path)
{

    if(!pvolume || !pvolume->disk || !pvolume->fat || !dir_path)
    {
        errno = EFAULT;
        return NULL;
    }

    struct dir_t* dir = calloc(1, sizeof(struct dir_t));
    if(!dir)
    {
        errno = ENOMEM;
        return NULL;
    }
    dir->curr_entry = 0;
    dir->entry = malloc(pvolume->root_dir_sectors * pvolume->super->bytes_per_sector);
    if (!dir->entry)
    {
        free(dir);
        return NULL;
    }

    uint32_t read_blocks = (uint32_t)disk_read(pvolume->disk, pvolume->first_data_sector - pvolume->root_dir_sectors, dir->entry, pvolume->root_dir_sectors);
    if (read_blocks != pvolume->root_dir_sectors)
    {
        free(dir->entry);
        free(dir);
        return NULL;
    }
    char* temp = strchr(dir_path, '\\');

    if(!temp)
    {
        char next_name[256] = {0};
        for(int i = 0; dir_path[i] != 0; ++i)
            next_name[i] = dir_path[i];

        int offset = file_search(dir, next_name);
        if(offset == -1)
        {
            free(dir->entry);
            free(dir);
            return NULL;
        }

        if(!((dir->entry + offset)->attr & 0x10))
            return dir;

        int32_t new_entry_size_cl = get_dir_cluster_size(dir->entry + offset, pvolume);
        struct fat_entry_t* temp_entry = malloc(new_entry_size_cl * pvolume->super->sectors_per_cluster * SIZE_SECTOR);
        if(!temp_entry)
        {
            free(dir->entry);
            free(dir);
            return NULL;
        }

        int32_t curr_cluster = (dir->entry + offset)->first_cluster_low16B;
        int32_t curr_sector_real = PHYSICAL_ADRESS_TEST(curr_cluster);

        for(int i = 0; i < new_entry_size_cl; ++i)
        {
            read_blocks = disk_read(pvolume->disk, curr_sector_real, (uint8_t*)temp_entry + i * SIZE_SECTOR * pvolume->super->sectors_per_cluster, pvolume->super->sectors_per_cluster);
            if(read_blocks != pvolume->super->sectors_per_cluster)
            {
                free(dir->entry);
                free(dir);
                return NULL;
            }
            curr_cluster = pvolume->fat[curr_cluster];
            if(curr_cluster == 0xFFF8)
                break;
            curr_sector_real = PHYSICAL_ADRESS_TEST(curr_cluster);
        }

        free(dir->entry);
        dir->entry = temp_entry;
        dir->curr_entry = 0;

        return dir;
    }

    while(temp)
    {
        char next_name[256] = {0};
        if(*temp == '\\')
            ++temp;

        for(int i = 0; temp[i] != 0 && temp[i] != '\\' != 0; ++i)
            next_name[i] = temp[i];

        int offset = file_search(dir, next_name);
        if(offset == -1)
        {
            free(dir->entry);
            free(dir);
            return NULL;
        }

        if(!((dir->entry + offset)->attr & 0x10))
            return dir;

        /*if(*(dir->entry + offset)->name != '.') //oh shoot, its a root dir again!
        {
            read_blocks = (uint32_t)disk_read(pvolume->disk, pvolume->first_data_sector - pvolume->root_dir_sectors, dir->entry, pvolume->root_dir_sectors);
            if (read_blocks != pvolume->root_dir_sectors)
            {
                free(dir->entry);
                free(dir);
                return NULL;
            }
            return dir;
        }*/

        int32_t new_entry_size_cl = get_dir_cluster_size(dir->entry + offset, pvolume);
        struct fat_entry_t* temp_entry = malloc(new_entry_size_cl * pvolume->super->sectors_per_cluster * SIZE_SECTOR);
        if(!temp_entry)
        {
            free(dir->entry);
            free(dir);
            return NULL;
        }

        int32_t curr_cluster = (dir->entry + offset)->first_cluster_low16B;
        int32_t curr_sector_real = PHYSICAL_ADRESS_TEST(curr_cluster);

        for(int i = 0; i < new_entry_size_cl; ++i)
        {
            read_blocks = disk_read(pvolume->disk, curr_sector_real, (uint8_t*)temp_entry + i * SIZE_SECTOR * pvolume->super->sectors_per_cluster, pvolume->super->sectors_per_cluster);
            if(read_blocks != pvolume->super->sectors_per_cluster)
            {
                free(dir->entry);
                free(dir);
                return NULL;
            }
            curr_cluster = pvolume->fat[curr_cluster];
            if(curr_cluster == 0xFFF8)
                break;
            curr_sector_real = PHYSICAL_ADRESS_TEST(curr_cluster);
        }

        free(dir->entry);
        dir->entry = temp_entry;
        dir->curr_entry = 0;

        temp = strchr(temp, '\\');
    }

    return dir;
}

struct file_t* file_open(struct volume_t* pvolume, const char* path)
{
    if (!pvolume || !pvolume->disk || !pvolume->fat || !path)
    {
        errno = EFAULT;
        return NULL;
    }

    struct dir_t* directory = dir_open_file(pvolume, path);
    if(!directory)
    {
        errno = EFAULT;
        return NULL;
    }

    char* filename = strrchr(path, '\\');
    if(!filename)
        filename = (char*)path;
    if(*filename == '\\')
        filename += 1;

    directory->curr_entry = 0;
    int dir_offset = file_search(directory, filename);
    if (dir_offset == -1)
    {
        dir_close(directory);
        errno = ENOENT;
        return NULL;
    }

    struct file_t *file = (struct file_t *)malloc(sizeof(struct file_t));
    if (!file)
    {
        dir_close(directory);
        errno = ENOMEM;
        return NULL;
    }

    file->entry = (struct fat_entry_t *)malloc(sizeof(struct fat_entry_t));
    if (!file->entry)
    {
        free(file);
        dir_close(directory);
        errno = ENOMEM;
        return NULL;
    }

    memcpy(file->entry, directory->entry + dir_offset, DIR_ENTRY_SIZE);
    file->offset = 0;
    file->volume = pvolume;

    if(file->entry->attr & 0x10)  //if found entry is a directory instead of file, then something is not yes =d
    {
        dir_close(directory);
        errno = EISDIR;
        free(file->entry);
        free(file);
        return NULL;
    }

    dir_close(directory);
    return file;
}

int file_close(struct file_t* stream)
{
    if (!stream)
    {
        errno = EFAULT;
        return -1;
    }
    free(stream->entry);
    free(stream);

    return 0;
}

size_t file_read(void *ptr, size_t size, size_t nmemb, struct file_t *stream)
{
    if(!ptr || !stream)
    {
        if(stream->entry->file_size == stream->offset) return 0;
        errno = EFAULT;
        return -1;
    }

    int32_t curr_cluster = stream->entry->first_cluster_low16B;
    int32_t curr_sector_real;

    uint16_t cluster_offset = stream->offset / (stream->volume->super->bytes_per_sector * stream->volume->super->sectors_per_cluster);
    uint32_t sector_offset = (stream->offset / stream->volume->super->bytes_per_sector) % stream->volume->super->sectors_per_cluster;
    uint32_t byte_offset = stream->offset % stream->volume->super->bytes_per_sector;

    unsigned long to_read;
    if(size * nmemb > stream->entry->file_size - stream->offset)
        to_read = stream->entry->file_size - stream->offset;
    else
        to_read = size * nmemb;

    for(int i = 0; i < cluster_offset; ++i)
        curr_cluster = stream->volume->fat[curr_cluster];

    curr_sector_real = PHYSICAL_ADRESS(curr_cluster);
    size_t bytes_read = 0;

    while(to_read)
    {
        uint8_t sector_bytes[SIZE_SECTOR] = {0};
        int read_blocks = disk_read(stream->volume->disk, curr_sector_real + sector_offset, sector_bytes, 1);
        if(read_blocks != 1)
        {
            errno = ERANGE;
            return -1;
        }

        if(byte_offset)
        {
            if(to_read > SIZE_SECTOR - byte_offset)
            {
                memcpy((uint8_t*)ptr + bytes_read, sector_bytes + byte_offset, SIZE_SECTOR - byte_offset);
                bytes_read += (SIZE_SECTOR - byte_offset);
                to_read -= SIZE_SECTOR - byte_offset;
                byte_offset = 0;
                ++sector_offset;
                if(sector_offset % stream->volume->super->sectors_per_cluster == 0)
                {
                    sector_offset = 0;
                    curr_cluster = stream->volume->fat[curr_cluster];
                    curr_sector_real = PHYSICAL_ADRESS(curr_cluster);
                    continue;
                }
                else
                    continue;
            }
            else
            {
                memcpy((uint8_t*)ptr, sector_bytes + byte_offset, to_read);
                bytes_read += to_read;
                stream->offset += bytes_read;
                return bytes_read / size;
            }
        }

        if(to_read > SIZE_SECTOR)
        {
            memcpy((uint8_t*)ptr + bytes_read, sector_bytes, SIZE_SECTOR);
            bytes_read += SIZE_SECTOR;
            to_read -= SIZE_SECTOR;
            ++sector_offset;
            if(sector_offset % stream->volume->super->sectors_per_cluster == 0)
            {
                sector_offset = 0;
                curr_cluster = stream->volume->fat[curr_cluster];
                curr_sector_real = PHYSICAL_ADRESS(curr_cluster);
                continue;
            }
            else
                continue;
        }
        else
        {
            memcpy((uint8_t*)ptr + bytes_read, sector_bytes, to_read);
            bytes_read += to_read;
            stream->offset += bytes_read;
            return bytes_read / size;
        }
    }
    return bytes_read / size;
}

int32_t file_seek(struct file_t* stream, int32_t offset, int whence)
{
    if(!stream)
    {
        errno = EFAULT;
        return -1;
    }

    if(whence != SEEK_SET && whence != SEEK_CUR && whence != SEEK_END)
    {
        errno = EINVAL;
        return -1;
    }

    if(offset >= 0)
    {
        if(whence == SEEK_SET)
        {
            if((uint32_t)offset > stream->entry->file_size)
            {
                errno = ENXIO;
                return -1;
            }
            stream->offset = offset;
            return stream->offset;
        }
        else if(whence == SEEK_CUR)
        {
            if((uint32_t)offset + stream->offset > stream->entry->file_size)
            {
                errno = ENXIO;
                return -1;
            }
            stream->offset += offset;
            return stream->offset;
        }
        else
        {
            if(offset != 0)
            {
                errno = ENXIO;
                return -1;
            }
            return stream->offset;
        }
    }
    else
    {
        if(whence == SEEK_CUR)
        {
            if((size_t)abs(offset) > stream->offset)
            {
                errno = ENXIO;
                return -1;
            }
            stream->offset += offset;
            return stream->offset;
        }
        else if(whence == SEEK_END)
        {
            if((size_t)abs(offset) > stream->entry->file_size)
            {
                errno = ENXIO;
                return -1;
            }
            stream->offset = stream->entry->file_size + offset;
            return stream->offset;
        }
    }

    errno = ENXIO;
    return -1;
}

int32_t get_dir_cluster_size(struct fat_entry_t* dir_entry, struct volume_t* pvolume)
{
    uint8_t* data = calloc(pvolume->super->sectors_per_cluster * SIZE_SECTOR, 1);
    if(!data)
        return -1;

    int ctr = 0;

    int32_t curr_cluster = dir_entry->first_cluster_low16B;
    int32_t curr_sector_real = PHYSICAL_ADRESS_TEST(curr_cluster);

    while(1)
    {
        int read_blocks = disk_read(pvolume->disk, curr_sector_real, data, pvolume->super->sectors_per_cluster);
        if(read_blocks != pvolume->super->sectors_per_cluster)
        {
            errno = ERANGE;
            free(data);
            return -1;
        }
        ++ctr;
        for(int i = 0; i < SIZE_SECTOR * pvolume->super->sectors_per_cluster; i += DIR_ENTRY_SIZE)
        {
            if(data[i] == 0)
            {
                free(data);
                return ctr;
            }
        }
        curr_cluster = pvolume->fat[curr_cluster];
        if(curr_cluster == 0xFFF8 || curr_cluster == 0xFFFF)
        {
            free(data);
            return ctr;
        }
        curr_sector_real = PHYSICAL_ADRESS_TEST(curr_cluster);
    }
}

struct dir_t* dir_open(struct volume_t* pvolume, const char* dir_path)
{
    if(!pvolume || !pvolume->disk || !pvolume->fat || !dir_path)
    {
        errno = EFAULT;
        return NULL;
    }

    struct dir_t* dir = calloc(1, sizeof(struct dir_t));
    if(!dir)
    {
        errno = ENOMEM;
        return NULL;
    }
    dir->curr_entry = 0;
    dir->entry = malloc(pvolume->root_dir_sectors * pvolume->super->bytes_per_sector);
    if (!dir->entry)
    {
        free(dir);
        return NULL;
    }

    uint32_t read_blocks = (uint32_t)disk_read(pvolume->disk, pvolume->first_data_sector - pvolume->root_dir_sectors, dir->entry, pvolume->root_dir_sectors);
    if (read_blocks != pvolume->root_dir_sectors)
    {
        free(dir->entry);
        free(dir);
        return NULL;
    }
    if(*dir_path == '\\' && dir_path[1] == '\0')
        return dir;

    char* temp = strchr(dir_path, '\\');

    if(!temp)
    {
        char next_name[256] = {0};
        for(int i = 0; dir_path[i] != 0; ++i)
            next_name[i] = dir_path[i];

        int offset = file_search(dir, next_name);
        if(offset == -1)
        {
            free(dir->entry);
            free(dir);
            return NULL;
        }

        if(!((dir->entry + offset)->attr & 0x10))
        {
            free(dir->entry);
            free(dir);
            return NULL;
        }

        int32_t new_entry_size_cl = get_dir_cluster_size(dir->entry + offset, pvolume);
        struct fat_entry_t* temp_entry = malloc(new_entry_size_cl * pvolume->super->sectors_per_cluster * SIZE_SECTOR);
        if(!temp_entry)
        {
            free(dir->entry);
            free(dir);
            return NULL;
        }

        int32_t curr_cluster = (dir->entry + offset)->first_cluster_low16B;
        int32_t curr_sector_real = PHYSICAL_ADRESS_TEST(curr_cluster);

        for(int i = 0; i < new_entry_size_cl; ++i)
        {
            read_blocks = disk_read(pvolume->disk, curr_sector_real, (uint8_t*)temp_entry + i * SIZE_SECTOR * pvolume->super->sectors_per_cluster, pvolume->super->sectors_per_cluster);
            if(read_blocks != pvolume->super->sectors_per_cluster)
            {
                free(dir->entry);
                free(dir);
                return NULL;
            }
            curr_cluster = pvolume->fat[curr_cluster];
            if(curr_cluster == 0xFFF8)
                break;
            curr_sector_real = PHYSICAL_ADRESS_TEST(curr_cluster);
        }

        free(dir->entry);
        dir->entry = temp_entry;
        dir->curr_entry = 0;

        return dir;
    }

    while(temp)
    {
        char next_name[256] = {0};
        if(*temp == '\\')
            ++temp;

        for(int i = 0; temp[i] != 0 && temp[i] != '\\' != 0; ++i)
            next_name[i] = temp[i];

        int offset = file_search(dir, next_name);
        if(offset == -1)
        {
            free(dir->entry);
            free(dir);
            return NULL;
        }

        if(!((dir->entry + offset)->attr & 0x10))
        {
            free(dir->entry);
            free(dir);
            return NULL;
        }

        int32_t new_entry_size_cl = get_dir_cluster_size(dir->entry + offset, pvolume);
        struct fat_entry_t* temp_entry = malloc(new_entry_size_cl * pvolume->super->sectors_per_cluster * SIZE_SECTOR);
        if(!temp_entry)
        {
            free(dir->entry);
            free(dir);
            return NULL;
        }

        int32_t curr_cluster = (dir->entry + offset)->first_cluster_low16B;
        if(curr_cluster == 0)
        {
            free(temp_entry);
            free(dir->entry);
            dir->curr_entry = 0;
            dir->entry = malloc(pvolume->root_dir_sectors * pvolume->super->bytes_per_sector);
            if (!dir->entry)
            {
                free(dir);
                return NULL;
            }

            read_blocks = (uint32_t)disk_read(pvolume->disk, pvolume->first_data_sector - pvolume->root_dir_sectors, dir->entry, pvolume->root_dir_sectors);
            if (read_blocks != pvolume->root_dir_sectors)
            {
                free(dir->entry);
                free(dir);
                return NULL;
            }

            temp = strchr(temp, '\\');
            continue;
        }
        int32_t curr_sector_real = PHYSICAL_ADRESS_TEST(curr_cluster);

        for(int i = 0; i < new_entry_size_cl; ++i)
        {
            read_blocks = disk_read(pvolume->disk, curr_sector_real, (uint8_t*)temp_entry + i * SIZE_SECTOR * pvolume->super->sectors_per_cluster, pvolume->super->sectors_per_cluster);
            if(read_blocks != pvolume->super->sectors_per_cluster)
            {
                free(dir->entry);
                free(dir);
                return NULL;
            }
            curr_cluster = pvolume->fat[curr_cluster];
            if(curr_cluster == 0xFFF8)
                break;
            curr_sector_real = PHYSICAL_ADRESS_TEST(curr_cluster);
        }

        free(dir->entry);
        dir->entry = temp_entry;
        dir->curr_entry = 0;

        temp = strchr(temp, '\\');
    }

    return dir;
}

int dir_read(struct dir_t* pdir, struct dir_entry_t* pentry)
{
    if(!pdir || !pdir->entry || !pentry)
    {
        errno = EFAULT;
        return -1;
    }
    if(*((pdir->entry + pdir->curr_entry)->name) == 0x00)
        return 1;

    size_t i;
    for(i = pdir->curr_entry; ; ++i)
    {
        pentry->has_long_name = 0;
        if(((pdir->entry + i)->attr & 0x0F) == 0x0F) // LFN
        {
            uint8_t ctr = ((pdir->entry + i)->name)[0];
            for(int k = ctr ^ 0x40; k > 0; --k)
            {
                int bcnt = 0;
                for(int j = 0; j < 5; ++j) //first 5*2 bytes
                {
                    (pentry->long_name)[bcnt + (k - 1) * LFN_BYTES] = *((int16_t*)((int8_t*)(pdir->entry + i) + 2 * j + 1));
                    ++bcnt;
                }

                for(int j = 7; j < 13; ++j) //second 6*2 bytes
                {
                    (pentry->long_name)[bcnt + (k - 1) * LFN_BYTES] = *((int16_t*)((int8_t*)(pdir->entry + i) + 2 * j));
                    ++bcnt;
                }

                for(int j = 14; j < 16; ++j) //last 2*2 bytes
                {
                    (pentry->long_name)[bcnt + (k - 1) * LFN_BYTES] = *((int16_t*)((int8_t*)(pdir->entry + i) + 2 * j));
                    ++bcnt;
                }
                bcnt = 0;
                ++i;
            }
            pentry->has_long_name = 1;
            break;
        }
        if(((pdir->entry + i)->attr & 0x08) || ((uint8_t)*(pdir->entry + i)->name == 0xE5))
            continue;
        else if(*(pdir->entry + i)->name == 0x00)
            return 1;
        else
            break;
    }

    pentry->size = (pdir->entry + i)->file_size;
    get_filename(pdir->entry + i, pentry->name);
    pentry->is_readonly = ((pdir->entry + i)->attr & 0x01) != 0;
    pentry->is_hidden = ((pdir->entry + i)->attr & 0x02) != 0;
    pentry->is_system = ((pdir->entry + i)->attr & 0x04) != 0;
    pentry->is_directory = ((pdir->entry + i)->attr & 0x10) != 0;
    pentry->is_archived = ((pdir->entry + i)->attr & 0x20) != 0;
    pdir->curr_entry = ++i;

    return 0;
}

int dir_close(struct dir_t* pdir)
{
    if(!pdir)
    {
        errno = EFAULT;
        return -1;
    }
    free(pdir->entry);
    free(pdir);
    return 0;
}


