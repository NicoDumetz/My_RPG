/*
** EPITECH PROJECT, 2024
** song
** File description:
** song
*/

#ifndef SONG_H
    #define SONG_H
    #include "lib.h"
    #define GUTS "music/guts.wav"

typedef struct play_song_s {
    sfMusic *music;
    float volume;
} play_song_t;

typedef struct song_management_s {
    play_song_t music;
    play_song_t sword;
} song_management_t;


void init_song(rpg_t *rpg);
void destroy_all_song(song_management_t *song_management);
#endif
