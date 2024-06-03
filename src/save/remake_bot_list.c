/*
** EPITECH PROJECT, 2023
** create_sprite
** File description:
** create_sprite + texture
*/

#include "rpg.h"

void clean_boss(rpg_t *rpg)
{
    rpg->biome[CAMP]->boss = NULL;
    rpg->biome[MINE]->boss = NULL;
    rpg->biome[CASTLE]->boss = NULL;
}

void remake_bot_list(save_data_t *save, rpg_t *rpg)
{
    npc_t *npc = NULL;

    for (int i = 0; i <= MINE; i++)
        for (int j = 0; j <= ARCHER; j++) {
            free_bot_list(rpg->biome[i]->bot_data->bot_list[j]);
            rpg->biome[i]->bot_data->bot_list[j] = NULL;
        }
    clean_boss(rpg);
    for (int i = 0; i <= MINE; i++) {
        rpg->biome[i]->nbr_bot = 0;
        for (int j = 0; save->save_bot[i][j].pv != 0 && j < 30; j++) {
            npc = create_bot(save->save_bot[i][j].id_bot,
                rpg->biome[i]->bot_data,
                (sfVector2f){save->save_bot[i][j].pos_x,
                save->save_bot[i][j].pos_y}, rpg->text_tab);
            npc->pv = save->save_bot[i][j].pv;
            rpg->biome[i]->nbr_bot += 1;
        }
    }
}
