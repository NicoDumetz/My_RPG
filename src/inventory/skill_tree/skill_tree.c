/*
** EPITECH PROJECT, 2024
** B-MUL-200-LIL-2-1-myrpg-matisse.dufour
** File description:
** skill_tree.c
*/

#include "rpg.h"

static void set_text(inventory_t *inventory, rpg_t *rpg, sfVector2f back_pos)
{
    sfVector2f pos = back_pos;
    char str[255] = "Error";

    snprintf(str, 255, "Skill point: %d", rpg->heros->skill_point);
    pos.x += inventory->text_point_pos.x;
    pos.y += inventory->text_point_pos.y;
    sfText_setString(inventory->text_point, str);
    sfText_setPosition(inventory->text_point, pos);
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
        pos_lvl.x += inventory->skill_tree[i].pos.x;
        if (rpg->heros->skill->skill_level[i] == 3)
            snprintf(str, 255, "Level: %s", "Max");
        else {
            snprintf(str, 255, "Level: %-2d",
            rpg->heros->skill->skill_level[i]);
        }
        sfText_setString(inventory->skill_tree[i].level, str);
        sfText_setPosition(inventory->skill_tree[i].level, pos_lvl);
        sfRenderWindow_drawText(rpg->window, inventory->skill_tree[i].level,
        NULL);
    }
}

static void block_buttons(skill_tree_t *skill_tree, rpg_t *rpg, int skill)
{
    button_t *button = skill_tree->button;
    button_t *equip = skill_tree->equip;

    if (button->state == BLOCK && rpg->heros->skill_point > 0 &&
    rpg->heros->skill->skill_level[skill] < 3)
        button->state = NONE;
    if (rpg->heros->skill_point <= 0 ||
    rpg->heros->skill->skill_level[skill] >= 3)
        button->state = BLOCK;
    if (equip->state == BLOCK && rpg->heros->skill->act_skill != skill)
        equip->state = NONE;
    if (rpg->heros->skill->act_skill == skill)
        equip->state = BLOCK;
}

static void draw_button(skill_tree_t *skill, rpg_t *rpg, sfVector2f back_pos)
{
    sfVector2f pos = back_pos;

    pos.x += skill->button->pos.x;
    pos.y += skill->button->pos.y;
    sfSprite_setPosition(skill->button->sprite, pos);
    sfRenderWindow_drawSprite(rpg->window, skill->button->sprite, NULL);
    pos = back_pos;
    pos.x += skill->equip->pos.x;
    pos.y += skill->equip->pos.y;
    sfSprite_setPosition(skill->equip->sprite, pos);
    sfRenderWindow_drawSprite(rpg->window, skill->equip->sprite, NULL);
}

static void set_button(inventory_t *inventory, mouse_data_t *mouse_data,
    rpg_t *rpg)
{
    sfVector2f back_pos =
    sfRectangleShape_getPosition(inventory->skill_tree_pos);
    button_t *button;

    for (unsigned char i = 0; i <= RUN; i++) {
        button = inventory->skill_tree[i].button;
        block_buttons(&inventory->skill_tree[i], rpg, i);
        update_button(button, mouse_data, rpg);
        update_button(inventory->skill_tree[i].equip, mouse_data, rpg);
        draw_button(&inventory->skill_tree[i], rpg, back_pos);
    }
}

void manage_skill_tree(inventory_t *inventory, rpg_t *rpg)
{
    sfFloatRect equipment_pos =
    sfRectangleShape_getGlobalBounds(inventory->equipment_pos);
    sfVector2f pos = {equipment_pos.left + 40.f,
    equipment_pos.top + equipment_pos.height + 30.f};

    sfRectangleShape_setPosition(inventory->skill_tree_pos, pos);
    sfRenderWindow_drawRectangleShape(rpg->window, inventory->skill_tree_pos,
    NULL);
    set_text(inventory, rpg, pos);
    set_level(inventory, rpg, pos);
    set_button(inventory, &rpg->mouse_data, rpg);
}
