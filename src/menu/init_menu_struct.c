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
    destroy_button(menu->saves);
    destroy_button(menu->del_save);
    destroy_button(menu->param);
    destroy_button(menu->quit);
    free(menu);
}

static void set_background(sfTexture **text_tab)
{
    text_tab[35] = sfTexture_createFromFile("menu_asset/menu1.png", NULL);
    text_tab[36] = sfTexture_createFromFile("menu_asset/menu2.png", NULL);
    text_tab[37] = sfTexture_createFromFile("menu_asset/menu3.png", NULL);
    text_tab[38] = sfTexture_createFromFile("menu_asset/menu4.png", NULL);
    text_tab[39] = sfTexture_createFromFile("menu_asset/menu5.png", NULL);
    text_tab[40] = sfTexture_createFromFile("menu_asset/menu6.png", NULL);
    text_tab[41] = sfTexture_createFromFile("menu_asset/menu7.png", NULL);
    text_tab[42] = sfTexture_createFromFile("menu_asset/menu8.png", NULL);
    text_tab[43] = sfTexture_createFromFile("menu_asset/menu3.png", NULL);
    text_tab[44] = sfTexture_createFromFile("menu_asset/menu4.png", NULL);
    text_tab[45] = sfTexture_createFromFile("menu_asset/menu5.png", NULL);
    text_tab[46] = sfTexture_createFromFile("menu_asset/menu6.png", NULL);
}

static void create_menu_button(sfTexture **text_tab, menu_t *menu)
{
    menu->play = create_button(text_tab, (int[5]){47, 48, 62, 47, -1});
    sfSprite_setPosition(menu->play->sprite, (sfVector2f){810, 400});
    init_action_button(&play_button, NULL, NULL, menu->play);
    menu->saves = create_button(text_tab, (int[5]){49, 50, 51, 49, -1});
    sfSprite_setPosition(menu->saves->sprite, (sfVector2f){850, 655});
    init_action_button(&saves_button, NULL, NULL, menu->saves);
    menu->del_save = create_button(text_tab, (int[5]){52, 53, 54, 52, 55});
    sfSprite_setPosition(menu->del_save->sprite, (sfVector2f){1043, 660});
    menu->del_save->state = BLOCK;
    init_action_button(&del_save_button, NULL, NULL, menu->del_save);
    menu->param = create_button(text_tab, (int[5]){56, 57, 58, 56, -1});
    sfSprite_setPosition(menu->param->sprite, (sfVector2f){847, 735});
    init_action_button(&param_button, NULL, NULL, menu->param);
    menu->quit = create_button(text_tab, (int[5]){59, 60, 61, 59, -1});
    sfSprite_setPosition(menu->quit->sprite, (sfVector2f){847, 815});
    init_action_button(&quit_button, NULL, NULL, menu->quit);
}

static void set_button(sfTexture **text_tab, menu_t *menu)
{
    text_tab[47] = sfTexture_createFromFile(PLAY, NULL);
    text_tab[48] = sfTexture_createFromFile(PLAY_PRESSED, NULL);
    text_tab[62] = sfTexture_createFromFile(PLAY_HOVER, NULL);
    text_tab[49] = sfTexture_createFromFile(B_SAVE, NULL);
    text_tab[50] = sfTexture_createFromFile(B_SAVE_PRESSED, NULL);
    text_tab[51] = sfTexture_createFromFile(B_SAVE_HOVER, NULL);
    text_tab[52] = sfTexture_createFromFile(DEL_SAVE, NULL);
    text_tab[53] = sfTexture_createFromFile(DEL_SAVE_PRESSED, NULL);
    text_tab[54] = sfTexture_createFromFile(DEL_SAVE_HOVER, NULL);
    text_tab[55] = sfTexture_createFromFile(DEL_SAVE_DISABLE, NULL);
    text_tab[56] = sfTexture_createFromFile(PARAM, NULL);
    text_tab[57] = sfTexture_createFromFile(PARAM_PRESSED, NULL);
    text_tab[58] = sfTexture_createFromFile(PARAM_HOVER, NULL);
    text_tab[59] = sfTexture_createFromFile(QUIT, NULL);
    text_tab[60] = sfTexture_createFromFile(QUIT_PRESSED, NULL);
    text_tab[61] = sfTexture_createFromFile(QUIT_HOVER, NULL);
    create_menu_button(text_tab, menu);
}

menu_t *create_menu_struct(rpg_t *rpg)
{
    menu_t *menu = malloc(sizeof(menu_t));

    if (!menu)
        return (NULL);
    menu->pos = 35;
    set_background(rpg->text_tab);
    menu->background = sfSprite_create();
    set_button(rpg->text_tab, menu);
    return menu;
}
