/*
** EPITECH PROJECT, 2023
** graph.h
** File description:
** macro for CSFML
*/

#include "rpg.h"

void set_offset(entity_t *entity, sfVector2i size_sprite)
{
    sfFloatRect sprite_dim = sfSprite_getGlobalBounds(entity->sprite);
    float width = sprite_dim.width / size_sprite.x;
    float height = sprite_dim.height / size_sprite.y;

    entity->size = (sfVector2f){width, height};
    entity->frame_nbr = (int)size_sprite.x;
    entity->rect_sprite = (sfIntRect){0, 0, width, height};
}
