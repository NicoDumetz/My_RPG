/*
** EPITECH PROJECT, 2024
** init_song
** File description:
** init_song
*/

#include "rpg.h"



static play_song_t create_song(const char *file, float vol)
{
    play_song_t song;

    song.music = sfMusic_createFromFile(file);
    if (!song.music) {
        fprintf(stderr, "Error with song files\n");
        exit(84);
    } else {
        song.volume = vol;
        sfMusic_setVolume(song.music, vol);
    }
    return song;
}

void init_song(rpg_t *rpg)
{
    rpg->song = malloc(sizeof(song_management_t));
    if (!rpg->song)
        exit(84);
    rpg->song->music = create_song(GUTS, 50.0f);
    rpg->song->sword.music = NULL;
    sfMusic_play(rpg->song->music.music);
}

static void destroy_play_song(play_song_t *song)
{
    if (song && song->music) {
        sfMusic_destroy(song->music);
        song->music = NULL;
    }
}

void destroy_all_song(song_management_t *song_management)
{
    if (song_management) {
        destroy_play_song(&song_management->music);
        destroy_play_song(&song_management->sword);
        free(song_management);
    }
}
