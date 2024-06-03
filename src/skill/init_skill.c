/*
** EPITECH PROJECT, 2023
** game
** File description:
** rpg.h
*/

#include "rpg.h"

void destroy_skill(skill_t *skill)
{
    destroy_run((run_t *)skill->skill_tab[RUN]);
    destroy_fire_ball((fire_ball_t *)skill->skill_tab[FIRE_BALL]);
    destroy_shield((shield_t *)skill->skill_tab[SHIELD]);
    free(skill);
}

skill_t *init_skill(void)
{
    skill_t *skill = malloc(sizeof(skill_t));

    skill->act_skill = RUN;
    skill->skill_tab[FIRE_BALL] = init_fire_ball();
    skill->skill_tab[SHIELD] = init_shield();
    skill->skill_tab[RUN] = init_run();
    skill->skill_funct_tab[FIRE_BALL] = fire_ball_function;
    skill->skill_funct_tab[SHIELD] = shield_function;
    skill->skill_funct_tab[RUN] = run_function;
    return skill;
}
