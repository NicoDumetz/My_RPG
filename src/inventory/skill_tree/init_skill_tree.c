/*
** EPITECH PROJECT, 2024
** B-MUL-200-LIL-2-1-myrpg-matisse.dufour
** File description:
** init_skill_tree.c
*/

#include "rpg.h"

void destroy_skill_tree(inventory_t *inventory)
{
    sfRectangleShape_destroy(inventory->skill_tree_pos);
    sfText_destroy(inventory->text_point);
    for (unsigned char i = 0; i <= RUN; i++) {
        sfText_destroy(inventory->skill_tree[i].level);
        destroy_button(inventory->skill_tree[i].button);
        destroy_button(inventory->skill_tree[i].equip);
    }
}

static void init_text(inventory_t *inventory, sfFont **font_tab)
{
    inventory->text_point = sfText_create();
    sfText_setColor(inventory->text_point, sfCyan);
    sfText_setFont(inventory->text_point, font_tab[PIXEL]);
    sfText_setOutlineColor(inventory->text_point, sfBlack);
    sfText_setOutlineThickness(inventory->text_point, 0.8);
    sfText_setCharacterSize(inventory->text_point, 30);
    inventory->text_point_pos = (sfVector2f){30.f, 15.f};
}

static void init_button_pos(skill_tree_t *skills, sfVector2f pos,
    unsigned int size)
{
    sfFloatRect button_rect = sfSprite_getGlobalBounds(skills->button->sprite);
    sfVector2f new_pos = {200.f + pos.x, pos.y + (size / 2.f) -
    (button_rect.height / 2.f) + 10.f};

    skills->equip->pos = new_pos;
    new_pos.x += button_rect.width * 1.75;
    skills->button->pos = new_pos;
}

static void init_skill_button_function(inventory_t *inventory)
{
    init_action_button(add_run_lvl, NULL, NULL,
    inventory->skill_tree[RUN].button);
    init_action_button(add_shield_lvl, NULL, NULL,
    inventory->skill_tree[SHIELD].button);
    init_action_button(add_fireball_lvl, NULL, NULL,
    inventory->skill_tree[FIRE_BALL].button);
}

static void init_skill_button(inventory_t *inventory, sfFont **font_tab,
    sfTexture **text_tab)
{
    unsigned int size = 35;
    int text_id[5] = {BLUE_PLUS_TEXT, BLUE_PLUS_PRESSED_TEXT, PLUS_HOVER_TEXT,
    BLUE_PLUS_TEXT, PLUS_BLOCK_TEXT};
    sfVector2f pos =
    {inventory->text_point_pos.x,
    inventory->text_point_pos.y + size * 1.75f};

    for (unsigned char i = 0; i <= RUN; i++) {
        inventory->skill_tree[i].button = create_button(text_tab, text_id);
        inventory->skill_tree[i].level = sfText_create();
        sfText_setColor(inventory->skill_tree[i].level, sfWhite);
        sfText_setFont(inventory->skill_tree[i].level, font_tab[PIXEL]);
        sfText_setOutlineColor(inventory->skill_tree[i].level, sfBlack);
        sfText_setOutlineThickness(inventory->skill_tree[i].level, 0.8);
        sfText_setCharacterSize(inventory->skill_tree[i].level, size);
        inventory->skill_tree[i].pos = pos;
        init_button_pos(&inventory->skill_tree[i], pos, size);
        pos.y += size * 2;
    }
}

static void init_equip_skills(inventory_t *inventory, sfTexture **texture_tab)
{
    int text_id_run[5] = {RUN_RELEASED_TEXT, RUN_PRESSED_TEXT, RUN_HOVER_TEXT,
    RUN_PRESSED_TEXT, RUN_PRESSED_TEXT};
    int text_id_fire[5] = {FIRE_RELEASED_TEXT, FIRE_PRESSED_TEXT,
    FIRE_HOVER_TEXT, FIRE_PRESSED_TEXT, FIRE_PRESSED_TEXT};
    int text_id_shield[5] = {SHIELD_RELEASED_TEXT, SHIELD_PRESSED_TEXT,
    SHIELD_HOVER_TEXT, SHIELD_PRESSED_TEXT, SHIELD_PRESSED_TEXT};

    inventory->skill_tree[RUN].equip = create_button(texture_tab, text_id_run);
    init_action_button(equip_run, NULL, NULL,
    inventory->skill_tree[RUN].equip);
    inventory->skill_tree[FIRE_BALL].equip = create_button(texture_tab,
    text_id_fire);
    init_action_button(equip_fire_ball, NULL, NULL,
    inventory->skill_tree[FIRE_BALL].equip);
    inventory->skill_tree[SHIELD].equip = create_button(texture_tab,
    text_id_shield);
    init_action_button(equip_shield, NULL, NULL,
    inventory->skill_tree[SHIELD].equip);
}

void init_skill_tree(inventory_t *inventory, sfFont **font_tab,
    sfTexture **texture_tab)
{
    inventory->skill_tree_pos = sfRectangleShape_create();
    if (RECTANGLE_BOX)
        sfRectangleShape_setOutlineColor(inventory->skill_tree_pos, sfRed);
    else {
        sfRectangleShape_setOutlineColor(inventory->skill_tree_pos,
        sfTransparent);
    }
    sfRectangleShape_setOutlineThickness(inventory->skill_tree_pos, 2.f);
    sfRectangleShape_setSize(inventory->skill_tree_pos,
    (sfVector2f){430.f, 300.f});
    sfRectangleShape_setTexture(inventory->skill_tree_pos,
    texture_tab[BACK_INVENTORY_HERO], sfTrue);
    init_text(inventory, font_tab);
    init_equip_skills(inventory, texture_tab);
    init_skill_button(inventory, font_tab, texture_tab);
    init_skill_button_function(inventory);
}
