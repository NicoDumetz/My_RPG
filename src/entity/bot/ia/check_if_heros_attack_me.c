/*
** EPITECH PROJECT, 2023
** graph.h
** File description:
** macro for CSFML
*/

#include "rpg.h"

void check_bot_death(heros_t *heros, npc_t *to_check)
{
    if (to_check->pv <= 0) {
        to_check->is_alive = false;
        heros->npc->xp += to_check->xp;
    }
}

static void check_fire_touch(heros_t *heros, npc_t *npc)
{
    if (col_hitbox(heros->npc->projectile->hitbox, npc->hitbox)) {
        npc->pv = npc->pv - (heros->npc->attack * 1.5);
        npc->entity->effect_tab[EXPLO_BOT]->active = true;
        sfSprite_setColor(
            npc->entity->sprite, sfColor_fromRGBA(255, 0, 0, 255));
        heros->npc->projectile->active = 0;
        check_bot_death(heros, npc);
    }
}

void check_if_heros_attack_me(npc_t *to_check, heros_t *heros)
{
    sfRectangleShape *npc_rect = to_check->hitbox;

    if (heros->npc->projectile->active == 1)
        check_fire_touch(heros, to_check);
    if (heros->npc->act_action > ATTACK_R || heros->npc->cur_attack == false) {
        sfSprite_setColor(
            to_check->entity->sprite, sfColor_fromRGBA(255, 255, 255, 255));
        return;
    }
    for (int i = 0; i <= ATTACK_R; i++) {
        if (heros->npc->act_action == (action_t)i &&
            col_hitbox(heros->npc->attbox[i], npc_rect)) {
            to_check->pv = to_check->pv - heros->npc->attack;
            to_check->entity->effect_tab[BLOOD_BOT]->active = true;
            sfSprite_setColor(
                to_check->entity->sprite, sfColor_fromRGBA(255, 0, 0, 255));
            heros->npc->cur_attack = false;
        }
    }
    check_bot_death(heros, to_check);
}
