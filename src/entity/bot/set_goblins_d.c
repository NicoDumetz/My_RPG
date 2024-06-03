/*
** EPITECH PROJECT, 2023
** graph.h
** File description:
** macro for CSFML
*/

#include "rpg.h"

void set_action_tab_goblins_d(npc_t *goblins_d)
{
    goblins_d->action[ATTACK_F] = (sfVector2i){7, 2};
    goblins_d->action[ATTACK_B] = (sfVector2i){7, 2};
    goblins_d->action[ATTACK_L] = (sfVector2i){7, -2};
    goblins_d->action[ATTACK_R] = (sfVector2i){7, 2};
    goblins_d->action[MOVE_R] = (sfVector2i){6, 1};
    goblins_d->action[MOVE_L] = (sfVector2i){6, -1};
    goblins_d->action[MOVE_F] = (sfVector2i){6, 1};
    goblins_d->action[MOVE_B] = (sfVector2i){6, 1};
    goblins_d->action[STAND] = (sfVector2i){6, 0};
}

npc_t *set_goblins_d(sfTexture *texture)
{
    npc_t *goblins_d = init_npc(texture);

    goblins_d->next = NULL;
    goblins_d->prev = NULL;
    goblins_d->pv = 0;
    goblins_d->attack = 0;
    set_offset(goblins_d->entity, (sfVector2i){7, 3});
    set_action_tab_goblins_d(goblins_d);
    return (goblins_d);
}
