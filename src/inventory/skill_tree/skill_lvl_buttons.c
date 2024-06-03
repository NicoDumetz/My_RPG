/*
** EPITECH PROJECT, 2024
** B-MUL-200-LIL-2-1-myrpg-matisse.dufour
** File description:
** skill_buttons.c
*/

#include "rpg.h"

void add_run_lvl(void *data, button_t *)
{
    rpg_t *rpg = data;

    rpg->heros->skill->skill_level[RUN]++;
    rpg->heros->skill->skill_tab[RUN] =
        &(run_tab[rpg->heros->skill->skill_level[RUN]]);
    rpg->heros->skill_point--;
}

void add_shield_lvl(void *data, button_t *)
{
    rpg_t *rpg = data;

    rpg->heros->skill->skill_level[SHIELD]++;
    rpg->heros->skill->skill_tab[SHIELD] =
        &(shield_tab[rpg->heros->skill->skill_level[SHIELD]]);
    rpg->heros->skill_point--;
}

void add_fireball_lvl(void *data, button_t *)
{
    rpg_t *rpg = data;

    rpg->heros->skill->skill_level[FIRE_BALL]++;
    rpg->heros->skill->skill_tab[FIRE_BALL] =
        &(fireball_tab[rpg->heros->skill->skill_level[FIRE_BALL]]);
    rpg->heros->skill_point--;
}
