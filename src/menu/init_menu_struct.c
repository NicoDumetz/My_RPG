/*
** EPITECH PROJECT, 2024
** B-MUL-200-LIL-2-1-myrpg-matisse.dufour
** File description:
** init_menu_struct.c
*/

#include "rpg.h"

void destroy_menu(menu_t *menu)
{
    sfSprite_destroy(menu->background);
    destroy_button(menu->play);
    destroy_button(menu->new);
    destroy_button(menu->saves);
    destroy_button(menu->param);
    destroy_button(menu->quit);
    free(menu);
}

static void create_menu_button(sfTexture **text_tab, menu_t *menu)
{
    menu->new = create_button(text_tab, (int[5]){NEW_E, NEW_PRESSED_E,
        NEW_HOVER_E, NEW_E, -1});
    init_action_button(&new_button, NULL, NULL, menu->new);
    menu->saves = create_button(text_tab, (int[5]){B_SAVE_E,
        B_SAVE_PRESSED_E, B_SAVE_HOVER_E, B_SAVE_E, B_SAVE_BLOCK_E});
    init_action_button(&saves_button, NULL, NULL, menu->saves);
    menu->param = create_button(text_tab, (int[5]){PARAM_E, PARAM_PRESSED_E,
        PARAM_HOVER_E, PARAM_E, -1});
    init_action_button(&param_button, NULL, NULL, menu->param);
    menu->quit = create_button(text_tab, (int[5]){QUIT_E, QUIT_PRESSED_E,
        QUIT_HOVER_E, QUIT_E, -1});
    init_action_button(&quit_button, NULL, NULL, menu->quit);
    sfSprite_setPosition(menu->quit->sprite, (sfVector2f){847,
        895});
    sfSprite_setPosition(menu->play->sprite, (sfVector2f){810, 400});
    sfSprite_setPosition(menu->new->sprite, (sfVector2f){847, 655});
    sfSprite_setPosition(menu->saves->sprite, (sfVector2f){847, 735});
    sfSprite_setPosition(menu->param->sprite, (sfVector2f){847, 815});
}

static void set_button(sfTexture **text_tab, menu_t *menu)
{
    menu->play = create_button(text_tab, (int[5]){PLAY_E, PLAY_PRESSED_E,
        PLAY_HOVER_E, PLAY_E, -1});
    init_action_button(&play_button, NULL, NULL, menu->play);
    create_menu_button(text_tab, menu);
}

menu_t *create_menu_struct(rpg_t *rpg)
{
    menu_t *menu = malloc(sizeof(menu_t));

    if (!menu)
        return (NULL);
    menu->pos = MENU_1;
    menu->background = sfSprite_create();
    sfSprite_setPosition(menu->background, (sfVector2f){0, 0});
    set_button(rpg->text_tab, menu);
    return menu;
}
