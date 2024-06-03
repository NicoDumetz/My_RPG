/*
** EPITECH PROJECT, 2023
** graph.h
** File description:
** macro for CSFML
*/

#include "rpg.h"

void reverse_sprite(entity_t *entity, sfVector2i offset, bool ticks)
{
    sfVector2f origin = sfSprite_getOrigin(entity->sprite);

    if (!entity->is_reverse) {
        sfSprite_setScale(entity->sprite, (sfVector2f){-1, 1});
        sfSprite_setOrigin(
            entity->sprite, (sfVector2f){entity->size.x - origin.x, origin.y});
        entity->is_reverse = 1;
    }
    entity->rect_sprite.top = ABS(offset.y) * entity->size.y;
    if (ticks) {
        entity->rect_sprite.left -= entity->size.x;
        if (entity->rect_sprite.left <= 0)
            entity->rect_sprite.left = entity->size.x * (offset.x - 1);
        sfSprite_setTextureRect(entity->sprite, entity->rect_sprite);
    }
}

void right_sprite(entity_t *entity, sfVector2i offset, bool ticks)
{
    sfVector2f origin = sfSprite_getOrigin(entity->sprite);

    if (entity->is_reverse) {
        sfSprite_setScale(entity->sprite, (sfVector2f){1, 1});
        sfSprite_setOrigin(entity->sprite, (sfVector2f){0, origin.y});
        entity->is_reverse = 0;
    }
    entity->rect_sprite.top = ABS(offset.y) * entity->size.y;
    if (ticks) {
        entity->rect_sprite.left += entity->size.x;
        if (entity->rect_sprite.left >= entity->size.x * offset.x)
            entity->rect_sprite.left = 0;
        sfSprite_setTextureRect(entity->sprite, entity->rect_sprite);
    }
}

void anim_entity(entity_t *entity, sfVector2i offset, bool ticks)
{
    if (offset.y >= 0)
        right_sprite(entity, offset, ticks);
    else
        reverse_sprite(entity, offset, ticks);
}
