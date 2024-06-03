/*
** EPITECH PROJECT, 2023
** graph.h
** File description:
** macro for CSFML
*/

#include "rpg.h"

void anim_obj_long(
    front_obj_t *obj, sfVector2i offset, bool ticks)
{
    if (ticks) {
        obj->rect_sprite.top = obj->size.y * offset.y;
        obj->rect_sprite.left += obj->size.x;
        if (obj->rect_sprite.left >= obj->size.x * offset.x) {
            obj->rect_sprite.left = 0;
            return;
        }
        sfSprite_setTextureRect(obj->sprite, obj->rect_sprite);
    }
}
