/*
** EPITECH PROJECT, 2023
** graph.h
** File description:
** macro for CSFML
*/

#include "rpg.h"

void check_if_heros_attack_me(npc_t *to_check, heros_t *heros)
{
    sfRectangleShape *npc_rect = to_check->hitbox;

    if (heros->npc->act_action > ATTACK_R || heros->npc->cur_attack == false) {
        sfSprite_setColor(
            to_check->entity->sprite, sfColor_fromRGBA(255, 255, 255, 255));
        return;
    }
    for (int i = 0; i <= ATTACK_R; i++) {
        if (heros->npc->act_action == (action_t)i &&
            col_hitbox(heros->npc->attbox[i], npc_rect)) {
            to_check->pv = to_check->pv - heros->npc->attack;
            sfSprite_setColor(
                to_check->entity->sprite, sfColor_fromRGBA(255, 0, 0, 255));
            heros->npc->cur_attack = false;
        }
    }
    if (to_check->pv <= 0)
        to_check->is_alive = false;
}
