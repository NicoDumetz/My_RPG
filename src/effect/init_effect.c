/*
** EPITECH PROJECT, 2024
** check_collisions
** File description:
** check_collisions
*/

#include "rpg.h"

void destroy_effect(effect_t *effect)
{
    sfSprite_destroy(effect->sprite);
    effect->sprite = NULL;
    free(effect);
    effect = NULL;
}

void resize_sprite_to_match(
    sfSprite* sprite_to_resize, sfSprite* reference_sprite)
{
    sfFloatRect reference_bounds = sfSprite_getGlobalBounds(reference_sprite);
    sfFloatRect resize_bounds = sfSprite_getGlobalBounds(sprite_to_resize);
    float scale_x = reference_bounds.width / resize_bounds.width;
    float scale_y = reference_bounds.height / resize_bounds.height;

    sfSprite_setScale(sprite_to_resize, (sfVector2f){scale_x, scale_y});
}

effect_t *create_effect(
    sfTexture *texture, bool is_short, sfVector2i offset, sfSprite *to_match)
{
    effect_t *effect = malloc(sizeof(effect_t));
    sfFloatRect sprite_dim;
    float width;
    float height;

    effect->sprite = sfSprite_create();
    sfSprite_setTexture(effect->sprite, texture, sfTrue);
    sprite_dim = sfSprite_getGlobalBounds(effect->sprite);
    effect->active = false;
    effect->is_short = is_short;
    effect->frame_nbr = offset.x;
    width = sprite_dim.width / offset.x;
    height = sprite_dim.height / offset.y;
    effect->offset = offset;
    effect->size = (sfVector2f){width, height};
    effect->rect_sprite = (sfIntRect){0, 0, width, height};
    sfSprite_setTextureRect(effect->sprite, effect->rect_sprite);
    resize_sprite_to_match(effect->sprite, to_match);
    return (effect);
}
