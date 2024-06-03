/*
** EPITECH PROJECT, 2023
** graph.h
** File description:
** macro for CSFML
*/

#include "rpg.h"

sfBool sprite_is_in_float_rect(sfSprite *sprite, sfFloatRect rect)
{
    sfFloatRect sprite_bounds = sfSprite_getGlobalBounds(sprite);

    return sfFloatRect_intersects(&sprite_bounds, &rect, NULL);
}
