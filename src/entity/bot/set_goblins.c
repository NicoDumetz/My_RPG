/*
** EPITECH PROJECT, 2023
** graph.h
** File description:
** macro for CSFML
*/

#include "rpg.h"

void set_action_tab_goblins(npc_t *goblins)
{
    goblins->action[ATTACK_F] = (sfVector2i){6, 4};
    goblins->action[ATTACK_B] = (sfVector2i){6, 3};
    goblins->action[ATTACK_L] = (sfVector2i){6, -2};
    goblins->action[ATTACK_R] = (sfVector2i){6, 2};
    goblins->action[MOVE_R] = (sfVector2i){6, 1};
    goblins->action[MOVE_L] = (sfVector2i){6, -1};
    goblins->action[MOVE_F] = (sfVector2i){6, 1};
    goblins->action[MOVE_B] = (sfVector2i){6, 1};
    goblins->action[STAND] = (sfVector2i){7, 6};
}

npc_t *set_goblins(sfTexture *texture)
{
    npc_t *goblins = init_npc(texture);

    goblins->next = NULL;
    goblins->prev = NULL;
    goblins->pv = 0;
    goblins->attack = 0;
    set_offset(goblins->entity, (sfVector2i){7, 5});
    set_action_tab_goblins(goblins);
    return (goblins);
}
