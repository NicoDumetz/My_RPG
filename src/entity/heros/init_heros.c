/*
** EPITECH PROJECT, 2023
** graph.h
** File description:
** macro for CSFML
*/

#include "rpg.h"

void destroy_heros(heros_t *heros)
{
    destroy_npc(heros->npc);
    free(heros);
}

void set_action_tab_heros(heros_t *heros)
{
    heros->npc->action[ATTACK_F] = 4;
    heros->npc->action[ATTACK_B] = 7;
    heros->npc->action[ATTACK_L] = -2;
    heros->npc->action[ATTACK_R] = 2;
    heros->npc->action[MOVE_R] = 1;
    heros->npc->action[MOVE_L] = -1;
    heros->npc->action[MOVE_F] = 1;
    heros->npc->action[MOVE_B] = 1;
    heros->npc->action[STAND] = 0;
}

heros_t *init_heros(char *asset)
{
    heros_t *heros = malloc(sizeof(heros_t));

    heros->npc = init_npc(asset);
    set_offset(heros->npc->entity, (sfVector2i){6, 8});
    set_action_tab_heros(heros);
    return heros;
}
