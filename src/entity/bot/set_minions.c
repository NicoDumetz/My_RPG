/*
** EPITECH PROJECT, 2023
** graph.h
** File description:
** macro for CSFML
*/

#include "rpg.h"

void set_action_tab_minions(npc_t *minions)
{
    minions->action[ATTACK_F] = (sfVector2i){6, 4};
    minions->action[ATTACK_B] = (sfVector2i){6, 7};
    minions->action[ATTACK_L] = (sfVector2i){6, -2};
    minions->action[ATTACK_R] = (sfVector2i){6, 2};
    minions->action[MOVE_R] = (sfVector2i){6, 1};
    minions->action[MOVE_L] = (sfVector2i){6, -1};
    minions->action[MOVE_F] = (sfVector2i){6, 1};
    minions->action[MOVE_B] = (sfVector2i){6, 1};
    minions->action[STAND] = (sfVector2i){6, 0};
}

npc_t *set_minions(sfTexture *texture)
{
    npc_t *minions = init_npc(texture);

    minions->next = NULL;
    minions->prev = NULL;
    minions->pv = 0;
    minions->attack = 0;
    set_offset(minions->entity, (sfVector2i){6, 6});
    set_action_tab_minions(minions);
    return (minions);
}
