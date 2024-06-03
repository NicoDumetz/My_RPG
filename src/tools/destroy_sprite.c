/*
** EPITECH PROJECT, 2023
** destroy_sprite
** File description:
** destroy_sprite + texture
*/

#include "rpg.h"

void destroy_sprite(sfSprite *sprite)
{
    sfTexture *texture = (sfTexture *)sfSprite_getTexture(sprite);

    if (texture)
        sfTexture_destroy(texture);
    sfSprite_destroy(sprite);
}
