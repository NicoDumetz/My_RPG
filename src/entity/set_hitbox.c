/*
** EPITECH PROJECT, 2023
** graph.h
** File description:
** macro for CSFML
*/

#include "rpg.h"

void set_hitbox(entity_t *entity)
{
    float padded_top = (entity->size.y * entity->hitbox_dim.top) / 100.0;
    float padded_left = (entity->size.x * entity->hitbox_dim.left) / 100.0;
    float padded_right = (entity->size.x * entity->hitbox_dim.width) / 100.0;
    float padded_bottom = (entity->size.y * entity->hitbox_dim.height) / 100.0;
    sfFloatRect pos = sfSprite_getGlobalBounds(entity->sprite);
    sfFloatRect hitbox = {
        pos.left + padded_left,
        pos.top + padded_top,
        entity->size.x - padded_right,
        entity->size.y - padded_bottom
    };

    sfRectangleShape_setSize(
        entity->hitbox, (sfVector2f){hitbox.width, hitbox.height});
    sfRectangleShape_setPosition(
        entity->hitbox, (sfVector2f){hitbox.left, hitbox.top});
}
