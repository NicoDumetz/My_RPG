/*
** EPITECH PROJECT, 2023
** graph.h
** File description:
** macro for CSFML
*/

#include "rpg.h"

void manage_heros(heros_t *heros, rpg_t *rpg)
{
    manage_movements(rpg);
    manage_heros_attack(heros, rpg->key_state);
}
