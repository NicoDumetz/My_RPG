/*
** EPITECH PROJECT, 2023
** graph.h
** File description:
** macro for CSFML
*/

#include "rpg.h"

void set_action_tab_knight(npc_t *knight)
{
    knight->action[ATTACK_F] = (sfVector2i){6, 4};
    knight->action[ATTACK_B] = (sfVector2i){6, 7};
    knight->action[ATTACK_L] = (sfVector2i){6, -2};
    knight->action[ATTACK_R] = (sfVector2i){6, 2};
    knight->action[MOVE_R] = (sfVector2i){6, 1};
    knight->action[MOVE_L] = (sfVector2i){6, -1};
    knight->action[MOVE_F] = (sfVector2i){6, 1};
    knight->action[MOVE_B] = (sfVector2i){6, 1};
    knight->action[STAND] = (sfVector2i){6, 0};
}

npc_t *set_knight(sfTexture *texture)
{
    npc_t *knight = init_npc(texture);

    knight->next = NULL;
    knight->prev = NULL;
    knight->pv = 0;
    knight->attack = 0;
    set_offset(knight->entity, (sfVector2i){6, 8});
    set_action_tab_knight(knight);
    return (knight);
}
