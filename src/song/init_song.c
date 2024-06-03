/*
** EPITECH PROJECT, 2024
** init_song
** File description:
** init_song
*/

#include "rpg.h"

void init_song(rpg_t *rpg)
{
    rpg->song = malloc(sizeof(song_management_t));
    rpg->song->volume = 50.f;
    rpg->song->song_tab[SWORD_S] = sfMusic_createFromFile(SWORD_SONG);
    rpg->song->song_tab[GUTS_S] = sfMusic_createFromFile(GUTS_SONG);
}

void set_all_volume(rpg_t *rpg)
{
    for (int i = 0; i < GUTS_S; i++) {
        sfMusic_setVolume(rpg->song->song_tab[i], rpg->song->volume);
    }
}

static void destroy_song(sfMusic *music)
{
    if (music) {
        sfMusic_destroy(music);
        music = NULL;
    }
}

void destroy_all_song(song_management_t *song_management)
{
    if (song_management) {
        for (int i = 0; i <= GUTS_S; i++) {
            destroy_song(song_management->song_tab[i]);
        }
        free(song_management);
    }
}

int launch_sword_song(rpg_t *rpg)
{
    sfMusic_stop(rpg->song->song_tab[SWORD_S]);
    sfMusic_play(rpg->song->song_tab[SWORD_S]);
    return 1;
}
