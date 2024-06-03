/*
** EPITECH PROJECT, 2023
** graph.h
** File description:
** macro for CSFML
*/

#include "rpg.h"

void anim_effect_long(
    effect_t *effect, bool ticks)
{
    if (ticks) {
        effect->rect_sprite.left += effect->size.x;
        if (effect->rect_sprite.left >= effect->size.x * effect->offset.x)
            effect->rect_sprite.left = 0;
        sfSprite_setTextureRect(effect->sprite, effect->rect_sprite);
    }
}
