/*
** EPITECH PROJECT, 2024
** attack bot
** File description:
** attack bot
*/

#include "rpg.h"
#include "player.h"

void attack_left(npc_t *npc_act, rpg_t *rpg, heros_t *heros, int *chase)
{
    if (npc_act->is_attack == false)
        npc_act->entity->rect_sprite.left = 0;
    npc_act->act_action = ATTACK_L;
    if (npc_act->cur_attack == true &&
        col_hitbox(npc_act->attbox[2], heros->npc->hitbox))
        heros->npc->pv -= 0.05;
    npc_act->is_attack = true;
    *chase = 1;
}

void attack_right(npc_t *npc_act, rpg_t *rpg, heros_t *heros, int *chase)
{
    if (npc_act->is_attack == false)
        npc_act->entity->rect_sprite.left = 0;
    npc_act->act_action = ATTACK_R;
    if (npc_act->cur_attack == true &&
        col_hitbox(npc_act->attbox[3], heros->npc->hitbox))
        heros->npc->pv -= 0.05;
    npc_act->is_attack = true;
    *chase = 1;
}

void attack_back(npc_t *npc_act, rpg_t *rpg, heros_t *heros, int *chase)
{
    if (npc_act->is_attack == false)
        npc_act->entity->rect_sprite.left = 0;
    npc_act->act_action = ATTACK_B;
    if (npc_act->cur_attack == true &&
        col_hitbox(npc_act->attbox[1], heros->npc->hitbox))
        heros->npc->pv -= 0.05;
    npc_act->is_attack = true;
    *chase = 1;
}

void attack_front(npc_t *npc_act, rpg_t *rpg, heros_t *heros, int *chase)
{
    if (npc_act->is_attack == false)
        npc_act->entity->rect_sprite.left = 0;
    npc_act->act_action = ATTACK_F;
    if (npc_act->cur_attack == true &&
        col_hitbox(npc_act->attbox[0], heros->npc->hitbox))
        heros->npc->pv -= 0.05;
    npc_act->is_attack = true;
    *chase = 1;
}
