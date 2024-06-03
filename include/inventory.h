/*
** EPITECH PROJECT, 2024
** B-MUL-200-LIL-2-1-myrpg-matisse.dufour
** File description:
** inventory.h
*/

#ifndef INVENTORY_H
    #define INVENTORY_H

    #include "lib.h"
    #define INVENTORY_BACK "background_inventory.png"
    #define INVENTORY_SLOT "tiny_world_asset/UI/Banners/Carved_Regular.png"
    #define BACK_HERO "tiny_world_asset/UI/Banners/Carved_Slides.png"
    #define NUM_SLOT 20
    #define SLOT_PER_LINE 4 // Need to be a diviser of NUM_SLOT
    #define NUM_EQUIPMENT 4

struct stats_text_s {
    sfRectangleShape *stats_pos;
    sfText *pv;
    sfVector2f pv_pos;
    sfText *xp;
    sfVector2f xp_pox;
};

typedef struct inventory_s {
    sfSprite *background;
    sfRectangleShape *slot_pos;
    button_t *slot[NUM_SLOT];
    sfRectangleShape *equipment_pos;
    button_t *equipment[NUM_EQUIPMENT];
    sfFloatRect slot_rect;
    sfRectangleShape *hero_pos;
    sfVector2f hero_scale;
    struct stats_text_s stats;
} inventory_t;

void init_inventory(inventory_t *inventory, sfTexture **texture_tab,
    rpg_t *rpg);
void init_slots(inventory_t *inventory, sfTexture **texture_tab);
void init_stats(inventory_t *inventory, sfFont **font_tab);
void destroy_inventory(inventory_t *inventory);
void destroy_slots(inventory_t *inventory);
void destroy_stats(inventory_t *inventory);
void flush_inventory(inventory_t *inventory, heros_t *hero);
void set_slot_pos(rpg_t *rpg, sfFloatRect *pos);
void manage_inventory(rpg_t *rpg);
void draw_slots(rpg_t *rpg, inventory_t *inventory);
void set_stats(inventory_t *inventory, rpg_t *rpg);
button_t *get_free_slot(button_t **list, unsigned char size_list);
void use_item(void *data, button_t *button);
void unequip_equipment(void *data, button_t *button);
#endif
