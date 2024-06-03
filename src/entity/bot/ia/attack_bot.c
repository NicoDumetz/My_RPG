/*
** EPITECH PROJECT, 2024
** attack bot
** File description:
** attack bot
*/

#include "rpg.h"
#include "player.h"


static void lunch_attack(npc_t *npc_act, int i)
{
    action_t anim[] = {ATTACK_F, ATTACK_B, ATTACK_L, ATTACK_R};

    npc_act->entity->rect_sprite.left = 0;
    npc_act->act_action = anim[i];
    npc_act->is_attack = true;
    npc_act->stamina -= npc_act->max_stamina;
}

void manage_attack_bot(npc_t *npc_act, heros_t *heros, int *chase, int *stand)
{
    bool touch = 0;

    for (int i = 0; i <= 3; i++) {
        touch = col_hitbox(npc_act->attbox[i], heros->npc->hitbox);
        *chase = touch ? 1 : *chase;
        if (npc_act->is_attack == false && touch &&
            npc_act->stamina >= npc_act->max_stamina)
            lunch_attack(npc_act, i);
        if (npc_act->cur_attack == true && touch) {
            heros->npc->pv -= npc_act->damage;
            npc_act->cur_attack = false;
            heros->npc->entity->effect_tab[BLOOD_HEROS]->active = true;
            break;
        }
        if (touch && npc_act->is_attack == false)
            *stand = 1;
    }
}
