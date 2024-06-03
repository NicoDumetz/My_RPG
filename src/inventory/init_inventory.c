/*
** EPITECH PROJECT, 2024
** perso_rpg
** File description:
** init_inventory.c
*/
#include "rpg.h"

void destroy_inventory(inventory_t *inventory)
{
    sfSprite_destroy(inventory->background);
    destroy_slots(inventory);
}

void flush_inventory(inventory_t *inventory, heros_t *hero)
{
    for (unsigned char i = 0; i < NUM_SLOT; i++) {
        if (inventory->slot[i]->child == NULL)
            continue;
        delete_from_list(inventory->slot[i]->child, &hero->inventory);
        destroy_back_obj(inventory->slot[i]->child);
        inventory->slot[i]->child = NULL;
    }
}

void init_inventory(inventory_t *inventory, sfTexture **texture_tab)
{
    sfVector2u size = sfTexture_getSize(texture_tab[INVENTORY_TEXT]);

    inventory->background = sfSprite_create();
    sfSprite_setTexture(inventory->background, texture_tab[INVENTORY_TEXT],
    sfTrue);
    sfSprite_setOrigin(inventory->background, (sfVector2f){size.x / 2.f,
    size.y / 2.f + 10.f});
    sfSprite_scale(inventory->background, (sfVector2f){3.f, 3.f});
    init_slots(inventory, texture_tab);
}
