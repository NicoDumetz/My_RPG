/*
** EPITECH PROJECT, 2024
** B-MUL-200-LIL-2-1-myrpg-matisse.dufour
** File description:
** param.c
*/

#include "rpg.h"

static void update_param_button(rpg_t *rpg)
{
    update_button(rpg->params->quit, &(rpg->mouse_data), rpg);
    update_param_button_display(rpg, rpg->params->display);
    update_param_button_sound(rpg, rpg->params->sound);
    update_param_button_fps(rpg, rpg->params->fps);
}

static void display_param_button(rpg_t *rpg)
{
    display_param_button_display(rpg, rpg->params->display);
    display_param_button_sound(rpg, rpg->params->sound);
    display_param_button_fps(rpg, rpg->params->fps);
}

void params_page(rpg_t *rpg)
{
    sfRenderWindow_drawSprite(rpg->window, rpg->params->background, NULL);
    sfRenderWindow_drawSprite(rpg->window, rpg->params->quit->sprite, NULL);
    sfRenderWindow_drawSprite(rpg->window, rpg->params->page, NULL);
    update_param_button(rpg);
    display_param_button(rpg);
}
