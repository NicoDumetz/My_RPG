/*
** EPITECH PROJECT, 2023
** game
** File description:
** rpg.h
*/

#include "rpg.h"

void destroy_skill(skill_t *skill)
{
    free(skill);
}

skill_t *init_skill(void)
{
    skill_t *skill = malloc(sizeof(skill_t));
    int level_tab[] = {1, 1, 1};

    for (int i = 0; i < 3; i++)
        skill->skill_level[i] = level_tab[i];
    skill->act_skill = FIRE_BALL;
    skill->skill_tab[FIRE_BALL] = &(fireball_tab[1]);
    skill->skill_tab[SHIELD] = &(shield_tab[1]);
    skill->skill_tab[RUN] = &(run_tab[1]);
    skill->skill_funct_tab[FIRE_BALL] = fire_ball_function;
    skill->skill_funct_tab[SHIELD] = shield_function;
    skill->skill_funct_tab[RUN] = run_function;
    return skill;
}
