/*
** EPITECH PROJECT, 2023
** graph.h
** File description:
** macro for CSFML
*/

#include "rpg.h"

entity_t *create_knight_house(sfVector2f pos, sfTexture *texture)
{
    entity_t *entity = init_entity(texture);
    sfFloatRect colbox = {15, 40, 30, 55};

    set_offset(entity, (sfVector2i){1, 1});
    sfSprite_setPosition(entity->sprite, pos);
    entity->colbox_dim = colbox;
    return entity;
}

entity_t *create_tree_plain(sfVector2f pos, sfTexture *texture)
{
    entity_t *entity = init_entity(texture);
    sfFloatRect colbox = {40, 80, 80, 85};

    set_offset(entity, (sfVector2i){4, 3});
    sfSprite_setPosition(entity->sprite, pos);
    entity->colbox_dim = colbox;
    return entity;
}

entity_t *create_mine(sfVector2f pos, sfTexture *texture)
{
    entity_t *entity = init_entity(texture);
    sfFloatRect colbox = {10, 20, 20, 40};

    set_offset(entity, (sfVector2i){1, 1});
    sfSprite_setPosition(entity->sprite, pos);
    entity->colbox_dim = colbox;
    return entity;
}
