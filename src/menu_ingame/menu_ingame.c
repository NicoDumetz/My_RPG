/*
** EPITECH PROJECT, 2024
** B-MUL-200-LIL-2-1-myrpg-matisse.dufour
** File description:
** menu.c
*/

#include "../../include/rpg.h"

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

static void display_menu_ingame_button(ingame_menu_t *menu,
    sfRenderWindow *window)
{
    sfRenderWindow_drawSprite(window, menu->resume->sprite, NULL);
    sfRenderWindow_drawSprite(window, menu->save->sprite, NULL);
    sfRenderWindow_drawSprite(window, menu->load_save->sprite, NULL);
    sfRenderWindow_drawSprite(window, menu->param->sprite, NULL);
    sfRenderWindow_drawSprite(window, menu->quit->sprite, NULL);
}

static void manage_menu_ingame_button(ingame_menu_t *menu, rpg_t *rpg)
{
    if (menu->from == TUTO)
        menu->save->state = BLOCK;
    if (menu->save->state == BLOCK && menu->from != TUTO)
        menu->save->state = NONE;
    if (rpg->save_scene->button_list == NULL)
        menu->load_save->state = BLOCK;
    if (menu->load_save->state == BLOCK &&
        rpg->save_scene->button_list != NULL)
        menu->load_save->state = NONE;
    update_button(menu->resume, &(rpg->mouse_data), rpg);
    update_button(menu->save, &(rpg->mouse_data), rpg);
    update_button(menu->load_save, &(rpg->mouse_data), rpg);
    update_button(menu->param, &(rpg->mouse_data), rpg);
    update_button(menu->quit, &(rpg->mouse_data), rpg);
}

void manage_ingame_menu(rpg_t *rpg)
{
    if (rpg->key_state[sfKeyEscape] && rpg->scene != INGAME_MENU &&
        rpg->scene != MENU) {
        rpg->ingame_menu->from = rpg->scene;
        rpg->scene = INGAME_MENU;
        set_view(rpg, rpg->ingame_menu->background,
            rpg->ingame_menu->background);
    }
    if (rpg->scene == INGAME_MENU)
        menu_ingame(rpg);
}

void menu_ingame(rpg_t *rpg)
{
    display_menu_back(rpg);
    manage_menu_ingame_button(rpg->ingame_menu, rpg);
    display_menu_ingame_button(rpg->ingame_menu, rpg->window);
}
