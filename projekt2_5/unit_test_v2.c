/*
 * Unit Test Bootstrap
 * Autor: Tomasz Jaworski, 2018-2020
 *
 * Test dla zadania Projekt: Virtual FAT i długie nazwy plików (5,0)
 * Autor testowanej odpowiedzi: Mikołaj Rajczyk
 * Test wygenerowano automatycznie o 2021-12-19 22:07:43.254082
 *
 * Debug: 
 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <signal.h>
#include <setjmp.h>
#include <assert.h>

#if !defined(__clang__) && !defined(__GNUC__)
// Zakomentuj poniższy błąd, jeżeli chcesz przetestować testy na swoim kompilatorze C.
#error System testow jednostkowych jest przeznaczony dla kompilatorów GCC/Clang.
#endif

#if defined(_WIN32) || defined(_WIN64) || defined(__CYGWIN__)
// Zakomentuj poniższy błąd, jeżeli chcesz przetestować testy na platformie Windows.
#error System testow jednostkowych NIE jest przeznaczony dla testów uruchamianych na platformach Windows.
#endif

#define _RLDEBUG_API_
#include "unit_helper_v2.h"
#include "rdebug.h"

#include "tested_declarations.h"
#include "rdebug.h"

//
// Elementy globalne dla całego testu
//




//
//  Test 1: Sprawdzanie poprawności działania funkcji disk_open_from_file
//
void UTEST1(void)
{
    // informacje o teście
    test_start(1, "Sprawdzanie poprawności działania funkcji disk_open_from_file", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    


            struct disk_t* disk = disk_open_from_file("SEEM.TXT");
            test_error(disk == NULL, "Funkcja disk_open_from_file() powinna zwrócić NULL przy próbie otwarcia nieistniejącego pliku");

            test_no_heap_leakage();
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
        
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 2: Sprawdzanie poprawności działania funkcji disk_open_from_file
//
void UTEST2(void)
{
    // informacje o teście
    test_start(2, "Sprawdzanie poprawności działania funkcji disk_open_from_file", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    


            struct disk_t* disk = disk_open_from_file(NULL);
            test_error(disk == NULL, "Funkcja disk_open_from_file() powinna zwrócić NULL przy próbie otwarcia nieistniejącego pliku");

            test_no_heap_leakage();
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
        
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 3: Sprawdzanie poprawności działania funkcji disk_close
//
void UTEST3(void)
{
    // informacje o teście
    test_start(3, "Sprawdzanie poprawności działania funkcji disk_close", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    


            disk_close(NULL);
      
            test_no_heap_leakage();
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
        
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 4: Sprawdzanie poprawności działania funkcji fat_open
//
void UTEST4(void)
{
    // informacje o teście
    test_start(4, "Sprawdzanie poprawności działania funkcji fat_open", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    


            struct disk_t* disk = disk_open_from_file("able.img");
            test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");

            struct volume_t* volume = fat_open(disk, 0);
            test_error(volume == NULL, "Funkcja fat_open() powinna zwrócić NULL w przypadku przekazania błędnego obrazu dysku");
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

            disk_close(disk);

            test_no_heap_leakage();
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
        
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 5: Sprawdzanie poprawności działania funkcji disk_open_from_file
//
void UTEST5(void)
{
    // informacje o teście
    test_start(5, "Sprawdzanie poprawności działania funkcji disk_open_from_file", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

            struct volume_t* volume = fat_open(NULL, 0);
            test_error(volume == NULL, "Funkcja fat_open() powinna zwrócić NULL w przypadku przekazania błędnego obrazu dysku");

            test_no_heap_leakage();
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
        
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 6: Sprawdzanie poprawności działania funkcji file_read
//
void UTEST6(void)
{
    // informacje o teście
    test_start(6, "Sprawdzanie poprawności działania funkcji file_read", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    
        
                char *filecontent = (char *)calloc(1958, 1);
                char expected_filecontent[1959] = "";
        
                strcat(expected_filecontent, "it leads thee up\nAlong this ladder, down whose hallow\'d steps\nNone e\'er descend, and mount them not again,\nWho from his phial should refuse thee wine\nTo slake thy thirst, no less constrained were,\nThan water flowing not unto the sea.\nThou fain wouldst hear, what plants are these, that bloom\nIn the bright garland, which, admiring, girds\nThis fair dame round, who strengthens thee for heav\'n.\nI then was of the lambs, that Dominic\nLeads, for his saintly flock, along the way,\nWhere well they thrive, not sworn with vanity.\nHe, nearest on my right hand, brother was,\nAnd master to me:  Albert of Cologne\nIs this:  and of Aquinum, Thomas I.\nIf thou of all the rest wouldst be assur\'d,\nLet thine eye, waiting on the words I speak,\nIn circuit journey round the blessed wreath.\nThat next resplendence issues from the smile\nOf Gratian, who to either forum lent\nSuch help, as favour wins in Paradise.\nThe other, nearest, who adorns our quire,\nWas Peter, he that with the widow gave\nTo holy church his treasure.  The fifth light,\nGoodliest of all, is by such love inspired,\nThat all your world craves tidings of its doom:\nWithin, there is the lofty light, endow\'d\nWith sapience so profound, if truth be truth,\nThat with a ken of such wide amplitude\nNo second hath arisen.  Next behold\nThat taper\'s radiance, to whose view was shown,\nClearliest, the nature and the ministry\nAngelical, while yet in flesh it dwelt.\nIn the other little light serenely smiles\nThat pleader for the Christian temples, he\nWho did provide Augustin of his lore.\nNow, if thy mind\'s eye pass from light to light,\nUpon my praises following, of the eighth\nThy thirst is next.  The saintly soul, that shows\nThe world\'s deceitfulness, to all who hear him,\nIs, with the sight of all the good, that is,\nBlest there.  The limbs, whence it was driven, lie\nDown in Cieldauro, and from martyrdom\nAnd exile came it here.  Lo!  further on,\nWhere flames the arduous Spirit of Isidore,\nOf Bede, and Richard, ");
                
        
                struct disk_t* disk = disk_open_from_file("see_fat16_volume.img");
                test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
        
                struct volume_t* volume = fat_open(disk, 0);
                test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
        
                struct file_t* file = file_open(volume, "BOaRd.BIN");
                test_error(file != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
        
                size_t size = file_read(filecontent, 1, 1958, file);
                test_error(size == 1958, "Funkcja file_read() niepoprawnie wczytała dane z pliku, powinna wczytać 1958 bajtów, a wczytała %lu", size);
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                int diff_pos = mem_find_first_difference(filecontent, expected_filecontent, 1958);
            
                // jeśli jest, to raportuj błąd
                test_error(diff_pos == -1, "Dane wczytane z pliku nie są poprawne; różnica w bajcie %d; jest 0x%02x a powinno być 0x%02x",
                    diff_pos, mem_get_byte(filecontent, diff_pos), mem_get_byte(expected_filecontent, diff_pos));
            
                onerror_compare_memory(expected_filecontent, filecontent, 1958);


                free(filecontent);
        
                file_close(file);
                fat_close(volume);
                disk_close(disk);
        
                test_no_heap_leakage();
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
            
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 7: Sprawdzanie poprawności działania funkcji file_read
//
void UTEST7(void)
{
    // informacje o teście
    test_start(7, "Sprawdzanie poprawności działania funkcji file_read", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    
        
                char *filecontent = (char *)calloc(419, 1);
                char expected_filecontent[420] = "";
        
                strcat(expected_filecontent, "The damsels turn\'d; and on the Gryphon mov\'d\nThe sacred burden, with a pace so smooth,\nNo feather on him trembled.  The fair dame\nWho through the wave had drawn me, companied\nBy Statius and myself, pursued the wheel,\nWhose orbit, rolling, mark\'d a lesser arch.\n     Through the high wood, now void (the more her blame,\nWho by the serpent was beguil\'d) I past\nWith step in cadence to the harmony\nAngelic.  Onward had we ");
                
        
                struct disk_t* disk = disk_open_from_file("see_fat16_volume.img");
                test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
        
                struct volume_t* volume = fat_open(disk, 0);
                test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
        
                struct file_t* file = file_open(volume, "DEserT");
                test_error(file != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
        
                size_t size = file_read(filecontent, 1, 419, file);
                test_error(size == 419, "Funkcja file_read() niepoprawnie wczytała dane z pliku, powinna wczytać 419 bajtów, a wczytała %lu", size);
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                int diff_pos = mem_find_first_difference(filecontent, expected_filecontent, 419);
            
                // jeśli jest, to raportuj błąd
                test_error(diff_pos == -1, "Dane wczytane z pliku nie są poprawne; różnica w bajcie %d; jest 0x%02x a powinno być 0x%02x",
                    diff_pos, mem_get_byte(filecontent, diff_pos), mem_get_byte(expected_filecontent, diff_pos));
            
                onerror_compare_memory(expected_filecontent, filecontent, 419);


                free(filecontent);
        
                file_close(file);
                fat_close(volume);
                disk_close(disk);
        
                test_no_heap_leakage();
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
            
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 8: Sprawdzanie poprawności działania funkcji file_read
//
void UTEST8(void)
{
    // informacje o teście
    test_start(8, "Sprawdzanie poprawności działania funkcji file_read", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    
        
                char *filecontent = (char *)calloc(2667, 1);
                char expected_filecontent[2668] = "";
        
                strcat(expected_filecontent, "them whate\'er thou list.\"\n     And I therewith began:  \"So may no time\nFilch your remembrance from the thoughts of men\nIn th\' upper world, but after many suns\nSurvive it, as ye tell me, who ye are,\nAnd of what race ye come.  Your punishment,\nUnseemly and disgustful in its kind,\nDeter you not from opening thus much to me.\"\n     \"Arezzo was my dwelling,\" answer\'d one,\n\"And me Albero of Sienna brought\nTo die by fire; but that, for which I died,\nLeads me not here.  True is in sport I told him,\nThat I had learn\'d to wing my flight in air.\nAnd he admiring much, as he was void\nOf wisdom, will\'d me to declare to him\nThe secret of mine art:  and only hence,\nBecause I made him not a Daedalus,\nPrevail\'d on one suppos\'d his sire to burn me.\nBut Minos to this chasm last of the ten,\nFor that I practis\'d alchemy on earth,\nHas doom\'d me.  Him no subterfuge eludes.\"\n     Then to the bard I spake:  \"Was ever race\nLight as Sienna\'s?  Sure not France herself\nCan show a tribe so frivolous and vain.\"\n     The other leprous spirit heard my words,\nAnd thus return\'d:  \"Be Stricca from this charge\nExempted, he who knew so temp\'rately\nTo lay out fortune\'s gifts; and Niccolo\nWho first the spice\'s costly luxury\nDiscover\'d in that garden, where such seed\nRoots deepest in the soil:  and be that troop\nExempted, with whom Caccia of Asciano\nLavish\'d his vineyards and wide-spreading woods,\nAnd his rare wisdom Abbagliato show\'d\nA spectacle for all.  That thou mayst know\nWho seconds thee against the Siennese\nThus gladly, bend this way thy sharpen\'d sight,\nThat well my face may answer to thy ken;\nSo shalt thou see I am Capocchio\'s ghost,\nWho forg\'d transmuted metals by the power\nOf alchemy; and if I scan thee right,\nThus needs must well remember how I aped\nCreative nature by my subtle art.\"\n\n\n\nCANTO XXX\n\nWHAT time resentment burn\'d in Juno\'s breast\nFor Semele against the Theban blood,\nAs more than once in dire mischance was rued,\nSuch fatal frenzy seiz\'d on Athamas,\nThat he his spouse beholding with a babe\nLaden on either arm, \"Spread out,\" he cried,\n\"The meshes, that I take the lioness\nAnd the young lions at the pass:  \"then forth\nStretch\'d he his merciless talons, grasping one,\nOne helpless innocent, Learchus nam\'d,\nWhom swinging down he dash\'d upon a rock,\nAnd with her other burden self-destroy\'d\nThe hapless mother plung\'d:  and when the pride\nOf all-presuming Troy fell from its height,\nBy fortune overwhelm\'d, and the old king\nWith his realm perish\'d, then did Hecuba,\nA wretch forlorn and captive, when she saw\nPolyxena first slaughter\'d, and her son,\nHer Polydorus, on the wild sea-beach\nNext met the mourner\'s view, then reft of sense\nDid she run barking ");
                
        
                struct disk_t* disk = disk_open_from_file("see_fat16_volume.img");
                test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
        
                struct volume_t* volume = fat_open(disk, 0);
                test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
        
                struct file_t* file = file_open(volume, "ROOM.BiN");
                test_error(file != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
        
                size_t size = file_read(filecontent, 1, 2667, file);
                test_error(size == 2667, "Funkcja file_read() niepoprawnie wczytała dane z pliku, powinna wczytać 2667 bajtów, a wczytała %lu", size);
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                int diff_pos = mem_find_first_difference(filecontent, expected_filecontent, 2667);
            
                // jeśli jest, to raportuj błąd
                test_error(diff_pos == -1, "Dane wczytane z pliku nie są poprawne; różnica w bajcie %d; jest 0x%02x a powinno być 0x%02x",
                    diff_pos, mem_get_byte(filecontent, diff_pos), mem_get_byte(expected_filecontent, diff_pos));
            
                onerror_compare_memory(expected_filecontent, filecontent, 2667);


                free(filecontent);
        
                file_close(file);
                fat_close(volume);
                disk_close(disk);
        
                test_no_heap_leakage();
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
            
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 9: Sprawdzanie poprawności działania funkcji file_read
//
void UTEST9(void)
{
    // informacje o teście
    test_start(9, "Sprawdzanie poprawności działania funkcji file_read", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    
        
                char *filecontent = (char *)calloc(2750, 1);
                char expected_filecontent[2751] = "";
        
                strcat(expected_filecontent, "son for which supposed crime he suffered\ndeath. So say the Italian commentators.  Henault represents the\nmatter very differently: \"Pierre de la Brosse, formerly barber to\nSt. Louis, afterwards the favorite of Philip, fearing the too\ngreat attachment of the king for his wife Mary, accuses this\nprincess of having poisoned Louis, eldest son of Philip, by his\nfirst marriage. This calumny is discovered by a nun of Nivelle in\nFlanders.  La Brosse is hung.\" Abrege Chron. t. 275, &c.\n\nv. 30.  In thy text.]  He refers to Virgil, Aen. 1, vi.  376.\nDesine fata deum flecti sperare precando, 37. The sacred height\nOf judgment. Shakespeare, Measure for Measure, a. ii. s. 2.\nIf he, which is the top of judgment\n\nv. 66.  Eyeing us as a lion on his watch.]\nA guisa di Leon quando si posa.\nA line taken by Tasso, G.  L. c. x. st. 56.\n\nv. 76.  Sordello.]  The history of Sordello\'s life is wrapt in\nthe obscurity of romance.  That he distinguished himself by his\nskill in Provencal poetry is certain. It is probable that he was\nborn towards the end of the twelfth, and died about the middle of\nthe succeeding century.  Tiraboschi has taken much pains to sift\nall the notices he could collect relating to him.  Honourable\nmention of his name is made by our Poet in the Treatise de Vulg.\nEloq.  1. i. c. 15.\n\nv. 76.  Thou inn of grief.]\nThou most beauteous inn\nWhy should hard-favour\'d grief be lodg\'d in thee?\nShakespeare, Richard II a. 5. s. 1.\n\nv. 89.  Justinian\'s hand.]  \"What avails it that Justinian\ndelivered thee from the Goths, and reformed thy laws, if thou art\nno longer under the control of his successors in the empire?\"\n\nv. 94.  That which God commands.]  He alludes to the precept-\n\"Render unto Caesar the things which are Caesar\'s.\"\n\nv. 98.  O German Albert!]  The Emperor Albert I. succeeded\nAdolphus in 1298, and was murdered in 1308.  See Par Canto XIX\n114 v. 103.  Thy successor.]  The successor of Albert was Henry\nof Luxembourg, by whose interposition in the affairs of Italy our\nPoet hoped to have been reinstated in his native city.\n\nv. 101.  Thy sire.]  The Emperor Rodolph, too intent on\nincreasing his power in Germany to give much of his thoughts to\nItaly, \"the garden of the empire.\"\n\nv. 107.  Capulets and Montagues.]  Our ears are so familiarized\nto the names of these rival families in the language of\nShakespeare, that I have used them instead of the \"Montecchi\" and\n\"Cappelletti.\"\n\nv. 108.  Philippeschi and Monaldi.] Two other rival families in\nOrvieto.\n\nv. 113.  What safety, Santafiore can supply.]  A place between\nPisa and Sienna.  What he alludes to is so doubtful, that it is\nnot certain whether we should not read \"come si cura\"--\" How\nSantafiore is governed.\" Perhaps the event related in the note to\nv. 58, Canto XI. m");
                
        
                struct disk_t* disk = disk_open_from_file("see_fat16_volume.img");
                test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
        
                struct volume_t* volume = fat_open(disk, 0);
                test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
        
                struct file_t* file = file_open(volume, "GREEn.bIN");
                test_error(file != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
        
                size_t size = file_read(filecontent, 1, 2750, file);
                test_error(size == 2750, "Funkcja file_read() niepoprawnie wczytała dane z pliku, powinna wczytać 2750 bajtów, a wczytała %lu", size);
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                int diff_pos = mem_find_first_difference(filecontent, expected_filecontent, 2750);
            
                // jeśli jest, to raportuj błąd
                test_error(diff_pos == -1, "Dane wczytane z pliku nie są poprawne; różnica w bajcie %d; jest 0x%02x a powinno być 0x%02x",
                    diff_pos, mem_get_byte(filecontent, diff_pos), mem_get_byte(expected_filecontent, diff_pos));
            
                onerror_compare_memory(expected_filecontent, filecontent, 2750);


                free(filecontent);
        
                file_close(file);
                fat_close(volume);
                disk_close(disk);
        
                test_no_heap_leakage();
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
            
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 10: Sprawdzanie poprawności działania funkcji file_read
//
void UTEST10(void)
{
    // informacje o teście
    test_start(10, "Sprawdzanie poprawności działania funkcji file_read", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    
        
                char *filecontent = (char *)calloc(1924, 1);
                char expected_filecontent[1925] = "";
        
                strcat(expected_filecontent, "di, king of Naples and Sicily, is\ndefeated and slain by Charles of Anjou.  Hell, C. XXVIII. 13.\nAnd Purgatory, C. III. 110.\n\nGuido Novello of Polenta obtains the sovereignty of Ravenna.\nH. C. XXVII. 38.\n\n1266.  Two of the Frati Godenti chosen arbitrators of the\ndifferences at Florence.  H. C. XXIII. 104.\nGianni de\' Soldanieri heads the populace in that city.  H. C.\nXXXII. 118.\n\n1268.  Charles of Anjou puts Conradine to death, and becomes King\nof Naples.  H. C. XXVIII. 16 and Purg C. XX. 66.\n\n1272.  Henry III. of England is succeeded by Edward I. Purg. C.\nVII. 129.\n\n1274.  Our Poet first sees Beatrice, daughter of Folco Portinari.\n\nFra.\nGuittone d\'Arezzo, the poet, dies.  Purg. C. XXIV. 56.\nThomas Aquinas dies.  Purg. C. XX. 67.  and Par. C. X. 96.\nBuonaventura dies.  Par. C. XII. 25.\n\n1275.  Pierre de la Brosse, secretary to Philip III. of France,\nexecuted.  Purg. C. VI. 23.\n\n1276.  Giotto, the painter, is born.  Purg. C. XI. 95.  Pope\nAdrian V. dies.  Purg. C. XIX. 97.\nGuido Guinicelli, the poet, dies.  Purg. C. XI. 96. and C. XXVI.\n83.\n\n1277.  Pope John XXI.  dies.  Par. C. XII. 126.\n\n1278.  Ottocar, king of Bohemia, dies.  Purg. C. VII. 97.\n\n1279.  Dionysius succeeds to the throne of Portugal.  Par. C.\nXIX. 135.\n\n1280.  Albertus Magnus dies.  Par. C. X. 95.\n\n1281.  Pope Nicholas III. dies.  H. C. XIX 71.\nDante studies at the universities of Bologna and Padua.\n\n1282.  The Sicilian vespers.  Par. C. VIII. 80.\nThe French defeated by the people of Forli.  H. C. XXVII. 41.\nTribaldello de\' Manfredi betrays the city of Faenza.  H. C.\nXXXII. 119.\n\n1284.  Prince Charles of Anjou is defeated and made prisoner by\nRugiez\nde Lauria, admiral to Peter III. of Arragon.  Purg. C. XX. 78.\nCharles I.  king of Naples, dies.  Purg. C. VII. 111.\n\n1285.  Pope Martin IV.  dies.  Purg. C. XXIV. 23.\nPhilip III.  of France, and Peter III.  of Arragon, die. Purg. C.\nVII. 101 and\n110.\nHenry II. king of Cyprus, comes ");
                
        
                struct disk_t* disk = disk_open_from_file("see_fat16_volume.img");
                test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
        
                struct volume_t* volume = fat_open(disk, 0);
                test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
        
                struct file_t* file = file_open(volume, "EQUAL.TX");
                test_error(file != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
        
                size_t size = file_read(filecontent, 1, 1924, file);
                test_error(size == 1924, "Funkcja file_read() niepoprawnie wczytała dane z pliku, powinna wczytać 1924 bajtów, a wczytała %lu", size);
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                int diff_pos = mem_find_first_difference(filecontent, expected_filecontent, 1924);
            
                // jeśli jest, to raportuj błąd
                test_error(diff_pos == -1, "Dane wczytane z pliku nie są poprawne; różnica w bajcie %d; jest 0x%02x a powinno być 0x%02x",
                    diff_pos, mem_get_byte(filecontent, diff_pos), mem_get_byte(expected_filecontent, diff_pos));
            
                onerror_compare_memory(expected_filecontent, filecontent, 1924);


                free(filecontent);
        
                file_close(file);
                fat_close(volume);
                disk_close(disk);
        
                test_no_heap_leakage();
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
            
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 11: Sprawdzanie poprawności działania funkcji file_read
//
void UTEST11(void)
{
    // informacje o teście
    test_start(11, "Sprawdzanie poprawności działania funkcji file_read", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    
        
                char *filecontent = (char *)calloc(2048, 1);
                char expected_filecontent[2049] = "";
        
                strcat(expected_filecontent, "that which follows them?\"\n     I straightway mark\'d a tribe behind them walk,\nAs if attendant on their leaders, cloth\'d\nWith raiment of such whiteness, as on earth\nWas never.  On my left, the wat\'ry gleam\nBorrow\'d, and gave me back, when there I look\'d.\nAs in a mirror, my left side portray\'d.\n     When I had chosen on the river\'s edge\nSuch station, that the distance of the stream\nAlone did separate me; there I stay\'d\nMy steps for clearer prospect, and beheld\nThe flames go onward, leaving, as they went,\nThe air behind them painted as with trail\nOf liveliest pencils!  so distinct were mark\'d\nAll those sev\'n listed colours, whence the sun\nMaketh his bow, and Cynthia her zone.\nThese streaming gonfalons did flow beyond\nMy vision; and ten paces, as I guess,\nParted the outermost.  Beneath a sky\nSo beautiful, came foul and-twenty elders,\nBy two and two, with flower-de-luces crown\'d.\nAll sang one song:  \"Blessed be thou among\nThe daughters of Adam!  and thy loveliness\nBlessed for ever!\"  After that the flowers,\nAnd the fresh herblets, on the opposite brink,\nWere free from that elected race; as light\nIn heav\'n doth second light, came after them\nFour animals, each crown\'d with verdurous leaf.\nWith six wings each was plum\'d, the plumage full\nOf eyes, and th\' eyes of Argus would be such,\nWere they endued with life.  Reader, more rhymes\nWill not waste in shadowing forth their form:\nFor other need no straitens, that in this\nI may not give my bounty room.  But read\nEzekiel; for he paints them, from the north\nHow he beheld them come by Chebar\'s flood,\nIn whirlwind, cloud and fire; and even such\nAs thou shalt find them character\'d by him,\nHere were they; save as to the pennons; there,\nFrom him departing, John accords with me.\n     The space, surrounded by the four, enclos\'d\nA car triumphal: on two wheels it came\nDrawn at a Gryphon\'s neck; and he above\nStretch\'d either wing uplifted, \'tween the midst\nAnd the three listed hues, on each side three;\nSo that the wings did cleave or injure none;\nAnd out of sight they rose.  The members,");
                
        
                struct disk_t* disk = disk_open_from_file("see_fat16_volume.img");
                test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
        
                struct volume_t* volume = fat_open(disk, 0);
                test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
        
                struct file_t* file = file_open(volume, "TEN");
                test_error(file != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
        
                size_t size = file_read(filecontent, 1, 2048, file);
                test_error(size == 2048, "Funkcja file_read() niepoprawnie wczytała dane z pliku, powinna wczytać 2048 bajtów, a wczytała %lu", size);
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                int diff_pos = mem_find_first_difference(filecontent, expected_filecontent, 2048);
            
                // jeśli jest, to raportuj błąd
                test_error(diff_pos == -1, "Dane wczytane z pliku nie są poprawne; różnica w bajcie %d; jest 0x%02x a powinno być 0x%02x",
                    diff_pos, mem_get_byte(filecontent, diff_pos), mem_get_byte(expected_filecontent, diff_pos));
            
                onerror_compare_memory(expected_filecontent, filecontent, 2048);


                free(filecontent);
        
                file_close(file);
                fat_close(volume);
                disk_close(disk);
        
                test_no_heap_leakage();
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
            
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 12: Sprawdzanie poprawności działania funkcji file_read
//
void UTEST12(void)
{
    // informacje o teście
    test_start(12, "Sprawdzanie poprawności działania funkcji file_read", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    
        
                char *filecontent = (char *)calloc(3356, 1);
                char expected_filecontent[3357] = "";
        
                strcat(expected_filecontent, " the other more erect he stands,\nEach part except the gold, is rent throughout;\nAnd from the fissure tears distil, which join\'d\nPenetrate to that cave.  They in their course\nThus far precipitated down the rock\nForm Acheron, and Styx, and Phlegethon;\nThen by this straiten\'d channel passing hence\nBeneath, e\'en to the lowest depth of all,\nForm there Cocytus, of whose lake (thyself\nShall see it) I here give thee no account.\"\n     Then I to him:  \"If from our world this sluice\nBe thus deriv\'d; wherefore to us but now\nAppears it at this edge?\"  He straight replied:\n\"The place, thou know\'st, is round; and though great part\nThou have already pass\'d, still to the left\nDescending to the nethermost, not yet\nHast thou the circuit made of the whole orb.\nWherefore if aught of new to us appear,\nIt needs not bring up wonder in thy looks.\"\n     Then I again inquir\'d:  \"Where flow the streams\nOf Phlegethon and Lethe? for of one\nThou tell\'st not, and the other of that shower,\nThou say\'st, is form\'d.\"  He answer thus return\'d:\n\"Doubtless thy questions all well pleas\'d I hear.\nYet the red seething wave might have resolv\'d\nOne thou proposest.  Lethe thou shalt see,\nBut not within this hollow, in the place,\nWhither to lave themselves the spirits go,\nWhose blame hath been by penitence remov\'d.\"\nHe added:  \"Time is now we quit the wood.\nLook thou my steps pursue:  the margins give\nSafe passage, unimpeded by the flames;\nFor over them all vapour is extinct.\"\n\n\n\nCANTO XV\n\nOne of the solid margins bears us now\nEnvelop\'d in the mist, that from the stream\nArising, hovers o\'er, and saves from fire\nBoth piers and water.  As the Flemings rear\nTheir mound, \'twixt Ghent and Bruges, to chase back\nThe ocean, fearing his tumultuous tide\nThat drives toward them, or the Paduans theirs\nAlong the Brenta, to defend their towns\nAnd castles, ere the genial warmth be felt\nOn Chiarentana\'s top; such were the mounds,\nSo fram\'d, though not in height or bulk to these\nMade equal, by the master, whosoe\'er\nHe was, that rais\'d them here.  We from the wood\nWere not so far remov\'d, that turning round\nI might not have discern\'d it, when we met\nA troop of spirits, who came beside the pier.\n     They each one ey\'d us, as at eventide\nOne eyes another under a new moon,\nAnd toward us sharpen\'d their sight as keen,\nAs an old tailor at his needle\'s eye.\n     Thus narrowly explor\'d by all the tribe,\nI was agniz\'d of one, who by the skirt\nCaught me, and cried, \"What wonder have we here!\"\n     And I, when he to me outstretch\'d his arm,\nIntently fix\'d my ken on his parch\'d looks,\nThat although smirch\'d with fire, they hinder\'d not\nBut I remember\'d him; and towards his face\nMy hand inclining, answer\'d:  \"Sir! Brunetto!\nAnd art thou here?\"  He thus to me:  \"My son!\nOh let it not displease thee, if Brunetto\nLatini but a little space with thee\nTurn back, and leave his fellows to proceed.\"\n     I thus to him replied:  \"Much as I can,\nI thereto pray thee; and if thou be willing,\nThat I here seat me with thee, I consent;\nHis leave, with whom I journey, first obtain\'d.\"\n     \"O son!\" said he, \" whoever of this throng\nOne instant stops, lies then a hundred years,\nNo fan to ventilate him, when the fire\nSmites sorest.  Pass thou therefore on.  I close\nWill at thy garments walk, and then rejoin\nMy troop, who go mourning their endless doom.\"\n     I dar\'d not from the path des");
                
        
                struct disk_t* disk = disk_open_from_file("see_fat16_volume.img");
                test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
        
                struct volume_t* volume = fat_open(disk, 0);
                test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
        
                struct file_t* file = file_open(volume, "gaMe.TXt");
                test_error(file != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
        
                size_t size = file_read(filecontent, 1, 3356, file);
                test_error(size == 3356, "Funkcja file_read() niepoprawnie wczytała dane z pliku, powinna wczytać 3356 bajtów, a wczytała %lu", size);
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                int diff_pos = mem_find_first_difference(filecontent, expected_filecontent, 3356);
            
                // jeśli jest, to raportuj błąd
                test_error(diff_pos == -1, "Dane wczytane z pliku nie są poprawne; różnica w bajcie %d; jest 0x%02x a powinno być 0x%02x",
                    diff_pos, mem_get_byte(filecontent, diff_pos), mem_get_byte(expected_filecontent, diff_pos));
            
                onerror_compare_memory(expected_filecontent, filecontent, 3356);


                free(filecontent);
        
                file_close(file);
                fat_close(volume);
                disk_close(disk);
        
                test_no_heap_leakage();
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
            
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 13: Sprawdzanie poprawności działania funkcji file_read
//
void UTEST13(void)
{
    // informacje o teście
    test_start(13, "Sprawdzanie poprawności działania funkcji file_read", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    
        
                char *filecontent = (char *)calloc(88, 1);
                char expected_filecontent[89] = "";
        
                strcat(expected_filecontent, "\n\nv. 14.  Broad are their pennons.]  From Virg. Aen. l. iii. 216.\n\nv. 48.  In my verse d");
                
        
                struct disk_t* disk = disk_open_from_file("see_fat16_volume.img");
                test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
        
                struct volume_t* volume = fat_open(disk, 0);
                test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
        
                struct file_t* file = file_open(volume, "bar laSt wifE leD SCAle reach valuE ofFer.jII");
                test_error(file != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
        
                size_t size = file_read(filecontent, 1, 88, file);
                test_error(size == 88, "Funkcja file_read() niepoprawnie wczytała dane z pliku, powinna wczytać 88 bajtów, a wczytała %lu", size);
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                int diff_pos = mem_find_first_difference(filecontent, expected_filecontent, 88);
            
                // jeśli jest, to raportuj błąd
                test_error(diff_pos == -1, "Dane wczytane z pliku nie są poprawne; różnica w bajcie %d; jest 0x%02x a powinno być 0x%02x",
                    diff_pos, mem_get_byte(filecontent, diff_pos), mem_get_byte(expected_filecontent, diff_pos));
            
                onerror_compare_memory(expected_filecontent, filecontent, 88);


                free(filecontent);
        
                file_close(file);
                fat_close(volume);
                disk_close(disk);
        
                test_no_heap_leakage();
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
            
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 14: Sprawdzanie poprawności działania funkcji file_read
//
void UTEST14(void)
{
    // informacje o teście
    test_start(14, "Sprawdzanie poprawności działania funkcji file_read", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    
        
                char *filecontent = (char *)calloc(157, 1);
                char expected_filecontent[158] = "";
        
                strcat(expected_filecontent, "n 1285, at Perpignan, in his retreat from Arragon.\n\nv. 102.  Him of gentle look.]  Henry of Naverre, father of Jane\nmarried to Philip IV of France, whom Dant");
                
        
                struct disk_t* disk = disk_open_from_file("see_fat16_volume.img");
                test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
        
                struct volume_t* volume = fat_open(disk, 0);
                test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
        
                struct file_t* file = file_open(volume, "SUBSTANC");
                test_error(file != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
        
                size_t size = file_read(filecontent, 1, 157, file);
                test_error(size == 157, "Funkcja file_read() niepoprawnie wczytała dane z pliku, powinna wczytać 157 bajtów, a wczytała %lu", size);
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                int diff_pos = mem_find_first_difference(filecontent, expected_filecontent, 157);
            
                // jeśli jest, to raportuj błąd
                test_error(diff_pos == -1, "Dane wczytane z pliku nie są poprawne; różnica w bajcie %d; jest 0x%02x a powinno być 0x%02x",
                    diff_pos, mem_get_byte(filecontent, diff_pos), mem_get_byte(expected_filecontent, diff_pos));
            
                onerror_compare_memory(expected_filecontent, filecontent, 157);


                free(filecontent);
        
                file_close(file);
                fat_close(volume);
                disk_close(disk);
        
                test_no_heap_leakage();
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
            
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 15: Sprawdzanie poprawności działania funkcji file_read
//
void UTEST15(void)
{
    // informacje o teście
    test_start(15, "Sprawdzanie poprawności działania funkcji file_read", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

                char *filecontent = (char *)calloc(1958, 1);
                char expected_filecontent[1959] = "";

                strcat(expected_filecontent, "it leads thee up\nAlong this ladder, down whose hallow\'d steps\nNone e\'er descend, and mount them not again,\nWho from his phial should refuse thee wine\nTo slake thy thirst, no less constrained were,\nThan water flowing not unto the sea.\nThou fain wouldst hear, what plants are these, that bloom\nIn the bright garland, which, admiring, girds\nThis fair dame round, who strengthens thee for heav\'n.\nI then was of the lambs, that Dominic\nLeads, for his saintly flock, along the way,\nWhere well they thrive, not sworn with vanity.\nHe, nearest on my right hand, brother was,\nAnd master to me:  Albert of Cologne\nIs this:  and of Aquinum, Thomas I.\nIf thou of all the rest wouldst be assur\'d,\nLet thine eye, waiting on the words I speak,\nIn circuit journey round the blessed wreath.\nThat next resplendence issues from the smile\nOf Gratian, who to either forum lent\nSuch help, as favour wins in Paradise.\nThe other, nearest, who adorns our quire,\nWas Peter, he that with the widow gave\nTo holy church his treasure.  The fifth light,\nGoodliest of all, is by such love inspired,\nThat all your world craves tidings of its doom:\nWithin, there is the lofty light, endow\'d\nWith sapience so profound, if truth be truth,\nThat with a ken of such wide amplitude\nNo second hath arisen.  Next behold\nThat taper\'s radiance, to whose view was shown,\nClearliest, the nature and the ministry\nAngelical, while yet in flesh it dwelt.\nIn the other little light serenely smiles\nThat pleader for the Christian temples, he\nWho did provide Augustin of his lore.\nNow, if thy mind\'s eye pass from light to light,\nUpon my praises following, of the eighth\nThy thirst is next.  The saintly soul, that shows\nThe world\'s deceitfulness, to all who hear him,\nIs, with the sight of all the good, that is,\nBlest there.  The limbs, whence it was driven, lie\nDown in Cieldauro, and from martyrdom\nAnd exile came it here.  Lo!  further on,\nWhere flames the arduous Spirit of Isidore,\nOf Bede, and Richard, ");

                struct disk_t* disk = disk_open_from_file("see_fat16_volume.img");
                test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct volume_t* volume = fat_open(disk, 0);
                test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct file_t* file = file_open(volume, "bOARD.BiN");
                test_error(file != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                size_t size = file_read(filecontent, 1, 2337, file);
                test_error(size == 1958, "Funkcja file_read() niepoprawnie wczytała dane z pliku, powinna wczytać 1958 bajtów, a wczytała %lu", size);
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                int diff_pos = mem_find_first_difference(filecontent, expected_filecontent, 1958);

                // jeśli jest, to raportuj błąd
                test_error(diff_pos == -1, "Dane wczytane z pliku nie są poprawne; różnica w bajcie %d; jest 0x%02x a powinno być 0x%02x",
                    diff_pos, mem_get_byte(filecontent, diff_pos), mem_get_byte(expected_filecontent, diff_pos));

                onerror_compare_memory(expected_filecontent, filecontent, 1958);


                free(filecontent);

                file_close(file);
                fat_close(volume);
                disk_close(disk);

                test_no_heap_leakage();
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
            
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 16: Sprawdzanie poprawności działania funkcji file_read
//
void UTEST16(void)
{
    // informacje o teście
    test_start(16, "Sprawdzanie poprawności działania funkcji file_read", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

                char *filecontent = (char *)calloc(419, 1);
                char expected_filecontent[420] = "";

                strcat(expected_filecontent, "The damsels turn\'d; and on the Gryphon mov\'d\nThe sacred burden, with a pace so smooth,\nNo feather on him trembled.  The fair dame\nWho through the wave had drawn me, companied\nBy Statius and myself, pursued the wheel,\nWhose orbit, rolling, mark\'d a lesser arch.\n     Through the high wood, now void (the more her blame,\nWho by the serpent was beguil\'d) I past\nWith step in cadence to the harmony\nAngelic.  Onward had we ");

                struct disk_t* disk = disk_open_from_file("see_fat16_volume.img");
                test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct volume_t* volume = fat_open(disk, 0);
                test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct file_t* file = file_open(volume, "DeSERT");
                test_error(file != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                size_t size = file_read(filecontent, 1, 684, file);
                test_error(size == 419, "Funkcja file_read() niepoprawnie wczytała dane z pliku, powinna wczytać 419 bajtów, a wczytała %lu", size);
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                int diff_pos = mem_find_first_difference(filecontent, expected_filecontent, 419);

                // jeśli jest, to raportuj błąd
                test_error(diff_pos == -1, "Dane wczytane z pliku nie są poprawne; różnica w bajcie %d; jest 0x%02x a powinno być 0x%02x",
                    diff_pos, mem_get_byte(filecontent, diff_pos), mem_get_byte(expected_filecontent, diff_pos));

                onerror_compare_memory(expected_filecontent, filecontent, 419);


                free(filecontent);

                file_close(file);
                fat_close(volume);
                disk_close(disk);

                test_no_heap_leakage();
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
            
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 17: Sprawdzanie poprawności działania funkcji file_read
//
void UTEST17(void)
{
    // informacje o teście
    test_start(17, "Sprawdzanie poprawności działania funkcji file_read", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

                char *filecontent = (char *)calloc(2667, 1);
                char expected_filecontent[2668] = "";

                strcat(expected_filecontent, "them whate\'er thou list.\"\n     And I therewith began:  \"So may no time\nFilch your remembrance from the thoughts of men\nIn th\' upper world, but after many suns\nSurvive it, as ye tell me, who ye are,\nAnd of what race ye come.  Your punishment,\nUnseemly and disgustful in its kind,\nDeter you not from opening thus much to me.\"\n     \"Arezzo was my dwelling,\" answer\'d one,\n\"And me Albero of Sienna brought\nTo die by fire; but that, for which I died,\nLeads me not here.  True is in sport I told him,\nThat I had learn\'d to wing my flight in air.\nAnd he admiring much, as he was void\nOf wisdom, will\'d me to declare to him\nThe secret of mine art:  and only hence,\nBecause I made him not a Daedalus,\nPrevail\'d on one suppos\'d his sire to burn me.\nBut Minos to this chasm last of the ten,\nFor that I practis\'d alchemy on earth,\nHas doom\'d me.  Him no subterfuge eludes.\"\n     Then to the bard I spake:  \"Was ever race\nLight as Sienna\'s?  Sure not France herself\nCan show a tribe so frivolous and vain.\"\n     The other leprous spirit heard my words,\nAnd thus return\'d:  \"Be Stricca from this charge\nExempted, he who knew so temp\'rately\nTo lay out fortune\'s gifts; and Niccolo\nWho first the spice\'s costly luxury\nDiscover\'d in that garden, where such seed\nRoots deepest in the soil:  and be that troop\nExempted, with whom Caccia of Asciano\nLavish\'d his vineyards and wide-spreading woods,\nAnd his rare wisdom Abbagliato show\'d\nA spectacle for all.  That thou mayst know\nWho seconds thee against the Siennese\nThus gladly, bend this way thy sharpen\'d sight,\nThat well my face may answer to thy ken;\nSo shalt thou see I am Capocchio\'s ghost,\nWho forg\'d transmuted metals by the power\nOf alchemy; and if I scan thee right,\nThus needs must well remember how I aped\nCreative nature by my subtle art.\"\n\n\n\nCANTO XXX\n\nWHAT time resentment burn\'d in Juno\'s breast\nFor Semele against the Theban blood,\nAs more than once in dire mischance was rued,\nSuch fatal frenzy seiz\'d on Athamas,\nThat he his spouse beholding with a babe\nLaden on either arm, \"Spread out,\" he cried,\n\"The meshes, that I take the lioness\nAnd the young lions at the pass:  \"then forth\nStretch\'d he his merciless talons, grasping one,\nOne helpless innocent, Learchus nam\'d,\nWhom swinging down he dash\'d upon a rock,\nAnd with her other burden self-destroy\'d\nThe hapless mother plung\'d:  and when the pride\nOf all-presuming Troy fell from its height,\nBy fortune overwhelm\'d, and the old king\nWith his realm perish\'d, then did Hecuba,\nA wretch forlorn and captive, when she saw\nPolyxena first slaughter\'d, and her son,\nHer Polydorus, on the wild sea-beach\nNext met the mourner\'s view, then reft of sense\nDid she run barking ");

                struct disk_t* disk = disk_open_from_file("see_fat16_volume.img");
                test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct volume_t* volume = fat_open(disk, 0);
                test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct file_t* file = file_open(volume, "roOM.BIN");
                test_error(file != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                size_t size = file_read(filecontent, 1, 3074, file);
                test_error(size == 2667, "Funkcja file_read() niepoprawnie wczytała dane z pliku, powinna wczytać 2667 bajtów, a wczytała %lu", size);
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                int diff_pos = mem_find_first_difference(filecontent, expected_filecontent, 2667);

                // jeśli jest, to raportuj błąd
                test_error(diff_pos == -1, "Dane wczytane z pliku nie są poprawne; różnica w bajcie %d; jest 0x%02x a powinno być 0x%02x",
                    diff_pos, mem_get_byte(filecontent, diff_pos), mem_get_byte(expected_filecontent, diff_pos));

                onerror_compare_memory(expected_filecontent, filecontent, 2667);


                free(filecontent);

                file_close(file);
                fat_close(volume);
                disk_close(disk);

                test_no_heap_leakage();
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
            
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 18: Sprawdzanie poprawności działania funkcji file_read
//
void UTEST18(void)
{
    // informacje o teście
    test_start(18, "Sprawdzanie poprawności działania funkcji file_read", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

                char *filecontent = (char *)calloc(2750, 1);
                char expected_filecontent[2751] = "";

                strcat(expected_filecontent, "son for which supposed crime he suffered\ndeath. So say the Italian commentators.  Henault represents the\nmatter very differently: \"Pierre de la Brosse, formerly barber to\nSt. Louis, afterwards the favorite of Philip, fearing the too\ngreat attachment of the king for his wife Mary, accuses this\nprincess of having poisoned Louis, eldest son of Philip, by his\nfirst marriage. This calumny is discovered by a nun of Nivelle in\nFlanders.  La Brosse is hung.\" Abrege Chron. t. 275, &c.\n\nv. 30.  In thy text.]  He refers to Virgil, Aen. 1, vi.  376.\nDesine fata deum flecti sperare precando, 37. The sacred height\nOf judgment. Shakespeare, Measure for Measure, a. ii. s. 2.\nIf he, which is the top of judgment\n\nv. 66.  Eyeing us as a lion on his watch.]\nA guisa di Leon quando si posa.\nA line taken by Tasso, G.  L. c. x. st. 56.\n\nv. 76.  Sordello.]  The history of Sordello\'s life is wrapt in\nthe obscurity of romance.  That he distinguished himself by his\nskill in Provencal poetry is certain. It is probable that he was\nborn towards the end of the twelfth, and died about the middle of\nthe succeeding century.  Tiraboschi has taken much pains to sift\nall the notices he could collect relating to him.  Honourable\nmention of his name is made by our Poet in the Treatise de Vulg.\nEloq.  1. i. c. 15.\n\nv. 76.  Thou inn of grief.]\nThou most beauteous inn\nWhy should hard-favour\'d grief be lodg\'d in thee?\nShakespeare, Richard II a. 5. s. 1.\n\nv. 89.  Justinian\'s hand.]  \"What avails it that Justinian\ndelivered thee from the Goths, and reformed thy laws, if thou art\nno longer under the control of his successors in the empire?\"\n\nv. 94.  That which God commands.]  He alludes to the precept-\n\"Render unto Caesar the things which are Caesar\'s.\"\n\nv. 98.  O German Albert!]  The Emperor Albert I. succeeded\nAdolphus in 1298, and was murdered in 1308.  See Par Canto XIX\n114 v. 103.  Thy successor.]  The successor of Albert was Henry\nof Luxembourg, by whose interposition in the affairs of Italy our\nPoet hoped to have been reinstated in his native city.\n\nv. 101.  Thy sire.]  The Emperor Rodolph, too intent on\nincreasing his power in Germany to give much of his thoughts to\nItaly, \"the garden of the empire.\"\n\nv. 107.  Capulets and Montagues.]  Our ears are so familiarized\nto the names of these rival families in the language of\nShakespeare, that I have used them instead of the \"Montecchi\" and\n\"Cappelletti.\"\n\nv. 108.  Philippeschi and Monaldi.] Two other rival families in\nOrvieto.\n\nv. 113.  What safety, Santafiore can supply.]  A place between\nPisa and Sienna.  What he alludes to is so doubtful, that it is\nnot certain whether we should not read \"come si cura\"--\" How\nSantafiore is governed.\" Perhaps the event related in the note to\nv. 58, Canto XI. m");

                struct disk_t* disk = disk_open_from_file("see_fat16_volume.img");
                test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct volume_t* volume = fat_open(disk, 0);
                test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct file_t* file = file_open(volume, "grEEN.BIN");
                test_error(file != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                size_t size = file_read(filecontent, 1, 3059, file);
                test_error(size == 2750, "Funkcja file_read() niepoprawnie wczytała dane z pliku, powinna wczytać 2750 bajtów, a wczytała %lu", size);
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                int diff_pos = mem_find_first_difference(filecontent, expected_filecontent, 2750);

                // jeśli jest, to raportuj błąd
                test_error(diff_pos == -1, "Dane wczytane z pliku nie są poprawne; różnica w bajcie %d; jest 0x%02x a powinno być 0x%02x",
                    diff_pos, mem_get_byte(filecontent, diff_pos), mem_get_byte(expected_filecontent, diff_pos));

                onerror_compare_memory(expected_filecontent, filecontent, 2750);


                free(filecontent);

                file_close(file);
                fat_close(volume);
                disk_close(disk);

                test_no_heap_leakage();
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
            
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 19: Sprawdzanie poprawności działania funkcji file_read
//
void UTEST19(void)
{
    // informacje o teście
    test_start(19, "Sprawdzanie poprawności działania funkcji file_read", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

                char *filecontent = (char *)calloc(1924, 1);
                char expected_filecontent[1925] = "";

                strcat(expected_filecontent, "di, king of Naples and Sicily, is\ndefeated and slain by Charles of Anjou.  Hell, C. XXVIII. 13.\nAnd Purgatory, C. III. 110.\n\nGuido Novello of Polenta obtains the sovereignty of Ravenna.\nH. C. XXVII. 38.\n\n1266.  Two of the Frati Godenti chosen arbitrators of the\ndifferences at Florence.  H. C. XXIII. 104.\nGianni de\' Soldanieri heads the populace in that city.  H. C.\nXXXII. 118.\n\n1268.  Charles of Anjou puts Conradine to death, and becomes King\nof Naples.  H. C. XXVIII. 16 and Purg C. XX. 66.\n\n1272.  Henry III. of England is succeeded by Edward I. Purg. C.\nVII. 129.\n\n1274.  Our Poet first sees Beatrice, daughter of Folco Portinari.\n\nFra.\nGuittone d\'Arezzo, the poet, dies.  Purg. C. XXIV. 56.\nThomas Aquinas dies.  Purg. C. XX. 67.  and Par. C. X. 96.\nBuonaventura dies.  Par. C. XII. 25.\n\n1275.  Pierre de la Brosse, secretary to Philip III. of France,\nexecuted.  Purg. C. VI. 23.\n\n1276.  Giotto, the painter, is born.  Purg. C. XI. 95.  Pope\nAdrian V. dies.  Purg. C. XIX. 97.\nGuido Guinicelli, the poet, dies.  Purg. C. XI. 96. and C. XXVI.\n83.\n\n1277.  Pope John XXI.  dies.  Par. C. XII. 126.\n\n1278.  Ottocar, king of Bohemia, dies.  Purg. C. VII. 97.\n\n1279.  Dionysius succeeds to the throne of Portugal.  Par. C.\nXIX. 135.\n\n1280.  Albertus Magnus dies.  Par. C. X. 95.\n\n1281.  Pope Nicholas III. dies.  H. C. XIX 71.\nDante studies at the universities of Bologna and Padua.\n\n1282.  The Sicilian vespers.  Par. C. VIII. 80.\nThe French defeated by the people of Forli.  H. C. XXVII. 41.\nTribaldello de\' Manfredi betrays the city of Faenza.  H. C.\nXXXII. 119.\n\n1284.  Prince Charles of Anjou is defeated and made prisoner by\nRugiez\nde Lauria, admiral to Peter III. of Arragon.  Purg. C. XX. 78.\nCharles I.  king of Naples, dies.  Purg. C. VII. 111.\n\n1285.  Pope Martin IV.  dies.  Purg. C. XXIV. 23.\nPhilip III.  of France, and Peter III.  of Arragon, die. Purg. C.\nVII. 101 and\n110.\nHenry II. king of Cyprus, comes ");

                struct disk_t* disk = disk_open_from_file("see_fat16_volume.img");
                test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct volume_t* volume = fat_open(disk, 0);
                test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct file_t* file = file_open(volume, "EQUAL.Tx");
                test_error(file != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                size_t size = file_read(filecontent, 1, 2102, file);
                test_error(size == 1924, "Funkcja file_read() niepoprawnie wczytała dane z pliku, powinna wczytać 1924 bajtów, a wczytała %lu", size);
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                int diff_pos = mem_find_first_difference(filecontent, expected_filecontent, 1924);

                // jeśli jest, to raportuj błąd
                test_error(diff_pos == -1, "Dane wczytane z pliku nie są poprawne; różnica w bajcie %d; jest 0x%02x a powinno być 0x%02x",
                    diff_pos, mem_get_byte(filecontent, diff_pos), mem_get_byte(expected_filecontent, diff_pos));

                onerror_compare_memory(expected_filecontent, filecontent, 1924);


                free(filecontent);

                file_close(file);
                fat_close(volume);
                disk_close(disk);

                test_no_heap_leakage();
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
            
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 20: Sprawdzanie poprawności działania funkcji file_read
//
void UTEST20(void)
{
    // informacje o teście
    test_start(20, "Sprawdzanie poprawności działania funkcji file_read", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

                char *filecontent = (char *)calloc(2048, 1);
                char expected_filecontent[2049] = "";

                strcat(expected_filecontent, "that which follows them?\"\n     I straightway mark\'d a tribe behind them walk,\nAs if attendant on their leaders, cloth\'d\nWith raiment of such whiteness, as on earth\nWas never.  On my left, the wat\'ry gleam\nBorrow\'d, and gave me back, when there I look\'d.\nAs in a mirror, my left side portray\'d.\n     When I had chosen on the river\'s edge\nSuch station, that the distance of the stream\nAlone did separate me; there I stay\'d\nMy steps for clearer prospect, and beheld\nThe flames go onward, leaving, as they went,\nThe air behind them painted as with trail\nOf liveliest pencils!  so distinct were mark\'d\nAll those sev\'n listed colours, whence the sun\nMaketh his bow, and Cynthia her zone.\nThese streaming gonfalons did flow beyond\nMy vision; and ten paces, as I guess,\nParted the outermost.  Beneath a sky\nSo beautiful, came foul and-twenty elders,\nBy two and two, with flower-de-luces crown\'d.\nAll sang one song:  \"Blessed be thou among\nThe daughters of Adam!  and thy loveliness\nBlessed for ever!\"  After that the flowers,\nAnd the fresh herblets, on the opposite brink,\nWere free from that elected race; as light\nIn heav\'n doth second light, came after them\nFour animals, each crown\'d with verdurous leaf.\nWith six wings each was plum\'d, the plumage full\nOf eyes, and th\' eyes of Argus would be such,\nWere they endued with life.  Reader, more rhymes\nWill not waste in shadowing forth their form:\nFor other need no straitens, that in this\nI may not give my bounty room.  But read\nEzekiel; for he paints them, from the north\nHow he beheld them come by Chebar\'s flood,\nIn whirlwind, cloud and fire; and even such\nAs thou shalt find them character\'d by him,\nHere were they; save as to the pennons; there,\nFrom him departing, John accords with me.\n     The space, surrounded by the four, enclos\'d\nA car triumphal: on two wheels it came\nDrawn at a Gryphon\'s neck; and he above\nStretch\'d either wing uplifted, \'tween the midst\nAnd the three listed hues, on each side three;\nSo that the wings did cleave or injure none;\nAnd out of sight they rose.  The members,");

                struct disk_t* disk = disk_open_from_file("see_fat16_volume.img");
                test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct volume_t* volume = fat_open(disk, 0);
                test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct file_t* file = file_open(volume, "TEN");
                test_error(file != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                size_t size = file_read(filecontent, 1, 2386, file);
                test_error(size == 2048, "Funkcja file_read() niepoprawnie wczytała dane z pliku, powinna wczytać 2048 bajtów, a wczytała %lu", size);
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                int diff_pos = mem_find_first_difference(filecontent, expected_filecontent, 2048);

                // jeśli jest, to raportuj błąd
                test_error(diff_pos == -1, "Dane wczytane z pliku nie są poprawne; różnica w bajcie %d; jest 0x%02x a powinno być 0x%02x",
                    diff_pos, mem_get_byte(filecontent, diff_pos), mem_get_byte(expected_filecontent, diff_pos));

                onerror_compare_memory(expected_filecontent, filecontent, 2048);


                free(filecontent);

                file_close(file);
                fat_close(volume);
                disk_close(disk);

                test_no_heap_leakage();
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
            
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 21: Sprawdzanie poprawności działania funkcji file_read
//
void UTEST21(void)
{
    // informacje o teście
    test_start(21, "Sprawdzanie poprawności działania funkcji file_read", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

                char *filecontent = (char *)calloc(3356, 1);
                char expected_filecontent[3357] = "";

                strcat(expected_filecontent, " the other more erect he stands,\nEach part except the gold, is rent throughout;\nAnd from the fissure tears distil, which join\'d\nPenetrate to that cave.  They in their course\nThus far precipitated down the rock\nForm Acheron, and Styx, and Phlegethon;\nThen by this straiten\'d channel passing hence\nBeneath, e\'en to the lowest depth of all,\nForm there Cocytus, of whose lake (thyself\nShall see it) I here give thee no account.\"\n     Then I to him:  \"If from our world this sluice\nBe thus deriv\'d; wherefore to us but now\nAppears it at this edge?\"  He straight replied:\n\"The place, thou know\'st, is round; and though great part\nThou have already pass\'d, still to the left\nDescending to the nethermost, not yet\nHast thou the circuit made of the whole orb.\nWherefore if aught of new to us appear,\nIt needs not bring up wonder in thy looks.\"\n     Then I again inquir\'d:  \"Where flow the streams\nOf Phlegethon and Lethe? for of one\nThou tell\'st not, and the other of that shower,\nThou say\'st, is form\'d.\"  He answer thus return\'d:\n\"Doubtless thy questions all well pleas\'d I hear.\nYet the red seething wave might have resolv\'d\nOne thou proposest.  Lethe thou shalt see,\nBut not within this hollow, in the place,\nWhither to lave themselves the spirits go,\nWhose blame hath been by penitence remov\'d.\"\nHe added:  \"Time is now we quit the wood.\nLook thou my steps pursue:  the margins give\nSafe passage, unimpeded by the flames;\nFor over them all vapour is extinct.\"\n\n\n\nCANTO XV\n\nOne of the solid margins bears us now\nEnvelop\'d in the mist, that from the stream\nArising, hovers o\'er, and saves from fire\nBoth piers and water.  As the Flemings rear\nTheir mound, \'twixt Ghent and Bruges, to chase back\nThe ocean, fearing his tumultuous tide\nThat drives toward them, or the Paduans theirs\nAlong the Brenta, to defend their towns\nAnd castles, ere the genial warmth be felt\nOn Chiarentana\'s top; such were the mounds,\nSo fram\'d, though not in height or bulk to these\nMade equal, by the master, whosoe\'er\nHe was, that rais\'d them here.  We from the wood\nWere not so far remov\'d, that turning round\nI might not have discern\'d it, when we met\nA troop of spirits, who came beside the pier.\n     They each one ey\'d us, as at eventide\nOne eyes another under a new moon,\nAnd toward us sharpen\'d their sight as keen,\nAs an old tailor at his needle\'s eye.\n     Thus narrowly explor\'d by all the tribe,\nI was agniz\'d of one, who by the skirt\nCaught me, and cried, \"What wonder have we here!\"\n     And I, when he to me outstretch\'d his arm,\nIntently fix\'d my ken on his parch\'d looks,\nThat although smirch\'d with fire, they hinder\'d not\nBut I remember\'d him; and towards his face\nMy hand inclining, answer\'d:  \"Sir! Brunetto!\nAnd art thou here?\"  He thus to me:  \"My son!\nOh let it not displease thee, if Brunetto\nLatini but a little space with thee\nTurn back, and leave his fellows to proceed.\"\n     I thus to him replied:  \"Much as I can,\nI thereto pray thee; and if thou be willing,\nThat I here seat me with thee, I consent;\nHis leave, with whom I journey, first obtain\'d.\"\n     \"O son!\" said he, \" whoever of this throng\nOne instant stops, lies then a hundred years,\nNo fan to ventilate him, when the fire\nSmites sorest.  Pass thou therefore on.  I close\nWill at thy garments walk, and then rejoin\nMy troop, who go mourning their endless doom.\"\n     I dar\'d not from the path des");

                struct disk_t* disk = disk_open_from_file("see_fat16_volume.img");
                test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct volume_t* volume = fat_open(disk, 0);
                test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct file_t* file = file_open(volume, "gAmE.TxT");
                test_error(file != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                size_t size = file_read(filecontent, 1, 3680, file);
                test_error(size == 3356, "Funkcja file_read() niepoprawnie wczytała dane z pliku, powinna wczytać 3356 bajtów, a wczytała %lu", size);
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                int diff_pos = mem_find_first_difference(filecontent, expected_filecontent, 3356);

                // jeśli jest, to raportuj błąd
                test_error(diff_pos == -1, "Dane wczytane z pliku nie są poprawne; różnica w bajcie %d; jest 0x%02x a powinno być 0x%02x",
                    diff_pos, mem_get_byte(filecontent, diff_pos), mem_get_byte(expected_filecontent, diff_pos));

                onerror_compare_memory(expected_filecontent, filecontent, 3356);


                free(filecontent);

                file_close(file);
                fat_close(volume);
                disk_close(disk);

                test_no_heap_leakage();
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
            
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 22: Sprawdzanie poprawności działania funkcji file_read
//
void UTEST22(void)
{
    // informacje o teście
    test_start(22, "Sprawdzanie poprawności działania funkcji file_read", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

                char *filecontent = (char *)calloc(88, 1);
                char expected_filecontent[89] = "";

                strcat(expected_filecontent, "\n\nv. 14.  Broad are their pennons.]  From Virg. Aen. l. iii. 216.\n\nv. 48.  In my verse d");

                struct disk_t* disk = disk_open_from_file("see_fat16_volume.img");
                test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct volume_t* volume = fat_open(disk, 0);
                test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct file_t* file = file_open(volume, "bar LaSt wiFe led ScalE reacH ValuE ofFer.JIi");
                test_error(file != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                size_t size = file_read(filecontent, 1, 401, file);
                test_error(size == 88, "Funkcja file_read() niepoprawnie wczytała dane z pliku, powinna wczytać 88 bajtów, a wczytała %lu", size);
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                int diff_pos = mem_find_first_difference(filecontent, expected_filecontent, 88);

                // jeśli jest, to raportuj błąd
                test_error(diff_pos == -1, "Dane wczytane z pliku nie są poprawne; różnica w bajcie %d; jest 0x%02x a powinno być 0x%02x",
                    diff_pos, mem_get_byte(filecontent, diff_pos), mem_get_byte(expected_filecontent, diff_pos));

                onerror_compare_memory(expected_filecontent, filecontent, 88);


                free(filecontent);

                file_close(file);
                fat_close(volume);
                disk_close(disk);

                test_no_heap_leakage();
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
            
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 23: Sprawdzanie poprawności działania funkcji file_read
//
void UTEST23(void)
{
    // informacje o teście
    test_start(23, "Sprawdzanie poprawności działania funkcji file_read", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

                char *filecontent = (char *)calloc(157, 1);
                char expected_filecontent[158] = "";

                strcat(expected_filecontent, "n 1285, at Perpignan, in his retreat from Arragon.\n\nv. 102.  Him of gentle look.]  Henry of Naverre, father of Jane\nmarried to Philip IV of France, whom Dant");

                struct disk_t* disk = disk_open_from_file("see_fat16_volume.img");
                test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct volume_t* volume = fat_open(disk, 0);
                test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct file_t* file = file_open(volume, "SUBSTANC");
                test_error(file != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                size_t size = file_read(filecontent, 1, 631, file);
                test_error(size == 157, "Funkcja file_read() niepoprawnie wczytała dane z pliku, powinna wczytać 157 bajtów, a wczytała %lu", size);
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                int diff_pos = mem_find_first_difference(filecontent, expected_filecontent, 157);

                // jeśli jest, to raportuj błąd
                test_error(diff_pos == -1, "Dane wczytane z pliku nie są poprawne; różnica w bajcie %d; jest 0x%02x a powinno być 0x%02x",
                    diff_pos, mem_get_byte(filecontent, diff_pos), mem_get_byte(expected_filecontent, diff_pos));

                onerror_compare_memory(expected_filecontent, filecontent, 157);


                free(filecontent);

                file_close(file);
                fat_close(volume);
                disk_close(disk);

                test_no_heap_leakage();
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
            
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 24: Sprawdzanie poprawności działania funkcji file_read
//
void UTEST24(void)
{
    // informacje o teście
    test_start(24, "Sprawdzanie poprawności działania funkcji file_read", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

                char *filecontent = (char *)calloc(1958, 1);
                char expected_filecontent[1959] = "";

                strcat(expected_filecontent, "it leads thee up\nAlong this ladder, down whose hallow\'d steps\nNone e\'er descend, and mount them not again,\nWho from his phial should refuse thee wine\nTo slake thy thirst, no less constrained were,\nThan water flowing not unto the sea.\nThou fain wouldst hear, what plants are these, that bloom\nIn the bright garland, which, admiring, girds\nThis fair dame round, who strengthens thee for heav\'n.\nI then was of the lambs, that Dominic\nLeads, for his saintly flock, along the way,\nWhere well they thrive, not sworn with vanity.\nHe, nearest on my right hand, brother was,\nAnd master to me:  Albert of Cologne\nIs this:  and of Aquinum, Thomas I.\nIf thou of all the rest wouldst be assur\'d,\nLet thine eye, waiting on the words I speak,\nIn circuit journey round the blessed wreath.\nThat next resplendence issues from the smile\nOf Gratian, who to either forum lent\nSuch help, as favour wins in Paradise.\nThe other, nearest, who adorns our quire,\nWas Peter, he that with the widow gave\nTo holy church his treasure.  The fifth light,\nGoodliest of all, is by such love inspired,\nThat all your world craves tidings of its doom:\nWithin, there is the lofty light, endow\'d\nWith sapience so profound, if truth be truth,\nThat with a ken of such wide amplitude\nNo second hath arisen.  Next behold\nThat taper\'s radiance, to whose view was shown,\nClearliest, the nature and the ministry\nAngelical, while yet in flesh it dwelt.\nIn the other little light serenely smiles\nThat pleader for the Christian temples, he\nWho did provide Augustin of his lore.\nNow, if thy mind\'s eye pass from light to light,\nUpon my praises following, of the eighth\nThy thirst is next.  The saintly soul, that shows\nThe world\'s deceitfulness, to all who hear him,\nIs, with the sight of all the good, that is,\nBlest there.  The limbs, whence it was driven, lie\nDown in Cieldauro, and from martyrdom\nAnd exile came it here.  Lo!  further on,\nWhere flames the arduous Spirit of Isidore,\nOf Bede, and Richard, ");

                struct disk_t* disk = disk_open_from_file("see_fat16_volume.img");
                test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct volume_t* volume = fat_open(disk, 0);
                test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct file_t* file = file_open(volume, "BOARD.BIN");
                test_error(file != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                size_t size = file_read(filecontent, 1, 2369, file);
                test_error(size == 1958, "Funkcja file_read() niepoprawnie wczytała dane z pliku, powinna wczytać 1958 bajtów, a wczytała %lu", size);
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                int diff_pos = mem_find_first_difference(filecontent, expected_filecontent, 1958);

                // jeśli jest, to raportuj błąd
                test_error(diff_pos == -1, "Dane wczytane z pliku nie są poprawne; różnica w bajcie %d; jest 0x%02x a powinno być 0x%02x",
                    diff_pos, mem_get_byte(filecontent, diff_pos), mem_get_byte(expected_filecontent, diff_pos));

                onerror_compare_memory(expected_filecontent, filecontent, 1958);


                free(filecontent);

                file_close(file);
                fat_close(volume);
                disk_close(disk);

                test_no_heap_leakage();
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
            
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 25: Sprawdzanie poprawności działania funkcji file_read
//
void UTEST25(void)
{
    // informacje o teście
    test_start(25, "Sprawdzanie poprawności działania funkcji file_read", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

                char *filecontent = (char *)calloc(419, 1);
                char expected_filecontent[420] = "";

                strcat(expected_filecontent, "The damsels turn\'d; and on the Gryphon mov\'d\nThe sacred burden, with a pace so smooth,\nNo feather on him trembled.  The fair dame\nWho through the wave had drawn me, companied\nBy Statius and myself, pursued the wheel,\nWhose orbit, rolling, mark\'d a lesser arch.\n     Through the high wood, now void (the more her blame,\nWho by the serpent was beguil\'d) I past\nWith step in cadence to the harmony\nAngelic.  Onward had we ");

                struct disk_t* disk = disk_open_from_file("see_fat16_volume.img");
                test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct volume_t* volume = fat_open(disk, 0);
                test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct file_t* file = file_open(volume, "DESERT");
                test_error(file != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                size_t size = file_read(filecontent, 1, 744, file);
                test_error(size == 419, "Funkcja file_read() niepoprawnie wczytała dane z pliku, powinna wczytać 419 bajtów, a wczytała %lu", size);
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                int diff_pos = mem_find_first_difference(filecontent, expected_filecontent, 419);

                // jeśli jest, to raportuj błąd
                test_error(diff_pos == -1, "Dane wczytane z pliku nie są poprawne; różnica w bajcie %d; jest 0x%02x a powinno być 0x%02x",
                    diff_pos, mem_get_byte(filecontent, diff_pos), mem_get_byte(expected_filecontent, diff_pos));

                onerror_compare_memory(expected_filecontent, filecontent, 419);


                free(filecontent);

                file_close(file);
                fat_close(volume);
                disk_close(disk);

                test_no_heap_leakage();
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
            
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 26: Sprawdzanie poprawności działania funkcji file_read
//
void UTEST26(void)
{
    // informacje o teście
    test_start(26, "Sprawdzanie poprawności działania funkcji file_read", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

                char *filecontent = (char *)calloc(2667, 1);
                char expected_filecontent[2668] = "";

                strcat(expected_filecontent, "them whate\'er thou list.\"\n     And I therewith began:  \"So may no time\nFilch your remembrance from the thoughts of men\nIn th\' upper world, but after many suns\nSurvive it, as ye tell me, who ye are,\nAnd of what race ye come.  Your punishment,\nUnseemly and disgustful in its kind,\nDeter you not from opening thus much to me.\"\n     \"Arezzo was my dwelling,\" answer\'d one,\n\"And me Albero of Sienna brought\nTo die by fire; but that, for which I died,\nLeads me not here.  True is in sport I told him,\nThat I had learn\'d to wing my flight in air.\nAnd he admiring much, as he was void\nOf wisdom, will\'d me to declare to him\nThe secret of mine art:  and only hence,\nBecause I made him not a Daedalus,\nPrevail\'d on one suppos\'d his sire to burn me.\nBut Minos to this chasm last of the ten,\nFor that I practis\'d alchemy on earth,\nHas doom\'d me.  Him no subterfuge eludes.\"\n     Then to the bard I spake:  \"Was ever race\nLight as Sienna\'s?  Sure not France herself\nCan show a tribe so frivolous and vain.\"\n     The other leprous spirit heard my words,\nAnd thus return\'d:  \"Be Stricca from this charge\nExempted, he who knew so temp\'rately\nTo lay out fortune\'s gifts; and Niccolo\nWho first the spice\'s costly luxury\nDiscover\'d in that garden, where such seed\nRoots deepest in the soil:  and be that troop\nExempted, with whom Caccia of Asciano\nLavish\'d his vineyards and wide-spreading woods,\nAnd his rare wisdom Abbagliato show\'d\nA spectacle for all.  That thou mayst know\nWho seconds thee against the Siennese\nThus gladly, bend this way thy sharpen\'d sight,\nThat well my face may answer to thy ken;\nSo shalt thou see I am Capocchio\'s ghost,\nWho forg\'d transmuted metals by the power\nOf alchemy; and if I scan thee right,\nThus needs must well remember how I aped\nCreative nature by my subtle art.\"\n\n\n\nCANTO XXX\n\nWHAT time resentment burn\'d in Juno\'s breast\nFor Semele against the Theban blood,\nAs more than once in dire mischance was rued,\nSuch fatal frenzy seiz\'d on Athamas,\nThat he his spouse beholding with a babe\nLaden on either arm, \"Spread out,\" he cried,\n\"The meshes, that I take the lioness\nAnd the young lions at the pass:  \"then forth\nStretch\'d he his merciless talons, grasping one,\nOne helpless innocent, Learchus nam\'d,\nWhom swinging down he dash\'d upon a rock,\nAnd with her other burden self-destroy\'d\nThe hapless mother plung\'d:  and when the pride\nOf all-presuming Troy fell from its height,\nBy fortune overwhelm\'d, and the old king\nWith his realm perish\'d, then did Hecuba,\nA wretch forlorn and captive, when she saw\nPolyxena first slaughter\'d, and her son,\nHer Polydorus, on the wild sea-beach\nNext met the mourner\'s view, then reft of sense\nDid she run barking ");

                struct disk_t* disk = disk_open_from_file("see_fat16_volume.img");
                test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct volume_t* volume = fat_open(disk, 0);
                test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct file_t* file = file_open(volume, "rOom.BIN");
                test_error(file != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                size_t size = file_read(filecontent, 1, 2796, file);
                test_error(size == 2667, "Funkcja file_read() niepoprawnie wczytała dane z pliku, powinna wczytać 2667 bajtów, a wczytała %lu", size);
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                int diff_pos = mem_find_first_difference(filecontent, expected_filecontent, 2667);

                // jeśli jest, to raportuj błąd
                test_error(diff_pos == -1, "Dane wczytane z pliku nie są poprawne; różnica w bajcie %d; jest 0x%02x a powinno być 0x%02x",
                    diff_pos, mem_get_byte(filecontent, diff_pos), mem_get_byte(expected_filecontent, diff_pos));

                onerror_compare_memory(expected_filecontent, filecontent, 2667);


                free(filecontent);

                file_close(file);
                fat_close(volume);
                disk_close(disk);

                test_no_heap_leakage();
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
            
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 27: Sprawdzanie poprawności działania funkcji file_read
//
void UTEST27(void)
{
    // informacje o teście
    test_start(27, "Sprawdzanie poprawności działania funkcji file_read", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

                char *filecontent = (char *)calloc(2750, 1);
                char expected_filecontent[2751] = "";

                strcat(expected_filecontent, "son for which supposed crime he suffered\ndeath. So say the Italian commentators.  Henault represents the\nmatter very differently: \"Pierre de la Brosse, formerly barber to\nSt. Louis, afterwards the favorite of Philip, fearing the too\ngreat attachment of the king for his wife Mary, accuses this\nprincess of having poisoned Louis, eldest son of Philip, by his\nfirst marriage. This calumny is discovered by a nun of Nivelle in\nFlanders.  La Brosse is hung.\" Abrege Chron. t. 275, &c.\n\nv. 30.  In thy text.]  He refers to Virgil, Aen. 1, vi.  376.\nDesine fata deum flecti sperare precando, 37. The sacred height\nOf judgment. Shakespeare, Measure for Measure, a. ii. s. 2.\nIf he, which is the top of judgment\n\nv. 66.  Eyeing us as a lion on his watch.]\nA guisa di Leon quando si posa.\nA line taken by Tasso, G.  L. c. x. st. 56.\n\nv. 76.  Sordello.]  The history of Sordello\'s life is wrapt in\nthe obscurity of romance.  That he distinguished himself by his\nskill in Provencal poetry is certain. It is probable that he was\nborn towards the end of the twelfth, and died about the middle of\nthe succeeding century.  Tiraboschi has taken much pains to sift\nall the notices he could collect relating to him.  Honourable\nmention of his name is made by our Poet in the Treatise de Vulg.\nEloq.  1. i. c. 15.\n\nv. 76.  Thou inn of grief.]\nThou most beauteous inn\nWhy should hard-favour\'d grief be lodg\'d in thee?\nShakespeare, Richard II a. 5. s. 1.\n\nv. 89.  Justinian\'s hand.]  \"What avails it that Justinian\ndelivered thee from the Goths, and reformed thy laws, if thou art\nno longer under the control of his successors in the empire?\"\n\nv. 94.  That which God commands.]  He alludes to the precept-\n\"Render unto Caesar the things which are Caesar\'s.\"\n\nv. 98.  O German Albert!]  The Emperor Albert I. succeeded\nAdolphus in 1298, and was murdered in 1308.  See Par Canto XIX\n114 v. 103.  Thy successor.]  The successor of Albert was Henry\nof Luxembourg, by whose interposition in the affairs of Italy our\nPoet hoped to have been reinstated in his native city.\n\nv. 101.  Thy sire.]  The Emperor Rodolph, too intent on\nincreasing his power in Germany to give much of his thoughts to\nItaly, \"the garden of the empire.\"\n\nv. 107.  Capulets and Montagues.]  Our ears are so familiarized\nto the names of these rival families in the language of\nShakespeare, that I have used them instead of the \"Montecchi\" and\n\"Cappelletti.\"\n\nv. 108.  Philippeschi and Monaldi.] Two other rival families in\nOrvieto.\n\nv. 113.  What safety, Santafiore can supply.]  A place between\nPisa and Sienna.  What he alludes to is so doubtful, that it is\nnot certain whether we should not read \"come si cura\"--\" How\nSantafiore is governed.\" Perhaps the event related in the note to\nv. 58, Canto XI. m");

                struct disk_t* disk = disk_open_from_file("see_fat16_volume.img");
                test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct volume_t* volume = fat_open(disk, 0);
                test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct file_t* file = file_open(volume, "GREEN.bIN");
                test_error(file != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                size_t size = file_read(filecontent, 1, 3108, file);
                test_error(size == 2750, "Funkcja file_read() niepoprawnie wczytała dane z pliku, powinna wczytać 2750 bajtów, a wczytała %lu", size);
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                int diff_pos = mem_find_first_difference(filecontent, expected_filecontent, 2750);

                // jeśli jest, to raportuj błąd
                test_error(diff_pos == -1, "Dane wczytane z pliku nie są poprawne; różnica w bajcie %d; jest 0x%02x a powinno być 0x%02x",
                    diff_pos, mem_get_byte(filecontent, diff_pos), mem_get_byte(expected_filecontent, diff_pos));

                onerror_compare_memory(expected_filecontent, filecontent, 2750);


                free(filecontent);

                file_close(file);
                fat_close(volume);
                disk_close(disk);

                test_no_heap_leakage();
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
            
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 28: Sprawdzanie poprawności działania funkcji file_read
//
void UTEST28(void)
{
    // informacje o teście
    test_start(28, "Sprawdzanie poprawności działania funkcji file_read", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

                char *filecontent = (char *)calloc(1924, 1);
                char expected_filecontent[1925] = "";

                strcat(expected_filecontent, "di, king of Naples and Sicily, is\ndefeated and slain by Charles of Anjou.  Hell, C. XXVIII. 13.\nAnd Purgatory, C. III. 110.\n\nGuido Novello of Polenta obtains the sovereignty of Ravenna.\nH. C. XXVII. 38.\n\n1266.  Two of the Frati Godenti chosen arbitrators of the\ndifferences at Florence.  H. C. XXIII. 104.\nGianni de\' Soldanieri heads the populace in that city.  H. C.\nXXXII. 118.\n\n1268.  Charles of Anjou puts Conradine to death, and becomes King\nof Naples.  H. C. XXVIII. 16 and Purg C. XX. 66.\n\n1272.  Henry III. of England is succeeded by Edward I. Purg. C.\nVII. 129.\n\n1274.  Our Poet first sees Beatrice, daughter of Folco Portinari.\n\nFra.\nGuittone d\'Arezzo, the poet, dies.  Purg. C. XXIV. 56.\nThomas Aquinas dies.  Purg. C. XX. 67.  and Par. C. X. 96.\nBuonaventura dies.  Par. C. XII. 25.\n\n1275.  Pierre de la Brosse, secretary to Philip III. of France,\nexecuted.  Purg. C. VI. 23.\n\n1276.  Giotto, the painter, is born.  Purg. C. XI. 95.  Pope\nAdrian V. dies.  Purg. C. XIX. 97.\nGuido Guinicelli, the poet, dies.  Purg. C. XI. 96. and C. XXVI.\n83.\n\n1277.  Pope John XXI.  dies.  Par. C. XII. 126.\n\n1278.  Ottocar, king of Bohemia, dies.  Purg. C. VII. 97.\n\n1279.  Dionysius succeeds to the throne of Portugal.  Par. C.\nXIX. 135.\n\n1280.  Albertus Magnus dies.  Par. C. X. 95.\n\n1281.  Pope Nicholas III. dies.  H. C. XIX 71.\nDante studies at the universities of Bologna and Padua.\n\n1282.  The Sicilian vespers.  Par. C. VIII. 80.\nThe French defeated by the people of Forli.  H. C. XXVII. 41.\nTribaldello de\' Manfredi betrays the city of Faenza.  H. C.\nXXXII. 119.\n\n1284.  Prince Charles of Anjou is defeated and made prisoner by\nRugiez\nde Lauria, admiral to Peter III. of Arragon.  Purg. C. XX. 78.\nCharles I.  king of Naples, dies.  Purg. C. VII. 111.\n\n1285.  Pope Martin IV.  dies.  Purg. C. XXIV. 23.\nPhilip III.  of France, and Peter III.  of Arragon, die. Purg. C.\nVII. 101 and\n110.\nHenry II. king of Cyprus, comes ");

                struct disk_t* disk = disk_open_from_file("see_fat16_volume.img");
                test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct volume_t* volume = fat_open(disk, 0);
                test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct file_t* file = file_open(volume, "EQuAL.TX");
                test_error(file != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                size_t size = file_read(filecontent, 1, 2174, file);
                test_error(size == 1924, "Funkcja file_read() niepoprawnie wczytała dane z pliku, powinna wczytać 1924 bajtów, a wczytała %lu", size);
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                int diff_pos = mem_find_first_difference(filecontent, expected_filecontent, 1924);

                // jeśli jest, to raportuj błąd
                test_error(diff_pos == -1, "Dane wczytane z pliku nie są poprawne; różnica w bajcie %d; jest 0x%02x a powinno być 0x%02x",
                    diff_pos, mem_get_byte(filecontent, diff_pos), mem_get_byte(expected_filecontent, diff_pos));

                onerror_compare_memory(expected_filecontent, filecontent, 1924);


                free(filecontent);

                file_close(file);
                fat_close(volume);
                disk_close(disk);

                test_no_heap_leakage();
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
            
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 29: Sprawdzanie poprawności działania funkcji file_read
//
void UTEST29(void)
{
    // informacje o teście
    test_start(29, "Sprawdzanie poprawności działania funkcji file_read", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

                char *filecontent = (char *)calloc(2048, 1);
                char expected_filecontent[2049] = "";

                strcat(expected_filecontent, "that which follows them?\"\n     I straightway mark\'d a tribe behind them walk,\nAs if attendant on their leaders, cloth\'d\nWith raiment of such whiteness, as on earth\nWas never.  On my left, the wat\'ry gleam\nBorrow\'d, and gave me back, when there I look\'d.\nAs in a mirror, my left side portray\'d.\n     When I had chosen on the river\'s edge\nSuch station, that the distance of the stream\nAlone did separate me; there I stay\'d\nMy steps for clearer prospect, and beheld\nThe flames go onward, leaving, as they went,\nThe air behind them painted as with trail\nOf liveliest pencils!  so distinct were mark\'d\nAll those sev\'n listed colours, whence the sun\nMaketh his bow, and Cynthia her zone.\nThese streaming gonfalons did flow beyond\nMy vision; and ten paces, as I guess,\nParted the outermost.  Beneath a sky\nSo beautiful, came foul and-twenty elders,\nBy two and two, with flower-de-luces crown\'d.\nAll sang one song:  \"Blessed be thou among\nThe daughters of Adam!  and thy loveliness\nBlessed for ever!\"  After that the flowers,\nAnd the fresh herblets, on the opposite brink,\nWere free from that elected race; as light\nIn heav\'n doth second light, came after them\nFour animals, each crown\'d with verdurous leaf.\nWith six wings each was plum\'d, the plumage full\nOf eyes, and th\' eyes of Argus would be such,\nWere they endued with life.  Reader, more rhymes\nWill not waste in shadowing forth their form:\nFor other need no straitens, that in this\nI may not give my bounty room.  But read\nEzekiel; for he paints them, from the north\nHow he beheld them come by Chebar\'s flood,\nIn whirlwind, cloud and fire; and even such\nAs thou shalt find them character\'d by him,\nHere were they; save as to the pennons; there,\nFrom him departing, John accords with me.\n     The space, surrounded by the four, enclos\'d\nA car triumphal: on two wheels it came\nDrawn at a Gryphon\'s neck; and he above\nStretch\'d either wing uplifted, \'tween the midst\nAnd the three listed hues, on each side three;\nSo that the wings did cleave or injure none;\nAnd out of sight they rose.  The members,");

                struct disk_t* disk = disk_open_from_file("see_fat16_volume.img");
                test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct volume_t* volume = fat_open(disk, 0);
                test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct file_t* file = file_open(volume, "tEn");
                test_error(file != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                size_t size = file_read(filecontent, 1, 2188, file);
                test_error(size == 2048, "Funkcja file_read() niepoprawnie wczytała dane z pliku, powinna wczytać 2048 bajtów, a wczytała %lu", size);
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                int diff_pos = mem_find_first_difference(filecontent, expected_filecontent, 2048);

                // jeśli jest, to raportuj błąd
                test_error(diff_pos == -1, "Dane wczytane z pliku nie są poprawne; różnica w bajcie %d; jest 0x%02x a powinno być 0x%02x",
                    diff_pos, mem_get_byte(filecontent, diff_pos), mem_get_byte(expected_filecontent, diff_pos));

                onerror_compare_memory(expected_filecontent, filecontent, 2048);


                free(filecontent);

                file_close(file);
                fat_close(volume);
                disk_close(disk);

                test_no_heap_leakage();
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
            
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 30: Sprawdzanie poprawności działania funkcji file_read
//
void UTEST30(void)
{
    // informacje o teście
    test_start(30, "Sprawdzanie poprawności działania funkcji file_read", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

                char *filecontent = (char *)calloc(3356, 1);
                char expected_filecontent[3357] = "";

                strcat(expected_filecontent, " the other more erect he stands,\nEach part except the gold, is rent throughout;\nAnd from the fissure tears distil, which join\'d\nPenetrate to that cave.  They in their course\nThus far precipitated down the rock\nForm Acheron, and Styx, and Phlegethon;\nThen by this straiten\'d channel passing hence\nBeneath, e\'en to the lowest depth of all,\nForm there Cocytus, of whose lake (thyself\nShall see it) I here give thee no account.\"\n     Then I to him:  \"If from our world this sluice\nBe thus deriv\'d; wherefore to us but now\nAppears it at this edge?\"  He straight replied:\n\"The place, thou know\'st, is round; and though great part\nThou have already pass\'d, still to the left\nDescending to the nethermost, not yet\nHast thou the circuit made of the whole orb.\nWherefore if aught of new to us appear,\nIt needs not bring up wonder in thy looks.\"\n     Then I again inquir\'d:  \"Where flow the streams\nOf Phlegethon and Lethe? for of one\nThou tell\'st not, and the other of that shower,\nThou say\'st, is form\'d.\"  He answer thus return\'d:\n\"Doubtless thy questions all well pleas\'d I hear.\nYet the red seething wave might have resolv\'d\nOne thou proposest.  Lethe thou shalt see,\nBut not within this hollow, in the place,\nWhither to lave themselves the spirits go,\nWhose blame hath been by penitence remov\'d.\"\nHe added:  \"Time is now we quit the wood.\nLook thou my steps pursue:  the margins give\nSafe passage, unimpeded by the flames;\nFor over them all vapour is extinct.\"\n\n\n\nCANTO XV\n\nOne of the solid margins bears us now\nEnvelop\'d in the mist, that from the stream\nArising, hovers o\'er, and saves from fire\nBoth piers and water.  As the Flemings rear\nTheir mound, \'twixt Ghent and Bruges, to chase back\nThe ocean, fearing his tumultuous tide\nThat drives toward them, or the Paduans theirs\nAlong the Brenta, to defend their towns\nAnd castles, ere the genial warmth be felt\nOn Chiarentana\'s top; such were the mounds,\nSo fram\'d, though not in height or bulk to these\nMade equal, by the master, whosoe\'er\nHe was, that rais\'d them here.  We from the wood\nWere not so far remov\'d, that turning round\nI might not have discern\'d it, when we met\nA troop of spirits, who came beside the pier.\n     They each one ey\'d us, as at eventide\nOne eyes another under a new moon,\nAnd toward us sharpen\'d their sight as keen,\nAs an old tailor at his needle\'s eye.\n     Thus narrowly explor\'d by all the tribe,\nI was agniz\'d of one, who by the skirt\nCaught me, and cried, \"What wonder have we here!\"\n     And I, when he to me outstretch\'d his arm,\nIntently fix\'d my ken on his parch\'d looks,\nThat although smirch\'d with fire, they hinder\'d not\nBut I remember\'d him; and towards his face\nMy hand inclining, answer\'d:  \"Sir! Brunetto!\nAnd art thou here?\"  He thus to me:  \"My son!\nOh let it not displease thee, if Brunetto\nLatini but a little space with thee\nTurn back, and leave his fellows to proceed.\"\n     I thus to him replied:  \"Much as I can,\nI thereto pray thee; and if thou be willing,\nThat I here seat me with thee, I consent;\nHis leave, with whom I journey, first obtain\'d.\"\n     \"O son!\" said he, \" whoever of this throng\nOne instant stops, lies then a hundred years,\nNo fan to ventilate him, when the fire\nSmites sorest.  Pass thou therefore on.  I close\nWill at thy garments walk, and then rejoin\nMy troop, who go mourning their endless doom.\"\n     I dar\'d not from the path des");

                struct disk_t* disk = disk_open_from_file("see_fat16_volume.img");
                test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct volume_t* volume = fat_open(disk, 0);
                test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct file_t* file = file_open(volume, "GaME.TxT");
                test_error(file != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                size_t size = file_read(filecontent, 1, 3468, file);
                test_error(size == 3356, "Funkcja file_read() niepoprawnie wczytała dane z pliku, powinna wczytać 3356 bajtów, a wczytała %lu", size);
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                int diff_pos = mem_find_first_difference(filecontent, expected_filecontent, 3356);

                // jeśli jest, to raportuj błąd
                test_error(diff_pos == -1, "Dane wczytane z pliku nie są poprawne; różnica w bajcie %d; jest 0x%02x a powinno być 0x%02x",
                    diff_pos, mem_get_byte(filecontent, diff_pos), mem_get_byte(expected_filecontent, diff_pos));

                onerror_compare_memory(expected_filecontent, filecontent, 3356);


                free(filecontent);

                file_close(file);
                fat_close(volume);
                disk_close(disk);

                test_no_heap_leakage();
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
            
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 31: Sprawdzanie poprawności działania funkcji file_read
//
void UTEST31(void)
{
    // informacje o teście
    test_start(31, "Sprawdzanie poprawności działania funkcji file_read", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

                char *filecontent = (char *)calloc(88, 1);
                char expected_filecontent[89] = "";

                strcat(expected_filecontent, "\n\nv. 14.  Broad are their pennons.]  From Virg. Aen. l. iii. 216.\n\nv. 48.  In my verse d");

                struct disk_t* disk = disk_open_from_file("see_fat16_volume.img");
                test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct volume_t* volume = fat_open(disk, 0);
                test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct file_t* file = file_open(volume, "bar last wiFe Led scaLe rEach vaLue oFFer.Jii");
                test_error(file != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                size_t size = file_read(filecontent, 1, 291, file);
                test_error(size == 88, "Funkcja file_read() niepoprawnie wczytała dane z pliku, powinna wczytać 88 bajtów, a wczytała %lu", size);
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                int diff_pos = mem_find_first_difference(filecontent, expected_filecontent, 88);

                // jeśli jest, to raportuj błąd
                test_error(diff_pos == -1, "Dane wczytane z pliku nie są poprawne; różnica w bajcie %d; jest 0x%02x a powinno być 0x%02x",
                    diff_pos, mem_get_byte(filecontent, diff_pos), mem_get_byte(expected_filecontent, diff_pos));

                onerror_compare_memory(expected_filecontent, filecontent, 88);


                free(filecontent);

                file_close(file);
                fat_close(volume);
                disk_close(disk);

                test_no_heap_leakage();
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
            
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 32: Sprawdzanie poprawności działania funkcji file_read
//
void UTEST32(void)
{
    // informacje o teście
    test_start(32, "Sprawdzanie poprawności działania funkcji file_read", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

                char *filecontent = (char *)calloc(157, 1);
                char expected_filecontent[158] = "";

                strcat(expected_filecontent, "n 1285, at Perpignan, in his retreat from Arragon.\n\nv. 102.  Him of gentle look.]  Henry of Naverre, father of Jane\nmarried to Philip IV of France, whom Dant");

                struct disk_t* disk = disk_open_from_file("see_fat16_volume.img");
                test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct volume_t* volume = fat_open(disk, 0);
                test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct file_t* file = file_open(volume, "SUBSTANC");
                test_error(file != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                size_t size = file_read(filecontent, 1, 384, file);
                test_error(size == 157, "Funkcja file_read() niepoprawnie wczytała dane z pliku, powinna wczytać 157 bajtów, a wczytała %lu", size);
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                int diff_pos = mem_find_first_difference(filecontent, expected_filecontent, 157);

                // jeśli jest, to raportuj błąd
                test_error(diff_pos == -1, "Dane wczytane z pliku nie są poprawne; różnica w bajcie %d; jest 0x%02x a powinno być 0x%02x",
                    diff_pos, mem_get_byte(filecontent, diff_pos), mem_get_byte(expected_filecontent, diff_pos));

                onerror_compare_memory(expected_filecontent, filecontent, 157);


                free(filecontent);

                file_close(file);
                fat_close(volume);
                disk_close(disk);

                test_no_heap_leakage();
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
            
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 33: Sprawdzanie poprawności działania funkcji file_read
//
void UTEST33(void)
{
    // informacje o teście
    test_start(33, "Sprawdzanie poprawności działania funkcji file_read", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

            char expected_filecontent[422] = "";

            strcat(expected_filecontent, "onti was slain, as if\nhe had been a victim to the god; and Florence had not since known\nthe blessing of peace.\n\nv. 150.  The lily.]  \"The arms of Florence had never hung\nreversed on the spear of her enemies, in token of her defeat; nor\nbeen changed from argent to gules;\" as they afterwards were, when\nthe Guelfi gained the predominance.\n\nCANTO XVII\n\nv. 1.  The youth.]  Phaeton, who came to his mother Clymene, to\ninquir");

            struct disk_t* disk = disk_open_from_file("see_fat16_volume.img");
            test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

            struct volume_t* volume = fat_open(disk, 0);
            test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

            struct file_t* file = file_open(volume, "\\STOP\\CaRd sTrong She materiAl\\wEATHER\\.\\..\\WEATHeR\\HAT\\area spot Corn name OCcUR\\UNDER");
            test_error(file != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

            for (int i = 0; i < 421; ++i)
            {
                char c;
                int res = file_read(&c, 1, 1, file);
                test_error(res == 1, "Funkcja file_read() powinna zwrócić wartość 1, a zwróciła %d", res);
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
                test_error(c == expected_filecontent[i], "Funkcja file_read() powinna odczytać w kroku %d znak %c, a odczytała znak %c", i, expected_filecontent[i], c);
            }

            file_close(file);
            fat_close(volume);
            disk_close(disk);

            test_no_heap_leakage();
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
        
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 34: Sprawdzanie poprawności działania funkcji file_read
//
void UTEST34(void)
{
    // informacje o teście
    test_start(34, "Sprawdzanie poprawności działania funkcji file_read", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

                char expected_filecontent[405] = "";

                strcat(expected_filecontent, "d you.\"\n     \"This circuit,\" said my teacher, \"knots the scourge\nFor envy, and the cords are therefore drawn\nBy charity\'s correcting hand.  The curb\nIs of a harsher sound, as thou shalt hear\n(If I deem rightly), ere thou reach the pass,\nWhere pardon sets them free.  But fix thine eyes\nIntently through the air, and thou shalt see\nA multitude before thee seated, each\nAlong the shelving grot.\"  Then more");

                struct disk_t* disk = disk_open_from_file("see_fat16_volume.img");
                test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct volume_t* volume = fat_open(disk, 0);
                test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct file_t* file = file_open(volume, "\\WomAn\\TRAIn\\bEgAn\\FOUr\\STeAM\\ABoUT\\BaBY");
                test_error(file != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                for (int i = 0; i < 404; ++i)
                {
                    char c;
                    int res = file_read(&c, 1, 1, file);
                    test_error(res == 1, "Funkcja file_read() powinna zwrócić wartość 1, a zwróciła %d", res);
                    onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
                    test_error(c == expected_filecontent[i], "Funkcja file_read() powinna odczytać w kroku %d znak %c, a odczytała znak %c", i, expected_filecontent[i], c);
                }

                file_close(file);
                fat_close(volume);
                disk_close(disk);

                test_no_heap_leakage();
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
            
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 35: Sprawdzanie poprawności działania funkcji file_read
//
void UTEST35(void)
{
    // informacje o teście
    test_start(35, "Sprawdzanie poprawności działania funkcji file_read", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

                char expected_filecontent[501] = "";

                strcat(expected_filecontent, "-flies innumerous spangling o\'er the vale,\nVineyard or tilth, where his day-labour lies:\nWith flames so numberless throughout its space\nShone the eighth chasm, apparent, when the depth\nWas to my view expos\'d. As he, whose wrongs\nThe bears aveng\'d, at its departure saw\nElijah\'s chariot, when the steeds erect\nRais\'d their steep flight for heav\'n; his eyes meanwhile,\nStraining pursu\'d them, till the flame alone\nUpsoaring like a misty speck he kenn\'d;\nE\'en thus along the gulf moves every flame,\nA si");

                struct disk_t* disk = disk_open_from_file("see_fat16_volume.img");
                test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct volume_t* volume = fat_open(disk, 0);
                test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct file_t* file = file_open(volume, "\\COOK\\dEgREE\\exPERIME\\EFFeCT\\CUT.TX");
                test_error(file != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                for (int i = 0; i < 500; ++i)
                {
                    char c;
                    int res = file_read(&c, 1, 1, file);
                    test_error(res == 1, "Funkcja file_read() powinna zwrócić wartość 1, a zwróciła %d", res);
                    onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
                    test_error(c == expected_filecontent[i], "Funkcja file_read() powinna odczytać w kroku %d znak %c, a odczytała znak %c", i, expected_filecontent[i], c);
                }

                file_close(file);
                fat_close(volume);
                disk_close(disk);

                test_no_heap_leakage();
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
            
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 36: Sprawdzanie poprawności działania funkcji file_read
//
void UTEST36(void)
{
    // informacje o teście
    test_start(36, "Sprawdzanie poprawności działania funkcji file_read", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

                char expected_filecontent[160] = "";

                strcat(expected_filecontent, "nd mount them not again,\nWho from his phial should refuse thee wine\nTo slake thy thirst, no less constrained were,\nThan water flowing not unto the sea.\nThou fa");

                struct disk_t* disk = disk_open_from_file("see_fat16_volume.img");
                test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct volume_t* volume = fat_open(disk, 0);
                test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct file_t* file = file_open(volume, "\\oR\\SToRY\\rOW\\DISTaNT\\UNDER.TX");
                test_error(file != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                for (int i = 0; i < 159; ++i)
                {
                    char c;
                    int res = file_read(&c, 1, 1, file);
                    test_error(res == 1, "Funkcja file_read() powinna zwrócić wartość 1, a zwróciła %d", res);
                    onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
                    test_error(c == expected_filecontent[i], "Funkcja file_read() powinna odczytać w kroku %d znak %c, a odczytała znak %c", i, expected_filecontent[i], c);
                }

                file_close(file);
                fat_close(volume);
                disk_close(disk);

                test_no_heap_leakage();
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
            
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 37: Sprawdzanie poprawności działania funkcji file_read
//
void UTEST37(void)
{
    // informacje o teście
    test_start(37, "Sprawdzanie poprawności działania funkcji file_read", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

                char expected_filecontent[1938] = "";

                strcat(expected_filecontent, "track\nPointed, that, on this side projecting, round\nCircles the hill.  His words so spurr\'d me on,\nThat I behind him clamb\'ring, forc\'d myself,\nTill my feet press\'d the circuit plain beneath.\nThere both together seated, turn\'d we round\nTo eastward, whence was our ascent: and oft\nMany beside have with delight look\'d back.\n     First on the nether shores I turn\'d my eyes,\nThen rais\'d them to the sun, and wond\'ring mark\'d\nThat from the left it smote us.  Soon perceiv\'d\nThat Poet sage how at the car of light\nAmaz\'d I stood, where \'twixt us and the north\nIts course it enter\'d.  Whence he thus to me:\n\"Were Leda\'s offspring now in company\nOf that broad mirror, that high up and low\nImparts his light beneath, thou might\'st behold\nThe ruddy zodiac nearer to the bears\nWheel, if its ancient course it not forsook.\nHow that may be if thou would\'st think; within\nPond\'ring, imagine Sion with this mount\nPlac\'d on the earth, so that to both be one\nHorizon, and two hemispheres apart,\nWhere lies the path that Phaeton ill knew\nTo guide his erring chariot: thou wilt see\nHow of necessity by this on one\nHe passes, while by that on the\' other side,\nIf with clear view shine intellect attend.\"\n     \"Of truth, kind teacher!\"  I exclaim\'d, \"so clear\nAught saw I never, as I now discern\nWhere seem\'d my ken to fail, that the mid orb\nOf the supernal motion (which in terms\nOf art is called the Equator, and remains\nEver between the sun and winter) for the cause\nThou hast assign\'d, from hence toward the north\nDeparts, when those who in the Hebrew land\nInhabit, see it tow\'rds the warmer part.\nBut if it please thee, I would gladly know,\nHow far we have to journey: for the hill\nMounts higher, than this sight of mine can mount.\"\n     He thus to me:  \"Such is this steep ascent,\nThat it is ever difficult at first,\nBut, more a man proceeds, less evil grows.\nWhen pleasant it shall seem to thee, so much\nThat upward going shall be easy to thee.\nAs i");

                struct disk_t* disk = disk_open_from_file("see_fat16_volume.img");
                test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct volume_t* volume = fat_open(disk, 0);
                test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct file_t* file = file_open(volume, "\\CoLD\\hUNDReD");
                test_error(file != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                for (int i = 0; i < 1937; ++i)
                {
                    char c;
                    int res = file_read(&c, 1, 1, file);
                    test_error(res == 1, "Funkcja file_read() powinna zwrócić wartość 1, a zwróciła %d", res);
                    onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
                    test_error(c == expected_filecontent[i], "Funkcja file_read() powinna odczytać w kroku %d znak %c, a odczytała znak %c", i, expected_filecontent[i], c);
                }

                file_close(file);
                fat_close(volume);
                disk_close(disk);

                test_no_heap_leakage();
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
            
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 38: Sprawdzanie poprawności działania funkcji file_read
//
void UTEST38(void)
{
    // informacje o teście
    test_start(38, "Sprawdzanie poprawności działania funkcji file_read", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

                char expected_filecontent[456] = "";

                strcat(expected_filecontent, "ain.]  Purgatory.\n\nv. 92.  Florence.]  See G. Villani, l. iii.  c. 2.\n\nv. 93.  Which calls her still.]  The public clock being still\nwithin the circuit of the ancient walls.\n\nv. 98.  When.]  When the women were not married at too early an\nage, and did not expect too large a portion.\n\nv. 101.  Void.]  Through the civil wars.\n\nv. 102 Sardanapalus.]  The luxurious monarch of Assyria Juvenal\nis here imitated, who uses his name for an instance of\neffeminac");

                struct disk_t* disk = disk_open_from_file("see_fat16_volume.img");
                test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct volume_t* volume = fat_open(disk, 0);
                test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct file_t* file = file_open(volume, "\\WomAn\\TrAIN\\BEGAN\\fouR\\StEAM\\Noun now mOunTain.Uun");
                test_error(file != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                for (int i = 0; i < 455; ++i)
                {
                    char c;
                    int res = file_read(&c, 1, 1, file);
                    test_error(res == 1, "Funkcja file_read() powinna zwrócić wartość 1, a zwróciła %d", res);
                    onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
                    test_error(c == expected_filecontent[i], "Funkcja file_read() powinna odczytać w kroku %d znak %c, a odczytała znak %c", i, expected_filecontent[i], c);
                }

                file_close(file);
                fat_close(volume);
                disk_close(disk);

                test_no_heap_leakage();
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
            
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 39: Sprawdzanie poprawności działania funkcji file_read
//
void UTEST39(void)
{
    // informacje o teście
    test_start(39, "Sprawdzanie poprawności działania funkcji file_read", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

                char expected_filecontent[112] = "";

                strcat(expected_filecontent, "ngeance, and such needs\nMust doat on other\'s evil.  Here beneath\nThis threefold love is mourn\'d.  Of th\' other ");

                struct disk_t* disk = disk_open_from_file("see_fat16_volume.img");
                test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct volume_t* volume = fat_open(disk, 0);
                test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct file_t* file = file_open(volume, "\\THIn\\raIl swIm WoRk mine\\hIGH\\bLock\\TImE");
                test_error(file != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                for (int i = 0; i < 111; ++i)
                {
                    char c;
                    int res = file_read(&c, 1, 1, file);
                    test_error(res == 1, "Funkcja file_read() powinna zwrócić wartość 1, a zwróciła %d", res);
                    onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
                    test_error(c == expected_filecontent[i], "Funkcja file_read() powinna odczytać w kroku %d znak %c, a odczytała znak %c", i, expected_filecontent[i], c);
                }

                file_close(file);
                fat_close(volume);
                disk_close(disk);

                test_no_heap_leakage();
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
            
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 40: Sprawdzanie poprawności działania funkcji file_read
//
void UTEST40(void)
{
    // informacje o teście
    test_start(40, "Sprawdzanie poprawności działania funkcji file_read", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

                char expected_filecontent[2062] = "";

                strcat(expected_filecontent, "ost patience in his look,\nWailing exclaim\'d:  \"I can endure no more.\"\n\n\n\nCANTO XI\n\nO thou Almighty Father, who dost make\nThe heavens thy dwelling, not in bounds confin\'d,\nBut that with love intenser there thou view\'st\nThy primal effluence, hallow\'d be thy name:\nJoin each created being to extol\nThy might, for worthy humblest thanks and praise\nIs thy blest Spirit.  May thy kingdom\'s peace\nCome unto us; for we, unless it come,\nWith all our striving thither tend in vain.\nAs of their will the angels unto thee\nTender meet sacrifice, circling thy throne\nWith loud hosannas, so of theirs be done\nBy saintly men on earth.  Grant us this day\nOur daily manna, without which he roams\nThrough this rough desert retrograde, who most\nToils to advance his steps.  As we to each\nPardon the evil done us, pardon thou\nBenign, and of our merit take no count.\n\'Gainst the old adversary prove thou not\nOur virtue easily subdu\'d; but free\nFrom his incitements and defeat his wiles.\nThis last petition, dearest Lord!  is made\nNot for ourselves, since that were needless now,\nBut for their sakes who after us remain.\"\n     Thus for themselves and us good speed imploring,\nThose spirits went beneath a weight like that\nWe sometimes feel in dreams, all, sore beset,\nBut with unequal anguish, wearied all,\nRound the first circuit, purging as they go,\nThe world\'s gross darkness off:  In our behalf\nIf there vows still be offer\'d, what can here\nFor them be vow\'d and done by such, whose wills\nHave root of goodness in them?  Well beseems\nThat we should help them wash away the stains\nThey carried hence, that so made pure and light,\nThey may spring upward to the starry spheres.\n     \"Ah!  so may mercy-temper\'d justice rid\nYour burdens speedily, that ye have power\nTo stretch your wing, which e\'en to your desire\nShall lift you, as ye show us on which hand\nToward the ladder leads the shortest way.\nAnd if there be more passages than one,\nInstruct us of that easiest to ascend;\nFor this man who comes with me, and bears yet\nThe charge of fleshly raiment Adam left him,\nDespite his be");

                struct disk_t* disk = disk_open_from_file("see_fat16_volume.img");
                test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct volume_t* volume = fat_open(disk, 0);
                test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct file_t* file = file_open(volume, "\\FEED\\ALWayS perhaps\\SLAVE\\SOUND.tXT");
                test_error(file != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                for (int i = 0; i < 2061; ++i)
                {
                    char c;
                    int res = file_read(&c, 1, 1, file);
                    test_error(res == 1, "Funkcja file_read() powinna zwrócić wartość 1, a zwróciła %d", res);
                    onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
                    test_error(c == expected_filecontent[i], "Funkcja file_read() powinna odczytać w kroku %d znak %c, a odczytała znak %c", i, expected_filecontent[i], c);
                }

                file_close(file);
                fat_close(volume);
                disk_close(disk);

                test_no_heap_leakage();
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
            
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 41: Sprawdzanie poprawności działania funkcji file_read
//
void UTEST41(void)
{
    // informacje o teście
    test_start(41, "Sprawdzanie poprawności działania funkcji file_read", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

                char expected_filecontent[198] = "";

                strcat(expected_filecontent, "d stone.]  See Hell, Canto XIII. 144. Near\nthe remains of the statue of Mars.  Buondelmonti was slain, as if\nhe had been a victim to the god; and Florence had not since known\nthe blessing of peace.");

                struct disk_t* disk = disk_open_from_file("see_fat16_volume.img");
                test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct volume_t* volume = fat_open(disk, 0);
                test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct file_t* file = file_open(volume, "\\ThIN\\WATEr\\aDD\\DiStANT\\ocEAN\\gREW.BIN");
                test_error(file != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                for (int i = 0; i < 197; ++i)
                {
                    char c;
                    int res = file_read(&c, 1, 1, file);
                    test_error(res == 1, "Funkcja file_read() powinna zwrócić wartość 1, a zwróciła %d", res);
                    onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
                    test_error(c == expected_filecontent[i], "Funkcja file_read() powinna odczytać w kroku %d znak %c, a odczytała znak %c", i, expected_filecontent[i], c);
                }

                file_close(file);
                fat_close(volume);
                disk_close(disk);

                test_no_heap_leakage();
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
            
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 42: Sprawdzanie poprawności działania funkcji file_read
//
void UTEST42(void)
{
    // informacje o teście
    test_start(42, "Sprawdzanie poprawności działania funkcji file_read", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

                char expected_filecontent[296] = "";

                strcat(expected_filecontent, "m Dante\'s Treatise\nDe Vulg. Eloq. 1. i. cap. 4. \"Quod prius vox primi loquentis\nsonaverit, viro sanae mentis in promptu esse non dubito ipsum\nfuisse quod Deus est, videlicet El.\"  St. Isidore in the\nOrigines, 1.  vii. c. 1. had said, \"Primum apud Hebraeos Dei\nnomen El dicitur.\"\n\nv. 135.  Use.] ");

                struct disk_t* disk = disk_open_from_file("see_fat16_volume.img");
                test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct volume_t* volume = fat_open(disk, 0);
                test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct file_t* file = file_open(volume, "\\WoMAN\\tRaIN\\CENTER\\eQuaTE\\simple create.qty");
                test_error(file != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                for (int i = 0; i < 295; ++i)
                {
                    char c;
                    int res = file_read(&c, 1, 1, file);
                    test_error(res == 1, "Funkcja file_read() powinna zwrócić wartość 1, a zwróciła %d", res);
                    onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
                    test_error(c == expected_filecontent[i], "Funkcja file_read() powinna odczytać w kroku %d znak %c, a odczytała znak %c", i, expected_filecontent[i], c);
                }

                file_close(file);
                fat_close(volume);
                disk_close(disk);

                test_no_heap_leakage();
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
            
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 43: Sprawdzanie poprawności działania funkcji file_read
//
void UTEST43(void)
{
    // informacje o teście
    test_start(43, "Sprawdzanie poprawności działania funkcji file_read", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

                char expected_filecontent[2300] = "";

                strcat(expected_filecontent, " the master of the sapient throng,\nSeated amid the philosophic train.\nHim all admire, all pay him rev\'rence due.\nThere Socrates and Plato both I mark\'d,\nNearest to him in rank; Democritus,\nWho sets the world at chance, Diogenes,\nWith Heraclitus, and Empedocles,\nAnd Anaxagoras, and Thales sage,\nZeno, and Dioscorides well read\nIn nature\'s secret lore.  Orpheus I mark\'d\nAnd Linus, Tully and moral Seneca,\nEuclid and Ptolemy, Hippocrates,\nGalenus, Avicen, and him who made\nThat commentary vast, Averroes.\n     Of all to speak at full were vain attempt;\nFor my wide theme so urges, that ofttimes\nMy words fall short of what bechanc\'d.  In two\nThe six associates part.  Another way\nMy sage guide leads me, from that air serene,\nInto a climate ever vex\'d with storms:\nAnd to a part I come where no light shines.\n\n\n\nCANTO V\n\nFROM the first circle I descended thus\nDown to the second, which, a lesser space\nEmbracing, so much more of grief contains\nProvoking bitter moans.  There, Minos stands\nGrinning with ghastly feature: he, of all\nWho enter, strict examining the crimes,\nGives sentence, and dismisses them beneath,\nAccording as he foldeth him around:\nFor when before him comes th\' ill fated soul,\nIt all confesses; and that judge severe\nOf sins, considering what place in hell\nSuits the transgression, with his tail so oft\nHimself encircles, as degrees beneath\nHe dooms it to descend.  Before him stand\nAlways a num\'rous throng; and in his turn\nEach one to judgment passing, speaks, and hears\nHis fate, thence downward to his dwelling hurl\'d.\n     \"O thou!  who to this residence of woe\nApproachest?\"  when he saw me coming, cried\nMinos, relinquishing his dread employ,\n\"Look how thou enter here; beware in whom\nThou place thy trust; let not the entrance broad\nDeceive thee to thy harm.\"  To him my guide:\n\"Wherefore exclaimest?  Hinder not his way\nBy destiny appointed;  so \'tis will\'d\nWhere will and power are one.  Ask thou no more.\"\n     Now \'gin the rueful wailings to be heard.\nNow am I come where many a plaining voice\nSmites on mine ear.  Into a place I came\nWhere light was silent all.  Bellowing there groan\'d\nA noise as of a sea in tempest torn\nBy warring winds.  The stormy blast of hell\nWith restless fury drives the spirits on\nWhirl\'d round and dash\'d amain with sore annoy.\nWhen they a");

                struct disk_t* disk = disk_open_from_file("see_fat16_volume.img");
                test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct volume_t* volume = fat_open(disk, 0);
                test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct file_t* file = file_open(volume, "\\sToP\\card stRonG she maTeRial\\PrActICE");
                test_error(file != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                for (int i = 0; i < 2299; ++i)
                {
                    char c;
                    int res = file_read(&c, 1, 1, file);
                    test_error(res == 1, "Funkcja file_read() powinna zwrócić wartość 1, a zwróciła %d", res);
                    onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
                    test_error(c == expected_filecontent[i], "Funkcja file_read() powinna odczytać w kroku %d znak %c, a odczytała znak %c", i, expected_filecontent[i], c);
                }

                file_close(file);
                fat_close(volume);
                disk_close(disk);

                test_no_heap_leakage();
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
            
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 44: Sprawdzanie poprawności działania funkcji file_read
//
void UTEST44(void)
{
    // informacje o teście
    test_start(44, "Sprawdzanie poprawności działania funkcji file_read", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

                char expected_filecontent[407] = "";

                strcat(expected_filecontent, " imperial Rome; nor less the guile\nLament they, whence of her Achilles \'reft\nDeidamia yet in death complains.\nAnd there is rued the stratagem, that Troy\nOf her Palladium spoil\'d.\"--\"If they have power\nOf utt\'rance from within these sparks,\" said I,\n\"O master!  think my prayer a thousand fold\nIn repetition urg\'d, that thou vouchsafe\nTo pause, till here the horned flame arrive.\nSee, how toward it with des");

                struct disk_t* disk = disk_open_from_file("see_fat16_volume.img");
                test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct volume_t* volume = fat_open(disk, 0);
                test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct file_t* file = file_open(volume, "\\oR\\DOg\\CoUNTRy\\nOTE\\WHEeL.Bin");
                test_error(file != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                for (int i = 0; i < 406; ++i)
                {
                    char c;
                    int res = file_read(&c, 1, 1, file);
                    test_error(res == 1, "Funkcja file_read() powinna zwrócić wartość 1, a zwróciła %d", res);
                    onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
                    test_error(c == expected_filecontent[i], "Funkcja file_read() powinna odczytać w kroku %d znak %c, a odczytała znak %c", i, expected_filecontent[i], c);
                }

                file_close(file);
                fat_close(volume);
                disk_close(disk);

                test_no_heap_leakage();
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
            
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 45: Sprawdzanie poprawności działania funkcji file_read
//
void UTEST45(void)
{
    // informacje o teście
    test_start(45, "Sprawdzanie poprawności działania funkcji file_read", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

                char expected_filecontent[3771] = "";

                strcat(expected_filecontent, "ejoice in the evil which befalls others.\"\n\nv. 111.  There is.]  The proud.\n\nv. 114.  There is.]  The envious.\n\nv. 117.  There is he.]  The resentful.\n\nv. 135.  Along Three circles.]  According to the allegorical\ncommentators, as Venturi has observed, Reason is represented\nunder the person of Virgil, and Sense under that of Dante.  The\nformer leaves to the latter to discover for itself the three\ncarnal sins, avarice, gluttony and libidinousness; having already\ndeclared the nature of the spiritual sins, pride, envy, anger,\nand indifference, or lukewarmness in piety, which the Italians\ncall accidia, from the Greek word.\n[GREEK HERE]\n\nCANTO XVIII\n\nv. 1.  The teacher ended.]  Compare Plato, Protagoras, v. iii.\np. 123.  Bip.  edit. [GREEK HERE]  Apoll. Rhod. 1. i. 513,\nand Milton, P. L. b. viii. 1.\nThe angel ended, &c.\n\nv. 23.  Your apprehension.]  It is literally, \"Your apprehensive\nfaculty derives intention from a thing really existing, and\ndisplays the intention within you, so that it makes the soul turn\nto it.\"  The commentators labour in explaining this; and whatever\nsense they have elicited may, I think, be resolved into the words\nof the translation in the text.\n\nv. 47.  Spirit.]  The human soul, which differs from that of\nbrutes, inasmuch as, though united with the body, it has a\nseparate existence of its own.\nv. 65.  Three men.]  The great moral philosophers among the\nheathens.\n\nv. 78.  A crag.]  I have preferred the reading of Landino,\nscheggion, \"crag,\" conceiving it to be more poetical than\nsecchion, \"bucket,\" which is the common reading.  The same cause,\nthe vapours, which the commentators say might give the appearance\nof increased magnitude to the moon, might also make her seem\nbroken at her rise.\n\nv. 78.  Up the vault.]  The moon passed with a motion opposite to\nthat of the heavens, through the constellation of the scorpion,\nin which the sun is, when to those who are in Rome he appears to\nset between the isles of Corsica and Sardinia.\n\nv. 84.  Andes.]  Andes, now Pietola, made more famous than Mantua\nnear which it is situated, by having been the birthplace of\nVirgil.\n\nv. 92.  Ismenus and Asopus.]  Rivers near Thebes\n\nv. 98.  Mary.]  Luke, c i. 39, 40\n\nv. 99.  Caesar.]  See Lucan, Phars. I. iii. and iv, and\nCaesar de Bello Civiii, I. i.  Caesar left Brutus to complete\nthe siege of Marseilles, and hastened on to the attack of\nAfranius and Petreius, the generals of Pompey, at Ilerda (Lerida)\nin Spain.\n\nv. 118.  abbot.]  Alberto, abbot of San Zeno in Verona, when\nFrederick I was emperor, by whom Milan was besieged and reduced\nto ashes.\n\nv. 121.  There is he.]  Alberto della Scala, lord of Verona, who\nhad made his natural son abbot of San Zeno.\n\nv. 133.  First they died.]  The Israelites, who, on account of\ntheir disobedience, died before reaching the promised land.\n\nv. 135.  And they.]  Virg  Aen. 1. v.\n\nCANTO XIX\n\nv. 1.  The hour.]  Near the dawn.\n\nv. 4.  The geomancer.]  The geomancers, says Landino, when they\ndivined, drew a figure consisting of sixteen marks, named from so\nmany stars which constitute the end of Aquarius and the beginning\nof Pisces. One of these they called \"the greater fortune.\"\n\nv. 7.  A woman\'s shape.]  Worldly happiness.  This allegory\nreminds us of the \"Choice of Hercules.\"\n\nv. 14.  Love\'s own hue.]\nA smile that glow\'d\nCelestial rosy red, love\'s proper hue.\nMilton, P. L. b. viii.  619\n\n--facies pulcherrima tune est\nQuum porphyriaco variatur candida rubro\nQuid color hic roseus sibi vult?  designat amorem:\nQuippe amor est igni similis; flammasque rubentes\nIgnus habere solet.\nPalingenii Zodiacus Vitae, 1. xii.\n\nv. 26.  A dame.]  Philosophy.\n\nv. 49.  Who mourn.]  Matt.  c. v. 4.\n\nv. 72.  My soul.]  Psalm cxix.  5\n\nv. 97.  The successor of Peter Ottobuono, of the family of\nFies");

                struct disk_t* disk = disk_open_from_file("see_fat16_volume.img");
                test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct volume_t* volume = fat_open(disk, 0);
                test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct file_t* file = file_open(volume, "\\sTOP\\CarD strong She MATERial\\wEATHEr\\TALL\\cENTUrY\\AM\\PAsT.BIN");
                test_error(file != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                for (int i = 0; i < 3770; ++i)
                {
                    char c;
                    int res = file_read(&c, 1, 1, file);
                    test_error(res == 1, "Funkcja file_read() powinna zwrócić wartość 1, a zwróciła %d", res);
                    onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
                    test_error(c == expected_filecontent[i], "Funkcja file_read() powinna odczytać w kroku %d znak %c, a odczytała znak %c", i, expected_filecontent[i], c);
                }

                file_close(file);
                fat_close(volume);
                disk_close(disk);

                test_no_heap_leakage();
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
            
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 46: Sprawdzanie poprawności działania funkcji file_read
//
void UTEST46(void)
{
    // informacje o teście
    test_start(46, "Sprawdzanie poprawności działania funkcji file_read", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

                char expected_filecontent[2004] = "";

                strcat(expected_filecontent, " and other\nprelates of the holy church, for not observing their duty, nor\nleading the angelic life, and affirmed that he ought to be pope.\nHe was followed by more than three thousand men and women, who\nlived promiscuously on the mountains together, like beasts, and,\nwhen they wanted provisions, supplied themselves by depredation\nand rapine.  This lasted for two years till, many being struck\nwith compunction at the dissolute life they led, his sect was\nmuch diminished; and through failure of food, and the severity of\nthe snows, he was taken by the people of Novarra, and burnt, with\nMargarita his companion and many other men and women whom his\nerrors had seduced.\"  G. Villanni, l. viii. c. 84.\n\nLandino observes, that he was possessed of singular eloquence,\nand that both he and Margarita endored their fate with a firmness\nworthy of a better cause.  For a further account of him, see\nMuratori Rer. Ital. Script. t. ix. p. 427.\n\nv. 69.  Medicina.]  A place in the territory of Bologna.  Piero\nfomented dissensions among the inhabitants of that city, and\namong the leaders of the neighbouring states.\n\nv. 70.  The pleasant land.]  Lombardy.\n\nv. 72.  The twain.]  Guido dal Cassero and Angiolello da Cagnano,\ntwo of the worthiest and most distinguished citizens of Fano,\nwere invited by Malatestino da Rimini to an entertainment on\npretence that he had some important business to transact with\nthem:  and, according to instructions given by him, they mere\ndrowned in their passage near Catolica, between Rimini and Fano.\n\nv. 85.  Focara\'s wind.] Focara is a mountain, from which a wind\nblows that is peculiarly dangerous to the navigators of that\ncoast.\n\nv. 94.  The doubt in Caesar\'s mind.]  Curio, whose speech\n(according to Lucan) determined Julius Caesar to proceed when he\nhad arrived at Rimini (the ancient Ariminum), and doubted whether\nhe should prosecute the civil war.\n        Tolle moras:  semper nocuit differre paratis\n               Pharsal, l. i. 281.\n\nv. 102.  Mosca.]  Buondelmonte");

                struct disk_t* disk = disk_open_from_file("see_fat16_volume.img");
                test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct volume_t* volume = fat_open(disk, 0);
                test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct file_t* file = file_open(volume, "\\OR\\STATE.Tx");
                test_error(file != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                for (int i = 0; i < 2003; ++i)
                {
                    char c;
                    int res = file_read(&c, 1, 1, file);
                    test_error(res == 1, "Funkcja file_read() powinna zwrócić wartość 1, a zwróciła %d", res);
                    onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
                    test_error(c == expected_filecontent[i], "Funkcja file_read() powinna odczytać w kroku %d znak %c, a odczytała znak %c", i, expected_filecontent[i], c);
                }

                file_close(file);
                fat_close(volume);
                disk_close(disk);

                test_no_heap_leakage();
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
            
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 47: Sprawdzanie poprawności działania funkcji file_read
//
void UTEST47(void)
{
    // informacje o teście
    test_start(47, "Sprawdzanie poprawności działania funkcji file_read", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

                char expected_filecontent[479] = "";

                strcat(expected_filecontent, " best effect, only the\nmatter, which he hath to work on is unframeable.\" Hooker\'s Eccl.\nPolity, b. 5.  9.\n\nCANTO II\n\nv. 1.  In small bark.]\n\nCon la barchetta mia cantando in rima\nPulci, Morg.  Magg.  c. xxviii.\n\nIo me n\'andro con la barchetta mia,\nQuanto l\'acqua comporta un picciol legno\nIbid.\n\nv. 30.  This first star.]  the moon\n\nv. 46.  E\'en as the truth.]  Like a truth that does not need\ndemonstration, but is self-evident.\"\n\nv. 52.  Cain.]  Compare Hell, Canto XX.  123. ");

                struct disk_t* disk = disk_open_from_file("see_fat16_volume.img");
                test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct volume_t* volume = fat_open(disk, 0);
                test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct file_t* file = file_open(volume, "\\Or\\ShArp success test.qVK");
                test_error(file != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                for (int i = 0; i < 478; ++i)
                {
                    char c;
                    int res = file_read(&c, 1, 1, file);
                    test_error(res == 1, "Funkcja file_read() powinna zwrócić wartość 1, a zwróciła %d", res);
                    onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
                    test_error(c == expected_filecontent[i], "Funkcja file_read() powinna odczytać w kroku %d znak %c, a odczytała znak %c", i, expected_filecontent[i], c);
                }

                file_close(file);
                fat_close(volume);
                disk_close(disk);

                test_no_heap_leakage();
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
            
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 48: Sprawdzanie poprawności działania funkcji file_read
//
void UTEST48(void)
{
    // informacje o teście
    test_start(48, "Sprawdzanie poprawności działania funkcji file_read", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

                char expected_filecontent[2049] = "";

                strcat(expected_filecontent, ", with the isle\nSardinia and Maremma\'s pestilent fen,\nHad heap\'d their maladies all in one foss\nTogether; such was here the torment: dire\nThe stench, as issuing steams from fester\'d limbs.\n     We on the utmost shore of the long rock\nDescended still to leftward.  Then my sight\nWas livelier to explore the depth, wherein\nThe minister of the most mighty Lord,\nAll-searching Justice, dooms to punishment\nThe forgers noted on her dread record.\n     More rueful was it not methinks to see\nThe nation in Aegina droop, what time\nEach living thing, e\'en to the little worm,\nAll fell, so full of malice was the air\n(And afterward, as bards of yore have told,\nThe ancient people were restor\'d anew\nFrom seed of emmets) than was here to see\nThe spirits, that languish\'d through the murky vale\nUp-pil\'d on many a stack.  Confus\'d they lay,\nOne o\'er the belly, o\'er the shoulders one\nRoll\'d of another; sideling crawl\'d a third\nAlong the dismal pathway.  Step by step\nWe journey\'d on, in silence looking round\nAnd list\'ning those diseas\'d, who strove in vain\nTo lift their forms.  Then two I mark\'d, that sat\nPropp\'d \'gainst each other, as two brazen pans\nSet to retain the heat.  From head to foot,\nA tetter bark\'d them round. Nor saw I e\'er\nGroom currying so fast, for whom his lord\nImpatient waited, or himself perchance\nTir\'d with long watching, as of these each one\nPlied quickly his keen nails, through furiousness\nOf ne\'er abated pruriency.  The crust\nCame drawn from underneath in flakes, like scales\nScrap\'d from the bream or fish of broader mail.\n     \"O thou, who with thy fingers rendest off\nThy coat of proof,\" thus spake my guide to one,\n\"And sometimes makest tearing pincers of them,\nTell me if any born of Latian land\nBe among these within: so may thy nails\nServe thee for everlasting to this toil.\"\n     \"Both are of Latium,\" weeping he replied,\n\"Whom tortur\'d thus thou seest:  but who art thou\nThat hast inquir\'d of us?\"  To whom my guide:\n\"One that descend with this man, who yet lives,\nFrom rock to rock, and show him hell\'s abyss.\"\n     T");

                struct disk_t* disk = disk_open_from_file("see_fat16_volume.img");
                test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct volume_t* volume = fat_open(disk, 0);
                test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct file_t* file = file_open(volume, "\\OR\\ThEM.BIN");
                test_error(file != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                for (int i = 0; i < 2048; ++i)
                {
                    char c;
                    int res = file_read(&c, 1, 1, file);
                    test_error(res == 1, "Funkcja file_read() powinna zwrócić wartość 1, a zwróciła %d", res);
                    onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
                    test_error(c == expected_filecontent[i], "Funkcja file_read() powinna odczytać w kroku %d znak %c, a odczytała znak %c", i, expected_filecontent[i], c);
                }

                file_close(file);
                fat_close(volume);
                disk_close(disk);

                test_no_heap_leakage();
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
            
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 49: Sprawdzanie poprawności działania funkcji file_read
//
void UTEST49(void)
{
    // informacje o teście
    test_start(49, "Sprawdzanie poprawności działania funkcji file_read", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

                char expected_filecontent[3148] = "";

                strcat(expected_filecontent, "rity and\ndenseness which thou hast assigned.\"  By \"formal principles,\n\"principj formali, are meant constituent or essential causes.\"\nMilton, in imitation of this passage, introduces the angel\narguing with Adam respecting the causes of the spots on the moon.\n\nBut, as a late French translator of the Paradise well remarks,\nhis reasoning is physical; that of Dante partly metaphysical and\npartly theologic.\n\nv. 111.  Within the heaven.]  According to our Poet\'s system,\nthere are ten heavens; the seven planets, the eighth spheres\ncontaining the fixed stars, the primum mobile, and the empyrean.\n\nv. 143.  The virtue mingled.]  Virg. Aen. 1. vi 724.\nPrincipio coelum, &c.\n\nCANTO III\n\nv. 16.  Delusion.]  \"An error the contrary to that of Narcissus,\nbecause he mistook a shadow for a substance, I a substance for a\nshadow.\"\n\nv. 50.  Piccarda.]  The sister of Forese whom we have seen in the\nPurgatory, Canto XXIII.\n\nv. 90.  The Lady.] St. Clare, the foundress of the order called\nafter her She was born of opulent and noble parents at Assisi, in\n1193, and died in 1253.  See Biogr.  Univ. t. 1.  p. 598.  8vo.\nParis, 1813.\n\nv. 121.  Constance.]  Daughter of Ruggieri, king of Sicily, who,\nbeing taken by force out of a monastery where she had professed,\nwas married to the Emperor Henry Vl. and by him was mother to\nFrederick 11. She was fifty years old or more at the time, and\n\"because it was not credited that she could have a child at that\nage, she was delivered in a pavilion and it was given out, that\nany lady, who pleased, was at liberty to see her.  Many came, and\nsaw her, and the suspicion ceased.\"  Ricordano Malaspina in\nMuratori, Rer. It. Script. t. viii.  p. 939; and G. Villani, in\nthe same words, Hist. I v. c. 16\n\nThe French translator above mentored speaks of her having\npoisoned her husband.  The death of Henry Vl. is recorded in the\nChronicon Siciliae, by an anonymous writer, (Muratori, t. x.) but\nnot a word of his having been poisoned by Constance, and\nRicordano Malaspina even mentions her decease as happening before\nthat of her husband, Henry V., for so this author, with some\nothers, terms him. v. 122.  The second.]  Henry Vl. son of\nFrederick I was the second emperor of the house of Saab; and his\nson Frederick II \"the third and last.\"\n\nCANTO IV\n\nv. 6.  Between two deer]\n\nTigris ut auditis, diversa valle duorum\nExtimulata fame, mugitibus armentorum\nNeseit utro potius ruat, et ruere ardet utroque.\nOvid, Metam. 1. v. 166\n\nv. 13.  Daniel.]  See Daniel, c. ii.\n\nv. 24.  Plato.]  [GREEK HERE]  Plato Timaeus v. ix.  p. 326.\nEdit. Bip.  \"The Creator, when he had framed the universe,\ndistributed to the stars an equal number of souls, appointing to\neach soul its several star.\"\n\nv. 27.  Of that.]  Plato\'s opinion.\n\nv. 34.  The first circle.]  The empyrean.\n\nv. 48.  Him who made Tobias whole.]\n\nRaphael, the sociable spirit, that deign\'d\nTo travel with Tobias, and secur\'d\nHis marriage with the sev\'n times wedded maid,\nMilton, P. L. b. v. 223.\n\nv. 67.  That to the eye of man.]  \"That the ways of divine\njustice are often inscrutable to man, ought rather to be a motive\nto faith than an inducement to heresy.\" Such app");

                struct disk_t* disk = disk_open_from_file("see_fat16_volume.img");
                test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct volume_t* volume = fat_open(disk, 0);
                test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct file_t* file = file_open(volume, "\\or\\ArRIVe.TXT");
                test_error(file != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                for (int i = 0; i < 3147; ++i)
                {
                    char c;
                    int res = file_read(&c, 1, 1, file);
                    test_error(res == 1, "Funkcja file_read() powinna zwrócić wartość 1, a zwróciła %d", res);
                    onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
                    test_error(c == expected_filecontent[i], "Funkcja file_read() powinna odczytać w kroku %d znak %c, a odczytała znak %c", i, expected_filecontent[i], c);
                }

                file_close(file);
                fat_close(volume);
                disk_close(disk);

                test_no_heap_leakage();
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
            
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 50: Sprawdzanie poprawności działania funkcji file_read
//
void UTEST50(void)
{
    // informacje o teście
    test_start(50, "Sprawdzanie poprawności działania funkcji file_read", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

                char expected_filecontent[106] = "";

                strcat(expected_filecontent, "n use\nWith those who look not at the deed alone,\nBut spy into the thoughts with subtle skill!\n     \"Quick");

                struct disk_t* disk = disk_open_from_file("see_fat16_volume.img");
                test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct volume_t* volume = fat_open(disk, 0);
                test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct file_t* file = file_open(volume, "\\OR\\rivER.TX");
                test_error(file != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                for (int i = 0; i < 105; ++i)
                {
                    char c;
                    int res = file_read(&c, 1, 1, file);
                    test_error(res == 1, "Funkcja file_read() powinna zwrócić wartość 1, a zwróciła %d", res);
                    onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
                    test_error(c == expected_filecontent[i], "Funkcja file_read() powinna odczytać w kroku %d znak %c, a odczytała znak %c", i, expected_filecontent[i], c);
                }

                file_close(file);
                fat_close(volume);
                disk_close(disk);

                test_no_heap_leakage();
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
            
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 51: Sprawdzanie poprawności działania funkcji file_read
//
void UTEST51(void)
{
    // informacje o teście
    test_start(51, "Sprawdzanie poprawności działania funkcji file_read", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

                char expected_filecontent[4061] = "";

                strcat(expected_filecontent, "rew me on to climb,\nAnd climbing wind along this mountain-steep,\nWhich rectifies in you whate\'er the world\nMade crooked and deprav\'d I have his word,\nThat he will bear me company as far\nAs till I come where Beatrice dwells:\nBut there must leave me.  Virgil is that spirit,\nWho thus hath promis\'d,\"  and I pointed to him;\n\"The other is that shade, for whom so late\nYour realm, as he arose, exulting shook\nThrough every pendent cliff and rocky bound.\"\n\n\n\nCANTO XXIV\n\nOur journey was not slacken\'d by our talk,\nNor yet our talk by journeying.  Still we spake,\nAnd urg\'d our travel stoutly, like a ship\nWhen the wind sits astern.  The shadowy forms,\nThat seem\'d things dead and dead again, drew in\nAt their deep-delved orbs rare wonder of me,\nPerceiving I had life; and I my words\nContinued, and thus spake; \"He journeys up\nPerhaps more tardily then else he would,\nFor others\' sake.  But tell me, if thou know\'st,\nWhere is Piccarda?  Tell me, if I see\nAny of mark, among this multitude,\nWho eye me thus.\"--\"My sister (she for whom,\n\'Twixt beautiful and good I cannot say\nWhich name was fitter ) wears e\'en now her crown,\nAnd triumphs in Olympus.\"  Saying this,\nHe added: \"Since spare diet hath so worn\nOur semblance out, \'t is lawful here to name\nEach one .   This,\" and his finger then he rais\'d,\n\"Is Buonaggiuna,--Buonaggiuna, he\nOf Lucca: and that face beyond him, pierc\'d\nUnto a leaner fineness than the rest,\nHad keeping of the church: he was of Tours,\nAnd purges by wan abstinence away\nBolsena\'s eels and cups of muscadel.\"\n     He show\'d me many others, one by one,\nAnd all, as they were nam\'d, seem\'d well content;\nFor no dark gesture I discern\'d in any.\nI saw through hunger Ubaldino grind\nHis teeth on emptiness; and Boniface,\nThat wav\'d the crozier o\'er a num\'rous flock.\nI saw the Marquis, who tad time erewhile\nTo swill at Forli with less drought, yet so\nWas one ne\'er sated.  I howe\'er, like him,\nThat gazing \'midst a crowd, singles out one,\nSo singled him of Lucca; for methought\nWas none amongst them took such note of me.\nSomewhat I heard him whisper of Gentucca:\nThe sound was indistinct, and murmur\'d there,\nWhere justice, that so strips them, fix\'d her sting.\n     \"Spirit!\" said I, \"it seems as thou wouldst fain\nSpeak with me.  Let me hear thee.  Mutual wish\nTo converse prompts, which let us both indulge.\"\n     He, answ\'ring, straight began: \"Woman is born,\nWhose brow no wimple shades yet, that shall make\nMy city please thee, blame it as they may.\nGo then with this forewarning.  If aught false\nMy whisper too implied, th\' event shall tell\nBut say, if of a  truth I see the man\nOf that new lay th\' inventor, which begins\nWith \'Ladies, ye that con the lore of love\'.\"\n     To whom I thus:  \"Count of me but as one\nWho am the scribe of love; that, when he breathes,\nTake up my pen, and, as he dictates, write.\"\n     \"Brother!\" said he, \"the hind\'rance which once held\nThe notary with Guittone and myself,\nShort of that new and sweeter style I hear,\nIs now disclos\'d.  I see how ye your plumes\nStretch, as th\' inditer guides them; which, no question,\nOurs did not.  He that seeks a grace beyond,\nSees not the distance parts one style from other.\"\nAnd, as contented, here he held his peace.\n     Like as the bird, that winter near the Nile,\nIn squared regiment direct their course,\nThen stretch themselves in file for speedier flight;\nThus all the tribe of spirits, as they turn\'d\nTheir visage, faster deaf, nimble alike\nThrough leanness and desire.  And as a man,\nTir\'d With the motion of a trotting steed,\nSlacks pace, and stays behind his company,\nTill his o\'erbreathed lungs keep temperate time;\nE\'en so Forese let that holy crew\nProceed, behind them lingering at my side,\nAnd saying: \"When shall I again behold thee?\"\n     \"How long my life may last,\" said I, \"I know not;\nThis know, how soon soever I return,\nMy wishes will before me have arriv\'d.\nSithence the place, where I am set to live,\nIs, day by day, more scoop\'d of all its good,\nAnd dismal ruin seems to threaten it.\"\n     \"Go now,\" he cried:  \"lo!  he, whose guilt is most,\nPa");

                struct disk_t* disk = disk_open_from_file("see_fat16_volume.img");
                test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct volume_t* volume = fat_open(disk, 0);
                test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct file_t* file = file_open(volume, "\\OR\\chart AM raise.toj");
                test_error(file != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                for (int i = 0; i < 4060; ++i)
                {
                    char c;
                    int res = file_read(&c, 1, 1, file);
                    test_error(res == 1, "Funkcja file_read() powinna zwrócić wartość 1, a zwróciła %d", res);
                    onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
                    test_error(c == expected_filecontent[i], "Funkcja file_read() powinna odczytać w kroku %d znak %c, a odczytała znak %c", i, expected_filecontent[i], c);
                }

                file_close(file);
                fat_close(volume);
                disk_close(disk);

                test_no_heap_leakage();
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
            
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 52: Sprawdzanie poprawności działania funkcji file_read
//
void UTEST52(void)
{
    // informacje o teście
    test_start(52, "Sprawdzanie poprawności działania funkcji file_read", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

                char expected_filecontent[496] = "";

                strcat(expected_filecontent, "r 1 had not\nrisen above my human nature, and were not merely such as thou\nhadst then, formed me.\"\n\nv.  125.  Through sluggishness.]\nPerch\' a risponder la materia e sorda.\n\nSo Filicaja, canz.  vi. st 9.\nPerche a risponder la discordia e sorda\n\n\"The workman hath in his heart a purpose, he carrieth in mind the\nwhole form which his work should have; there wanteth not him\nskill and desire to bring his labour to the best effect, only the\nmatter, which he hath to work on is unframeable.\" Hooker\'s ");

                struct disk_t* disk = disk_open_from_file("see_fat16_volume.img");
                test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct volume_t* volume = fat_open(disk, 0);
                test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct file_t* file = file_open(volume, "\\oR\\COOl");
                test_error(file != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                for (int i = 0; i < 495; ++i)
                {
                    char c;
                    int res = file_read(&c, 1, 1, file);
                    test_error(res == 1, "Funkcja file_read() powinna zwrócić wartość 1, a zwróciła %d", res);
                    onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
                    test_error(c == expected_filecontent[i], "Funkcja file_read() powinna odczytać w kroku %d znak %c, a odczytała znak %c", i, expected_filecontent[i], c);
                }

                file_close(file);
                fat_close(volume);
                disk_close(disk);

                test_no_heap_leakage();
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
            
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 53: Sprawdzanie poprawności działania funkcji file_read
//
void UTEST53(void)
{
    // informacje o teście
    test_start(53, "Sprawdzanie poprawności działania funkcji file_read", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

                char expected_filecontent[3073] = "";

                strcat(expected_filecontent, "nd he, who had to her descended, once,\nOn earth, now hail\'d in heav\'n; and on pois\'d wing.\n\"Ave, Maria, Gratia Plena,\" sang:\nTo whose sweet anthem all the blissful court,\nFrom all parts answ\'ring, rang: that holier joy\nBrooded the deep serene.  \"Father rever\'d:\nWho deign\'st, for me, to quit the pleasant place,\nWherein thou sittest, by eternal lot!\nSay, who that angel is, that with such glee\nBeholds our queen, and so enamour\'d glows\nOf her high beauty, that all fire he seems.\"\nSo I again resorted to the lore\nOf my wise teacher, he, whom Mary\'s charms\nEmbellish\'d, as the sun the morning star;\nWho thus in answer spake:  \"In him are summ\'d,\nWhatever of buxomness and free delight\nMay be in Spirit, or in angel, met:\nAnd so beseems:  for that he bare the palm\nDown unto Mary, when the Son of God\nVouchsaf\'d to clothe him in terrestrial weeds.\nNow let thine eyes wait heedful on my words,\nAnd note thou of this just and pious realm\nThe chiefest nobles.  Those, highest in bliss,\nThe twain, on each hand next our empress thron\'d,\nAre as it were two roots unto this rose.\nHe to the left, the parent, whose rash taste\nProves bitter to his seed; and, on the right,\nThat ancient father of the holy church,\nInto whose keeping Christ did give the keys\nOf this sweet flow\'r: near whom behold the seer,\nThat, ere he died, saw all the grievous times\nOf the fair bride, who with the lance and nails\nWas won.  And, near unto the other, rests\nThe leader, under whom on manna fed\nTh\' ungrateful nation, fickle and perverse.\nOn th\' other part, facing to Peter, lo!\nWhere Anna sits, so well content to look\nOn her lov\'d daughter, that with moveless eye\nShe chants the loud hosanna:  while, oppos\'d\nTo the first father of your mortal kind,\nIs Lucia, at whose hest thy lady sped,\nWhen on the edge of ruin clos\'d thine eye.\n     \"But (for the vision hasteneth so an end)\nHere break we off, as the good workman doth,\nThat shapes the cloak according to the cloth:\nAnd to the primal love our ken shall rise;\nThat thou mayst penetrate the brightness, far\nAs sight can bear thee.  Yet, alas!  in sooth\nBeating thy pennons, thinking to advance,\nThou backward fall\'st.  Grace then must first be gain\'d;\nHer grace, whose might can help thee. Thou in prayer\nSeek her: and, with affection, whilst I sue,\nAttend, and yield me all thy heart.\"  He said,\nAnd thus the saintly orison began.\n\n\n\nCANTO XXXIII\n\n\"O virgin mother, daughter of thy Son,\nCreated beings all in lowliness\nSurpassing, as in height, above them all,\nTerm by th\' eternal counsel pre-ordain\'d,\nEnnobler of thy nature, so advanc\'d\nIn thee, that its great Maker did not scorn,\nHimself, in his own work enclos\'d to dwell!\nFor in thy womb rekindling shone the love\nReveal\'d, whose genial influence makes now\nThis flower to germin in eternal peace!\nHere thou to us, of charity and love,\nArt, as the noon-day torch: and art, beneath,\nTo mortal men, of hope a living spring.\nSo mighty art thou, lady!  and so great,\nThat he who grace desireth, and comes not\nTo thee for aidance, fain would have desire\nFly without wings.  Nor only him who ask");

                struct disk_t* disk = disk_open_from_file("see_fat16_volume.img");
                test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct volume_t* volume = fat_open(disk, 0);
                test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct file_t* file = file_open(volume, "\\Or\\cAMP");
                test_error(file != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                for (int i = 0; i < 3072; ++i)
                {
                    char c;
                    int res = file_read(&c, 1, 1, file);
                    test_error(res == 1, "Funkcja file_read() powinna zwrócić wartość 1, a zwróciła %d", res);
                    onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
                    test_error(c == expected_filecontent[i], "Funkcja file_read() powinna odczytać w kroku %d znak %c, a odczytała znak %c", i, expected_filecontent[i], c);
                }

                file_close(file);
                fat_close(volume);
                disk_close(disk);

                test_no_heap_leakage();
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
            
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 54: Sprawdzanie poprawności działania funkcji file_read
//
void UTEST54(void)
{
    // informacje o teście
    test_start(54, "Sprawdzanie poprawności działania funkcji file_read", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

                char expected_filecontent[10] = "";

                strcat(expected_filecontent, "emselves ");

                struct disk_t* disk = disk_open_from_file("see_fat16_volume.img");
                test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct volume_t* volume = fat_open(disk, 0);
                test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct file_t* file = file_open(volume, "\\OR\\elsE sAme Operate hit.IHe");
                test_error(file != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                for (int i = 0; i < 9; ++i)
                {
                    char c;
                    int res = file_read(&c, 1, 1, file);
                    test_error(res == 1, "Funkcja file_read() powinna zwrócić wartość 1, a zwróciła %d", res);
                    onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
                    test_error(c == expected_filecontent[i], "Funkcja file_read() powinna odczytać w kroku %d znak %c, a odczytała znak %c", i, expected_filecontent[i], c);
                }

                file_close(file);
                fat_close(volume);
                disk_close(disk);

                test_no_heap_leakage();
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
            
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 55: Sprawdzanie poprawności działania funkcji file_read
//
void UTEST55(void)
{
    // informacje o teście
    test_start(55, "Sprawdzanie poprawności działania funkcji file_read", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

                char expected_filecontent[276] = "";

                strcat(expected_filecontent, "  Of one already I descried the face,\nShoulders, and breast, and of the belly huge\nGreat part, and both arms down along his ribs.\n     All-teeming nature, when her plastic hand\nLeft framing of these monsters, did display\nPast doubt her wisdom, taking from mad War\nSuch slaves");

                struct disk_t* disk = disk_open_from_file("see_fat16_volume.img");
                test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct volume_t* volume = fat_open(disk, 0);
                test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct file_t* file = file_open(volume, "\\OR\\Red Pair sugAr.wzY");
                test_error(file != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                for (int i = 0; i < 275; ++i)
                {
                    char c;
                    int res = file_read(&c, 1, 1, file);
                    test_error(res == 1, "Funkcja file_read() powinna zwrócić wartość 1, a zwróciła %d", res);
                    onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
                    test_error(c == expected_filecontent[i], "Funkcja file_read() powinna odczytać w kroku %d znak %c, a odczytała znak %c", i, expected_filecontent[i], c);
                }

                file_close(file);
                fat_close(volume);
                disk_close(disk);

                test_no_heap_leakage();
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
            
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 56: Sprawdzanie poprawności działania funkcji file_read
//
void UTEST56(void)
{
    // informacje o teście
    test_start(56, "Sprawdzanie poprawności działania funkcji file_read", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

                char expected_filecontent[13] = "";

                strcat(expected_filecontent, "est th\' accu");

                struct disk_t* disk = disk_open_from_file("see_fat16_volume.img");
                test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct volume_t* volume = fat_open(disk, 0);
                test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct file_t* file = file_open(volume, "\\OR\\iS.BIN");
                test_error(file != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                for (int i = 0; i < 12; ++i)
                {
                    char c;
                    int res = file_read(&c, 1, 1, file);
                    test_error(res == 1, "Funkcja file_read() powinna zwrócić wartość 1, a zwróciła %d", res);
                    onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
                    test_error(c == expected_filecontent[i], "Funkcja file_read() powinna odczytać w kroku %d znak %c, a odczytała znak %c", i, expected_filecontent[i], c);
                }

                file_close(file);
                fat_close(volume);
                disk_close(disk);

                test_no_heap_leakage();
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
            
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 57: Sprawdzanie poprawności działania funkcji file_read
//
void UTEST57(void)
{
    // informacje o teście
    test_start(57, "Sprawdzanie poprawności działania funkcji file_read", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

                char expected_filecontent[400] = "";

                strcat(expected_filecontent, "nd port.\nThen still my sight pursuing its career,\nAnother I beheld, than blood more red.\nA goose display of whiter wing than curd.\nAnd one, who bore a fat and azure swine\nPictur\'d on his white scrip, addressed me thus:\n\"What dost thou in this deep?  Go now and know,\nSince yet thou livest, that my neighbour here\nVitaliano on my left shall sit.\nA Paduan with these Florentines am I.\nOfttimes they th");

                struct disk_t* disk = disk_open_from_file("see_fat16_volume.img");
                test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct volume_t* volume = fat_open(disk, 0);
                test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct file_t* file = file_open(volume, "\\OR\\Supply StArt gReat bOAt.LAD");
                test_error(file != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                for (int i = 0; i < 399; ++i)
                {
                    char c;
                    int res = file_read(&c, 1, 1, file);
                    test_error(res == 1, "Funkcja file_read() powinna zwrócić wartość 1, a zwróciła %d", res);
                    onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
                    test_error(c == expected_filecontent[i], "Funkcja file_read() powinna odczytać w kroku %d znak %c, a odczytała znak %c", i, expected_filecontent[i], c);
                }

                file_close(file);
                fat_close(volume);
                disk_close(disk);

                test_no_heap_leakage();
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
            
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 58: Sprawdzanie poprawności działania funkcji file_read
//
void UTEST58(void)
{
    // informacje o teście
    test_start(58, "Sprawdzanie poprawności działania funkcji file_read", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

                char expected_filecontent[327] = "";

                strcat(expected_filecontent, "he flame\nIn dolour parted, beating to and fro,\nAnd writhing its sharp horn.  We onward went,\nI and my leader, up along the rock,\nFar as another arch, that overhangs\nThe foss, wherein the penalty is paid\nOf those, who load them with committed sin.\n\n\n\nCANTO XXVIII\n\nWHO, e\'en in words unfetter\'d, might at full\nTell of the wound");

                struct disk_t* disk = disk_open_from_file("see_fat16_volume.img");
                test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct volume_t* volume = fat_open(disk, 0);
                test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct file_t* file = file_open(volume, "\\OR\\HIM");
                test_error(file != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                for (int i = 0; i < 326; ++i)
                {
                    char c;
                    int res = file_read(&c, 1, 1, file);
                    test_error(res == 1, "Funkcja file_read() powinna zwrócić wartość 1, a zwróciła %d", res);
                    onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
                    test_error(c == expected_filecontent[i], "Funkcja file_read() powinna odczytać w kroku %d znak %c, a odczytała znak %c", i, expected_filecontent[i], c);
                }

                file_close(file);
                fat_close(volume);
                disk_close(disk);

                test_no_heap_leakage();
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
            
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 59: Sprawdzanie poprawności działania funkcji file_read
//
void UTEST59(void)
{
    // informacje o teście
    test_start(59, "Sprawdzanie poprawności działania funkcji file_read", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

                char expected_filecontent[2307] = "";

                strcat(expected_filecontent, "gain.\n     \"Expect that by such stairs as these,\" thus spake\nThe teacher, panting like a man forespent,\n\"We must depart from evil so extreme.\"\nThen at a rocky opening issued forth,\nAnd plac\'d me on a brink to sit, next join\'d\nWith wary step my side.  I rais\'d mine eyes,\nBelieving that I Lucifer should see\nWhere he was lately left, but saw him now\nWith legs held upward.  Let the grosser sort,\nWho see not what the point was I had pass\'d,\nBethink them if sore toil oppress\'d me then.\n     \"Arise,\" my master cried, \"upon thy feet.\n\"The way is long, and much uncouth the road;\nAnd now within one hour and half of noon\nThe sun returns.\"  It was no palace-hall\nLofty and luminous wherein we stood,\nBut natural dungeon where ill footing was\nAnd scant supply of light.  \"Ere from th\' abyss\nI sep\'rate,\" thus when risen I began,\n\"My guide!  vouchsafe few words to set me free\nFrom error\'s thralldom.  Where is now the ice?\nHow standeth he in posture thus revers\'d?\nAnd how from eve to morn in space so brief\nHath the sun made his transit?\"  He in few\nThus answering spake:  \"Thou deemest thou art still\nOn th\' other side the centre, where I grasp\'d\nTh\' abhorred worm, that boreth through the world.\nThou wast on th\' other side, so long as I\nDescended; when I turn\'d, thou didst o\'erpass\nThat point, to which from ev\'ry part is dragg\'d\nAll heavy substance.  Thou art now arriv\'d\nUnder the hemisphere opposed to that,\nWhich the great continent doth overspread,\nAnd underneath whose canopy expir\'d\nThe Man, that was born sinless, and so liv\'d.\nThy feet are planted on the smallest sphere,\nWhose other aspect is Judecca.  Morn\nHere rises, when there evening sets:  and he,\nWhose shaggy pile was scal\'d, yet standeth fix\'d,\nAs at the first.  On this part he fell down\nFrom heav\'n; and th\' earth, here prominent before,\nThrough fear of him did veil her with the sea,\nAnd to our hemisphere retir\'d.  Perchance\nTo shun him was the vacant space left here\nBy what of firm land on this side appears,\nThat sprang aloof.\"  There is a place beneath,\nFrom Belzebub as distant, as extends\nThe vaulted tomb, discover\'d not by sight,\nBut by the sound of brooklet, that descends\nThis way along the hollow of a rock,\nWhich, as it winds with no precipitous course,\nThe wave hath eaten.  By that hidden way\nMy guide and I did enter, ");

                struct disk_t* disk = disk_open_from_file("see_fat16_volume.img");
                test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct volume_t* volume = fat_open(disk, 0);
                test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct file_t* file = file_open(volume, "\\OR\\ReCeiVE.TX");
                test_error(file != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                for (int i = 0; i < 2306; ++i)
                {
                    char c;
                    int res = file_read(&c, 1, 1, file);
                    test_error(res == 1, "Funkcja file_read() powinna zwrócić wartość 1, a zwróciła %d", res);
                    onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
                    test_error(c == expected_filecontent[i], "Funkcja file_read() powinna odczytać w kroku %d znak %c, a odczytała znak %c", i, expected_filecontent[i], c);
                }

                file_close(file);
                fat_close(volume);
                disk_close(disk);

                test_no_heap_leakage();
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
            
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 60: Sprawdzanie poprawności działania funkcji file_read
//
void UTEST60(void)
{
    // informacje o teście
    test_start(60, "Sprawdzanie poprawności działania funkcji file_read", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

                char expected_filecontent[72] = "";

                strcat(expected_filecontent, "ou wouldst,\nWho of this light is denizen, that here\nBeside me sparkles,");

                struct disk_t* disk = disk_open_from_file("see_fat16_volume.img");
                test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct volume_t* volume = fat_open(disk, 0);
                test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct file_t* file = file_open(volume, "\\OR\\LAST");
                test_error(file != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                for (int i = 0; i < 71; ++i)
                {
                    char c;
                    int res = file_read(&c, 1, 1, file);
                    test_error(res == 1, "Funkcja file_read() powinna zwrócić wartość 1, a zwróciła %d", res);
                    onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
                    test_error(c == expected_filecontent[i], "Funkcja file_read() powinna odczytać w kroku %d znak %c, a odczytała znak %c", i, expected_filecontent[i], c);
                }

                file_close(file);
                fat_close(volume);
                disk_close(disk);

                test_no_heap_leakage();
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
            
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 61: Sprawdzanie poprawności działania funkcji file_read
//
void UTEST61(void)
{
    // informacje o teście
    test_start(61, "Sprawdzanie poprawności działania funkcji file_read", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

                char expected_filecontent[3073] = "";

                strcat(expected_filecontent, "ich John the Baptist was the\npatron saint.\n\nv. 31.  From the day.]  From the Incarnation to the birth of\nCacciaguida, the planet Mars had returned five hundred and\nfifty-three times to the constellation of Leo, with which it is\nsupposed to have a congenial influence.  His birth may,\ntherefore, be placed about 1106.\n\nv. 38.  The last.]  The city was divided into four compartments.\nThe Elisei, the ancestors of Dante, resided near the entrance of\nthat named from the Porta S. Piero, which was the last reached by\nthe competitor in the annual race at Florence.  See G. Villani,\n1.  iv. c.  10.\n\nv. 44.  From Mars.]  \"Both in the times of heathenish and of\nChristianity.\"  Hell, Canto XIII. 144.\n\nv. 48.  Campi and Certaldo and Fighine.]  Country places near\nFlorence.\n\nv. 50.  That these people.]  That the inhabitants of the above-\nmentioned places had not been mixed with the citizens: nor the\nlimits of Florence extended beyond Galluzzo and Trespiano.\"\n\nv. 54.  Aguglione\'s hind and Signa\'s.]  Baldo of Aguglione, and\nBonifazio of Signa.\n\nv. 56.  Had not the people.]  If Rome had continued in her\nallegiance to the emperor, and the Guelph and Ghibelline factions\nhad thus been prevented, Florence would not have been polluted by\na race of upstarts, nor lost the most respectable of her ancient\nfamilies.\n\nv. 61.  Simifonte.]  A castle dismantled by the Florentines.  G.\nVillani, 1. v. c. 30.  The individual here alluded to is no\nlonger known.\n\nv. 69.  The blind bull.]  So Chaucer, Troilus and Cresseide. b.\n2.\n\nFor swifter course cometh thing that is of wight\nWhen it descendeth than done things light.\n\nCompare Aristotle, Ethic.  Nic. l. vi.  c. 13.  [GREEK HERE]\n\nv. 72.  Luni, Urbisaglia.]  Cities formerly of importance, but\nthen fallen to decay.\n\nv. 74.  Chiusi and Sinigaglia.]  The same.\n\nv. 80.  As the moon.]  \"The fortune of us, that are the moon\'s\nmen doth ebb and flow like the sea.\"  Shakespeare, 1 Henry IV.\na. i. s. 2.\n\nv. 86.  The Ughi.]  Whoever is curious to know the habitations of\nthese and the other ancient Florentines, may consult G. Villani,\nl. iv.\n\nv. 91.  At the poop.]  Many editions read porta, \"gate.\" -The\nsame metaphor is found in Aeschylus, Supp. 356, and is there also\nscarce understood by the critics. [GREEK HERE] Respect these\nwreaths, that crown your city\'s poop.\n\nv. 99.  The gilded hilt and pommel.]  The symbols of knighthood\n\nv. 100.  The column cloth\'d with verrey.]  The arms of the Pigli.\n\nv. 103.  With them.]  Either the Chiaramontesi, or the Tosinghi\none of which had committed a fraud in measuring out the wheat\nfrom the public granary.  See Purgatory, Canto XII.  99\n\nv. 109.  The bullets of bright gold.]  The arms of the Abbati, as\nit is conjectured.\n\nv. 110.  The sires of those.]  \"Of the Visdomini, the Tosinghi\nand the Cortigiani, who, being sprung from the founders of the\nbishopric of Florence are the curators of its revenues, which\nthey do not spare, whenever it becomes vacant.\"\n\nv. 113.  Th\' o\'erweening brood.]  The Adimari.  This family was\nso little esteemed, that Ubertino Donato, who had married a\nda");

                struct disk_t* disk = disk_open_from_file("see_fat16_volume.img");
                test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct volume_t* volume = fat_open(disk, 0);
                test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct file_t* file = file_open(volume, "\\oR\\gAs.biN");
                test_error(file != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                for (int i = 0; i < 3072; ++i)
                {
                    char c;
                    int res = file_read(&c, 1, 1, file);
                    test_error(res == 1, "Funkcja file_read() powinna zwrócić wartość 1, a zwróciła %d", res);
                    onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
                    test_error(c == expected_filecontent[i], "Funkcja file_read() powinna odczytać w kroku %d znak %c, a odczytała znak %c", i, expected_filecontent[i], c);
                }

                file_close(file);
                fat_close(volume);
                disk_close(disk);

                test_no_heap_leakage();
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
            
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 62: Sprawdzanie poprawności działania funkcji file_read
//
void UTEST62(void)
{
    // informacje o teście
    test_start(62, "Sprawdzanie poprawności działania funkcji file_read", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

                char expected_filecontent[3558] = "";

                strcat(expected_filecontent, " Pisans\n\nv. 61.  Thy grandson.]  Fulcieri de\' Calboli, grandson of\nRinieri de\' Calboli, who is here spoken to.  The atrocities\npredicted came to pass in 1302.  See G. Villani, 1.  viii c. 59\n\nv. 95.  \'Twixt Po, the mount, the Reno, and the shore.]  The\nboundaries of Romagna.\n\nv. 99.  Lizio.]  Lizio da Valbona, introduced into Boccaccio\'s\nDecameron, G. v. N, 4.\n\nv. 100.  Manardi, Traversaro, and Carpigna.1 Arrigo Manardi of\nFaenza, or as some say, of Brettinoro, Pier Traversaro, lord of\nRavenna, and Guido di Carpigna of Montefeltro.\n\nv. 102.  In Bologna the low artisan.]  One who had been a\nmechanic named Lambertaccio, arrived at almost supreme power in\nBologna.\n\nv. 103.  Yon Bernardin.]  Bernardin di Fosco, a man of low\norigin but great talents, who governed at Faenza.\n\nv. 107.  Prata.]  A place between Faenza and Ravenna\n\nv. 107.  Of Azzo him.] Ugolino of the Ubaldini family in Tuscany\nHe is recounted among the poets by Crescimbeni and Tiraboschi.\n\nv. 108.  Tignoso.] Federigo Tignoso of Rimini.\n\nv. 109.  Traversaro\'s house and Anastagio\'s.]  Two noble families\nof Ravenna.  She to whom Dryden has given the name of Honoria, in\nthe fable so admirably paraphrased from Boccaccio, was of the\nformer: her lover and the specter were of the Anastagi family.\n\nv. 111.  The ladies, &c.]  These two lines express the true\nspirit of chivalry.  \"Agi\" is understood by the commentators whom\nI have consulted,to mean \"the ease procured for others by the\nexertions of knight-errantry.\"  But surely it signifies the\nalternation of ease with labour.\n\nv. 114.  O Brettinoro.]  A beautifully situated castle in\nRomagna, the hospitable residence of Guido del Duca, who is here\nspeaking.\n\nv. 118.  Baynacavallo.]  A castle between Imola and Ravenna\n\nv. 118.  Castracaro ill\nAnd Conio worse.]  Both in Romagna.\n\nv. 121.  Pagani.]  The Pagani were lords of Faenza and Imola. One\nof them Machinardo, was named the Demon, from his treachery.\nSee Hell, Canto XXVII. 47, and Note.\n\nv. 124.  Hugolin.]  Ugolino Ubaldini, a noble and virtuous person\nin Faenza, who, on account of his age probably, was not likely to\nleave any offspring behind him.  He is enumerated among the poets\nby Crescimbeni, and Tiraboschi.  Mr. Matthias\'s edit. vol. i. 143\n\nv. 136.  Whosoever finds Will slay me.] The words of Cain, Gen.\ne. iv. 14.\n\nv. 142.  Aglauros.]  Ovid, Met.  I, ii.  fate. 12.\n\nv. 145.  There was the galling bit.]  Referring to what had been\nbefore said, Canto XIII.  35.\n\nCANTO XV\n\nv. 1.  As much.]  It wanted three hours of sunset.\n\nv. 16.  As when the ray.]  Compare Virg. Aen. 1.viii. 22, and\nApol. Rhod. 1. iii. 755.\n\nv. 19.  Ascending at a glance.]  Lucretius, 1. iv. 215.\n\nv. 20.  Differs from the stone.]  The motion of light being\nquicker  than that of a stone through an equal space.\n\nv. 38.  Blessed the merciful.  Matt. c. v. 7.\n\nv. 43.  Romagna\'s spirit.] Guido del Duea, of Brettinoro whom we\nhave seen in the preceding Canto.\n\nv. 87.  A dame.]  Luke, c. ii.  18\n\nv. 101.  How shall we those requite.]  The answer of Pisistratus\nthe tyrant to his wife, when she urged him to inflict the\npunishment of death on a young man, who, inflamed with love for\nhis daughter, had snatched from her a kiss in public.  The story\nis told by Valerius Maximus, 1.v. 1.\n\nv. 105.  A stripling youth.]  The protomartyr Stephen.\n\nCANTO XVI\n\nv. 94.  As thou.]  \"If thou wert still living.\"\n\nv. 46.  I was of Lombardy, and Marco call\'d.]  A Venetian\ngentleman. \"Lombardo\" both was his surname and denoted the\ncountry to which he belonged. G. Villani, 1. vii. c. 120, terms\nhim");

                struct disk_t* disk = disk_open_from_file("see_fat16_volume.img");
                test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct volume_t* volume = fat_open(disk, 0);
                test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct file_t* file = file_open(volume, "\\Or\\NuMBeR.TX");
                test_error(file != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                for (int i = 0; i < 3557; ++i)
                {
                    char c;
                    int res = file_read(&c, 1, 1, file);
                    test_error(res == 1, "Funkcja file_read() powinna zwrócić wartość 1, a zwróciła %d", res);
                    onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
                    test_error(c == expected_filecontent[i], "Funkcja file_read() powinna odczytać w kroku %d znak %c, a odczytała znak %c", i, expected_filecontent[i], c);
                }

                file_close(file);
                fat_close(volume);
                disk_close(disk);

                test_no_heap_leakage();
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
            
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 63: Sprawdzanie poprawności działania funkcji file_read
//
void UTEST63(void)
{
    // informacje o teście
    test_start(63, "Sprawdzanie poprawności działania funkcji file_read", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

                char expected_filecontent[2881] = "";

                strcat(expected_filecontent, "dle play.\"\n     Such were the words that Beatrice spake:\nThese ended, to that region, where the world\nIs liveliest, full of fond desire she turn\'d.\n     Though mainly prompt new question to propose,\nHer silence and chang\'d look did keep me dumb.\nAnd as the arrow, ere the cord is still,\nLeapeth unto its mark; so on we sped\nInto the second realm.  There I beheld\nThe dame, so joyous enter, that the orb\nGrew brighter at her smiles; and, if the star\nWere mov\'d to gladness, what then was my cheer,\nWhom nature hath made apt for every change!\n     As in a quiet and clear lake the fish,\nIf aught approach them from without, do draw\nTowards it, deeming it their food; so drew\nFull more than thousand splendours towards us,\nAnd in each one was heard:  \"Lo!  one arriv\'d\nTo multiply our loves!\" and as each came\nThe shadow, streaming forth effulgence new,\nWitness\'d augmented joy.  Here, reader!  think,\nIf thou didst miss the sequel of my tale,\nTo know the rest how sorely thou wouldst crave;\nAnd thou shalt see what vehement desire\nPossess\'d me, as soon as these had met my view,\nTo know their state.  \"O born in happy hour!\nThou to whom grace vouchsafes, or ere thy close\nOf fleshly warfare, to behold the thrones\nOf that eternal triumph, know to us\nThe light communicated, which through heaven\nExpatiates without bound.  Therefore, if aught\nThou of our beams wouldst borrow for thine aid,\nSpare not; and of our radiance take thy fill.\"\n     Thus of those piteous spirits one bespake me;\nAnd Beatrice next:  \"Say on; and trust\nAs unto gods!\" --\"How in the light supreme\nThou harbour\'st, and from thence the virtue bring\'st,\nThat, sparkling in thine eyes, denotes thy joy,\nl mark; but, who thou art, am still to seek;\nOr wherefore, worthy spirit!  for thy lot\nThis sphere assign\'d, that oft from mortal ken\nIs veil\'d by others\' beams.\"  I said, and turn\'d\nToward the lustre, that with greeting, kind\nErewhile had hail\'d me.  Forthwith brighter far\nThan erst, it wax\'d:  and, as himself the sun\nHides through excess of light, when his warm gaze\nHath on the mantle of thick vapours prey\'d;\nWithin its proper ray the saintly shape\nWas, through increase of gladness, thus conceal\'d;\nAnd, shrouded so in splendour answer\'d me,\nE\'en as the tenour of my song declares.\n\n\n\nCANTO VI\n\n\"After that Constantine the eagle turn\'d\nAgainst the motions of the heav\'n, that roll\'d\nConsenting with its course, when he of yore,\nLavinia\'s spouse, was leader of the flight,\nA hundred years twice told and more, his seat\nAt Europe\'s extreme point, the bird of Jove\nHeld, near the mountains, whence he issued first.\nThere, under shadow of his sacred plumes\nSwaying the world, till through successive hands\nTo mine he came devolv\'d.  Caesar I was,\nAnd am Justinian; destin\'d by the will\nOf that prime love, whose influence I feel,\nFrom vain excess to clear th\' encumber\'d laws.\nOr ere that work engag\'d me, I");

                struct disk_t* disk = disk_open_from_file("see_fat16_volume.img");
                test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct volume_t* volume = fat_open(disk, 0);
                test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct file_t* file = file_open(volume, "\\OR\\Kill month BrighT Of RoUnd.Rge");
                test_error(file != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                for (int i = 0; i < 2880; ++i)
                {
                    char c;
                    int res = file_read(&c, 1, 1, file);
                    test_error(res == 1, "Funkcja file_read() powinna zwrócić wartość 1, a zwróciła %d", res);
                    onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
                    test_error(c == expected_filecontent[i], "Funkcja file_read() powinna odczytać w kroku %d znak %c, a odczytała znak %c", i, expected_filecontent[i], c);
                }

                file_close(file);
                fat_close(volume);
                disk_close(disk);

                test_no_heap_leakage();
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
            
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 64: Sprawdzanie poprawności działania funkcji file_read
//
void UTEST64(void)
{
    // informacje o teście
    test_start(64, "Sprawdzanie poprawności działania funkcji file_read", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

                char expected_filecontent[2244] = "";

                strcat(expected_filecontent, "  says Villani, Hist.\nl. vii. c14, \"put himself at the head of the people, in the hopes\nof rising into power, not aware that the result would be mischief\nto the Ghibelline party, and his own ruin; an event which seems\never to have befallen him, who has headed the populace in\nFlorence.\" A.D. 1266.\n\nv. 119.  Ganellon.]  The betrayer of Charlemain, mentioned by\nArchbishop Turpin.  He is a common instance of treachery with the\npoets of the middle ages.\n        Trop son fol e mal pensant,\n        Pis valent que Guenelon.\n               Thibaut, roi de Navarre\n        O new Scariot, and new Ganilion,\n        O false dissembler, &c.\n               Chaucer, Nonne\'s Prieste\'s Tale\nAnd in the Monke\'s Tale, Peter of Spaine.\nv. 119.  Tribaldello.]  Tribaldello de\'Manfredi, who was bribed\nto betray the city of Faonza, A. D. 1282. G. Villani, l. vii. c.\n80\n\nv. 128.  Tydeus.] See Statius, Theb. l. viii. ad finem.\n\nCANTO XXXIII.\n\nv. 14.  Count Ugolino.]  \"In the year 1288, in the month of July,\nPisa was much divided by competitors for the sovereignty; one\nparty, composed of certain of the Guelphi, being headed by the\nJudge Nino di Gallura de\'Visconti; another, consisting of others\nof the same faction, by the Count Ugolino de\' Gherardeschi; and\nthe third by the Archbishop Ruggieri degli Ubaldini, with the\nLanfranchi, Sismondi, Gualandi, and other Ghibelline houses.  The\nCount Ugolino,to effect his purpose, united with the Archbishop\nand his party, and having betrayed Nino, his sister\'s son, they\ncontrived that he and his followers should either be driven out\nof Pisa, or their persons seized.  Nino hearing this, and not\nseeing any means of defending himself, retired to Calci, his\ncastle, and formed an alliance with the Florentines and people of\nLucca, against the Pisans.  The Count, before Nino was gone, in\norder to cover his treachery, when everything was settled for his\nexpulsion, quitted Pisa, and repaired to a manor of his called\nSettimo; whence, as soon as he was informed of Nino\'s departure,\nhe returned to Pisa with great rejoicing and festivity, and was\nelevated to the supreme power with every demonstration of triumph\nand honour.  But his greatness was not of long continuauce.  It\npleased the Almighty that a total ");

                struct disk_t* disk = disk_open_from_file("see_fat16_volume.img");
                test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct volume_t* volume = fat_open(disk, 0);
                test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct file_t* file = file_open(volume, "\\OR\\lENgTH.Txt");
                test_error(file != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                for (int i = 0; i < 2243; ++i)
                {
                    char c;
                    int res = file_read(&c, 1, 1, file);
                    test_error(res == 1, "Funkcja file_read() powinna zwrócić wartość 1, a zwróciła %d", res);
                    onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
                    test_error(c == expected_filecontent[i], "Funkcja file_read() powinna odczytać w kroku %d znak %c, a odczytała znak %c", i, expected_filecontent[i], c);
                }

                file_close(file);
                fat_close(volume);
                disk_close(disk);

                test_no_heap_leakage();
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
            
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 65: Sprawdzanie poprawności działania funkcji file_read
//
void UTEST65(void)
{
    // informacje o teście
    test_start(65, "Sprawdzanie poprawności działania funkcji file_read", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    
            char *filecontent = (char *)calloc(1924, 1);
            char expected_filecontent[1925] = "";

            strcat(expected_filecontent, "di, king of Naples and Sicily, is\ndefeated and slain by Charles of Anjou.  Hell, C. XXVIII. 13.\nAnd Purgatory, C. III. 110.\n\nGuido Novello of Polenta obtains the sovereignty of Ravenna.\nH. C. XXVII. 38.\n\n1266.  Two of the Frati Godenti chosen arbitrators of the\ndifferences at Florence.  H. C. XXIII. 104.\nGianni de\' Soldanieri heads the populace in that city.  H. C.\nXXXII. 118.\n\n1268.  Charles of Anjou puts Conradine to death, and becomes King\nof Naples.  H. C. XXVIII. 16 and Purg C. XX. 66.\n\n1272.  Henry III. of England is succeeded by Edward I. Purg. C.\nVII. 129.\n\n1274.  Our Poet first sees Beatrice, daughter of Folco Portinari.\n\nFra.\nGuittone d\'Arezzo, the poet, dies.  Purg. C. XXIV. 56.\nThomas Aquinas dies.  Purg. C. XX. 67.  and Par. C. X. 96.\nBuonaventura dies.  Par. C. XII. 25.\n\n1275.  Pierre de la Brosse, secretary to Philip III. of France,\nexecuted.  Purg. C. VI. 23.\n\n1276.  Giotto, the painter, is born.  Purg. C. XI. 95.  Pope\nAdrian V. dies.  Purg. C. XIX. 97.\nGuido Guinicelli, the poet, dies.  Purg. C. XI. 96. and C. XXVI.\n83.\n\n1277.  Pope John XXI.  dies.  Par. C. XII. 126.\n\n1278.  Ottocar, king of Bohemia, dies.  Purg. C. VII. 97.\n\n1279.  Dionysius succeeds to the throne of Portugal.  Par. C.\nXIX. 135.\n\n1280.  Albertus Magnus dies.  Par. C. X. 95.\n\n1281.  Pope Nicholas III. dies.  H. C. XIX 71.\nDante studies at the universities of Bologna and Padua.\n\n1282.  The Sicilian vespers.  Par. C. VIII. 80.\nThe French defeated by the people of Forli.  H. C. XXVII. 41.\nTribaldello de\' Manfredi betrays the city of Faenza.  H. C.\nXXXII. 119.\n\n1284.  Prince Charles of Anjou is defeated and made prisoner by\nRugiez\nde Lauria, admiral to Peter III. of Arragon.  Purg. C. XX. 78.\nCharles I.  king of Naples, dies.  Purg. C. VII. 111.\n\n1285.  Pope Martin IV.  dies.  Purg. C. XXIV. 23.\nPhilip III.  of France, and Peter III.  of Arragon, die. Purg. C.\nVII. 101 and\n110.\nHenry II. king of Cyprus, comes ");

            struct disk_t* disk = disk_open_from_file("see_fat16_volume.img");
            test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

            struct volume_t* volume = fat_open(disk, 0);
            test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

            struct file_t* file = file_open(volume, "EqUaL.TX");
            test_error(file != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

            int i;
            for (i = 0; i < 137; ++i)
            {
                int res = file_read(filecontent + 14 * i, 14, 1, file);
                test_error(res == 1, "Funkcja file_read() powinna zwrócić wartość 1, a zwróciła %d", res);
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
            }

            int res = file_read(filecontent + 14 * i, 14, 1, file);
            test_error(res == 0, "Funkcja file_read() powinna zwrócić wartość 0, a zwróciła %d", res);
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

            int diff_pos = mem_find_first_difference(filecontent, expected_filecontent, 1924);

            // jeśli jest, to raportuj błąd
            test_error(diff_pos == -1, "Dane wczytane z pliku nie są poprawne; różnica w bajcie %d; jest 0x%02x a powinno być 0x%02x",
                diff_pos, mem_get_byte(filecontent, diff_pos), mem_get_byte(expected_filecontent, diff_pos));

            onerror_compare_memory(expected_filecontent, filecontent, 1924);

            free(filecontent);
            file_close(file);
            fat_close(volume);
            disk_close(disk);

            test_no_heap_leakage();
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
        
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 66: Sprawdzanie poprawności działania funkcji file_read
//
void UTEST66(void)
{
    // informacje o teście
    test_start(66, "Sprawdzanie poprawności działania funkcji file_read", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

            char *filecontent0 = (char *)calloc(1958, 1);
    char *filecontent1 = (char *)calloc(419, 1);
    char *filecontent2 = (char *)calloc(2667, 1);
    char *filecontent3 = (char *)calloc(2750, 1);
    char *filecontent4 = (char *)calloc(1924, 1);
    char *filecontent5 = (char *)calloc(2048, 1);
    char *filecontent6 = (char *)calloc(3356, 1);
    char *filecontent7 = (char *)calloc(88, 1);
    char *filecontent8 = (char *)calloc(157, 1);

            char expected_filecontent0[1959] = "";
    char expected_filecontent1[420] = "";
    char expected_filecontent2[2668] = "";
    char expected_filecontent3[2751] = "";
    char expected_filecontent4[1925] = "";
    char expected_filecontent5[2049] = "";
    char expected_filecontent6[3357] = "";
    char expected_filecontent7[89] = "";
    char expected_filecontent8[158] = "";

            strcat(expected_filecontent0, "it leads thee up\nAlong this ladder, down whose hallow\'d steps\nNone e\'er descend, and mount them not again,\nWho from his phial should refuse thee wine\nTo slake thy thirst, no less constrained were,\nThan water flowing not unto the sea.\nThou fain wouldst hear, what plants are these, that bloom\nIn the bright garland, which, admiring, girds\nThis fair dame round, who strengthens thee for heav\'n.\nI then was of the lambs, that Dominic\nLeads, for his saintly flock, along the way,\nWhere well they thrive, not sworn with vanity.\nHe, nearest on my right hand, brother was,\nAnd master to me:  Albert of Cologne\nIs this:  and of Aquinum, Thomas I.\nIf thou of all the rest wouldst be assur\'d,\nLet thine eye, waiting on the words I speak,\nIn circuit journey round the blessed wreath.\nThat next resplendence issues from the smile\nOf Gratian, who to either forum lent\nSuch help, as favour wins in Paradise.\nThe other, nearest, who adorns our quire,\nWas Peter, he that with the widow gave\nTo holy church his treasure.  The fifth light,\nGoodliest of all, is by such love inspired,\nThat all your world craves tidings of its doom:\nWithin, there is the lofty light, endow\'d\nWith sapience so profound, if truth be truth,\nThat with a ken of such wide amplitude\nNo second hath arisen.  Next behold\nThat taper\'s radiance, to whose view was shown,\nClearliest, the nature and the ministry\nAngelical, while yet in flesh it dwelt.\nIn the other little light serenely smiles\nThat pleader for the Christian temples, he\nWho did provide Augustin of his lore.\nNow, if thy mind\'s eye pass from light to light,\nUpon my praises following, of the eighth\nThy thirst is next.  The saintly soul, that shows\nThe world\'s deceitfulness, to all who hear him,\nIs, with the sight of all the good, that is,\nBlest there.  The limbs, whence it was driven, lie\nDown in Cieldauro, and from martyrdom\nAnd exile came it here.  Lo!  further on,\nWhere flames the arduous Spirit of Isidore,\nOf Bede, and Richard, ");strcat(expected_filecontent1, "The damsels turn\'d; and on the Gryphon mov\'d\nThe sacred burden, with a pace so smooth,\nNo feather on him trembled.  The fair dame\nWho through the wave had drawn me, companied\nBy Statius and myself, pursued the wheel,\nWhose orbit, rolling, mark\'d a lesser arch.\n     Through the high wood, now void (the more her blame,\nWho by the serpent was beguil\'d) I past\nWith step in cadence to the harmony\nAngelic.  Onward had we ");strcat(expected_filecontent2, "them whate\'er thou list.\"\n     And I therewith began:  \"So may no time\nFilch your remembrance from the thoughts of men\nIn th\' upper world, but after many suns\nSurvive it, as ye tell me, who ye are,\nAnd of what race ye come.  Your punishment,\nUnseemly and disgustful in its kind,\nDeter you not from opening thus much to me.\"\n     \"Arezzo was my dwelling,\" answer\'d one,\n\"And me Albero of Sienna brought\nTo die by fire; but that, for which I died,\nLeads me not here.  True is in sport I told him,\nThat I had learn\'d to wing my flight in air.\nAnd he admiring much, as he was void\nOf wisdom, will\'d me to declare to him\nThe secret of mine art:  and only hence,\nBecause I made him not a Daedalus,\nPrevail\'d on one suppos\'d his sire to burn me.\nBut Minos to this chasm last of the ten,\nFor that I practis\'d alchemy on earth,\nHas doom\'d me.  Him no subterfuge eludes.\"\n     Then to the bard I spake:  \"Was ever race\nLight as Sienna\'s?  Sure not France herself\nCan show a tribe so frivolous and vain.\"\n     The other leprous spirit heard my words,\nAnd thus return\'d:  \"Be Stricca from this charge\nExempted, he who knew so temp\'rately\nTo lay out fortune\'s gifts; and Niccolo\nWho first the spice\'s costly luxury\nDiscover\'d in that garden, where such seed\nRoots deepest in the soil:  and be that troop\nExempted, with whom Caccia of Asciano\nLavish\'d his vineyards and wide-spreading woods,\nAnd his rare wisdom Abbagliato show\'d\nA spectacle for all.  That thou mayst know\nWho seconds thee against the Siennese\nThus gladly, bend this way thy sharpen\'d sight,\nThat well my face may answer to thy ken;\nSo shalt thou see I am Capocchio\'s ghost,\nWho forg\'d transmuted metals by the power\nOf alchemy; and if I scan thee right,\nThus needs must well remember how I aped\nCreative nature by my subtle art.\"\n\n\n\nCANTO XXX\n\nWHAT time resentment burn\'d in Juno\'s breast\nFor Semele against the Theban blood,\nAs more than once in dire mischance was rued,\nSuch fatal frenzy seiz\'d on Athamas,\nThat he his spouse beholding with a babe\nLaden on either arm, \"Spread out,\" he cried,\n\"The meshes, that I take the lioness\nAnd the young lions at the pass:  \"then forth\nStretch\'d he his merciless talons, grasping one,\nOne helpless innocent, Learchus nam\'d,\nWhom swinging down he dash\'d upon a rock,\nAnd with her other burden self-destroy\'d\nThe hapless mother plung\'d:  and when the pride\nOf all-presuming Troy fell from its height,\nBy fortune overwhelm\'d, and the old king\nWith his realm perish\'d, then did Hecuba,\nA wretch forlorn and captive, when she saw\nPolyxena first slaughter\'d, and her son,\nHer Polydorus, on the wild sea-beach\nNext met the mourner\'s view, then reft of sense\nDid she run barking ");strcat(expected_filecontent3, "son for which supposed crime he suffered\ndeath. So say the Italian commentators.  Henault represents the\nmatter very differently: \"Pierre de la Brosse, formerly barber to\nSt. Louis, afterwards the favorite of Philip, fearing the too\ngreat attachment of the king for his wife Mary, accuses this\nprincess of having poisoned Louis, eldest son of Philip, by his\nfirst marriage. This calumny is discovered by a nun of Nivelle in\nFlanders.  La Brosse is hung.\" Abrege Chron. t. 275, &c.\n\nv. 30.  In thy text.]  He refers to Virgil, Aen. 1, vi.  376.\nDesine fata deum flecti sperare precando, 37. The sacred height\nOf judgment. Shakespeare, Measure for Measure, a. ii. s. 2.\nIf he, which is the top of judgment\n\nv. 66.  Eyeing us as a lion on his watch.]\nA guisa di Leon quando si posa.\nA line taken by Tasso, G.  L. c. x. st. 56.\n\nv. 76.  Sordello.]  The history of Sordello\'s life is wrapt in\nthe obscurity of romance.  That he distinguished himself by his\nskill in Provencal poetry is certain. It is probable that he was\nborn towards the end of the twelfth, and died about the middle of\nthe succeeding century.  Tiraboschi has taken much pains to sift\nall the notices he could collect relating to him.  Honourable\nmention of his name is made by our Poet in the Treatise de Vulg.\nEloq.  1. i. c. 15.\n\nv. 76.  Thou inn of grief.]\nThou most beauteous inn\nWhy should hard-favour\'d grief be lodg\'d in thee?\nShakespeare, Richard II a. 5. s. 1.\n\nv. 89.  Justinian\'s hand.]  \"What avails it that Justinian\ndelivered thee from the Goths, and reformed thy laws, if thou art\nno longer under the control of his successors in the empire?\"\n\nv. 94.  That which God commands.]  He alludes to the precept-\n\"Render unto Caesar the things which are Caesar\'s.\"\n\nv. 98.  O German Albert!]  The Emperor Albert I. succeeded\nAdolphus in 1298, and was murdered in 1308.  See Par Canto XIX\n114 v. 103.  Thy successor.]  The successor of Albert was Henry\nof Luxembourg, by whose interposition in the affairs of Italy our\nPoet hoped to have been reinstated in his native city.\n\nv. 101.  Thy sire.]  The Emperor Rodolph, too intent on\nincreasing his power in Germany to give much of his thoughts to\nItaly, \"the garden of the empire.\"\n\nv. 107.  Capulets and Montagues.]  Our ears are so familiarized\nto the names of these rival families in the language of\nShakespeare, that I have used them instead of the \"Montecchi\" and\n\"Cappelletti.\"\n\nv. 108.  Philippeschi and Monaldi.] Two other rival families in\nOrvieto.\n\nv. 113.  What safety, Santafiore can supply.]  A place between\nPisa and Sienna.  What he alludes to is so doubtful, that it is\nnot certain whether we should not read \"come si cura\"--\" How\nSantafiore is governed.\" Perhaps the event related in the note to\nv. 58, Canto XI. m");strcat(expected_filecontent4, "di, king of Naples and Sicily, is\ndefeated and slain by Charles of Anjou.  Hell, C. XXVIII. 13.\nAnd Purgatory, C. III. 110.\n\nGuido Novello of Polenta obtains the sovereignty of Ravenna.\nH. C. XXVII. 38.\n\n1266.  Two of the Frati Godenti chosen arbitrators of the\ndifferences at Florence.  H. C. XXIII. 104.\nGianni de\' Soldanieri heads the populace in that city.  H. C.\nXXXII. 118.\n\n1268.  Charles of Anjou puts Conradine to death, and becomes King\nof Naples.  H. C. XXVIII. 16 and Purg C. XX. 66.\n\n1272.  Henry III. of England is succeeded by Edward I. Purg. C.\nVII. 129.\n\n1274.  Our Poet first sees Beatrice, daughter of Folco Portinari.\n\nFra.\nGuittone d\'Arezzo, the poet, dies.  Purg. C. XXIV. 56.\nThomas Aquinas dies.  Purg. C. XX. 67.  and Par. C. X. 96.\nBuonaventura dies.  Par. C. XII. 25.\n\n1275.  Pierre de la Brosse, secretary to Philip III. of France,\nexecuted.  Purg. C. VI. 23.\n\n1276.  Giotto, the painter, is born.  Purg. C. XI. 95.  Pope\nAdrian V. dies.  Purg. C. XIX. 97.\nGuido Guinicelli, the poet, dies.  Purg. C. XI. 96. and C. XXVI.\n83.\n\n1277.  Pope John XXI.  dies.  Par. C. XII. 126.\n\n1278.  Ottocar, king of Bohemia, dies.  Purg. C. VII. 97.\n\n1279.  Dionysius succeeds to the throne of Portugal.  Par. C.\nXIX. 135.\n\n1280.  Albertus Magnus dies.  Par. C. X. 95.\n\n1281.  Pope Nicholas III. dies.  H. C. XIX 71.\nDante studies at the universities of Bologna and Padua.\n\n1282.  The Sicilian vespers.  Par. C. VIII. 80.\nThe French defeated by the people of Forli.  H. C. XXVII. 41.\nTribaldello de\' Manfredi betrays the city of Faenza.  H. C.\nXXXII. 119.\n\n1284.  Prince Charles of Anjou is defeated and made prisoner by\nRugiez\nde Lauria, admiral to Peter III. of Arragon.  Purg. C. XX. 78.\nCharles I.  king of Naples, dies.  Purg. C. VII. 111.\n\n1285.  Pope Martin IV.  dies.  Purg. C. XXIV. 23.\nPhilip III.  of France, and Peter III.  of Arragon, die. Purg. C.\nVII. 101 and\n110.\nHenry II. king of Cyprus, comes ");strcat(expected_filecontent5, "that which follows them?\"\n     I straightway mark\'d a tribe behind them walk,\nAs if attendant on their leaders, cloth\'d\nWith raiment of such whiteness, as on earth\nWas never.  On my left, the wat\'ry gleam\nBorrow\'d, and gave me back, when there I look\'d.\nAs in a mirror, my left side portray\'d.\n     When I had chosen on the river\'s edge\nSuch station, that the distance of the stream\nAlone did separate me; there I stay\'d\nMy steps for clearer prospect, and beheld\nThe flames go onward, leaving, as they went,\nThe air behind them painted as with trail\nOf liveliest pencils!  so distinct were mark\'d\nAll those sev\'n listed colours, whence the sun\nMaketh his bow, and Cynthia her zone.\nThese streaming gonfalons did flow beyond\nMy vision; and ten paces, as I guess,\nParted the outermost.  Beneath a sky\nSo beautiful, came foul and-twenty elders,\nBy two and two, with flower-de-luces crown\'d.\nAll sang one song:  \"Blessed be thou among\nThe daughters of Adam!  and thy loveliness\nBlessed for ever!\"  After that the flowers,\nAnd the fresh herblets, on the opposite brink,\nWere free from that elected race; as light\nIn heav\'n doth second light, came after them\nFour animals, each crown\'d with verdurous leaf.\nWith six wings each was plum\'d, the plumage full\nOf eyes, and th\' eyes of Argus would be such,\nWere they endued with life.  Reader, more rhymes\nWill not waste in shadowing forth their form:\nFor other need no straitens, that in this\nI may not give my bounty room.  But read\nEzekiel; for he paints them, from the north\nHow he beheld them come by Chebar\'s flood,\nIn whirlwind, cloud and fire; and even such\nAs thou shalt find them character\'d by him,\nHere were they; save as to the pennons; there,\nFrom him departing, John accords with me.\n     The space, surrounded by the four, enclos\'d\nA car triumphal: on two wheels it came\nDrawn at a Gryphon\'s neck; and he above\nStretch\'d either wing uplifted, \'tween the midst\nAnd the three listed hues, on each side three;\nSo that the wings did cleave or injure none;\nAnd out of sight they rose.  The members,");strcat(expected_filecontent6, " the other more erect he stands,\nEach part except the gold, is rent throughout;\nAnd from the fissure tears distil, which join\'d\nPenetrate to that cave.  They in their course\nThus far precipitated down the rock\nForm Acheron, and Styx, and Phlegethon;\nThen by this straiten\'d channel passing hence\nBeneath, e\'en to the lowest depth of all,\nForm there Cocytus, of whose lake (thyself\nShall see it) I here give thee no account.\"\n     Then I to him:  \"If from our world this sluice\nBe thus deriv\'d; wherefore to us but now\nAppears it at this edge?\"  He straight replied:\n\"The place, thou know\'st, is round; and though great part\nThou have already pass\'d, still to the left\nDescending to the nethermost, not yet\nHast thou the circuit made of the whole orb.\nWherefore if aught of new to us appear,\nIt needs not bring up wonder in thy looks.\"\n     Then I again inquir\'d:  \"Where flow the streams\nOf Phlegethon and Lethe? for of one\nThou tell\'st not, and the other of that shower,\nThou say\'st, is form\'d.\"  He answer thus return\'d:\n\"Doubtless thy questions all well pleas\'d I hear.\nYet the red seething wave might have resolv\'d\nOne thou proposest.  Lethe thou shalt see,\nBut not within this hollow, in the place,\nWhither to lave themselves the spirits go,\nWhose blame hath been by penitence remov\'d.\"\nHe added:  \"Time is now we quit the wood.\nLook thou my steps pursue:  the margins give\nSafe passage, unimpeded by the flames;\nFor over them all vapour is extinct.\"\n\n\n\nCANTO XV\n\nOne of the solid margins bears us now\nEnvelop\'d in the mist, that from the stream\nArising, hovers o\'er, and saves from fire\nBoth piers and water.  As the Flemings rear\nTheir mound, \'twixt Ghent and Bruges, to chase back\nThe ocean, fearing his tumultuous tide\nThat drives toward them, or the Paduans theirs\nAlong the Brenta, to defend their towns\nAnd castles, ere the genial warmth be felt\nOn Chiarentana\'s top; such were the mounds,\nSo fram\'d, though not in height or bulk to these\nMade equal, by the master, whosoe\'er\nHe was, that rais\'d them here.  We from the wood\nWere not so far remov\'d, that turning round\nI might not have discern\'d it, when we met\nA troop of spirits, who came beside the pier.\n     They each one ey\'d us, as at eventide\nOne eyes another under a new moon,\nAnd toward us sharpen\'d their sight as keen,\nAs an old tailor at his needle\'s eye.\n     Thus narrowly explor\'d by all the tribe,\nI was agniz\'d of one, who by the skirt\nCaught me, and cried, \"What wonder have we here!\"\n     And I, when he to me outstretch\'d his arm,\nIntently fix\'d my ken on his parch\'d looks,\nThat although smirch\'d with fire, they hinder\'d not\nBut I remember\'d him; and towards his face\nMy hand inclining, answer\'d:  \"Sir! Brunetto!\nAnd art thou here?\"  He thus to me:  \"My son!\nOh let it not displease thee, if Brunetto\nLatini but a little space with thee\nTurn back, and leave his fellows to proceed.\"\n     I thus to him replied:  \"Much as I can,\nI thereto pray thee; and if thou be willing,\nThat I here seat me with thee, I consent;\nHis leave, with whom I journey, first obtain\'d.\"\n     \"O son!\" said he, \" whoever of this throng\nOne instant stops, lies then a hundred years,\nNo fan to ventilate him, when the fire\nSmites sorest.  Pass thou therefore on.  I close\nWill at thy garments walk, and then rejoin\nMy troop, who go mourning their endless doom.\"\n     I dar\'d not from the path des");strcat(expected_filecontent7, "\n\nv. 14.  Broad are their pennons.]  From Virg. Aen. l. iii. 216.\n\nv. 48.  In my verse d");strcat(expected_filecontent8, "n 1285, at Perpignan, in his retreat from Arragon.\n\nv. 102.  Him of gentle look.]  Henry of Naverre, father of Jane\nmarried to Philip IV of France, whom Dant");


            struct disk_t* disk = disk_open_from_file("see_fat16_volume.img");
            test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

            struct volume_t* volume = fat_open(disk, 0);
            test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

            
                    struct file_t* file0 = file_open(volume, "bOARD.BIN");
                    test_error(file0 != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
                    onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)"

            
                    struct file_t* file1 = file_open(volume, "deSERT");
                    test_error(file1 != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
                    onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)"

            
                    struct file_t* file2 = file_open(volume, "ROOM.BIN");
                    test_error(file2 != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
                    onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)"

            
                    struct file_t* file3 = file_open(volume, "GrEEN.Bin");
                    test_error(file3 != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
                    onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)"

            
                    struct file_t* file4 = file_open(volume, "EQUaL.TX");
                    test_error(file4 != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
                    onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)"

            
                    struct file_t* file5 = file_open(volume, "tEN");
                    test_error(file5 != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
                    onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)"

            
                    struct file_t* file6 = file_open(volume, "GAME.tXT");
                    test_error(file6 != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
                    onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)"

            
                    struct file_t* file7 = file_open(volume, "bar last wiFe led scalE ReacH VAluE offeR.Jii");
                    test_error(file7 != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
                    onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)"

            
                    struct file_t* file8 = file_open(volume, "sUBsTAnC");
                    test_error(file8 != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
                    onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)"

            
            
                size_t size0 = file_read(filecontent0, 1, 1958, file0);
                test_error(size0 == 1958, "Funkcja file_read() niepoprawnie wczytała dane z pliku, powinna wczytać 1958 bajtów, a wczytała %lu", size0);
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
                int diff_pos0 = mem_find_first_difference(filecontent0, expected_filecontent0, 1958);
        
                // jeśli jest, to raportuj błąd
                test_error(diff_pos0 == -1, "Dane wczytane z pliku nie są poprawne; różnica w bajcie %d; jest 0x%02x a powinno być 0x%02x",
                    diff_pos0, mem_get_byte(filecontent0, diff_pos0), mem_get_byte(expected_filecontent0, diff_pos0));
        
                onerror_compare_memory(expected_filecontent0, filecontent0, 1958);
            
                size_t size1 = file_read(filecontent1, 1, 419, file1);
                test_error(size1 == 419, "Funkcja file_read() niepoprawnie wczytała dane z pliku, powinna wczytać 419 bajtów, a wczytała %lu", size1);
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
                int diff_pos1 = mem_find_first_difference(filecontent1, expected_filecontent1, 419);
        
                // jeśli jest, to raportuj błąd
                test_error(diff_pos1 == -1, "Dane wczytane z pliku nie są poprawne; różnica w bajcie %d; jest 0x%02x a powinno być 0x%02x",
                    diff_pos1, mem_get_byte(filecontent1, diff_pos1), mem_get_byte(expected_filecontent1, diff_pos1));
        
                onerror_compare_memory(expected_filecontent1, filecontent1, 419);
            
                size_t size2 = file_read(filecontent2, 1, 2667, file2);
                test_error(size2 == 2667, "Funkcja file_read() niepoprawnie wczytała dane z pliku, powinna wczytać 2667 bajtów, a wczytała %lu", size2);
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
                int diff_pos2 = mem_find_first_difference(filecontent2, expected_filecontent2, 2667);
        
                // jeśli jest, to raportuj błąd
                test_error(diff_pos2 == -1, "Dane wczytane z pliku nie są poprawne; różnica w bajcie %d; jest 0x%02x a powinno być 0x%02x",
                    diff_pos2, mem_get_byte(filecontent2, diff_pos2), mem_get_byte(expected_filecontent2, diff_pos2));
        
                onerror_compare_memory(expected_filecontent2, filecontent2, 2667);
            
                size_t size3 = file_read(filecontent3, 1, 2750, file3);
                test_error(size3 == 2750, "Funkcja file_read() niepoprawnie wczytała dane z pliku, powinna wczytać 2750 bajtów, a wczytała %lu", size3);
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
                int diff_pos3 = mem_find_first_difference(filecontent3, expected_filecontent3, 2750);
        
                // jeśli jest, to raportuj błąd
                test_error(diff_pos3 == -1, "Dane wczytane z pliku nie są poprawne; różnica w bajcie %d; jest 0x%02x a powinno być 0x%02x",
                    diff_pos3, mem_get_byte(filecontent3, diff_pos3), mem_get_byte(expected_filecontent3, diff_pos3));
        
                onerror_compare_memory(expected_filecontent3, filecontent3, 2750);
            
                size_t size4 = file_read(filecontent4, 1, 1924, file4);
                test_error(size4 == 1924, "Funkcja file_read() niepoprawnie wczytała dane z pliku, powinna wczytać 1924 bajtów, a wczytała %lu", size4);
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
                int diff_pos4 = mem_find_first_difference(filecontent4, expected_filecontent4, 1924);
        
                // jeśli jest, to raportuj błąd
                test_error(diff_pos4 == -1, "Dane wczytane z pliku nie są poprawne; różnica w bajcie %d; jest 0x%02x a powinno być 0x%02x",
                    diff_pos4, mem_get_byte(filecontent4, diff_pos4), mem_get_byte(expected_filecontent4, diff_pos4));
        
                onerror_compare_memory(expected_filecontent4, filecontent4, 1924);
            
                size_t size5 = file_read(filecontent5, 1, 2048, file5);
                test_error(size5 == 2048, "Funkcja file_read() niepoprawnie wczytała dane z pliku, powinna wczytać 2048 bajtów, a wczytała %lu", size5);
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
                int diff_pos5 = mem_find_first_difference(filecontent5, expected_filecontent5, 2048);
        
                // jeśli jest, to raportuj błąd
                test_error(diff_pos5 == -1, "Dane wczytane z pliku nie są poprawne; różnica w bajcie %d; jest 0x%02x a powinno być 0x%02x",
                    diff_pos5, mem_get_byte(filecontent5, diff_pos5), mem_get_byte(expected_filecontent5, diff_pos5));
        
                onerror_compare_memory(expected_filecontent5, filecontent5, 2048);
            
                size_t size6 = file_read(filecontent6, 1, 3356, file6);
                test_error(size6 == 3356, "Funkcja file_read() niepoprawnie wczytała dane z pliku, powinna wczytać 3356 bajtów, a wczytała %lu", size6);
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
                int diff_pos6 = mem_find_first_difference(filecontent6, expected_filecontent6, 3356);
        
                // jeśli jest, to raportuj błąd
                test_error(diff_pos6 == -1, "Dane wczytane z pliku nie są poprawne; różnica w bajcie %d; jest 0x%02x a powinno być 0x%02x",
                    diff_pos6, mem_get_byte(filecontent6, diff_pos6), mem_get_byte(expected_filecontent6, diff_pos6));
        
                onerror_compare_memory(expected_filecontent6, filecontent6, 3356);
            
                size_t size7 = file_read(filecontent7, 1, 88, file7);
                test_error(size7 == 88, "Funkcja file_read() niepoprawnie wczytała dane z pliku, powinna wczytać 88 bajtów, a wczytała %lu", size7);
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
                int diff_pos7 = mem_find_first_difference(filecontent7, expected_filecontent7, 88);
        
                // jeśli jest, to raportuj błąd
                test_error(diff_pos7 == -1, "Dane wczytane z pliku nie są poprawne; różnica w bajcie %d; jest 0x%02x a powinno być 0x%02x",
                    diff_pos7, mem_get_byte(filecontent7, diff_pos7), mem_get_byte(expected_filecontent7, diff_pos7));
        
                onerror_compare_memory(expected_filecontent7, filecontent7, 88);
            
                size_t size8 = file_read(filecontent8, 1, 157, file8);
                test_error(size8 == 157, "Funkcja file_read() niepoprawnie wczytała dane z pliku, powinna wczytać 157 bajtów, a wczytała %lu", size8);
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
                int diff_pos8 = mem_find_first_difference(filecontent8, expected_filecontent8, 157);
        
                // jeśli jest, to raportuj błąd
                test_error(diff_pos8 == -1, "Dane wczytane z pliku nie są poprawne; różnica w bajcie %d; jest 0x%02x a powinno być 0x%02x",
                    diff_pos8, mem_get_byte(filecontent8, diff_pos8), mem_get_byte(expected_filecontent8, diff_pos8));
        
                onerror_compare_memory(expected_filecontent8, filecontent8, 157);
            

            free(filecontent0);
    free(filecontent1);
    free(filecontent2);
    free(filecontent3);
    free(filecontent4);
    free(filecontent5);
    free(filecontent6);
    free(filecontent7);
    free(filecontent8);

            file_close(file0);
    file_close(file1);
    file_close(file2);
    file_close(file3);
    file_close(file4);
    file_close(file5);
    file_close(file6);
    file_close(file7);
    file_close(file8);


            fat_close(volume);
            disk_close(disk);

            test_no_heap_leakage();
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
        
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 67: Sprawdzanie poprawności działania funkcji file_seek
//
void UTEST67(void)
{
    // informacje o teście
    test_start(67, "Sprawdzanie poprawności działania funkcji file_seek", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    
            char *filecontent = (char *)calloc(2048, 1);
            char expected_filecontent[2049] = "";

            strcat(expected_filecontent, "that which follows them?\"\n     I straightway mark\'d a tribe behind them walk,\nAs if attendant on their leaders, cloth\'d\nWith raiment of such whiteness, as on earth\nWas never.  On my left, the wat\'ry gleam\nBorrow\'d, and gave me back, when there I look\'d.\nAs in a mirror, my left side portray\'d.\n     When I had chosen on the river\'s edge\nSuch station, that the distance of the stream\nAlone did separate me; there I stay\'d\nMy steps for clearer prospect, and beheld\nThe flames go onward, leaving, as they went,\nThe air behind them painted as with trail\nOf liveliest pencils!  so distinct were mark\'d\nAll those sev\'n listed colours, whence the sun\nMaketh his bow, and Cynthia her zone.\nThese streaming gonfalons did flow beyond\nMy vision; and ten paces, as I guess,\nParted the outermost.  Beneath a sky\nSo beautiful, came foul and-twenty elders,\nBy two and two, with flower-de-luces crown\'d.\nAll sang one song:  \"Blessed be thou among\nThe daughters of Adam!  and thy loveliness\nBlessed for ever!\"  After that the flowers,\nAnd the fresh herblets, on the opposite brink,\nWere free from that elected race; as light\nIn heav\'n doth second light, came after them\nFour animals, each crown\'d with verdurous leaf.\nWith six wings each was plum\'d, the plumage full\nOf eyes, and th\' eyes of Argus would be such,\nWere they endued with life.  Reader, more rhymes\nWill not waste in shadowing forth their form:\nFor other need no straitens, that in this\nI may not give my bounty room.  But read\nEzekiel; for he paints them, from the north\nHow he beheld them come by Chebar\'s flood,\nIn whirlwind, cloud and fire; and even such\nAs thou shalt find them character\'d by him,\nHere were they; save as to the pennons; there,\nFrom him departing, John accords with me.\n     The space, surrounded by the four, enclos\'d\nA car triumphal: on two wheels it came\nDrawn at a Gryphon\'s neck; and he above\nStretch\'d either wing uplifted, \'tween the midst\nAnd the three listed hues, on each side three;\nSo that the wings did cleave or injure none;\nAnd out of sight they rose.  The members,");

            struct disk_t* disk = disk_open_from_file("see_fat16_volume.img");
            test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

            struct volume_t* volume = fat_open(disk, 0);
            test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

            struct file_t* file = file_open(volume, "tEn");
            test_error(file != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

            file_seek(file, 1390, SEEK_SET);
        
            char c;
            int res = file_read(&c, 1, 1, file);
            test_error(res == 1, "Funkcja file_read() powinna zwrócić wartość 1, a zwróciła %d", res);
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
            test_error(expected_filecontent[1390] == c, "Funkcja file_read() powinna odczyatć z pliku wartość |%c|, a odczytała |%c|", expected_filecontent[1390], c);

            free(filecontent);
            file_close(file);
            fat_close(volume);
            disk_close(disk);

            test_no_heap_leakage();
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
        
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 68: Sprawdzanie poprawności działania funkcji file_seek
//
void UTEST68(void)
{
    // informacje o teście
    test_start(68, "Sprawdzanie poprawności działania funkcji file_seek", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    
            char *filecontent = (char *)calloc(2750, 1);
            char expected_filecontent[2751] = "";

            strcat(expected_filecontent, "son for which supposed crime he suffered\ndeath. So say the Italian commentators.  Henault represents the\nmatter very differently: \"Pierre de la Brosse, formerly barber to\nSt. Louis, afterwards the favorite of Philip, fearing the too\ngreat attachment of the king for his wife Mary, accuses this\nprincess of having poisoned Louis, eldest son of Philip, by his\nfirst marriage. This calumny is discovered by a nun of Nivelle in\nFlanders.  La Brosse is hung.\" Abrege Chron. t. 275, &c.\n\nv. 30.  In thy text.]  He refers to Virgil, Aen. 1, vi.  376.\nDesine fata deum flecti sperare precando, 37. The sacred height\nOf judgment. Shakespeare, Measure for Measure, a. ii. s. 2.\nIf he, which is the top of judgment\n\nv. 66.  Eyeing us as a lion on his watch.]\nA guisa di Leon quando si posa.\nA line taken by Tasso, G.  L. c. x. st. 56.\n\nv. 76.  Sordello.]  The history of Sordello\'s life is wrapt in\nthe obscurity of romance.  That he distinguished himself by his\nskill in Provencal poetry is certain. It is probable that he was\nborn towards the end of the twelfth, and died about the middle of\nthe succeeding century.  Tiraboschi has taken much pains to sift\nall the notices he could collect relating to him.  Honourable\nmention of his name is made by our Poet in the Treatise de Vulg.\nEloq.  1. i. c. 15.\n\nv. 76.  Thou inn of grief.]\nThou most beauteous inn\nWhy should hard-favour\'d grief be lodg\'d in thee?\nShakespeare, Richard II a. 5. s. 1.\n\nv. 89.  Justinian\'s hand.]  \"What avails it that Justinian\ndelivered thee from the Goths, and reformed thy laws, if thou art\nno longer under the control of his successors in the empire?\"\n\nv. 94.  That which God commands.]  He alludes to the precept-\n\"Render unto Caesar the things which are Caesar\'s.\"\n\nv. 98.  O German Albert!]  The Emperor Albert I. succeeded\nAdolphus in 1298, and was murdered in 1308.  See Par Canto XIX\n114 v. 103.  Thy successor.]  The successor of Albert was Henry\nof Luxembourg, by whose interposition in the affairs of Italy our\nPoet hoped to have been reinstated in his native city.\n\nv. 101.  Thy sire.]  The Emperor Rodolph, too intent on\nincreasing his power in Germany to give much of his thoughts to\nItaly, \"the garden of the empire.\"\n\nv. 107.  Capulets and Montagues.]  Our ears are so familiarized\nto the names of these rival families in the language of\nShakespeare, that I have used them instead of the \"Montecchi\" and\n\"Cappelletti.\"\n\nv. 108.  Philippeschi and Monaldi.] Two other rival families in\nOrvieto.\n\nv. 113.  What safety, Santafiore can supply.]  A place between\nPisa and Sienna.  What he alludes to is so doubtful, that it is\nnot certain whether we should not read \"come si cura\"--\" How\nSantafiore is governed.\" Perhaps the event related in the note to\nv. 58, Canto XI. m");

            struct disk_t* disk = disk_open_from_file("see_fat16_volume.img");
            test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

            struct volume_t* volume = fat_open(disk, 0);
            test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

            struct file_t* file = file_open(volume, "GrEEN.BIN");
            test_error(file != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

            file_seek(file, -684, SEEK_END);

            char c;
            int res = file_read(&c, 1, 1, file);
            test_error(res == 1, "Funkcja file_read() powinna zwrócić wartość 1, a zwróciła %d", res);
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
            test_error(expected_filecontent[2066] == c, "Funkcja file_read() powinna odczyatć z pliku wartość |%c|, a odczytała |%c|", expected_filecontent[2066], c);

            free(filecontent);
            file_close(file);
            fat_close(volume);
            disk_close(disk);

            test_no_heap_leakage();
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
        
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 69: Sprawdzanie poprawności działania funkcji file_seek
//
void UTEST69(void)
{
    // informacje o teście
    test_start(69, "Sprawdzanie poprawności działania funkcji file_seek", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    
            char *filecontent = (char *)calloc(157, 1);
            char expected_filecontent[158] = "";

            strcat(expected_filecontent, "n 1285, at Perpignan, in his retreat from Arragon.\n\nv. 102.  Him of gentle look.]  Henry of Naverre, father of Jane\nmarried to Philip IV of France, whom Dant");

            struct disk_t* disk = disk_open_from_file("see_fat16_volume.img");
            test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

            struct volume_t* volume = fat_open(disk, 0);
            test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

            struct file_t* file = file_open(volume, "SUBsTANC");
            test_error(file != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

            file_seek(file, 70, SEEK_SET);
            file_seek(file, 33, SEEK_CUR);

            char c;
            int res = file_read(&c, 1, 1, file);
            test_error(res == 1, "Funkcja file_read() powinna zwrócić wartość 1, a zwróciła %d", res);
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
            test_error(expected_filecontent[103] == c, "Funkcja file_read() powinna odczyatć z pliku wartość |%c|, a odczytała |%c|", expected_filecontent[103], c);

            free(filecontent);
            file_close(file);
            fat_close(volume);
            disk_close(disk);

            test_no_heap_leakage();
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
        
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 70: Sprawdzanie poprawności działania funkcji file_open
//
void UTEST70(void)
{
    // informacje o teście
    test_start(70, "Sprawdzanie poprawności działania funkcji file_open", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

                 struct disk_t* disk = disk_open_from_file("see_fat16_volume.img");
                 test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                 onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                 struct volume_t* volume = fat_open(disk, 0);
                 test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                 onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                 struct file_t* file = file_open(volume, "\\STOp\\DECIdE\\WHiTE\\SHOP");
                 test_error(file == NULL, "Funkcja file_open() powinna zwrócić NULL - nazwa podana w parametrze (\\STOp\\dEcIdE\\WHitE\\SHoP) jest nazwą katalogu, a nie pliku");
                 onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                 fat_close(volume);
                 disk_close(disk);

                 test_no_heap_leakage();
                 onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
             
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 71: Sprawdzanie poprawności działania funkcji file_open
//
void UTEST71(void)
{
    // informacje o teście
    test_start(71, "Sprawdzanie poprawności działania funkcji file_open", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

                 struct disk_t* disk = disk_open_from_file("see_fat16_volume.img");
                 test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                 onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                 struct volume_t* volume = fat_open(disk, 0);
                 test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                 onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                 struct file_t* file = file_open(volume, "\\thIn\\WATER\\AdD\\fIT\\AGAIN");
                 test_error(file == NULL, "Funkcja file_open() powinna zwrócić NULL - nazwa podana w parametrze (\\thiN\\WaTer\\adD\\FIT\\AGAIN) jest nazwą katalogu, a nie pliku");
                 onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                 fat_close(volume);
                 disk_close(disk);

                 test_no_heap_leakage();
                 onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
             
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 72: Sprawdzanie poprawności działania funkcji file_open
//
void UTEST72(void)
{
    // informacje o teście
    test_start(72, "Sprawdzanie poprawności działania funkcji file_open", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

                 struct disk_t* disk = disk_open_from_file("see_fat16_volume.img");
                 test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                 onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                 struct volume_t* volume = fat_open(disk, 0);
                 test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                 onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                 struct file_t* file = file_open(volume, "\\fEeD\\aLways PErhAps\\WHERe");
                 test_error(file == NULL, "Funkcja file_open() powinna zwrócić NULL - nazwa podana w parametrze (\\FEED\\always PerhApS\\WHERE) jest nazwą katalogu, a nie pliku");
                 onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                 fat_close(volume);
                 disk_close(disk);

                 test_no_heap_leakage();
                 onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
             
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 73: Sprawdzanie poprawności działania funkcji file_open
//
void UTEST73(void)
{
    // informacje o teście
    test_start(73, "Sprawdzanie poprawności działania funkcji file_open", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

                 struct disk_t* disk = disk_open_from_file("see_fat16_volume.img");
                 test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                 onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                 struct volume_t* volume = fat_open(disk, 0);
                 test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                 onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                 struct file_t* file = file_open(volume, "\\FEEd\\alWays PErHaPS\\aNIMAL\\mILe\\buY leD KEpt dEaL");
                 test_error(file == NULL, "Funkcja file_open() powinna zwrócić NULL - nazwa podana w parametrze (\\FEED\\AlwayS peRhapS\\ANIMaL\\mILE\\buy led kept deaL) jest nazwą katalogu, a nie pliku");
                 onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                 fat_close(volume);
                 disk_close(disk);

                 test_no_heap_leakage();
                 onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
             
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 74: Sprawdzanie poprawności działania funkcji file_open
//
void UTEST74(void)
{
    // informacje o teście
    test_start(74, "Sprawdzanie poprawności działania funkcji file_open", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

                 struct disk_t* disk = disk_open_from_file("see_fat16_volume.img");
                 test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                 onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                 struct volume_t* volume = fat_open(disk, 0);
                 test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                 onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                 struct file_t* file = file_open(volume, "\\OR\\DOG\\CouNtry\\NOTE\\read Coat stick aGain");
                 test_error(file == NULL, "Funkcja file_open() powinna zwrócić NULL - nazwa podana w parametrze (\\Or\\dOg\\coUnTRY\\NOtE\\Read Coat stiCk AGain) jest nazwą katalogu, a nie pliku");
                 onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                 fat_close(volume);
                 disk_close(disk);

                 test_no_heap_leakage();
                 onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
             
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 75: Sprawdzanie poprawności działania funkcji file_open
//
void UTEST75(void)
{
    // informacje o teście
    test_start(75, "Sprawdzanie poprawności działania funkcji file_open", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

                 struct disk_t* disk = disk_open_from_file("see_fat16_volume.img");
                 test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                 onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                 struct volume_t* volume = fat_open(disk, 0);
                 test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                 onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                 struct file_t* file = file_open(volume, "\\OR\\dOG\\coUnTRY\\AgaINsT\\NATURe");
                 test_error(file == NULL, "Funkcja file_open() powinna zwrócić NULL - nazwa podana w parametrze (\\Or\\DOG\\COUNtry\\AGAiNST\\NAtuRe) jest nazwą katalogu, a nie pliku");
                 onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                 fat_close(volume);
                 disk_close(disk);

                 test_no_heap_leakage();
                 onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
             
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 76: Sprawdzanie poprawności działania funkcji file_open
//
void UTEST76(void)
{
    // informacje o teście
    test_start(76, "Sprawdzanie poprawności działania funkcji file_open", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

                 struct disk_t* disk = disk_open_from_file("see_fat16_volume.img");
                 test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                 onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                 struct volume_t* volume = fat_open(disk, 0);
                 test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                 onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                 struct file_t* file = file_open(volume, "\\fEeD\\always pErhaps\\ANIMAL\\miLe\\mOnth");
                 test_error(file == NULL, "Funkcja file_open() powinna zwrócić NULL - nazwa podana w parametrze (\\feeD\\AlwayS peRHaps\\AnIMaL\\MILE\\moNTH) jest nazwą katalogu, a nie pliku");
                 onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                 fat_close(volume);
                 disk_close(disk);

                 test_no_heap_leakage();
                 onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
             
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 77: Sprawdzanie poprawności działania funkcji file_open
//
void UTEST77(void)
{
    // informacje o teście
    test_start(77, "Sprawdzanie poprawności działania funkcji file_open", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

                 struct disk_t* disk = disk_open_from_file("see_fat16_volume.img");
                 test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                 onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                 struct volume_t* volume = fat_open(disk, 0);
                 test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                 onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                 struct file_t* file = file_open(volume, "WOmAN");
                 test_error(file == NULL, "Funkcja file_open() powinna zwrócić NULL - nazwa podana w parametrze (wOmAN) jest nazwą katalogu, a nie pliku");
                 onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                 fat_close(volume);
                 disk_close(disk);

                 test_no_heap_leakage();
                 onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
             
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 78: Sprawdzanie poprawności działania funkcji file_open
//
void UTEST78(void)
{
    // informacje o teście
    test_start(78, "Sprawdzanie poprawności działania funkcji file_open", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

                 struct disk_t* disk = disk_open_from_file("see_fat16_volume.img");
                 test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                 onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                 struct volume_t* volume = fat_open(disk, 0);
                 test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                 onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                 struct file_t* file = file_open(volume, "SToP");
                 test_error(file == NULL, "Funkcja file_open() powinna zwrócić NULL - nazwa podana w parametrze (sTOp) jest nazwą katalogu, a nie pliku");
                 onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                 fat_close(volume);
                 disk_close(disk);

                 test_no_heap_leakage();
                 onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
             
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 79: Sprawdzanie poprawności działania funkcji file_open
//
void UTEST79(void)
{
    // informacje o teście
    test_start(79, "Sprawdzanie poprawności działania funkcji file_open", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

                 struct disk_t* disk = disk_open_from_file("see_fat16_volume.img");
                 test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                 onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                 struct volume_t* volume = fat_open(disk, 0);
                 test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                 onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                 struct file_t* file = file_open(volume, "OR");
                 test_error(file == NULL, "Funkcja file_open() powinna zwrócić NULL - nazwa podana w parametrze (OR) jest nazwą katalogu, a nie pliku");
                 onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                 fat_close(volume);
                 disk_close(disk);

                 test_no_heap_leakage();
                 onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
             
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 80: Sprawdzanie poprawności działania funkcji file_open
//
void UTEST80(void)
{
    // informacje o teście
    test_start(80, "Sprawdzanie poprawności działania funkcji file_open", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

                 struct disk_t* disk = disk_open_from_file("see_fat16_volume.img");
                 test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                 onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                 struct volume_t* volume = fat_open(disk, 0);
                 test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                 onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                 struct file_t* file = file_open(volume, "tHIN");
                 test_error(file == NULL, "Funkcja file_open() powinna zwrócić NULL - nazwa podana w parametrze (THIn) jest nazwą katalogu, a nie pliku");
                 onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                 fat_close(volume);
                 disk_close(disk);

                 test_no_heap_leakage();
                 onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
             
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 81: Sprawdzanie poprawności działania funkcji file_open
//
void UTEST81(void)
{
    // informacje o teście
    test_start(81, "Sprawdzanie poprawności działania funkcji file_open", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

                 struct disk_t* disk = disk_open_from_file("see_fat16_volume.img");
                 test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                 onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                 struct volume_t* volume = fat_open(disk, 0);
                 test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                 onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                 struct file_t* file = file_open(volume, "COLD");
                 test_error(file == NULL, "Funkcja file_open() powinna zwrócić NULL - nazwa podana w parametrze (COld) jest nazwą katalogu, a nie pliku");
                 onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                 fat_close(volume);
                 disk_close(disk);

                 test_no_heap_leakage();
                 onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
             
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 82: Sprawdzanie poprawności działania funkcji file_open
//
void UTEST82(void)
{
    // informacje o teście
    test_start(82, "Sprawdzanie poprawności działania funkcji file_open", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

                 struct disk_t* disk = disk_open_from_file("see_fat16_volume.img");
                 test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                 onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                 struct volume_t* volume = fat_open(disk, 0);
                 test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                 onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                 struct file_t* file = file_open(volume, "coOk");
                 test_error(file == NULL, "Funkcja file_open() powinna zwrócić NULL - nazwa podana w parametrze (COOK) jest nazwą katalogu, a nie pliku");
                 onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                 fat_close(volume);
                 disk_close(disk);

                 test_no_heap_leakage();
                 onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
             
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 83: Sprawdzanie poprawności działania funkcji file_open
//
void UTEST83(void)
{
    // informacje o teście
    test_start(83, "Sprawdzanie poprawności działania funkcji file_open", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

                 struct disk_t* disk = disk_open_from_file("see_fat16_volume.img");
                 test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                 onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                 struct volume_t* volume = fat_open(disk, 0);
                 test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                 onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                 struct file_t* file = file_open(volume, "fEED");
                 test_error(file == NULL, "Funkcja file_open() powinna zwrócić NULL - nazwa podana w parametrze (fEED) jest nazwą katalogu, a nie pliku");
                 onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                 fat_close(volume);
                 disk_close(disk);

                 test_no_heap_leakage();
                 onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
             
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 84: Sprawdzanie poprawności działania funkcji file_open
//
void UTEST84(void)
{
    // informacje o teście
    test_start(84, "Sprawdzanie poprawności działania funkcji file_open", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

                 struct disk_t* disk = disk_open_from_file("see_fat16_volume.img");
                 test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                 onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                 struct volume_t* volume = fat_open(disk, 0);
                 test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                 onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                 struct file_t* file = file_open(volume, "lItTle dry tHose cARrY case sURE CreasE macHine");
                 test_error(file == NULL, "Funkcja file_open() powinna zwrócić NULL - nazwa podana w parametrze (Little dry thOse carry Case SuRe cReasE machIne) jest nazwą katalogu, a nie pliku");
                 onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                 fat_close(volume);
                 disk_close(disk);

                 test_no_heap_leakage();
                 onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
             
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 85: Sprawdzanie poprawności działania funkcji file_open
//
void UTEST85(void)
{
    // informacje o teście
    test_start(85, "Sprawdzanie poprawności działania funkcji file_open", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

                 struct disk_t* disk = disk_open_from_file("see_fat16_volume.img");
                 test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                 onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                 struct volume_t* volume = fat_open(disk, 0);
                 test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                 onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                 struct file_t* file = file_open(volume, "KINDrEsU");
                 test_error(file == NULL, "Funkcja file_open() powinna zwrócić NULL - nazwa podana w parametrze (KINDrEsU) jest nazwą katalogu, a nie pliku");
                 onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                 fat_close(volume);
                 disk_close(disk);

                 test_no_heap_leakage();
                 onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
             
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 86: Sprawdzanie poprawności działania funkcji file_open
//
void UTEST86(void)
{
    // informacje o teście
    test_start(86, "Sprawdzanie poprawności działania funkcji file_open", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

            struct disk_t* disk = disk_open_from_file("see_fat16_volume.img");
            test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

            struct volume_t* volume = fat_open(disk, 0);
            test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

            struct file_t* file = file_open(volume, "SeEM.TXT");
            test_error(file == NULL, "Funkcja file_open() nie powinna otworzyć pliku o nazwie SEEM.TXT, ponieważ nie istnieje on w katalogu głównym");
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

            fat_close(volume);
            disk_close(disk);

            test_no_heap_leakage();
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
        
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 87: Sprawdzanie poprawności działania funkcji file_read
//
void UTEST87(void)
{
    // informacje o teście
    test_start(87, "Sprawdzanie poprawności działania funkcji file_read", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

            struct disk_t* disk = disk_open_from_file("see_fat16_volume.img");
            test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

            struct volume_t* volume = fat_open(disk, 0);
            test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

            struct file_t* file = file_open(NULL, "SEEm.TxT");
            test_error(file == NULL, "Funkcja file_open() powinna zwrócić NULL w przypadku podania błędnych danych");
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

            fat_close(volume);
            disk_close(disk);

            test_no_heap_leakage();
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
        
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 88: Sprawdzanie poprawności działania funkcji file_read
//
void UTEST88(void)
{
    // informacje o teście
    test_start(88, "Sprawdzanie poprawności działania funkcji file_read", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

            struct disk_t* disk = disk_open_from_file("see_fat16_volume.img");
            test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

            struct volume_t* volume = fat_open(disk, 0);
            test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

            struct file_t* file = file_open(volume, NULL);
            test_error(file == NULL, "Funkcja file_open() powinna zwrócić NULL w przypadku podania błędnych danych");
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

            fat_close(volume);
            disk_close(disk);

            test_no_heap_leakage();
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
        
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 89: Sprawdzanie poprawności działania funkcji file_read
//
void UTEST89(void)
{
    // informacje o teście
    test_start(89, "Sprawdzanie poprawności działania funkcji file_read", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

            struct disk_t* disk = disk_open_from_file("see_fat16_volume.img");
            test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

            struct volume_t* volume = fat_open(disk, 0);
            test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

            struct file_t* file = file_open(NULL, NULL);
            test_error(file == NULL, "Funkcja file_open() powinna zwrócić NULL w przypadku podania błędnych danych");
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

            fat_close(volume);
            disk_close(disk);

            test_no_heap_leakage();
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
        
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 90: Sprawdzanie poprawności działania funkcji file_close
//
void UTEST90(void)
{
    // informacje o teście
    test_start(90, "Sprawdzanie poprawności działania funkcji file_close", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

            file_close(NULL);

            test_no_heap_leakage();
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
        
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 91: Sprawdzanie poprawności działania funkcji file_read
//
void UTEST91(void)
{
    // informacje o teście
    test_start(91, "Sprawdzanie poprawności działania funkcji file_read", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

            struct disk_t* disk = disk_open_from_file("see_fat16_volume.img");
            test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

            struct volume_t* volume = fat_open(disk, 0);
            test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

            struct file_t* file = file_open(volume, "boArd.bIN");
            test_error(file != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

            int res = file_read(NULL, 1, 1, file);
            test_error(res == -1, "Funkcja file_read() powinna zwrócić wartość -1, a zwróciła %d", res);
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

            file_close(file);
            fat_close(volume);
            disk_close(disk);

            test_no_heap_leakage();
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
        
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 92: Sprawdzanie poprawności działania funkcji dir_read
//
void UTEST92(void)
{
    // informacje o teście
    test_start(92, "Sprawdzanie poprawności działania funkcji dir_read", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

            char* expected_names[18] = { "BOARD.BIN", "DESERT", "ROOM.BIN", "GREEN.BIN", "EQUAL.TX", "TEN", "GAME.TXT", "bar last wife led scale reach value offer.JIi", "SUBSTANC", "WOMAN", "STOP", "OR", "THIN", "COLD", "COOK", "FEED", "little dry those carry case sure crease machine", "KINDRESU" };
            int found_names[18] = { 0 };

            struct disk_t* disk = disk_open_from_file("see_fat16_volume.img");
            test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

            struct volume_t* volume = fat_open(disk, 0);
            test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

            struct dir_t* pdir = dir_open(volume, "\\");
            test_error(pdir != NULL, "Funkcja dir_open() niepoprawnie otworzyła katalog");
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

            for (int i = 0; i < 18; ++i)
            {
                struct dir_entry_t entry;
                int res = dir_read(pdir, &entry);
                test_error(res == 0, "Funkcja dir_read() niepoprawnie odczytała wpis z katalogu");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                int name_found = 0;

                for (int j = 0; j < 18; ++j)
                {
                    int res = 0;
                    if (entry.has_long_name)
                        res = strcmp(entry.long_name, expected_names[j]);
                    else
                        res = strcmp(entry.name, expected_names[j]);
                    if (res == 0)
                    {
                        test_error(found_names[j] == 0, "Funkcja dir_read() ponownie zwróciła informację o wpisie %s", expected_names[j]);
                        found_names[j] = 1;
                        name_found = 1;
                        break;
                    }
                }

                test_error(name_found == 1, "Funkcja dir_read() zwróciła informację o wpisie %s, który nie znajduje się w katalogu", entry.name);
            }

            struct dir_entry_t entry;
            int res = dir_read(pdir, &entry);
            test_error(res == 1, "Funkcja dir_read() zwróciła niepoprawną wartość, po odczytaniu wszystkich wpisów z katalogu powinna zwrócić %d, a zwróciła %d", 1, res);
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

            dir_close(pdir);
            fat_close(volume);
            disk_close(disk);

            test_no_heap_leakage();
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
        
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 93: Sprawdzanie poprawności działania funkcji dir_read
//
void UTEST93(void)
{
    // informacje o teście
    test_start(93, "Sprawdzanie poprawności działania funkcji dir_read", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

            char* expected_names[27] = { "STATE.TX", "sharp success test.qVK", "THEM.BIN", "ARRIVE.TXT", "RIVER.TX", "chart am raise.tOj", "COOL", "CAMP", "else same operate hit.IHE", "red pair sugar.Wzy", "IS.BIN", "supply start great boat.lAD", "HIM", "RECEIVE.TX", "LAST", "GAS.BIN", "NUMBER.TX", "kill month bright of round.RGe", "LENGTH.TXT", "CHECK", "stay lay skin motion", "SIZE", "STORY", "four joy flower position", "DOG", ".", ".." };
            int found_names[27] = { 0 };

            struct disk_t* disk = disk_open_from_file("see_fat16_volume.img");
            test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

            struct volume_t* volume = fat_open(disk, 0);
            test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

            struct dir_t* pdir = dir_open(volume, "\\oR");
            test_error(pdir != NULL, "Funkcja dir_open() niepoprawnie otworzyła katalog");
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

            for (int i = 0; i < 27; ++i)
            {
                struct dir_entry_t entry;
                int res = dir_read(pdir, &entry);
                test_error(res == 0, "Funkcja dir_read() niepoprawnie odczytała wpis z katalogu");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                int name_found = 0;

                for (int j = 0; j < 27; ++j)
                {
                    int res = 0;
                    if (entry.has_long_name)
                        res = strcmp(entry.long_name, expected_names[j]);
                    else
                        res = strcmp(entry.name, expected_names[j]);
                    if (res == 0)
                    {
                        test_error(found_names[j] == 0, "Funkcja dir_read() ponownie zwróciła informację o wpisie %s", expected_names[j]);
                        found_names[j] = 1;
                        name_found = 1;
                        break;
                    }
                }

                test_error(name_found == 1, "Funkcja dir_read() zwróciła informację o wpisie %s, który nie znajduje się w katalogu", entry.name);
            }

            struct dir_entry_t entry;
            int res = dir_read(pdir, &entry);
            test_error(res == 1, "Funkcja dir_read() zwróciła niepoprawną wartość, po odczytaniu wszystkich wpisów z katalogu powinna zwrócić %d, a zwróciła %d", 1, res);
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

            dir_close(pdir);
            fat_close(volume);
            disk_close(disk);

            test_no_heap_leakage();
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
        
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 94: Sprawdzanie poprawności działania funkcji dir_read
//
void UTEST94(void)
{
    // informacje o teście
    test_start(94, "Sprawdzanie poprawności działania funkcji dir_read", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

            char* expected_names[9] = { "NOSE.TXT", "UNDER", "WAR", "THREE.TXT", "sheet letter count.tGE", "DAY.TX", "ADD", ".", ".." };
            int found_names[9] = { 0 };

            struct disk_t* disk = disk_open_from_file("see_fat16_volume.img");
            test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

            struct volume_t* volume = fat_open(disk, 0);
            test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

            struct dir_t* pdir = dir_open(volume, "\\STOp\\..\\sTOP\\carD StroNg sHe matERIal\\.\\WEATHER\\Hat\\area Spot cOrN name occUr");
            test_error(pdir != NULL, "Funkcja dir_open() niepoprawnie otworzyła katalog");
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

            for (int i = 0; i < 9; ++i)
            {
                struct dir_entry_t entry;
                int res = dir_read(pdir, &entry);
                test_error(res == 0, "Funkcja dir_read() niepoprawnie odczytała wpis z katalogu");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                int name_found = 0;

                for (int j = 0; j < 9; ++j)
                {
                    int res = 0;
                    if (entry.has_long_name)
                        res = strcmp(entry.long_name, expected_names[j]);
                    else
                        res = strcmp(entry.name, expected_names[j]);
                    if (res == 0)
                    {
                        test_error(found_names[j] == 0, "Funkcja dir_read() ponownie zwróciła informację o wpisie %s", expected_names[j]);
                        found_names[j] = 1;
                        name_found = 1;
                        break;
                    }
                }

                test_error(name_found == 1, "Funkcja dir_read() zwróciła informację o wpisie %s, który nie znajduje się w katalogu", entry.name);
            }

            struct dir_entry_t entry;
            int res = dir_read(pdir, &entry);
            test_error(res == 1, "Funkcja dir_read() zwróciła niepoprawną wartość, po odczytaniu wszystkich wpisów z katalogu powinna zwrócić %d, a zwróciła %d", 1, res);
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

            dir_close(pdir);
            fat_close(volume);
            disk_close(disk);

            test_no_heap_leakage();
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
        
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 95: Sprawdzanie poprawności działania funkcji dir_open
//
void UTEST95(void)
{
    // informacje o teście
    test_start(95, "Sprawdzanie poprawności działania funkcji dir_open", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

                        struct disk_t* disk = disk_open_from_file("see_fat16_volume.img");
                        test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                        onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                        struct volume_t* volume = fat_open(disk, 0);
                        test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                        onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                        struct dir_t*  dir = dir_open(volume, "\\KinDRESU\\AS\\COVeR\\YoUr\\ElsE");
                        test_error(dir == NULL, "Funkcja dir_open() powinna zwrócić NULL w przypadku podania niepoprawnej nazwy katalogu");
                        onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                        fat_close(volume);
                        disk_close(disk);

                        test_no_heap_leakage();
                        onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
                    
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 96: Sprawdzanie poprawności działania funkcji dir_open
//
void UTEST96(void)
{
    // informacje o teście
    test_start(96, "Sprawdzanie poprawności działania funkcji dir_open", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

                        struct disk_t* disk = disk_open_from_file("see_fat16_volume.img");
                        test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                        onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                        struct volume_t* volume = fat_open(disk, 0);
                        test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                        onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                        struct dir_t*  dir = dir_open(volume, "\\FEED\\aLWays perhapS\\RINg.TX");
                        test_error(dir == NULL, "Funkcja dir_open() powinna zwrócić NULL w przypadku podania niepoprawnej nazwy katalogu");
                        onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                        fat_close(volume);
                        disk_close(disk);

                        test_no_heap_leakage();
                        onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
                    
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 97: Sprawdzanie poprawności działania funkcji dir_open
//
void UTEST97(void)
{
    // informacje o teście
    test_start(97, "Sprawdzanie poprawności działania funkcji dir_open", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

                        struct disk_t* disk = disk_open_from_file("see_fat16_volume.img");
                        test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                        onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                        struct volume_t* volume = fat_open(disk, 0);
                        test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                        onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                        struct dir_t*  dir = dir_open(volume, "\\Or\\sTOrY\\NinE\\ForCe.BIN");
                        test_error(dir == NULL, "Funkcja dir_open() powinna zwrócić NULL w przypadku podania niepoprawnej nazwy katalogu");
                        onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                        fat_close(volume);
                        disk_close(disk);

                        test_no_heap_leakage();
                        onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
                    
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 98: Sprawdzanie poprawności działania funkcji dir_open
//
void UTEST98(void)
{
    // informacje o teście
    test_start(98, "Sprawdzanie poprawności działania funkcji dir_open", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

                        struct disk_t* disk = disk_open_from_file("see_fat16_volume.img");
                        test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                        onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                        struct volume_t* volume = fat_open(disk, 0);
                        test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                        onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                        struct dir_t*  dir = dir_open(volume, "\\WOMAN\\TRAIN\\cENTER\\WHeRE\\LOSt\\LoG sea rule.eFN");
                        test_error(dir == NULL, "Funkcja dir_open() powinna zwrócić NULL w przypadku podania niepoprawnej nazwy katalogu");
                        onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                        fat_close(volume);
                        disk_close(disk);

                        test_no_heap_leakage();
                        onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
                    
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 99: Sprawdzanie poprawności działania funkcji dir_open
//
void UTEST99(void)
{
    // informacje o teście
    test_start(99, "Sprawdzanie poprawności działania funkcji dir_open", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

                        struct disk_t* disk = disk_open_from_file("see_fat16_volume.img");
                        test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                        onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                        struct volume_t* volume = fat_open(disk, 0);
                        test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                        onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                        struct dir_t*  dir = dir_open(volume, "\\COLD\\DIVidE aM alWAys held\\HEAT\\nouN\\HEAD\\FAT");
                        test_error(dir == NULL, "Funkcja dir_open() powinna zwrócić NULL w przypadku podania niepoprawnej nazwy katalogu");
                        onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                        fat_close(volume);
                        disk_close(disk);

                        test_no_heap_leakage();
                        onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
                    
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 100: Sprawdzanie poprawności działania funkcji dir_open
//
void UTEST100(void)
{
    // informacje o teście
    test_start(100, "Sprawdzanie poprawności działania funkcji dir_open", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

                        struct disk_t* disk = disk_open_from_file("see_fat16_volume.img");
                        test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                        onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                        struct volume_t* volume = fat_open(disk, 0);
                        test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                        onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                        struct dir_t*  dir = dir_open(volume, "\\COLD\\divide am always HELd\\HEAT\\WOMEN\\LONG");
                        test_error(dir == NULL, "Funkcja dir_open() powinna zwrócić NULL w przypadku podania niepoprawnej nazwy katalogu");
                        onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                        fat_close(volume);
                        disk_close(disk);

                        test_no_heap_leakage();
                        onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
                    
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 101: Sprawdzanie poprawności działania funkcji dir_open
//
void UTEST101(void)
{
    // informacje o teście
    test_start(101, "Sprawdzanie poprawności działania funkcji dir_open", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

                        struct disk_t* disk = disk_open_from_file("see_fat16_volume.img");
                        test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                        onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                        struct volume_t* volume = fat_open(disk, 0);
                        test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                        onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                        struct dir_t*  dir = dir_open(volume, "\\THiN\\WaTER\\ADD\\SUBTrACT.TXT");
                        test_error(dir == NULL, "Funkcja dir_open() powinna zwrócić NULL w przypadku podania niepoprawnej nazwy katalogu");
                        onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                        fat_close(volume);
                        disk_close(disk);

                        test_no_heap_leakage();
                        onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
                    
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 102: Sprawdzanie poprawności działania funkcji dir_open
//
void UTEST102(void)
{
    // informacje o teście
    test_start(102, "Sprawdzanie poprawności działania funkcji dir_open", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

                        struct disk_t* disk = disk_open_from_file("see_fat16_volume.img");
                        test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                        onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                        struct volume_t* volume = fat_open(disk, 0);
                        test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                        onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                        struct dir_t*  dir = dir_open(volume, "\\WOMAN\\TRAIN\\LEarN\\FeET\\Life\\NOTHING\\sIX.TxT");
                        test_error(dir == NULL, "Funkcja dir_open() powinna zwrócić NULL w przypadku podania niepoprawnej nazwy katalogu");
                        onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                        fat_close(volume);
                        disk_close(disk);

                        test_no_heap_leakage();
                        onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
                    
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 103: Sprawdzanie poprawności działania funkcji dir_open
//
void UTEST103(void)
{
    // informacje o teście
    test_start(103, "Sprawdzanie poprawności działania funkcji dir_open", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

                        struct disk_t* disk = disk_open_from_file("see_fat16_volume.img");
                        test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                        onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                        struct volume_t* volume = fat_open(disk, 0);
                        test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                        onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                        struct dir_t*  dir = dir_open(volume, "\\THiN\\GonE\\TeAM.TX");
                        test_error(dir == NULL, "Funkcja dir_open() powinna zwrócić NULL w przypadku podania niepoprawnej nazwy katalogu");
                        onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                        fat_close(volume);
                        disk_close(disk);

                        test_no_heap_leakage();
                        onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
                    
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 104: Sprawdzanie poprawności działania funkcji dir_open
//
void UTEST104(void)
{
    // informacje o teście
    test_start(104, "Sprawdzanie poprawności działania funkcji dir_open", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

                struct disk_t* disk = disk_open_from_file("see_fat16_volume.img");
                test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct volume_t* volume = fat_open(disk, 0);
                test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct dir_t*  dir = dir_open(volume, "BOArD.BIN");
                test_error(dir == NULL, "Funkcja dir_open() powinna zwrócić NULL w przypadku podania niepoprawnej nazwy katalogu");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                fat_close(volume);
                disk_close(disk);

                test_no_heap_leakage();
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
            
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 105: Sprawdzanie poprawności działania funkcji dir_open
//
void UTEST105(void)
{
    // informacje o teście
    test_start(105, "Sprawdzanie poprawności działania funkcji dir_open", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

                struct disk_t* disk = disk_open_from_file("see_fat16_volume.img");
                test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct volume_t* volume = fat_open(disk, 0);
                test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct dir_t*  dir = dir_open(volume, "dESERt");
                test_error(dir == NULL, "Funkcja dir_open() powinna zwrócić NULL w przypadku podania niepoprawnej nazwy katalogu");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                fat_close(volume);
                disk_close(disk);

                test_no_heap_leakage();
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
            
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 106: Sprawdzanie poprawności działania funkcji dir_open
//
void UTEST106(void)
{
    // informacje o teście
    test_start(106, "Sprawdzanie poprawności działania funkcji dir_open", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

                struct disk_t* disk = disk_open_from_file("see_fat16_volume.img");
                test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct volume_t* volume = fat_open(disk, 0);
                test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct dir_t*  dir = dir_open(volume, "ROOM.biN");
                test_error(dir == NULL, "Funkcja dir_open() powinna zwrócić NULL w przypadku podania niepoprawnej nazwy katalogu");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                fat_close(volume);
                disk_close(disk);

                test_no_heap_leakage();
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
            
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 107: Sprawdzanie poprawności działania funkcji dir_open
//
void UTEST107(void)
{
    // informacje o teście
    test_start(107, "Sprawdzanie poprawności działania funkcji dir_open", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

                struct disk_t* disk = disk_open_from_file("see_fat16_volume.img");
                test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct volume_t* volume = fat_open(disk, 0);
                test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct dir_t*  dir = dir_open(volume, "GReEn.BIn");
                test_error(dir == NULL, "Funkcja dir_open() powinna zwrócić NULL w przypadku podania niepoprawnej nazwy katalogu");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                fat_close(volume);
                disk_close(disk);

                test_no_heap_leakage();
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
            
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 108: Sprawdzanie poprawności działania funkcji dir_open
//
void UTEST108(void)
{
    // informacje o teście
    test_start(108, "Sprawdzanie poprawności działania funkcji dir_open", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

                struct disk_t* disk = disk_open_from_file("see_fat16_volume.img");
                test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct volume_t* volume = fat_open(disk, 0);
                test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct dir_t*  dir = dir_open(volume, "EQUAL.tx");
                test_error(dir == NULL, "Funkcja dir_open() powinna zwrócić NULL w przypadku podania niepoprawnej nazwy katalogu");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                fat_close(volume);
                disk_close(disk);

                test_no_heap_leakage();
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
            
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 109: Sprawdzanie poprawności działania funkcji dir_open
//
void UTEST109(void)
{
    // informacje o teście
    test_start(109, "Sprawdzanie poprawności działania funkcji dir_open", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

                struct disk_t* disk = disk_open_from_file("see_fat16_volume.img");
                test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct volume_t* volume = fat_open(disk, 0);
                test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct dir_t*  dir = dir_open(volume, "TEn");
                test_error(dir == NULL, "Funkcja dir_open() powinna zwrócić NULL w przypadku podania niepoprawnej nazwy katalogu");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                fat_close(volume);
                disk_close(disk);

                test_no_heap_leakage();
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
            
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 110: Sprawdzanie poprawności działania funkcji dir_open
//
void UTEST110(void)
{
    // informacje o teście
    test_start(110, "Sprawdzanie poprawności działania funkcji dir_open", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

                struct disk_t* disk = disk_open_from_file("see_fat16_volume.img");
                test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct volume_t* volume = fat_open(disk, 0);
                test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct dir_t*  dir = dir_open(volume, "GamE.txT");
                test_error(dir == NULL, "Funkcja dir_open() powinna zwrócić NULL w przypadku podania niepoprawnej nazwy katalogu");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                fat_close(volume);
                disk_close(disk);

                test_no_heap_leakage();
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
            
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 111: Sprawdzanie poprawności działania funkcji dir_open
//
void UTEST111(void)
{
    // informacje o teście
    test_start(111, "Sprawdzanie poprawności działania funkcji dir_open", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

                struct disk_t* disk = disk_open_from_file("see_fat16_volume.img");
                test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct volume_t* volume = fat_open(disk, 0);
                test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct dir_t*  dir = dir_open(volume, "baR Last WIfe led SCale ReacH vAlUE oFFEr.JII");
                test_error(dir == NULL, "Funkcja dir_open() powinna zwrócić NULL w przypadku podania niepoprawnej nazwy katalogu");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                fat_close(volume);
                disk_close(disk);

                test_no_heap_leakage();
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
            
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 112: Sprawdzanie poprawności działania funkcji dir_open
//
void UTEST112(void)
{
    // informacje o teście
    test_start(112, "Sprawdzanie poprawności działania funkcji dir_open", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

                struct disk_t* disk = disk_open_from_file("see_fat16_volume.img");
                test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct volume_t* volume = fat_open(disk, 0);
                test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct dir_t*  dir = dir_open(volume, "SUBsTaNC");
                test_error(dir == NULL, "Funkcja dir_open() powinna zwrócić NULL w przypadku podania niepoprawnej nazwy katalogu");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                fat_close(volume);
                disk_close(disk);

                test_no_heap_leakage();
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
            
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 113: Sprawdzanie poprawności działania funkcji dir_open
//
void UTEST113(void)
{
    // informacje o teście
    test_start(113, "Sprawdzanie poprawności działania funkcji dir_open", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

            struct disk_t* disk = disk_open_from_file("see_fat16_volume.img");
            test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

            struct volume_t* volume = fat_open(disk, 0);
            test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

            struct dir_t*  dir = dir_open(volume, "Slip");
            test_error(dir == NULL, "Funkcja dir_open() powinna zwrócić NULL w przypadku podania niepoprawnej nazwy katalogu");
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

            fat_close(volume);
            disk_close(disk);

            test_no_heap_leakage();
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
        
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}




enum run_mode_t { rm_normal_with_rld = 0, rm_unit_test = 1, rm_main_test = 2 };

int __wrap_main(volatile int _argc, char** _argv, char** _envp)
{
    int volatile vargc = _argc;
    char ** volatile vargv = _argv, ** volatile venvp = _envp;
	volatile enum run_mode_t run_mode = rm_unit_test; // -1
	volatile int selected_test = -1;

    if (vargc > 1)
	{
	    char* smode = strtok(vargv[1], ",");
	    char* stest = strtok(NULL, "");
		char *errptr = NULL;
		run_mode = (enum run_mode_t)strtol(smode, &errptr, 10);
		if (*errptr == '\x0')
		{
			memmove(vargv + 1, vargv + 2, sizeof(char*) * (vargc - 1));
			vargc--;

			if (stest != NULL)
			{
			    int val = (int)strtol(stest, &errptr, 10);
			    if (*errptr == '\x0')
			        selected_test = val;
			}
		}
	}

    // printf("runmode=%d; selected_test=%d\n", run_mode, selected_test);

    // inicjuj testy jednostkowe
    unit_test_init(run_mode, "unit_test_v2.c");
    test_limit_init();
    rldebug_set_reported_severity_level(MSL_FAILURE);

    if (run_mode == rm_normal_with_rld)
    {
        // konfiguracja ograniczników
        rldebug_reset_limits();
        

        // uruchom funkcję main Studenta a potem wyświetl podsumowanie sterty i zasobów
        volatile int ret_code = rdebug_call_main(tested_main, vargc, vargv, venvp);

        rldebug_reset_limits();
        

        int leaks_detected = rldebug_show_leaked_resources(0);
        if (leaks_detected)
            raise(SIGHEAP);

        return ret_code;
    }

    
    if (run_mode == rm_unit_test)
    {
        test_title("Testy jednostkowe");

        void (*pfcn[])(void) =
        { 
            UTEST1, // Sprawdzanie poprawności działania funkcji disk_open_from_file
            UTEST2, // Sprawdzanie poprawności działania funkcji disk_open_from_file
            UTEST3, // Sprawdzanie poprawności działania funkcji disk_close
            UTEST4, // Sprawdzanie poprawności działania funkcji fat_open
            UTEST5, // Sprawdzanie poprawności działania funkcji disk_open_from_file
            UTEST6, // Sprawdzanie poprawności działania funkcji file_read
            UTEST7, // Sprawdzanie poprawności działania funkcji file_read
            UTEST8, // Sprawdzanie poprawności działania funkcji file_read
            UTEST9, // Sprawdzanie poprawności działania funkcji file_read
            UTEST10, // Sprawdzanie poprawności działania funkcji file_read
            UTEST11, // Sprawdzanie poprawności działania funkcji file_read
            UTEST12, // Sprawdzanie poprawności działania funkcji file_read
            UTEST13, // Sprawdzanie poprawności działania funkcji file_read
            UTEST14, // Sprawdzanie poprawności działania funkcji file_read
            UTEST15, // Sprawdzanie poprawności działania funkcji file_read
            UTEST16, // Sprawdzanie poprawności działania funkcji file_read
            UTEST17, // Sprawdzanie poprawności działania funkcji file_read
            UTEST18, // Sprawdzanie poprawności działania funkcji file_read
            UTEST19, // Sprawdzanie poprawności działania funkcji file_read
            UTEST20, // Sprawdzanie poprawności działania funkcji file_read
            UTEST21, // Sprawdzanie poprawności działania funkcji file_read
            UTEST22, // Sprawdzanie poprawności działania funkcji file_read
            UTEST23, // Sprawdzanie poprawności działania funkcji file_read
            UTEST24, // Sprawdzanie poprawności działania funkcji file_read
            UTEST25, // Sprawdzanie poprawności działania funkcji file_read
            UTEST26, // Sprawdzanie poprawności działania funkcji file_read
            UTEST27, // Sprawdzanie poprawności działania funkcji file_read
            UTEST28, // Sprawdzanie poprawności działania funkcji file_read
            UTEST29, // Sprawdzanie poprawności działania funkcji file_read
            UTEST30, // Sprawdzanie poprawności działania funkcji file_read
            UTEST31, // Sprawdzanie poprawności działania funkcji file_read
            UTEST32, // Sprawdzanie poprawności działania funkcji file_read
            UTEST33, // Sprawdzanie poprawności działania funkcji file_read
            UTEST34, // Sprawdzanie poprawności działania funkcji file_read
            UTEST35, // Sprawdzanie poprawności działania funkcji file_read
            UTEST36, // Sprawdzanie poprawności działania funkcji file_read
            UTEST37, // Sprawdzanie poprawności działania funkcji file_read
            UTEST38, // Sprawdzanie poprawności działania funkcji file_read
            UTEST39, // Sprawdzanie poprawności działania funkcji file_read
            UTEST40, // Sprawdzanie poprawności działania funkcji file_read
            UTEST41, // Sprawdzanie poprawności działania funkcji file_read
            UTEST42, // Sprawdzanie poprawności działania funkcji file_read
            UTEST43, // Sprawdzanie poprawności działania funkcji file_read
            UTEST44, // Sprawdzanie poprawności działania funkcji file_read
            UTEST45, // Sprawdzanie poprawności działania funkcji file_read
            UTEST46, // Sprawdzanie poprawności działania funkcji file_read
            UTEST47, // Sprawdzanie poprawności działania funkcji file_read
            UTEST48, // Sprawdzanie poprawności działania funkcji file_read
            UTEST49, // Sprawdzanie poprawności działania funkcji file_read
            UTEST50, // Sprawdzanie poprawności działania funkcji file_read
            UTEST51, // Sprawdzanie poprawności działania funkcji file_read
            UTEST52, // Sprawdzanie poprawności działania funkcji file_read
            UTEST53, // Sprawdzanie poprawności działania funkcji file_read
            UTEST54, // Sprawdzanie poprawności działania funkcji file_read
            UTEST55, // Sprawdzanie poprawności działania funkcji file_read
            UTEST56, // Sprawdzanie poprawności działania funkcji file_read
            UTEST57, // Sprawdzanie poprawności działania funkcji file_read
            UTEST58, // Sprawdzanie poprawności działania funkcji file_read
            UTEST59, // Sprawdzanie poprawności działania funkcji file_read
            UTEST60, // Sprawdzanie poprawności działania funkcji file_read
            UTEST61, // Sprawdzanie poprawności działania funkcji file_read
            UTEST62, // Sprawdzanie poprawności działania funkcji file_read
            UTEST63, // Sprawdzanie poprawności działania funkcji file_read
            UTEST64, // Sprawdzanie poprawności działania funkcji file_read
            UTEST65, // Sprawdzanie poprawności działania funkcji file_read
            UTEST66, // Sprawdzanie poprawności działania funkcji file_read
            UTEST67, // Sprawdzanie poprawności działania funkcji file_seek
            UTEST68, // Sprawdzanie poprawności działania funkcji file_seek
            UTEST69, // Sprawdzanie poprawności działania funkcji file_seek
            UTEST70, // Sprawdzanie poprawności działania funkcji file_open
            UTEST71, // Sprawdzanie poprawności działania funkcji file_open
            UTEST72, // Sprawdzanie poprawności działania funkcji file_open
            UTEST73, // Sprawdzanie poprawności działania funkcji file_open
            UTEST74, // Sprawdzanie poprawności działania funkcji file_open
            UTEST75, // Sprawdzanie poprawności działania funkcji file_open
            UTEST76, // Sprawdzanie poprawności działania funkcji file_open
            UTEST77, // Sprawdzanie poprawności działania funkcji file_open
            UTEST78, // Sprawdzanie poprawności działania funkcji file_open
            UTEST79, // Sprawdzanie poprawności działania funkcji file_open
            UTEST80, // Sprawdzanie poprawności działania funkcji file_open
            UTEST81, // Sprawdzanie poprawności działania funkcji file_open
            UTEST82, // Sprawdzanie poprawności działania funkcji file_open
            UTEST83, // Sprawdzanie poprawności działania funkcji file_open
            UTEST84, // Sprawdzanie poprawności działania funkcji file_open
            UTEST85, // Sprawdzanie poprawności działania funkcji file_open
            UTEST86, // Sprawdzanie poprawności działania funkcji file_open
            UTEST87, // Sprawdzanie poprawności działania funkcji file_read
            UTEST88, // Sprawdzanie poprawności działania funkcji file_read
            UTEST89, // Sprawdzanie poprawności działania funkcji file_read
            UTEST90, // Sprawdzanie poprawności działania funkcji file_close
            UTEST91, // Sprawdzanie poprawności działania funkcji file_read
            UTEST92, // Sprawdzanie poprawności działania funkcji dir_read
            UTEST93, // Sprawdzanie poprawności działania funkcji dir_read
            UTEST94, // Sprawdzanie poprawności działania funkcji dir_read
            UTEST95, // Sprawdzanie poprawności działania funkcji dir_open
            UTEST96, // Sprawdzanie poprawności działania funkcji dir_open
            UTEST97, // Sprawdzanie poprawności działania funkcji dir_open
            UTEST98, // Sprawdzanie poprawności działania funkcji dir_open
            UTEST99, // Sprawdzanie poprawności działania funkcji dir_open
            UTEST100, // Sprawdzanie poprawności działania funkcji dir_open
            UTEST101, // Sprawdzanie poprawności działania funkcji dir_open
            UTEST102, // Sprawdzanie poprawności działania funkcji dir_open
            UTEST103, // Sprawdzanie poprawności działania funkcji dir_open
            UTEST104, // Sprawdzanie poprawności działania funkcji dir_open
            UTEST105, // Sprawdzanie poprawności działania funkcji dir_open
            UTEST106, // Sprawdzanie poprawności działania funkcji dir_open
            UTEST107, // Sprawdzanie poprawności działania funkcji dir_open
            UTEST108, // Sprawdzanie poprawności działania funkcji dir_open
            UTEST109, // Sprawdzanie poprawności działania funkcji dir_open
            UTEST110, // Sprawdzanie poprawności działania funkcji dir_open
            UTEST111, // Sprawdzanie poprawności działania funkcji dir_open
            UTEST112, // Sprawdzanie poprawności działania funkcji dir_open
            UTEST113, // Sprawdzanie poprawności działania funkcji dir_open
            NULL
        };

        for (int idx = 0; pfcn[idx] != NULL && !test_get_session_termination_flag(); idx++)
        {
            if (selected_test == -1 || selected_test == idx + 1)
                pfcn[idx]();

            // limit niezaliczonych testów, po jakim testy jednostkowe zostaną przerwane
            if (test_session_get_fail_count() >= 1000)
                test_terminate_session();
        }


        test_title("RLDebug :: Analiza wycieku zasobów");
        // sprawdź wycieki pamięci
        int leaks_detected = rldebug_show_leaked_resources(1);
        test_set_session_leaks(leaks_detected);

        // poinformuj serwer Mrówka o wyniku testu - podsumowanie
        test_title("Podsumowanie");
        if (selected_test == -1)
            test_summary(113); // wszystkie testy muszą zakończyć się sukcesem
        else
            test_summary(1); // tylko jeden (selected_test) test musi zakończyć się  sukcesem
        return EXIT_SUCCESS;
    }
    

    if (run_mode == rm_main_test)
    {
        test_title("Testy funkcji main()");

        void (*pfcn[])(int, char**, char**) =
        { 
            NULL
        };

        for (volatile int idx = 0; pfcn[idx] != NULL && !test_get_session_termination_flag(); idx++)
        {
            if (selected_test == -1 || selected_test == idx + 1)
                pfcn[idx](vargc, vargv, venvp);

            // limit niezaliczonych testów, po jakim testy jednostkowe zostaną przerwane
            if (test_session_get_fail_count() >= 1000)
                test_terminate_session();
        }


        test_title("RLDebug :: Analiza wycieku zasobów");
        // sprawdź wycieki pamięci
        int leaks_detected = rldebug_show_leaked_resources(1);
        test_set_session_leaks(leaks_detected);

        // poinformuj serwer Mrówka o wyniku testu - podsumowanie
        test_title("Podsumowanie");
        if (selected_test == -1)
            test_summary(0); // wszystkie testy muszą zakończyć się sukcesem
        else
            test_summary(1); // tylko jeden (selected_test) test musi zakończyć się  sukcesem

        return EXIT_SUCCESS;
    }

    printf("*** Nieznana wartość RunMode: %d", (int)run_mode);
    abort();
}