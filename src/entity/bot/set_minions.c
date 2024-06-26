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
    sfFloatRect colbox = {40, 60, 80, 95};
    sfFloatRect hitbox = {35, 35, 70, 70};

    minions->pv = 50;
    minions->attack = 0;
    minions->entity->parent = minions;
    set_offset(minions->entity, (sfVector2i){6, 6});
    set_action_tab_minions(minions);
    minions->entity->colbox_dim = colbox;
    minions->xp = 10;
    minions->hitbox_dim = hitbox;
    minions->view = 500;
    minions->type = MELEE;
    return (minions);
}
