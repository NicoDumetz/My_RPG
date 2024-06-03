/*
** EPITECH PROJECT, 2023
** game
** File description:
** rpg.h
*/

#include "rpg.h"

int which_attack(heros_t *heros, bool *key_code, rpg_t *rpg)
{
    if (key_code[sfKeyI]) {
        heros->npc->act_action = ATTACK_F;
        return launch_sword_song(rpg);
    }
    if (key_code[sfKeyK]) {
        heros->npc->act_action = ATTACK_B;
        return launch_sword_song(rpg);
    }
    if (key_code[sfKeyJ]) {
        heros->npc->act_action = ATTACK_L;
        return launch_sword_song(rpg);
    }
    if (key_code[sfKeyL]) {
        heros->npc->act_action = ATTACK_R;
        return launch_sword_song(rpg);
    }
    return 0;
}

void manage_heros_attack(heros_t *heros, bool *key_code, rpg_t *rpg)
{
    if (heros->stamina > 15 && heros->npc->is_attack == false
        && which_attack(heros, key_code, rpg) == 1){
        heros->npc->entity->rect_sprite.left = 0;
        heros->stamina -= SWORD_COST;
        heros->npc->is_attack = true;
    }
}
