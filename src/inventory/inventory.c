/*
** EPITECH PROJECT, 2024
** B-MUL-200-LIL-2-1-myrpg-matisse.dufour
** File description:
** inventory.c
*/

#include "rpg.h"

static bool inventory_state(rpg_t *rpg)
{
    static int open = 0;
    static int pressed = 0;

    if (!rpg->key_state[sfKeyTab])
        pressed = 0;
    if (rpg->key_state[sfKeyTab] && !pressed) {
        pressed = 1;
        open = (open == 0) ? 1 : 0;
    }
    if (open)
        return false;
    return true;
}

static void inventory_slot_management(inventory_t *inventory,
    mouse_data_t *mouse_data, rpg_t *rpg)
{
    for (unsigned char i = 0; i < NUM_SLOT; i++)
        update_button(inventory->slot[i], mouse_data, rpg);
}

void manage_inventory(rpg_t *rpg)
{
    const sfView *view = sfRenderWindow_getView(rpg->window);
    sfFloatRect pos;

    if (inventory_state(rpg))
        return;
    sfSprite_setPosition(rpg->inventory.background, sfView_getCenter(view));
    pos = sfSprite_getGlobalBounds(rpg->inventory.background);
    sfRenderWindow_drawSprite(rpg->window, rpg->inventory.background, NULL);
    set_slot_pos(rpg, &pos);
    inventory_slot_management(&rpg->inventory, &rpg->mouse_data, rpg);
    draw_slots(rpg, &rpg->inventory);
}

button_t *get_free_slot(inventory_t *inventory)
{
    for (unsigned char i = 0; i < NUM_SLOT; i++) {
        if (inventory->slot[i]->child == NULL)
            return inventory->slot[i];
    }
    return NULL;
}
