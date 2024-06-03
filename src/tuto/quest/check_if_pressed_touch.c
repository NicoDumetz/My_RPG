/*
** EPITECH PROJECT, 2023
** graph.h
** File description:
** macro for CSFML
*/

#include "rpg.h"

void check_if_pressed_key(tuto_t *tuto, bool *key_tab)
{
    if (key_tab[sfKeyZ])
        tuto->move_tab[KEY_Z] = true;
    if (key_tab[sfKeyQ])
        tuto->move_tab[KEY_Q] = true;
    if (key_tab[sfKeyS])
        tuto->move_tab[KEY_S] = true;
    if (key_tab[sfKeyD])
        tuto->move_tab[KEY_D] = true;
    if (key_tab[sfKeyI])
        tuto->attack_tab[KEY_I] = true;
    if (key_tab[sfKeyJ])
        tuto->attack_tab[KEY_J] = true;
    if (key_tab[sfKeyK])
        tuto->attack_tab[KEY_K] = true;
    if (key_tab[sfKeyL])
        tuto->attack_tab[KEY_L] = true;
}
