/*
** EPITECH PROJECT, 2024
** B-MUL-200-LIL-2-1-myrpg-matisse.dufour
** File description:
** equip_skill.c
*/

#include "rpg.h"

void equip_shield(void *data, button_t *)
{
    rpg_t *rpg = data;

    if (rpg->heros->skill->skill_level[SHIELD] == 0)
        return;
    rpg->heros->skill->act_skill = SHIELD;
}

void equip_fire_ball(void *data, button_t *)
{
    rpg_t *rpg = data;

    if (rpg->heros->skill->skill_level[FIRE_BALL] == 0)
        return;
    rpg->heros->skill->act_skill = FIRE_BALL;
}

void equip_run(void *data, button_t *)
{
    rpg_t *rpg = data;

    if (rpg->heros->skill->skill_level[RUN] == 0)
        return;
    rpg->heros->skill->act_skill = RUN;
}
