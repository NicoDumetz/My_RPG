/*
** EPITECH PROJECT, 2023
** graph.h
** File description:
** macro for CSFML
*/

#include "rpg.h"

void align_deco_n_info_bar(
    sfVector2f rect_pos, sfVector2f rect_size, sfSprite* sprite)
{
    sfVector2f rect_center =
        {rect_pos.x + rect_size.x / 2, rect_pos.y + rect_size.y / 2};
    sfFloatRect sprite_bounds = sfSprite_getGlobalBounds(sprite);
    sfVector2f sprite_center =
        {sprite_bounds.width / 2, sprite_bounds.height / 2};

    sfSprite_setOrigin(sprite, sprite_center);
    sfSprite_setPosition(sprite, rect_center);
}

void update_bar(info_bar_t *info, sfVector2f pos)
{
    float ratio_act_max = info->act / info->max;
    float new_x = info->size.x * ratio_act_max;

    sfRectangleShape_setSize(info->bar, (sfVector2f){new_x, info->size.y});
    sfRectangleShape_setPosition(info->bar, pos);
    if (info->deco)
        align_deco_n_info_bar(pos, info->size, info->deco);
}
