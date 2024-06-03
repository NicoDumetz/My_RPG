/*
** EPITECH PROJECT, 2023
** graph.h
** File description:
** macro for CSFML
*/

#include "rpg.h"

void manage_quest_tuto(tuto_t *tuto, rpg_t *rpg)
{
    check_if_pressed_key(tuto, rpg->key_state);
    for (int i = 0; i <= TEST_T; i++)
        if (tuto->quest_tab[i].state == BEGIN &&
            tuto->quest_tab[i].check_f(&(tuto->quest_tab[i]), rpg))
            next_quest(tuto->biome->quest_giver, tuto->quest_tab);
}
