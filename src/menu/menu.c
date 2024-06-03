/*
** EPITECH PROJECT, 2024
** B-MUL-200-LIL-2-1-myrpg-matisse.dufour
** File description:
** menu.c
*/

#include "rpg.h"

static void display_menu_back(sfRenderWindow *window, menu_t *menu, bool ticks)
{
    sfRenderWindow_drawSprite(window, menu->sprite[menu->pos], NULL);
    if (ticks) {
        menu->pos += 1;
        if (menu->pos == 12)
            menu->pos = 0;
    }
}

void start_menu(rpg_t *rpg)
{
    display_menu_back(rpg->window, rpg->start_menu, rpg->ticks);
}
