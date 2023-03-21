#ifndef FILE_READER_H
#define FILE_READER_H

#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <ctype.h>

#define SIZE_SECTOR 512
#define DIR_ENTRY_SIZE 32
#define PHYSICAL_ADRESS(cluster) ((stream->volume->first_data_sector) + ((cluster) - 2) * (stream->volume->super->sectors_per_cluster))
#define PHYSICAL_ADRESS_TEST(cluster) ((pvolume->first_data_sector) + ((cluster) - 2) * (pvolume->super->sectors_per_cluster))
#define LFN_BYTES 13
struct disk_t
{
    FILE* disk_image;
};

struct volume_t {
    struct fat_super_t* super;

    struct disk_t* disk;
    uint16_t *fat;

    uint16_t total_sectors;
    int32_t fat_size;
    uint16_t root_dir_sectors;
    uint16_t first_data_sector;
    uint16_t first_fat_sector;
    uint32_t data_sectors;
    uint32_t total_clusters;
    uint8_t* root_dir_entries;

}__attribute__ ((packed));

struct fat_super_t {
    uint8_t jump_code[3]; //	The first three bytes EB 3C 90 disassemble to JMP SHORT 3C NOP.
    char oem_name[8]; // 	OEM identifier.
    uint16_t bytes_per_sector; // The number of Bytes per sector
    uint8_t sectors_per_cluster; // 	Number of sectors per cluster.
    uint16_t reserved_sectors; //	Number of reserved sectors. The boot record sectors are included in this value.
    uint8_t fat_count; // 	Number of File Allocation Tables (FAT's) on the storage media. Often this value is 2.
    uint16_t max_root_dir_entries; // 	Number of directory entries (must be set so that the root directory occupies entire sectors).
    uint16_t logical_sectors_count16; //2B sector count The total sectors in the logical volume. If this value is 0, it means there are more than 65535 sectors in the volume, and the actual count is stored in the Large Sector Count entry at 0x20.
    uint8_t media_descriptor_type; // This Byte indicates the media descriptor type.
    uint16_t sectors_per_fat; // This Byte indicates the media descriptor type.
    uint16_t chs_sectors_per_track; // 	Number of sectors per track.
    uint16_t chs_tracks_per_cylinder; // 	Number of heads or sides on the storage media.
    uint32_t hidden_sectors;  // Number of hidden sectors. (i.e. the LBA of the beginning of the partition.)
    uint32_t logical_sectors_count32; //4B sector count 	Large sector count. This field is set if there are more than 65535 sectors in the volume, resulting in a value which does not fit in the Number of Sectors entry at 0x13.
    uint8_t drive_number; // 	Drive number.
    uint8_t flags_windowsnt; // 	Flags in Windows NT. Reserved otherwise.
    uint8_t signature; // 	Signature (must be 0x28 or 0x29).
    uint32_t serial_number; // 	VolumeID 'Serial' number. Used for tracking volumes between computers. You can ignore this if you want.
    char volume_label[11]; // 	Volume label string. This field is padded with spaces.
    char system_identifier[8]; // 	System identifier string. This field is a string representation of the FAT file system type.
    uint8_t boot_code[448]; // 	Boot code.
    uint16_t magic_sig; //0x55AA in little endian so AA55 physically (10101010 01010101)
}__attribute__((packed));

struct time_t{
    uint16_t hour: 5;
    uint16_t minute: 6;
    uint16_t second: 5;
}__attribute__((packed));

struct date_t{
    uint16_t year: 7;
    uint16_t month: 4;
    uint16_t day: 5;
}__attribute__((packed));

struct datetime{
    struct time_t time;
    struct date_t date;
}__attribute__((packed));

struct creation_t{
    uint8_t tenth_seconds;
    struct time_t creation_time;
    struct date_t creation_date;
}__attribute__((packed));

struct fat_entry_t{
    char name[8];
    char extension[3];
    uint8_t attr;
    uint8_t res;
    struct creation_t creation; // 5B
    struct date_t access_date;  // 2B
    uint16_t first_cluster_high16B_ZERO;
    struct datetime modified;   // 4B
    uint16_t first_cluster_low16B;
    uint32_t file_size;
}__attribute__((packed));

struct file_t
{
    struct fat_entry_t* entry;
    size_t offset;
    struct volume_t* volume;
}__attribute__((packed));

struct dir_t
{
    struct fat_entry_t* entry;
    size_t curr_entry;
}__attribute__((packed));

struct dir_entry_t {
    char name[14];
    size_t size;
    uint8_t is_archived: 1;
    uint8_t is_readonly: 1;
    uint8_t is_system: 1;
    uint8_t is_hidden: 1;
    uint8_t is_directory: 1;
    int has_long_name;
    char long_name[256];
}__attribute__((packed));

struct disk_t* disk_open_from_file(const char* volume_file_name);
int disk_read(struct disk_t* pdisk, int32_t first_sector, void* buffer, int32_t sectors_to_read);
int disk_close(struct disk_t* pdisk);

struct volume_t* fat_open(struct disk_t* pdisk, uint32_t first_sector);
int fat_close(struct volume_t* pvolume);

struct file_t* file_open(struct volume_t* pvolume, const char* path);
int file_close(struct file_t* stream);
size_t file_read(void *ptr, size_t size, size_t nmemb, struct file_t *stream);
int32_t file_seek(struct file_t* stream, int32_t offset, int whence);

struct dir_t* dir_open(struct volume_t* pvolume, const char* dir_path);
struct dir_t* dir_open_file(struct volume_t* pvolume, const char* dir_path);
int dir_read(struct dir_t* pdir, struct dir_entry_t* pentry);
int dir_close(struct dir_t* pdir);
int32_t get_dir_cluster_size(struct fat_entry_t* dir_entry, struct volume_t* pvolume);

#endif
