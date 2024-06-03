/*
** EPITECH PROJECT, 2024
** perso_rpg
** File description:
** init_inventory.c
*/
#include "rpg.h"
#include <SFML/Graphics/Texture.h>
#include <SFML/Graphics/Types.h>

void destroy_inventory(inventory_t *inventory)
{
    destroy_sprite(inventory->sprite);
}

void init_inventory(inventory_t *inventory, sfTexture **texture_tab)
{
    sfVector2u size = sfTexture_getSize(texture_tab[INVENTORY_TEXT]);

    inventory->sprite = sfSprite_create();
    sfSprite_setTexture(inventory->sprite, texture_tab[INVENTORY_TEXT],
    sfTrue);
    sfSprite_setOrigin(inventory->sprite, (sfVector2f){size.x / 2.f,
    size.y / 2.f});
    sfSprite_scale(inventory->sprite, (sfVector2f){0.8f, 0.8f});
}
