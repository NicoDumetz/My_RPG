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
    run_t *run = (run_t *)heros->skill->skill_tab[RUN];
    static int spam = 0;

    if (act_skill >= 0 && rpg->key_state[sfKeyLShift] && spam == 0) {
        heros->skill->skill_funct_tab[act_skill](
            heros, rpg, heros->skill->skill_tab[act_skill]);
        spam = 1;
    }
    if (!rpg->key_state[sfKeyLShift])
        spam = 0;
    if (act_skill == RUN && !(rpg->key_state[sfKeyLShift]) && run->active) {
        run->active = false;
        heros->multi_speed /= run->speed_multi;
    }
}
