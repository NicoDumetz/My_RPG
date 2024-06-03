/*
** EPITECH PROJECT, 2024
** B-MUL-200-LIL-2-1-myrpg-matisse.dufour
** File description:
** manage_param_button.c
*/

#include "rpg.h"

void quit_params(void *data, button_t *)
{
    rpg_t *rpg = (rpg_t *) data;

    rpg->scene = rpg->params->from;
}
