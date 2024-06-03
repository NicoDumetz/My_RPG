/*
** EPITECH PROJECT, 2024
** B-MUL-200-LIL-2-1-myrpg-matisse.dufour
** File description:
** inventory.h
*/

#ifndef INVENTORY_H
    #define INVENTORY_H

    #include "lib.h"
    #define INVENTORY_BACK "assets/inventory_asset/background_inventory.png"
    #define INVENTORY_SLOT_PATH "assets/tiny_world_asset/UI/Banners/"
    #define INVENTORY_SLOT INVENTORY_SLOT_PATH "Carved_Regular.png"
    #define BACK_HERO "assets/tiny_world_asset/UI/Banners/Carved_Slides.png"
    #define BLUE_PLUS "assets/inventory_asset/Button_Blue.png"
    #define BLUE_PLUS_PRESSED "assets/inventory_asset/Button_Blue_Pressed.png"
    #define PLUS_HOVER "assets/inventory_asset/Button_Hover.png"
    #define DISABLED_PLUS "assets/inventory_asset/Button_Disable.png"
    #define RUN_RELEASED "assets/inventory_asset/run_released.PNG"
    #define RUN_PRESSED "assets/inventory_asset/run_pressed.PNG"
    #define RUN_HOVER "assets/inventory_asset/run_hover.PNG"
    #define FIRE_RELEASED "assets/inventory_asset/fire_released.PNG"
    #define FIRE_PRESSED "assets/inventory_asset/fire_pressed.PNG"
    #define FIRE_HOVER "assets/inventory_asset/fire_hover.PNG"
    #define SHIELD_RELEASED "assets/inventory_asset/shield_released.PNG"
    #define SHIELD_PRESSED "assets/inventory_asset/shield_press.PNG"
    #define SHIELD_HOVER "assets/inventory_asset/shield_hover.PNG"
    #define NUM_SLOT 20
    #define SLOT_PER_LINE 4 // Need to be a diviser of NUM_SLOT
    #define NUM_EQUIPMENT 4
    #define RECTANGLE_BOX false

enum stat_text_e {
    PV_STAT = 0,
    XP_STAT,
    SPEED_STAT,
    STAMINA_STAT,
    ATTACK_STAT,
    COUNT_STATS
};

typedef struct stats_text_s {
    sfText *text;
    sfVector2f pos;
} stats_text_t;

typedef struct skill_tree_s {
    button_t *button;
    button_t *equip;
    sfVector2f pos;
    sfText *level;
} skill_tree_t;

typedef struct inventory_s {
    sfSprite *background;
    sfRectangleShape *slot_pos;
    button_t *slot[NUM_SLOT];
    sfRectangleShape *equipment_pos;
    button_t *equipment[NUM_EQUIPMENT];
    sfFloatRect slot_rect;
    sfRectangleShape *hero_pos;
    sfVector2f hero_scale;
    sfRectangleShape *stats_pos;
    stats_text_t stats[COUNT_STATS];
    sfRectangleShape *skill_tree_pos;
    sfText *text_point;
    sfVector2f text_point_pos;
    skill_tree_t skill_tree[RUN + 1];
} inventory_t;

void init_inventory(inventory_t *inventory, sfTexture **texture_tab,
    rpg_t *rpg);
void init_slots(inventory_t *inventory, sfTexture **texture_tab);
void init_stats(inventory_t *inventory, sfFont **font_tab);
void init_skill_tree(inventory_t *inventory, sfFont **font_tab,
    sfTexture **texture_tab);
void destroy_inventory(inventory_t *inventory);
void destroy_slots(inventory_t *inventory);
void destroy_stats(inventory_t *inventory);
void destroy_skill_tree(inventory_t *inventory);
void flush_inventory(inventory_t *inventory, heros_t *hero);
void set_slot_pos(rpg_t *rpg, sfFloatRect *pos);
void manage_inventory(rpg_t *rpg);
void manage_skill_tree(inventory_t *inventory, rpg_t *rpg);
void draw_slots(rpg_t *rpg, inventory_t *inventory);
void set_stats(inventory_t *inventory, rpg_t *rpg);
button_t *get_free_slot(button_t **list, unsigned char size_list);
void use_item(void *data, button_t *button);
void unequip_equipment(void *data, button_t *rpg);
bool add_to_inventory(
    back_obj_t **inventory, front_obj_t *obj, back_obj_t *back, rpg_t *rpg);
void set_obj_scale(inventory_t *inventory, back_obj_t *obj);

/**SKILLS**/
void add_fireball_lvl(void *data, button_t *);
void add_shield_lvl(void *data, button_t *);
void add_run_lvl(void *data, button_t *);
void equip_shield(void *data, button_t *);
void equip_fire_ball(void *data, button_t *);
void equip_run(void *data, button_t *);
#endif
