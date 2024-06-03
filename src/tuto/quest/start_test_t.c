/*
** EPITECH PROJECT, 2023
** graph.h
** File description:
** macro for CSFML
*/

#include "rpg.h"


sfVector2f pos[30] = {
    {346, 401},
    {102, 1099},
    {218, 192},
    {412, 671},
    {624, 732},
    {999, 657},
    {917, 1040},
    {104, 145},
    {1030, 1070},
    {623, 218},
    {629, 1023},
    {998, 358},
    {180, 650},
    {123, 439},
    {832, 653},
    {999, 161},
    {385, 708},
    {239, 1091},
    {308, 160},
    {693, 1033},
    {235, 374},
    {625, 202},
    {1045, 507},
    {101, 654},
    {1042, 354},
    {405, 1080},
    {320, 251},
    {944, 1088},
    {311, 209},
    {840, 187}
};

bool start_final_test(quest_t *, void *data)
{
    rpg_t *rpg = (rpg_t *)(data);
    int tab[] = {GOBLINS_T, GOBLINS_B, GOBLINS_D};
    int j = 0;
    npc_t *npc = NULL;

    for (int i = 0; i < 30; i++) {
        npc = create_bot(tab[j], rpg->tuto->biome->bot_data,
            pos[i], rpg->text_tab);
        npc->pv = 1000;
        npc->pv_bar->max = 1000;
        npc->attack = 200;
        npc->in_chase = true;
        j++;
        if (j > 2)
            j = 0;
    }
    return true;
}

bool check_test_quest(quest_t *, void *data)
{
    rpg_t *rpg = (rpg_t *)data;
    npc_t *list = NULL;

    for (int i = 0; i <= ARCHER; i++) {
        list = rpg->tuto->biome->bot_data->bot_list[i];
        if (list != NULL)
            return false;
    }
    return true;
}
