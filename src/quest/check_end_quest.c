/*
** EPITECH PROJECT, 2023
** game
** File description:
** rpg.h
*/

#include "rpg.h"

void check_end_quest(rpg_t *rpg)
{
    if (rpg->biome[CAMP]->boss && rpg->biome[CAMP]->boss->is_alive == false)
        rpg->biome[CAMP]->boss = NULL;
    if (rpg->biome[MINE]->boss && rpg->biome[MINE]->boss->is_alive == false)
        rpg->biome[MINE]->boss = NULL;
    if (rpg->biome[CASTLE]->boss &&
        rpg->biome[CASTLE]->boss->is_alive == false)
        rpg->biome[CASTLE]->boss = NULL;
    if (rpg->biome[CAMP]->boss == NULL &&
        rpg->quest_tab[KILL_CAMP].state == BEGIN)
        next_quest(rpg->biome[PLAIN]->quest_giver, rpg->quest_tab);
    if (rpg->biome[MINE]->boss == NULL &&
        rpg->quest_tab[KILL_MINE].state == BEGIN)
        next_quest(rpg->biome[PLAIN]->quest_giver, rpg->quest_tab);
    if (rpg->biome[CASTLE]->boss == NULL &&
        rpg->quest_tab[KILL_CASTLE].state == BEGIN)
        next_quest(rpg->biome[PLAIN]->quest_giver, rpg->quest_tab);
}
