/*
** EPITECH PROJECT, 2023
** graph.h
** File description:
** macro for CSFML
*/

#include "rpg.h"

bool start_kill_goblins(quest_t *, void *data)
{
    rpg_t *rpg = (rpg_t *)(data);
    int tab[] = {PV_LVL_1, GLOVES_LVL_2};
    npc_t *npc = NULL;

    for (int i = 0; i < 2; i++) {
        npc = create_bot(GOBLINS_T, rpg->tuto->biome->bot_data,
            (sfVector2f){200 * (i + 1), 300}, rpg->text_tab);
        npc->attack = 0;
        npc->object_id = tab[i];
    }
    return true;
}

bool default_check(quest_t *, void *)
{
    return true;
}

bool check_if_kill_bot(quest_t *, void *data)
{
    rpg_t *rpg = (rpg_t *)data;
    npc_t *list = rpg->tuto->biome->bot_data->bot_list[GOBLINS_T];

    if (list != NULL)
        return false;
    return true;
}

bool check_quest_attack_tuto(quest_t *, void *data)
{
    rpg_t *rpg = (rpg_t *)data;
    bool *tab = rpg->tuto->attack_tab;

    for (int i = 0; i < 4; i++)
        if (tab[i] == false)
            return false;
    return true;
}

bool check_quest_move_tuto(quest_t *, void *data)
{
    rpg_t *rpg = (rpg_t *)data;
    bool *tab = rpg->tuto->move_tab;

    for (int i = 0; i < 4; i++)
        if (tab[i] == false)
            return false;
    return true;
}
