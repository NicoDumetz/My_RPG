/*
** EPITECH PROJECT, 2023
** graph.h
** File description:
** macro for CSFML
*/

#include "rpg.h"

void sort_entity_in_view(
    biome_t *biome, sfRenderWindow *window, heros_t *heros)
{
    put_entity_in_view_list(heros->npc->entity, biome, window);
    for (int i = 0; i <= MINE_DECO; i++)
        for (int j = 0; biome->deco_data->deco_entity[i][j]; j++)
            put_entity_in_view_list(
                biome->deco_data->deco_entity[i][j], biome, window);
    for (int i = 0; i <= ARCHER; i++) {
        for (npc_t *curr =
            biome->bot_data->bot_list[i]; curr; curr = curr->next)
            put_entity_in_view_list(curr->entity, biome, window);
    }
}
