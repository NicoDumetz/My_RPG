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
    bool end_scroll;
    sfSprite *back;
    sfSprite *header;
    sfSprite *footer;
    button_t *exit;
    float begin_button_list;
    button_t *button_list;
} save_scene_t;

typedef struct save_data_s {
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
} save_data_t;

typedef struct save_s {
    save_data_t *data;
    sfText *name;
    struct save_s *next;
    struct save_s *prev;
} save_t;

/**INIT**/
save_scene_t *init_load_page(sfTexture **text_tab);
void destroy_load_page(save_scene_t *save_scene);
void add_load_button_to_list(save_scene_t *save_scene, button_t *button);
#endif