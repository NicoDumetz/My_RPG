/*
** EPITECH PROJECT, 2024
** B-MUL-200-LIL-2-1-myrpg-matisse.dufour
** File description:
** manage_fps_param_button.c
*/

#include "rpg.h"

void inc_fps_p(void *data, button_t *button)
{
    rpg_t *rpg = (rpg_t *)data;

    rpg->params->fps->fps += 10;
    rpg->params->fps->dec_fps->state = NONE;
    if (rpg->params->fps->fps == 240)
        button->state = BLOCK;
    sfRenderWindow_setFramerateLimit(rpg->window, rpg->params->fps->fps);
}

void dec_fps_p(void *data, button_t *button)
{
    rpg_t *rpg = (rpg_t *)data;

    rpg->params->fps->fps -= 10;
    rpg->params->fps->inc_fps->state = NONE;
    if (rpg->params->fps->fps == 10)
        button->state = BLOCK;
    sfRenderWindow_setFramerateLimit(rpg->window, rpg->params->fps->fps);
}
