/*
** EPITECH PROJECT, 2023
** graph.h
** File description:
** macro for CSFML
*/

#include "rpg.h"

void set_colbox(entity_t *entity)
{
    float padded_top = (entity->size.y * entity->colbox_dim.top) / 100.0;
    float padded_left = (entity->size.x * entity->colbox_dim.left) / 100.0;
    float padded_right = (entity->size.x * entity->colbox_dim.width) / 100.0;
    float padded_bottom = (entity->size.y * entity->colbox_dim.height) / 100.0;
    sfFloatRect pos = sfSprite_getGlobalBounds(entity->sprite);
    sfFloatRect hitbox = {
        pos.left + padded_left,
        pos.top + padded_top,
        entity->size.x - padded_right,
        entity->size.y - padded_bottom
    };

    sfRectangleShape_setSize(
        entity->colbox, (sfVector2f){hitbox.width, hitbox.height});
    sfRectangleShape_setPosition(
        entity->colbox, (sfVector2f){hitbox.left, hitbox.top});
}

void set_hitbox(npc_t *npc)
{
    float padded_top = (npc->entity->size.y * npc->hitbox_dim.top) / 100.0;
    float padded_left = (npc->entity->size.x * npc->hitbox_dim.left) / 100.0;
    float padded_right = (npc->entity->size.x * npc->hitbox_dim.width) / 100.0;
    float padded_bottom = (
        npc->entity->size.y * npc->hitbox_dim.height) / 100.0;
    sfFloatRect pos = sfSprite_getGlobalBounds(npc->entity->sprite);
    sfFloatRect hitbox = {
        pos.left + padded_left,
        pos.top + padded_top,
        npc->entity->size.x - padded_right,
        npc->entity->size.y - padded_bottom
    };

    sfRectangleShape_setSize(
        npc->hitbox, (sfVector2f){hitbox.width, hitbox.height});
    sfRectangleShape_setPosition(
        npc->hitbox, (sfVector2f){hitbox.left, hitbox.top});
}
