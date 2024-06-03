/*
** EPITECH PROJECT, 2023
** game
** File description:
** rpg.h
*/

#include "rpg.h"

void destroy_shield(shield_t *shield)
{
    free(shield);
}

void shield_function(heros_t *heros, rpg_t *, void *skill_data)
{
    shield_t *data = (shield_t *)skill_data;

    if (heros->stamina > data->stamina)
        heros->stamina -= data->stamina;
}

shield_t *init_shield(void)
{
    shield_t *shield = malloc(sizeof(shield_t));

    shield->level = 0;
    shield->nbr_of_hit = 0;
    shield->hit_before_desactive = 0;
    shield->active = false;
    shield->stamina = 0;
    return (shield);
}
