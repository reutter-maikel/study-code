/*
 * File: main.c
 * Description: main program that uses the playlist API
 */

 #include "include/playlist.h"

 

 int main()

 {
    printf("The maximum of songs in the playlist is: %d\n", MAX_SONGS);
    printf("\n");

    Playlist* myPlaylist = init_playlist();

    add_song(myPlaylist, "Crawling", "Linkin Park"); // Add a song to the playlist
	add_song(myPlaylist, "Layla", "Eric Clapton");
	add_song(myPlaylist, "Esperanto", "Max Herre");

	print_playlist(myPlaylist);
	
	delete_firstSong(myPlaylist); // Delete the first song from the playlist

	print_playlist(myPlaylist); // Print the playlist after deleting the first song





    return 0;
 }


