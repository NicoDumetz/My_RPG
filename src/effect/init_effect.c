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
    free(effect);
}

effect_t *create_effect(
    sfTexture *texture, effect_funct_t *function, bool static_effect)
{
    effect_t *effect = malloc(sizeof(effect_t));

    effect->sprite = sfSprite_create();
    sfSprite_setTexture(effect->sprite, texture, sfTrue);
    effect->active = false;
    effect->active_effect = function;
    effect->static_effect = static_effect;
    return (effect);
}
