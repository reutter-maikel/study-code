/*
 * File: playlist.h
 * Description: Header file for implementation of playlist functions
 */

// using Header Guards to avoid multiple inclusions
#ifndef MYPLAYLIST_H
#define MYPLAYLIST_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a maximum of 15 songs allowed in the playlist
#define MAX_SONGS 15

// declare the structs which are involved
typedef struct Song
{
	char *arrSong_title;
	char *arrArtist;
	struct Song* pnext;
} Song;

typedef struct
{
	struct Song* phead;
    int countSongs; // new variable to count the numbers of songs in the list
} Playlist;


// declare the functions to include them in the following files
void add_song(Playlist *pl, const char *title, const char *artist);
Playlist* init_playlist();
void print_playlist(Playlist* pl);
void delete_firstSong(Playlist* pl);
void delete_playlist(Playlist* pl);


#endif 