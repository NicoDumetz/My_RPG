/*
** EPITECH PROJECT, 2023
** game
** File description:
** rpg.h
*/

#include "rpg.h"

void update_mouse_scroll(mouse_data_t *mouse_data, sfEvent *event)
{
    if (event->type == sfEvtMouseWheelScrolled) {
        if (event->mouseWheelScroll.delta > 0)
            mouse_data->scroll_down = true;
        if (event->mouseWheelScroll.delta < 0)
            mouse_data->scroll_up = true;
    } else {
        mouse_data->scroll_up = false;
        mouse_data->scroll_down = false;
    }
}

void update_mouse_state(mouse_data_t *mouse_data, sfEvent *event)
{
    if (event->type == sfEvtMouseButtonPressed) {
        if (event->mouseButton.button == sfMouseLeft)
            mouse_data->left = true;
        if (event->mouseButton.button == sfMouseRight)
            mouse_data->right = true;
    }
    if (event->type == sfEvtMouseButtonReleased) {
        if (event->mouseButton.button == sfMouseLeft)
            mouse_data->left = false;
        if (event->mouseButton.button == sfMouseRight)
            mouse_data->right = false;
    }
}

void close_window(sfRenderWindow *window, sfEvent *event)
{
    if (event->type == sfEvtClosed)
        sfRenderWindow_close(window);
}

void update_key_state(rpg_t *rpg, sfEvent *event)
{
    if (event->type == sfEvtKeyPressed) {
        rpg->key_state[event->key.code] = true;
    } else if (event->type == sfEvtKeyReleased) {
        rpg->key_state[event->key.code] = false;
    }
}

void manage_event(rpg_t *rpg)
{
    close_window(rpg->window, &(rpg->event));
    update_key_state(rpg, &(rpg)->event);
    update_mouse_state(&(rpg->mouse_data), &(rpg->event));
    update_mouse_scroll(&(rpg->mouse_data), &(rpg->event));
}
