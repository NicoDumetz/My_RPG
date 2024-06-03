/*
** EPITECH PROJECT, 2024
** B-MUL-200-LIL-2-1-myrpg-matisse.dufour
** File description:
** use_items.c
*/

#include "rpg.h"

static void drop_item(button_t *button, rpg_t *rpg)
{
    biome_t *biome = rpg->biome[rpg->scene];
    sfVector2f pos = rpg->heros->npc->entity->pos;
    back_obj_t *obj = button->child;

    create_front_obj(NOTHING, rpg->text_tab, &biome->obj_list, pos);
    biome->obj_list->in = obj;
    delete_from_list(obj, &rpg->heros->inventory);
    button->child = NULL;
}

void use_item(void *data, button_t *button)
{
    rpg_t *rpg = data;

    if (button->child == NULL)
        return;
    if (rpg->key_state[sfKeyLControl]) {
        return drop_item(button, rpg);
    }
}
