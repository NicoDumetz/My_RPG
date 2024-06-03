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
    npc_act->is_attack = true;
    *chase = 1;

}

void attack_right(npc_t *npc_act, rpg_t *rpg, heros_t *heros, int *chase)
{
    if (npc_act->is_attack == false)
        npc_act->entity->rect_sprite.left = 0;
    npc_act->act_action = ATTACK_R;
    npc_act->is_attack = true;
    *chase = 1;
}

void attack_back(npc_t *npc_act, rpg_t *rpg, heros_t *heros, int *chase)
{
    if (npc_act->is_attack == false)
        npc_act->entity->rect_sprite.left = 0;
    npc_act->act_action = ATTACK_B;
    npc_act->is_attack = true;
    *chase = 1;
}

void attack_front(npc_t *npc_act, rpg_t *rpg, heros_t *heros, int *chase)
{
    if (npc_act->is_attack == false)
        npc_act->entity->rect_sprite.left = 0;
    npc_act->act_action = ATTACK_F;
    npc_act->is_attack = true;
    *chase = 1;
}