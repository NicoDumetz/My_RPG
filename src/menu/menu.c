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
//    sfSprite_setScale(rpg->start_menu->background, (sfVector2f)
//        {rpg->params->view.width / 1920.0, rpg->params->view.height / 1080.0});
    sfRenderWindow_drawSprite(rpg->window, rpg->start_menu->background,
        NULL);
    if (rpg->ticks) {
        rpg->start_menu->pos += 1;
        if (rpg->start_menu->pos == MENU_12 + 1)
            rpg->start_menu->pos = MENU_1;
    }
}

static void display_menu_button_next(menu_t *menu, sfRenderWindow *window,
    sfVector2f ratio)
{
//    sfSprite_setScale(menu->quit->sprite, ratio);
//    sfSprite_setPosition(menu->quit->sprite, (sfVector2f){ratio.x * 847.0,
//        ratio.y * 895.0});
    sfRenderWindow_drawSprite(window, menu->quit->sprite, NULL);
}

static void display_menu_button(menu_t *menu, sfRenderWindow *window,
    sfVideoMode view)
{
    sfVector2f ratio = {view.width / 1920.0, view.height / 1080.0};

//    sfSprite_setPosition(menu->play->sprite,
//        (sfVector2f){ratio.x * 810.0, ratio.y * 400.0});
//    sfSprite_setScale(menu->play->sprite, ratio);
    sfRenderWindow_drawSprite(window, menu->play->sprite, NULL);
//    sfSprite_setPosition(menu->new->sprite,
//        (sfVector2f){ratio.x * 847.0, ratio.y * 655.0});
//    sfSprite_setScale(menu->new->sprite, ratio);
    sfRenderWindow_drawSprite(window, menu->new->sprite, NULL);
//    sfSprite_setPosition(menu->saves->sprite,
//        (sfVector2f){ratio.x * 847.0, ratio.y * 735.0});
//    sfSprite_setScale(menu->saves->sprite, ratio);
    sfRenderWindow_drawSprite(window, menu->saves->sprite, NULL);
//    sfSprite_setPosition(menu->param->sprite,
//        (sfVector2f){ratio.x * 847.0, ratio.y * 815.0});
//    sfSprite_setScale(menu->param->sprite, ratio);
    sfRenderWindow_drawSprite(window, menu->param->sprite, NULL);
    display_menu_button_next(menu, window, ratio);
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
    display_menu_button(rpg->start_menu, rpg->window, rpg->params->view);
}
