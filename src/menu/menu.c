/*
** EPITECH PROJECT, 2024
** B-MUL-200-LIL-2-1-myrpg-matisse.dufour
** File description:
** menu.c
*/

#include "rpg.h"

static void display_menu_back(rpg_t *rpg)
{
    sfSprite_setTexture(rpg->start_menu->background,
        rpg->text_tab[rpg->start_menu->pos], sfTrue);
    sfRenderWindow_drawSprite(rpg->window, rpg->start_menu->background,
        NULL);
    if (rpg->ticks) {
        rpg->start_menu->pos += 1;
        if (rpg->start_menu->pos == MENU_12 + 1)
            rpg->start_menu->pos = MENU_1;
    }
}

static void display_menu_button(menu_t *menu, sfRenderWindow *window)
{
    sfRenderWindow_drawSprite(window, menu->play->sprite, NULL);
    sfRenderWindow_drawSprite(window, menu->new->sprite, NULL);
    sfRenderWindow_drawSprite(window, menu->saves->sprite, NULL);
    sfRenderWindow_drawSprite(window, menu->param->sprite, NULL);
    sfRenderWindow_drawSprite(window, menu->quit->sprite, NULL);
}

static void manage_menu_button(menu_t *menu, rpg_t *rpg)
{
    update_button(menu->play, &(rpg->mouse_data), rpg);
    update_button(menu->new, &(rpg->mouse_data), NULL);
    update_button(menu->saves, &(rpg->mouse_data), rpg);
    update_button(menu->param, &(rpg->mouse_data), rpg);
    update_button(menu->quit, &(rpg->mouse_data), rpg->window);
}

void start_menu(rpg_t *rpg)
{
    display_menu_back(rpg);
    manage_menu_button(rpg->start_menu, rpg);
    display_menu_button(rpg->start_menu, rpg->window);
}
