/*
** EPITECH PROJECT, 2023
** game
** File description:
** rpg.h
*/

#include "rpg.h"

int which_attack(heros_t *heros, bool *key_code)
{
    if (key_code[sfKeyI]) {
        heros->npc->act_action = ATTACK_F;
        return 1;
    }
    if (key_code[sfKeyK]) {
        heros->npc->act_action = ATTACK_B;
        return 1;
    }
    if (key_code[sfKeyJ]) {
        heros->npc->act_action = ATTACK_L;
        return 1;
    }
    if (key_code[sfKeyL]) {
        heros->npc->act_action = ATTACK_R;
        return 1;
    }
    return 0;
}

void manage_heros_attack(heros_t *heros, bool *key_code)
{
    if (heros->npc->is_attack == false && which_attack(heros, key_code) == 1){
        heros->npc->entity->rect_sprite.left = 0;
        heros->npc->is_attack = true;
    }
}
