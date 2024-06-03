/*
** EPITECH PROJECT, 2024
** B-MUL-200-LIL-2-1-myrpg-matisse.dufour
** File description:
** set_slots.c
*/

#include "rpg.h"

void draw_slots(rpg_t *rpg, inventory_t *inventory)
{
    back_obj_t *obj;

    for (unsigned char i = 0; i < NUM_SLOT; i++) {
        obj = inventory->slot[i]->child;
        sfRenderWindow_drawSprite(rpg->window,
        inventory->slot[i]->sprite, NULL);
        if (obj == NULL)
            continue;
        sfRenderWindow_drawSprite(rpg->window, obj->sprite, NULL);
    }
    for (unsigned char i = 0; i < NUM_EQUIPMENT; i++) {
        obj = inventory->equipment[i]->child;
        sfRenderWindow_drawSprite(rpg->window, inventory->equipment[i]->sprite,
        NULL);
        if (obj == NULL)
            continue;
        sfRenderWindow_drawSprite(rpg->window, obj->sprite, NULL);
    }
}

static void set_obj_pos(back_obj_t *obj, sfVector2f *pos)
{
    if (obj == NULL)
        return;
    sfSprite_setPosition(obj->sprite, *pos);
}

static void set_equipment_pos(rpg_t *rpg)
{
    sfFloatRect inventory_pos =
    sfRectangleShape_getGlobalBounds(rpg->inventory.slot_pos);
    inventory_t *inventory = &rpg->inventory;
    sfVector2f pos;
    sfVector2f button_pos;

    pos.x = inventory_pos.left + inventory_pos.width + 10.f;
    pos.y = inventory_pos.top;
    sfRectangleShape_setPosition(inventory->equipment_pos, pos);
    sfRenderWindow_drawRectangleShape(rpg->window, inventory->equipment_pos,
    NULL);
    for (unsigned char i = 0; i < NUM_EQUIPMENT; i++) {
        button_pos = inventory->equipment[i]->pos;
        button_pos.x += pos.x;
        button_pos.y += pos.y;
        sfSprite_setPosition(inventory->equipment[i]->sprite, button_pos);
        set_obj_pos(inventory->equipment[i]->child, &button_pos);
    }
}

void set_slot_pos(rpg_t *rpg, sfFloatRect *background_pos)
{
    sfVector2f pos;
    sfVector2f button_pos;

    pos.x = background_pos->left + background_pos->width * 0.07;
    pos.y = background_pos->top + background_pos->height * 0.05;
    sfRectangleShape_setPosition(rpg->inventory.slot_pos, pos);
    sfRenderWindow_drawRectangleShape(rpg->window, rpg->inventory.slot_pos,
    NULL);
    for (unsigned char i = 0; i < NUM_SLOT; i++) {
        button_pos = rpg->inventory.slot[i]->pos;
        button_pos.x += pos.x;
        button_pos.y += pos.y;
        sfSprite_setPosition(rpg->inventory.slot[i]->sprite,
        button_pos);
        set_obj_pos(rpg->inventory.slot[i]->child, &button_pos);
    }
    set_equipment_pos(rpg);
}
