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
}

void manage_event(rpg_t *rpg)
{
    close_window(rpg->window, &(rpg->event));
}
