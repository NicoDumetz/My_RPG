/*
** EPITECH PROJECT, 2023
** graph.h
** File description:
** macro for CSFML
*/

#include "rpg.h"

void destroy_npc(npc_t *npc)
{
    destroy_entity(npc->entity);
    free(npc);
}

npc_t *init_npc(char *asset)
{
    npc_t *npc = malloc(sizeof(npc_t));

    npc->attack = 0;
    npc->pv = 0;
    npc->entity = init_entity(asset);
    npc->act_action = STAND;
    for (int i = ATTACK_F; i <= STAND; i++)
        npc->action[i] = 0;
    return npc;
}
