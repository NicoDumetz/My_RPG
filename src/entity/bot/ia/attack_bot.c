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
    if (npc_act->type == ARCHERY || npc_act->type == DYNA)
        set_positions_projectile(npc_act, heros);
}

static void check_touch_heros(npc_t *npc_act, heros_t *heros)
{
    if (absorb_hit(heros->skill->skill_tab[SHIELD], heros)) {
        npc_act->cur_attack = false;
        return;
    }
    heros->npc->pv -= npc_act->damage;
    npc_act->cur_attack = false;
    heros->npc->entity->effect_tab[BLOOD_HEROS]->active = true;
}

static int check_attack(npc_t *npc_act, int i, heros_t *heros, bool touch)
{
    if (npc_act->is_attack == false && touch &&
        npc_act->stamina >= npc_act->max_stamina)
        lunch_attack(npc_act, i, heros);
    if (npc_act->cur_attack == true && touch && npc_act->type == MELEE) {
        check_touch_heros(npc_act, heros);
        return 1;
    }
    return 0;
}

static void active_projectile(npc_t *npc_act)
{
    if (npc_act->cur_attack == true && npc_act->type == DYNA) {
        npc_act->projectile->active = 1;
        npc_act->cur_attack = false;
    }
    if (npc_act->end_attack == true && npc_act->type == ARCHERY) {
        npc_act->projectile->active = 1;
        npc_act->end_attack = false;
    }
}

void manage_attack_bot(npc_t *npc_act, heros_t *heros, int *chase, int *stand)
{
    bool touch = 0;

    for (int i = 0; i <= 3; i++) {
        touch = col_hitbox(npc_act->attbox[i], heros->npc->hitbox);
        *chase = touch ? 1 : *chase;
        if (check_attack(npc_act, i, heros, touch) == 1)
            break;
        active_projectile(npc_act);
        if (touch && npc_act->is_attack == false)
            *stand = 1;
    }
}
