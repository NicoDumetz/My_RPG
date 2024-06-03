/*
** EPITECH PROJECT, 2023
** graph.h
** File description:
** macro for CSFML
*/

#include "rpg.h"

void anim_obj_short(
    front_obj_t *obj, sfVector2i offset, bool ticks)
{
    if (ticks) {
        obj->entity->rect_sprite.top = obj->entity->size.y * offset.y;
        obj->entity->rect_sprite.left += obj->entity->size.x;
        if (obj->entity->rect_sprite.left >= obj->entity->size.x * offset.x) {
            obj->is_active = false;
            obj->entity->rect_sprite.left = 0;
            return;
        }
        sfSprite_setTextureRect(obj->entity->sprite, obj->entity->rect_sprite);
    }
}
