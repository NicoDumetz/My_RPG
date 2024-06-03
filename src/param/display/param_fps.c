/*
** EPITECH PROJECT, 2024
** B-MUL-200-LIL-2-1-myrpg-matisse.dufour
** File description:
** param_fps.c
*/

#include "../../../include/rpg.h"

void update_param_button_fps(rpg_t *rpg, fps_t *fps)
{
    update_button(fps->inc_fps, &(rpg->mouse_data), rpg);
    update_button(fps->dec_fps, &(rpg->mouse_data), rpg);
    update_fps_text(fps);
}

void display_param_button_fps(rpg_t *rpg, fps_t *fps)
{
    sfRenderWindow_drawSprite(rpg->window, fps->inc_fps->sprite, NULL);
    sfRenderWindow_drawSprite(rpg->window, fps->dec_fps->sprite, NULL);
    sfRenderWindow_drawText(rpg->window, fps->fps_text, NULL);
}
