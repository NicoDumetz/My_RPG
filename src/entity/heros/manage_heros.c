/*
** EPITECH PROJECT, 2023
** graph.h
** File description:
** macro for CSFML
*/

#include "rpg.h"

void manage_heros(heros_t *heros, rpg_t *rpg)
{
    if (heros->npc->is_attack == false)
        manage_movements(rpg);
    manage_heros_attack(rpg->heros, rpg->key_state);
}
