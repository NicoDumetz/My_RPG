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

static void set_background(sfTexture **text_tab)
{
    text_tab[MENU_1] = sfTexture_createFromFile("menu_asset/menu1.png", NULL);
    text_tab[MENU_2] = sfTexture_createFromFile("menu_asset/menu2.png", NULL);
    text_tab[MENU_3] = sfTexture_createFromFile("menu_asset/menu3.png", NULL);
    text_tab[MENU_4] = sfTexture_createFromFile("menu_asset/menu4.png", NULL);
    text_tab[MENU_5] = sfTexture_createFromFile("menu_asset/menu5.png", NULL);
    text_tab[MENU_6] = sfTexture_createFromFile("menu_asset/menu6.png", NULL);
    text_tab[MENU_7] = sfTexture_createFromFile("menu_asset/menu7.png", NULL);
    text_tab[MENU_8] = sfTexture_createFromFile("menu_asset/menu8.png", NULL);
    text_tab[MENU_9] = sfTexture_createFromFile("menu_asset/menu3.png", NULL);
    text_tab[MENU_10] = sfTexture_createFromFile("menu_asset/menu4.png", NULL);
    text_tab[MENU_11] = sfTexture_createFromFile("menu_asset/menu5.png", NULL);
    text_tab[MENU_12] = sfTexture_createFromFile("menu_asset/menu6.png", NULL);
}

static void create_menu_button(sfTexture **text_tab, menu_t *menu)
{
    menu->play = create_button(text_tab, (int[5]){PLAY_E, PLAY_PRESSED_E,
        PLAY_HOVER_E, PLAY_E, -1});
    sfSprite_setPosition(menu->play->sprite, (sfVector2f){810, 400});
    init_action_button(&play_button, NULL, NULL, menu->play);
    menu->new = create_button(text_tab, (int[5]){NEW_E, NEW_PRESSED_E,
        NEW_HOVER_E, NEW_E, -1});
    sfSprite_setPosition(menu->new->sprite, (sfVector2f){847, 655});
    init_action_button(&new_button, NULL, NULL, menu->new);
    menu->saves = create_button(text_tab, (int[5]){B_SAVE_E,
        B_SAVE_PRESSED_E, B_SAVE_HOVER_E, B_SAVE_E, -1});
    sfSprite_setPosition(menu->saves->sprite, (sfVector2f){847, 735});
    init_action_button(&saves_button, NULL, NULL, menu->saves);
    menu->param = create_button(text_tab, (int[5]){PARAM_E, PARAM_PRESSED_E,
        PARAM_HOVER_E, PARAM_E, -1});
    sfSprite_setPosition(menu->param->sprite, (sfVector2f){847, 815});
    init_action_button(&param_button, NULL, NULL, menu->param);
    menu->quit = create_button(text_tab, (int[5]){QUIT_E, QUIT_PRESSED_E,
        QUIT_HOVER_E, QUIT_E, -1});
    sfSprite_setPosition(menu->quit->sprite, (sfVector2f){847, 895});
    init_action_button(&quit_button, NULL, NULL, menu->quit);
}

static void set_button(sfTexture **text_tab, menu_t *menu)
{
    text_tab[PLAY_E] = sfTexture_createFromFile(PLAY, NULL);
    text_tab[PLAY_PRESSED_E] = sfTexture_createFromFile(PLAY_PRESSED, NULL);
    text_tab[PLAY_HOVER_E] = sfTexture_createFromFile(PLAY_HOVER, NULL);
    text_tab[B_SAVE_E] = sfTexture_createFromFile(B_SAVE, NULL);
    text_tab[B_SAVE_PRESSED_E] = sfTexture_createFromFile(B_SAVE_PRESSED, NULL);
    text_tab[B_SAVE_HOVER_E] = sfTexture_createFromFile(B_SAVE_HOVER, NULL);
    text_tab[NEW_E] = sfTexture_createFromFile(NEW, NULL);
    text_tab[NEW_PRESSED_E] = sfTexture_createFromFile(NEW_PRESSED, NULL);
    text_tab[NEW_HOVER_E] = sfTexture_createFromFile(NEW_HOVER, NULL);
    text_tab[PARAM_E] = sfTexture_createFromFile(PARAM, NULL);
    text_tab[PARAM_PRESSED_E] = sfTexture_createFromFile(PARAM_PRESSED, NULL);
    text_tab[PARAM_HOVER_E] = sfTexture_createFromFile(PARAM_HOVER, NULL);
    text_tab[QUIT_E] = sfTexture_createFromFile(QUIT, NULL);
    text_tab[QUIT_PRESSED_E] = sfTexture_createFromFile(QUIT_PRESSED, NULL);
    text_tab[QUIT_HOVER_E] = sfTexture_createFromFile(QUIT_HOVER, NULL);
    create_menu_button(text_tab, menu);
}

menu_t *create_menu_struct(rpg_t *rpg)
{
    menu_t *menu = malloc(sizeof(menu_t));

    if (!menu)
        return (NULL);
    menu->pos = MENU_1;
    set_background(rpg->text_tab);
    menu->background = sfSprite_create();
    set_button(rpg->text_tab, menu);
    return menu;
}
