/*
** EPITECH PROJECT, 2024
** B-MUL-200-LIL-2-1-myrpg-matisse.dufour
** File description:
** use_items.c
*/

#include "rpg.h"

void appli_multi_equip(heros_t *heros, back_obj_t *back)
{
    heros->multi_speed *= back->multi_speed;
    heros->pv_max *= back->multi_live;
    heros->bar_tab[LIFE_BAR]->max *= back->multi_live;
    heros->npc->pv *= back->multi_live;
    heros->npc->attack *= back->multi_attack;
}

void unappli_multi_equip(heros_t *heros, back_obj_t *back)
{
    heros->multi_speed /= back->multi_speed;
    heros->pv_max /= back->multi_live;
    heros->bar_tab[LIFE_BAR]->max /= back->multi_live;
    heros->npc->pv /= back->multi_live;
    heros->npc->attack /= back->multi_attack;
}

void appli_item_stat(back_obj_t *back, heros_t *heros)
{
    float life_net = heros->pv_max * (back->add_live / 100);
    float stamina_net = heros->stamina_max *
        (back->add_stamina / 100);

    heros->stamina += stamina_net;
    heros->npc->pv += life_net;
    heros->npc->xp += back->add_xp;
    if (heros->npc->pv > heros->pv_max)
        heros->npc->pv = heros->pv_max;
    if (heros->stamina > heros->stamina_max)
        heros->stamina = heros->stamina_max;
}

static void drop_item(button_t *button, rpg_t *rpg)
{
    biome_t *biome = (rpg->scene == TUTO) ? rpg->tuto->biome : rpg->biome[rpg->scene];
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
    back_obj_t *back = (back_obj_t *)button->child;

    if (free_equipment == NULL)
        return;
    appli_multi_equip(rpg->heros, back);
    free_equipment->child = button->child;
    button->child = NULL;
}

static void consume_item(button_t *button, rpg_t *rpg)
{
    back_obj_t *obj = button->child;

    if (obj == NULL)
        return;
    appli_item_stat(obj, rpg->heros);
    delete_from_list(obj, &rpg->heros->inventory);
    destroy_back_obj(obj);
    button->child = NULL;
}

static void unequip_item(button_t *button, rpg_t *rpg)
{
    button_t *free_slot = get_free_slot(rpg->inventory.slot, NUM_SLOT);
    back_obj_t *back = (back_obj_t *)button->child;

    if (free_slot == NULL)
        return;
    unappli_multi_equip(rpg->heros, back);
    free_slot->child = button->child;
    button->child = NULL;
}

void unequip_equipment(void *data, button_t *button)
{
    rpg_t *rpg = data;
    back_obj_t *obj = button->child;

    if (obj == NULL)
        return;
    if (rpg->key_state[sfKeyLControl]) {
        unappli_multi_equip(rpg->heros, button->child);
        return drop_item(button, rpg);
    }
    unequip_item(button, rpg);
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
