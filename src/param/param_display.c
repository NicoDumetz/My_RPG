/*
** EPITECH PROJECT, 2024
** B-MUL-200-LIL-2-1-myrpg-matisse.dufour
** File description:
** param_display.c
*/

#include "../../include/rpg.h"

void update_param_button_display(rpg_t *rpg, display_t *display)
{
    update_button(display->windowed, &(rpg->mouse_data), rpg);
    update_button(display->fullscreen, &(rpg->mouse_data), rpg);
    update_button(display->r1920x1080, &(rpg->mouse_data), rpg);
    update_button(display->r1280x720, &(rpg->mouse_data), rpg);
    update_button(display->r850x480, &(rpg->mouse_data), rpg);
}

void display_param_button_display(rpg_t *rpg, display_t *display)
{
    sfRenderWindow_drawSprite(rpg->window, display->windowed->sprite, NULL);
    sfRenderWindow_drawSprite(rpg->window, display->fullscreen->sprite, NULL);
    if (display->visible == 1) {
        sfRenderWindow_drawSprite(rpg->window, display->r1920x1080->sprite,
            NULL);
        sfRenderWindow_drawSprite(rpg->window, display->r1280x720->sprite,
            NULL);
        sfRenderWindow_drawSprite(rpg->window, display->r850x480->sprite, NULL);
        sfRenderWindow_drawSprite(rpg->window, display->selection, NULL);
    }
}
