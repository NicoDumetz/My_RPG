/*
** EPITECH PROJECT, 2023
** game
** File description:
** rpg.h
*/

#include "rpg.h"

void manage_skill(heros_t *heros, rpg_t *rpg)
{
    int act_skill = heros->skill->act_skill;

    if (act_skill >= 0 && rpg->key_state[sfKeyLShift])
        heros->skill->skill_funct_tab[act_skill](
            heros, rpg, heros->skill->skill_tab[act_skill]);
}
