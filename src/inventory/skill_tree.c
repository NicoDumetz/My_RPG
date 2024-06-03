/*
** EPITECH PROJECT, 2024
** B-MUL-200-LIL-2-1-myrpg-matisse.dufour
** File description:
** skill_tree.c
*/

#include "rpg.h"

void destroy_skill_tree(inventory_t *inventory)
{
    sfRectangleShape_destroy(inventory->skill_tree_pos);
    sfText_destroy(inventory->text_point);
    for  (unsigned char i = 0; i <= RUN; i++) {
        sfText_destroy(inventory->skill_tree[i].level);
        destroy_button(inventory->skill_tree[i].button);
    }
}

static void set_text(inventory_t *inventory, rpg_t *rpg, sfVector2f back_pos)
{
    char str[255] = "Error";

    snprintf(str, 255, "Skill point: %d", rpg->heros->skill_point);
    sfText_setString(inventory->text_point, str);
    sfText_setPosition(inventory->text_point, back_pos);
    sfRenderWindow_drawText(rpg->window, inventory->text_point,
    NULL);
}

static void set_level(inventory_t *inventory, rpg_t *rpg, sfVector2f pos)
{
    char str[255] = "Error";
    sfVector2f pos_lvl;

    for (unsigned char i = 0; i <= RUN; i++) {
        pos_lvl = pos;
        pos_lvl.y += inventory->skill_tree[i].pos.y;
        snprintf(str, 255, "Level: %-2d", rpg->heros->skill->skill_level[i]);
        sfText_setString(inventory->skill_tree[i].level, str);
        sfText_setPosition(inventory->skill_tree[i].level, pos_lvl);
        sfRenderWindow_drawText(rpg->window, inventory->skill_tree[i].level,
        NULL);
    }
}

void manage_skill_tree(inventory_t *inventory, rpg_t *rpg)
{
    sfFloatRect equipment_pos =
    sfRectangleShape_getGlobalBounds(inventory->equipment_pos);
    sfVector2f pos = {equipment_pos.left,
    equipment_pos.top + equipment_pos.height};

    sfRectangleShape_setPosition(inventory->skill_tree_pos, pos);
    sfRenderWindow_drawRectangleShape(rpg->window, inventory->skill_tree_pos,
    NULL);
    set_text(inventory, rpg, pos);
    set_level(inventory, rpg, pos);
}

static void init_text(inventory_t *inventory, sfFont **font_tab)
{
    inventory->text_point = sfText_create();
    sfText_setColor(inventory->text_point, sfCyan);
    sfText_setFont(inventory->text_point, font_tab[PIXEL]);
    sfText_setOutlineColor(inventory->text_point, sfBlack);
    sfText_setOutlineThickness(inventory->text_point, 0.8);
    sfText_setCharacterSize(inventory->text_point, 30);
}

static void init_skill_button(inventory_t *inventory, sfFont **font_tab,
    sfTexture **text_tab)
{
    int text_id[5] = {BLUE_PLUS_TEXT, BLUE_PLUS_PRESSED_TEXT, PLUS_HOVER_TEXT,
    BLUE_PLUS_TEXT, PLUS_BLOCK_TEXT};
    sfVector2f pos = {0.f, 30.f};

    for (unsigned char i = 0; i <= RUN; i++) {
        inventory->skill_tree[i].button = create_button(text_tab, text_id);
        inventory->skill_tree[i].level = sfText_create();
        sfText_setColor(inventory->skill_tree[i].level, sfWhite);
        sfText_setFont(inventory->skill_tree[i].level, font_tab[PIXEL]);
        sfText_setOutlineColor(inventory->skill_tree[i].level, sfBlack);
        sfText_setOutlineThickness(inventory->skill_tree[i].level, 0.8);
        sfText_setCharacterSize(inventory->skill_tree[i].level, 25);
        inventory->skill_tree[i].pos = pos;
        pos.y += 30;
    }
}

void init_skill_tree(inventory_t *inventory, sfFont **font_tab, sfTexture **texture_tab)
{
    inventory->skill_tree_pos = sfRectangleShape_create();
    sfRectangleShape_setOutlineColor(inventory->skill_tree_pos, sfRed);
    sfRectangleShape_setOutlineThickness(inventory->skill_tree_pos, 2.f);
    sfRectangleShape_setFillColor(inventory->skill_tree_pos, sfTransparent);
    sfRectangleShape_setSize(inventory->skill_tree_pos,
    (sfVector2f){100.f, 200.f});
    init_text(inventory, font_tab);
    init_skill_button(inventory, font_tab, texture_tab);
}
