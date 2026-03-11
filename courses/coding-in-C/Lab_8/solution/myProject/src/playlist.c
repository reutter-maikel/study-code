/*
 * File: playlist.c
 * Description: implement a music playlist manager, including a preprocessor macro MAX_SONGS
 */

#include "../include/playlist.h" // include the preprocessor macro MAX_Songs

#define _CRT_SECURE_NO_WARNINGS // ignore the warnings of strcpy

// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>



//  // Define the structure for a song
// typedef struct Song
// {
// 	char *arrSong_title;
// 	char *arrArtist;
// 	struct Song* pnext;
// } Song;

// // Define the structure for a playlist with starting point as the head of the playlist
// typedef struct
// {
// 	struct Song* phead;
//     int countSongs; // variable to count the numbers of Songs in the playlist
// } Playlist;




/**
* @brief		function to initialize an empty playlist
* param[in]		no parameters, playlist is initialized as empty
* param[out]	returns an empty playlist, with the head pointer and number of songs set to NULL
**/

Playlist* init_playlist()
{
	Playlist* pl = malloc(sizeof *pl); // Allocate memory for the playlist
	if (pl == NULL)
	{
		printf("Memory allocation failed for playlist\n");
		return NULL; //	Exit with an error code, if memory allocation fails
	}

	pl->phead = NULL; // Initialize the head of the playlist to NULL, indicating an empty playlist
    pl->countSongs = 0; // initialize the number of songs = 0

	return pl; // returns an empty playlist
}

/*
 * @brief		function to add a new song to the playlist
 * param[in]	pl: pointer to the playlist to which the song will be added
 * param[in2]	const char* title: the title of the song to be added
 * param[in3]	const char* artist: the artist of the song to be added
 * param[out]	no output value, function modifies the playlist by adding a new song to it
 */

void add_song(Playlist *pl, const char* title, const char* artist)
{
    if(pl->countSongs > MAX_SONGS)
    {
        printf("The maximum of %d Songs in the playlist is reached.\n", MAX_SONGS);
        return;
    }


	Song* newSong = malloc(sizeof *newSong); // Allocate memory for a new song
	if (newSong == NULL)
	{
		printf("Memory allocation failed for new song\n");
		return; // Exit with an error code, if memory allocation fails
	}

	// allocate memory for song title and artist, and copy the input strings to the new song structure
	newSong->arrSong_title = malloc(strlen(title) +1); // +1 for the null terminator
	newSong->arrArtist = malloc(strlen(artist) + 1); // +1 for the null terminator) + 1);
	
	strcpy(newSong->arrArtist, artist); // Copy the artist name to the new song structure
	strcpy(newSong->arrSong_title, title); // Copy the song title to the new song structure

	newSong->pnext = NULL; // new song will be added at the end of the playlist, so the next element is null

	// If the playlist is empty, set the new song as the head of the playlist
	if (pl->phead == NULL)
	{
		pl->phead = newSong; // If the playlist is empty, set the new song as the head of the playlist
		return;
	}

	// If the playlist is not empty, traverse to the end of the playlist and add the new song
	Song* current = pl->phead; 
	while (current->pnext != NULL)
	{
		current = current->pnext; // Traverse the playlist to find the last song
	}
	current->pnext = newSong; // Start from the head of the playlist

    pl->countSongs++; // if new song is added to the playlist, the number of songs will be incremented
}


/*
 * @brief		function to print the playlist
 * Param[in]	pointer to the playlist to be printed
 * Param[out]	no return value, the function prints title and artist of each song in the playlist to the console
*/

void print_playlist(Playlist* pl)

{
	Song* current = pl->phead; // Start from the head of the playlist
	while (current != NULL)
	{
		printf("Title: %s, Artist: %s\n", current->arrSong_title, current->arrArtist); // Print the title and artist of the current song);
		current = current->pnext; // Move to the next song in the playlist
	}
	printf("\n"); // Print a newline for better readability after printing the playlist
}

/*
 * @brief		function to delete the first song
 * Param[in]	pointer to the playlist from which the first song will be deleted
 * Param[out]	no return value, the function modifies the playlist by removing the first song and freeing the associated memory
*/

void delete_firstSong(Playlist* pl)
{
	// check if playlist is empty
	if (pl->phead == NULL)
	{
		printf("Playlist is empty, no song to delete\n");
		return; // Exit if the playlist is empty
	}


	Song* temp = pl->phead; // Store the current head of the playlist in a temporary variable
	pl->phead = temp->pnext; // Update the head of the playlist to the next song

	// Free the memory allocated for the deleted song
	free(temp->arrSong_title); // Free the memory allocated for the song title of the deleted song
	free(temp->arrArtist); // Free the memory allocated for the artist of the deleted song
	free(temp); // Free the memory allocated for the deleted song structure

    pl->countSongs--; // if one song is deleted, the number of songs increases

}

/*
 * @brief		function to delete the entire playlist
 * param[in]
 * param[out]
*/

void delete_playlist(Playlist* pl)
{
	while (pl->phead != NULL) // Loop until the playlist is empty
	{
		delete_firstSong(pl); // Delete the first song in the playlist, which will also free the associated memory
	}
    pl->countSongs = 0; // if the whole playlist is deleted, the number of songs will be 0
}


// int main()
// {
// 	Playlist* myPlaylist = init_playlist(); // Initialize an empty playlist

// 	add_song(myPlaylist, "Crawling", "Linkin Park"); // Add a song to the playlist
// 	add_song(myPlaylist, "Layla", "Eric Clapton");
// 	add_song(myPlaylist, "Esperanto", "Max Herre");

// 	print_playlist(myPlaylist);
	
// 	delete_firstSong(myPlaylist); // Delete the first song from the playlist

// 	print_playlist(myPlaylist); // Print the playlist after deleting the first song



// 	// delete_playlist(myPlaylist); // Delete the entire playlist and free all associated memory
// 	// free(myPlaylist); // Free the memory allocated for the playlist structure

// 	// Print the playlist after deleting the entire playlist, should indicate that the playlist is empty

// }