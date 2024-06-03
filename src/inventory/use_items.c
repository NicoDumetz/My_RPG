/*
** EPITECH PROJECT, 2024
** B-MUL-200-LIL-2-1-myrpg-matisse.dufour
** File description:
** use_items.c
*/

#include "rpg.h"
#include <SFML/Window/Keyboard.h>

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

static void equip_item(button_t *button, rpg_t *rpg)
{
    button_t *free_equipment = get_free_slot(rpg->inventory.equipment,
    NUM_EQUIPMENT);

    if (free_equipment == NULL)
        return;
    free_equipment->child = button->child;
    button->child = NULL;
}

static void consume_item(button_t *button, rpg_t *rpg)
{
    back_obj_t *obj = button->child;

    if (obj == NULL)
        return;
    delete_from_list(obj, &rpg->heros->inventory);
    button->child = NULL;
}

static void unequip_item(button_t *button, inventory_t *inventory)
{
    button_t *free_slot = get_free_slot(inventory->slot, NUM_SLOT);

    if (free_slot == NULL)
        return;
    free_slot->child = button->child;
    button->child = NULL;
}

void unequip_equipment(void *data, button_t *button)
{
    rpg_t *rpg = data;
    back_obj_t *obj = button->child;

    if (obj == NULL)
        return;
    if (rpg->key_state[sfKeyLControl])
        return drop_item(button, rpg);
    unequip_item(button, &rpg->inventory);
}

void use_item(void *data, button_t *button)
{
    rpg_t *rpg = data;
    back_obj_t *obj = button->child;

    if (obj == NULL)
        return;
    if (rpg->key_state[sfKeyLControl])
        return drop_item(button, rpg);
    if (obj->usage == CONSOMABLE)
        return consume_item(button, rpg);
    if (obj->usage == EQUIPABLE)
        return equip_item(button, rpg);
}
