/*
** EPITECH PROJECT, 2024
** movements
** File description:
** movements
*/

#include "rpg.h"

/**
    int text_id_front;
    int text_id_back;
    int time_left;
    bool is_pickable;
    bool is_short;
    sfVector2i offset;
    sfVector2i rect_quad;
*/

obj_template_t obj_tab[] = {
    {DEATH_TEXT, -1, -1, false, true, (sfVector2i){7, 2}, (sfVector2i){7, 0}},
    {BAG_TEXT, -1, 120, true, false, (sfVector2i){7, 1}, (sfVector2i){7, 0}}
};
