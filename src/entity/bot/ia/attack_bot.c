/*
** EPITECH PROJECT, 2024
** attack bot
** File description:
** attack bot
*/

#include "rpg.h"
#include "player.h"


static void lunch_attack(npc_t *npc_act, int i, heros_t *heros)
{
    action_t anim[] = {ATTACK_F, ATTACK_B, ATTACK_L, ATTACK_R};

    npc_act->entity->rect_sprite.left = 0;
    npc_act->act_action = anim[i];
    npc_act->is_attack = true;
    npc_act->stamina -= npc_act->max_stamina;
    if (npc_act->type == ARCHERY)
        set_positions_projectile(npc_act, heros);
}

static void check_touch_heros(npc_t *npc_act, heros_t *heros)
{
    heros->npc->pv -= npc_act->damage;
    npc_act->cur_attack = false;
    heros->npc->entity->effect_tab[BLOOD_HEROS]->active = true;
}

void manage_attack_bot(npc_t *npc_act, heros_t *heros, int *chase, int *stand)
{
    bool touch = 0;

    for (int i = 0; i <= 3; i++) {
        touch = col_hitbox(npc_act->attbox[i], heros->npc->hitbox);
        *chase = touch ? 1 : *chase;
        if (npc_act->is_attack == false && touch &&
            npc_act->stamina >= npc_act->max_stamina)
            lunch_attack(npc_act, i, heros);
        if (npc_act->cur_attack == true && touch) {
            check_touch_heros(npc_act, heros);
            break;
        }
        if (npc_act->end_attack == true && npc_act->type == ARCHERY) {
            npc_act->projectile->active = 1;
            npc_act->end_attack = false;
        }
        if (touch && npc_act->is_attack == false)
            *stand = 1;
    }
}
