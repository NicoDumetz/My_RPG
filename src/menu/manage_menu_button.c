/*
** EPITECH PROJECT, 2024
** B-MUL-200-LIL-2-1-myrpg-matisse.dufour
** File description:
** manage_menu_button.c
*/

#include "rpg.h"

void play_button(void *data, button_t *button)
{
    rpg_t *rpg = (rpg_t *)data;

    rpg->scene = PLAIN;
}

void saves_button(void *data, button_t *button)
{
    rpg_t *rpg = (rpg_t *)data;

    rpg->scene = SAVE;
    rpg->start_menu->del_save->state = NONE;
}

void del_save_button(void *data, button_t *button)
{
    button->state = BLOCK;
}

void param_button(void *data, button_t *button)
{
    rpg_t *rpg = (rpg_t *)data;

}

void quit_button(void *data, button_t *button)
{
    sfRenderWindow *window = (sfRenderWindow *)data;

    sfRenderWindow_close(window);
}
