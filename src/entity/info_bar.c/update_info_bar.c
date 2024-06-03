/*
** EPITECH PROJECT, 2023
** graph.h
** File description:
** macro for CSFML
*/

#include "rpg.h"

void update_bar(info_bar_t *info, sfVector2f pos)
{
    float ratio_act_max = info->act / info->max;
    float new_x = info->size.x * ratio_act_max;

    sfRectangleShape_setSize(info->bar, (sfVector2f){new_x, info->size.y});
    sfRectangleShape_setPosition(info->bar, pos);
}
