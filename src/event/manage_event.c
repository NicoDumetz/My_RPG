/*
** EPITECH PROJECT, 2023
** game
** File description:
** rpg.h
*/

#include "rpg.h"


void close_window(sfRenderWindow *window, sfEvent *event)
{
    if (event->type == sfEvtClosed)
        sfRenderWindow_close(window);
    if (event->type == sfEvtKeyPressed && event->key.code == sfKeyEscape)
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
}
