/*
** EPITECH PROJECT, 2023
** graph.h
** File description:
** macro for CSFML
*/

#include "rpg.h"

void destroy_entity(entity_t *entity)
{
    sfSprite_destroy(entity->sprite);
    sfRectangleShape_destroy(entity->colbox);
    free(entity);
}

sfRectangleShape *init_colbox_rect(void)
{
    sfRectangleShape *hitbox = sfRectangleShape_create();

    sfRectangleShape_setOutlineColor(hitbox, sfYellow);
    sfRectangleShape_setFillColor(hitbox, sfTransparent);
    sfRectangleShape_setOutlineThickness(hitbox, 2);
    return hitbox;
}

entity_t *init_entity(sfTexture *asset)
{
    entity_t *entity = malloc(sizeof(entity_t));
    sfFloatRect ss_size;

    entity->pos = (sfVector2f){0, 0};
    entity->size = (sfVector2f){0, 0};
    entity->rect_sprite = (sfIntRect){0, 0, 0, 0};
    entity->frame_nbr = 0;
    entity->sprite = sfSprite_create();
    entity->colbox = init_colbox_rect();
    entity->is_reverse = 0;
    sfSprite_setTexture(entity->sprite, asset, sfTrue);
    entity->colbox_dim = (sfFloatRect){0, 0, 0, 0};
    ss_size = sfSprite_getGlobalBounds(entity->sprite);
    entity->sprite_sheet_size = (sfVector2f){ss_size.width, ss_size.height};
    return entity;
}
