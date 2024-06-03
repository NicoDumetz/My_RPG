/*
** EPITECH PROJECT, 2024
** movements
** File description:
** movements
*/

#include "rpg.h"

void check_open_portal(rpg_t *rpg)
{
    for (int i = 0; i <= KILL_CASTLE; i++)
        if (rpg->quest_tab[i].state != NOT_BEGIN)
            rpg->biome[PLAIN]->portal[i]->is_open = true;
    if (rpg->quest_tab[KILL_CAMP].state != NOT_BEGIN)
        rpg->biome[CAMP]->portal[0]->is_open = true;
    else
        rpg->biome[CAMP]->portal[0]->is_open = false;
    if (rpg->quest_tab[KILL_MINE].state != NOT_BEGIN)
        rpg->biome[MINE]->portal[0]->is_open = true;
    else
        rpg->biome[MINE]->portal[0]->is_open = false;
    if (rpg->quest_tab[KILL_CASTLE].state != NOT_BEGIN)
        rpg->biome[CASTLE]->portal[0]->is_open = true;
    else
        rpg->biome[CASTLE]->portal[0]->is_open = false;
}
