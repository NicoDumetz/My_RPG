/*
** EPITECH PROJECT, 2024
** song
** File description:
** song
*/

#ifndef SONG_H
    #define SONG_H
    #include "lib.h"
    #define GUTS_SONG "assets/music/guts.wav"
    #define SWORD_SONG "assets/music/sword.wav"

typedef enum music_type_e {
    SWORD_S,
    GUTS_S
} music_type_t;

typedef struct song_management_s {
    sfMusic *song_tab[GUTS_S + 1];
    float volume;
} song_management_t;


void init_song(rpg_t *rpg);
void set_all_volume(rpg_t *rpg, float volume);
void destroy_all_song(song_management_t *song_management);
int launch_sword_song(rpg_t *rpg);
#endif
