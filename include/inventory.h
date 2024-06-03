/*
** EPITECH PROJECT, 2024
** B-MUL-200-LIL-2-1-myrpg-matisse.dufour
** File description:
** inventory.h
*/

#ifndef INVENTORY_H
    #include "lib.h"
    #define INVENTORY_H
    #define INVENTORY_BACK "background_inventory.png"
    #define INVENTORY_SLOT "tiny_world_asset/UI/Banners/Carved_Regular.png"
    #define NUM_SLOT 20
    #define SLOT_PER_LINE 5 // Need to be a diviser of NUM_SLOT

typedef struct slot_s {
    button_t *button;
    sfVector2f pos;
    back_obj_t *obj;
} slot_t;

typedef struct inventory_s {
    sfSprite *background;
    sfRectangleShape *slot_pos;
    slot_t slot[NUM_SLOT];
    sfFloatRect slot_rect;
} inventory_t;

void init_inventory(inventory_t *inventory, sfTexture **texture_tab);
void init_slots(inventory_t *inventory, sfTexture **texture_tab);
void destroy_inventory(inventory_t *inventory);
void destroy_slots(inventory_t *inventory);
void set_slot_pos(rpg_t *rpg, sfFloatRect *pos);
void manage_inventory(rpg_t *rpg);
void draw_slots(rpg_t *rpg, inventory_t *inventory);
slot_t *get_free_slot(inventory_t *inventory);
#endif
