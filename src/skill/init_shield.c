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

bool absorb_hit(void *skill_data, heros_t *heros)
{
    shield_t *data = (shield_t *)skill_data;

    if (data->active) {
        data->hit_before_desactive -= 1;
        if (data->hit_before_desactive <= 0) {
            data->hit_before_desactive = 0;
            data->active = false;
            heros->npc->entity->effect_tab[SHIELD_HEROS]->active = false;
        }
        return true;
    }
    return false;
}

void shield_function(heros_t *heros, rpg_t *, void *skill_data)
{
    shield_t *data = (shield_t *)skill_data;

    if (heros->stamina > data->stamina && data->active == false) {
        heros->stamina -= data->stamina;
        data->active = true;
        data->hit_before_desactive = data->nbr_of_hit;
        heros->npc->entity->effect_tab[SHIELD_HEROS]->active = true;
    }
}

shield_t *init_shield(void)
{
    shield_t *shield = malloc(sizeof(shield_t));

    shield->level = 0;
    shield->nbr_of_hit = 1;
    shield->hit_before_desactive = 0;
    shield->active = false;
    shield->stamina = 10;
    return (shield);
}
