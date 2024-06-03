/*
** EPITECH PROJECT, 2023
** graph.h
** File description:
** macro for CSFML
*/

#ifndef SAVE_H
    #define SAVE_H
    #include "lib.h"

typedef struct button_s button_t;
typedef struct save_scene_s {
    int from;
    sfSprite *back;
    sfSprite *header;
    sfSprite *footer;
    button_t *save;
    button_t *exit;
    button_t *button_list;
} save_scene_t;

typedef struct save_s {
    time_t time_last_save;
    int x_heros;
    int y_heros;
    int level_heros;
    int heros_xp;
    int heros_stami;
    int heros_pv;
    int id_biome;
    int object_id_inv[20];
    int object_id_equip[6];
    int end_save;
    struct save_s *next;
    struct save_s *prev;
} save_t;
#endif
