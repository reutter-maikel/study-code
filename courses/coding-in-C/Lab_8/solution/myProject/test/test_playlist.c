#include <assert.h>
#include <string.h>
#include <stdio.h>
#include "../include/playlist.h"

/* === Unit-tests === */

// example unit test
void test_init_playlist()
{
    Playlist p;
    init_playlist(&p);

    assert(p.phead == NULL);
    assert(p.countSongs == 0);
}

//testing add_song function
void test_add_song()
{
    Playlist p;
    init_playlist(&p);
    
    add_song(&p, "title1", "artist1");

    assert(p.countSongs == 1);
}

// testing delete first song function
void test_delete_firstSong()
{
        Playlist p;
        init_playlist(&p);

        add_song(&p, "title1", "title1");
        add_song(&p, "title2", "title2");

        delete_firstSong(&p);

        //assert(p.phead == NULL);
        assert(p.countSongs == 1);
}

// testing delete first song while playlist is empty
void test_delete_firstSong_empty()
    {
        Playlist p;
        init_playlist(&p);

        delete_firstSong(&p);

        assert(p.phead == NULL);
        assert(p.countSongs == 0);
    }


void test_delete_playlist()
    {
         Playlist p;
        init_playlist(&p);

        add_song(&p, "title1", "title1");
        add_song(&p, "title2", "title2");

        delete_playlist(&p);

        assert(p.phead == NULL);
        assert(p.countSongs == 0);
    }

    void test_max_songs_limit()
    {
        Playlist p;
        init_playlist(&p);

        for(int i = 0; i < MAX_SONGS; i++)
        {
            add_song(&p, "jjgjbdfb", "kkkk");
        }

        assert(p.countSongs == MAX_SONGS);
    }

/* === Test-Runner === */

int main(void)
{
    test_init_playlist();

    test_add_song();

    test_delete_firstSong();

    test_delete_firstSong_empty(); // what happens if we delete first song from empty playlist
     
    test_delete_playlist();
   
    test_max_songs_limit(); // verify if the limit will be not be surpassed

    printf("Alle Playlist-Tests erfolgreich bestanden.\n");
    return 0;
}
