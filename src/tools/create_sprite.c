/*
** EPITECH PROJECT, 2023
** create_sprite
** File description:
** create_sprite + texture
*/

#include "rpg.h"

sfSprite *create_sprite(char *asset)
{
    sfTexture *texture = sfTexture_createFromFile(asset, NULL);
    sfSprite *sprite = NULL;

    if (texture) {
        sprite = sfSprite_create();
        sfSprite_setTexture(sprite, texture, sfTrue);
        return sprite;
    }
    return NULL;
}
