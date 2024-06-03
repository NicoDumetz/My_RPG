/*
** EPITECH PROJECT, 2023
** graph.h
** File description:
** macro for CSFML
*/

#include "rpg.h"

void check_is_alive(npc_t **curr, npc_t **head, biome_t *biome)
{
    if ((*curr)->is_alive == false) {
        remove_entity_from_list((*curr)->entity, biome);
        if ((*curr)->prev == NULL)
            *head = (*curr)->next;
        if ((*curr)->prev)
            (*curr)->prev->next = (*curr)->next;
        if ((*curr)->next)
            (*curr)->next->prev = (*curr)->prev;
        destroy_npc(*curr);
        *curr = NULL;
        biome->nbr_bot = biome->nbr_bot - 1;
    }
}

npc_t *bot_loop_sort(
    npc_t *curr, biome_t *biome, sfRenderWindow *window, int i)
{
    npc_t *next = curr->next;

    check_is_alive(&curr, &(biome->bot_data->bot_list[i]), biome);
    if (curr != NULL)
        put_entity_in_view_list(curr->entity, biome, window);
    return next;
}

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
            biome->bot_data->bot_list[i]; curr;) {
            curr = bot_loop_sort(curr, biome, window, i);
        }
    }
}
