/*
** EPITECH PROJECT, 2023
** graph.h
** File description:
** macro for CSFML
*/

#include "rpg.h"

entity_t *create_knight_house(sfVector2f pos, sfTexture *texture, back_t *back)
{
    entity_t *entity = init_entity(texture);
    sfFloatRect colbox = {15, 40, 30, 55};

    set_offset(entity, (sfVector2i){1, 1});
    sfSprite_setPosition(entity->sprite, pos);
    entity->colbox_dim = colbox;
    set_box(entity->colbox, entity->colbox_dim, entity);
    draw_black_rect_on_image(entity->colbox, back->collision.col_image);
    return entity;
}

entity_t *create_tree_plain(sfVector2f pos, sfTexture *texture, back_t *back)
{
    entity_t *entity = init_entity(texture);
    sfFloatRect colbox = {40, 80, 80, 85};

    entity->simple_action = (sfVector2i){4, 0};
    set_offset(entity, (sfVector2i){4, 3});
    sfSprite_setPosition(entity->sprite, pos);
    entity->colbox_dim = colbox;
    set_box(entity->colbox, entity->colbox_dim, entity);
    draw_black_rect_on_image(entity->colbox, back->collision.col_image);
    return entity;
}

entity_t *create_mine(sfVector2f pos, sfTexture *texture, back_t *back)
{
    entity_t *entity = init_entity(texture);
    sfFloatRect colbox = {10, 20, 20, 40};

    set_offset(entity, (sfVector2i){1, 1});
    sfSprite_setPosition(entity->sprite, pos);
    entity->colbox_dim = colbox;
    set_box(entity->colbox, entity->colbox_dim, entity);
    draw_black_rect_on_image(entity->colbox, back->collision.col_image);
    return entity;
}
