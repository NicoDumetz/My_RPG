/*
** EPITECH PROJECT, 2023
** graph.h
** File description:
** macro for CSFML
*/

#include "rpg.h"

bool check_if_use_skill(quest_t *, void *data)
{
    rpg_t *rpg = (rpg_t *)data;
    static int i = 0;

    if (rpg->key_state[sfKeyLShift])
        i = 1;
    if (i == 1)
        return true;
    return false;
}

bool check_if_drop(quest_t *, void *data)
{
    rpg_t *rpg = (rpg_t *)data;

    for (int i = 0; i < 20; i++)
        if (rpg->inventory.slot[i]->child != NULL)
            return false;
    return true;
}

bool check_if_take(quest_t *, void *data)
{
    rpg_t *rpg = (rpg_t *)data;

    if (rpg->inventory.slot[0]->child == NULL)
        return false;
    return true;
}

bool check_if_consume(quest_t *, void *data)
{
    rpg_t *rpg = (rpg_t *)data;

    if (rpg->heros->level_act == 0)
        return false;
    return true;
}

bool check_if_equip(quest_t *, void *data)
{
    rpg_t *rpg = (rpg_t *)data;

    if (rpg->inventory.equipment[0]->child == NULL)
        return false;
    return true;
}
