/*
** EPITECH PROJECT, 2024
** B-MUL-200-LIL-2-1-myrpg-matisse.dufour
** File description:
** inventory.h
*/

#ifndef INVENTORY_H
    #define INVENTORY_H
    #define INVENTORY_BACK "image.png"
    #include "lib.h"

typedef struct inventory_s {
    sfSprite *sprite;
} inventory_t;
void init_inventory(inventory_t *inventory, sfTexture **texture_tab);
void destroy_inventory(inventory_t *inventory);
void inventory(rpg_t *rpg);
#endif
