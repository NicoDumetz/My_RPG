/*
** EPITECH PROJECT, 2024
** B-MUL-200-LIL-2-1-myrpg-matisse.dufour
** File description:
** init_menu_struct.c
*/

#include "../../include/rpg.h"

void destroy_menu_ingame(ingame_menu_t *menu)
{
    sfSprite_destroy(menu->background);
    sfRectangleShape_destroy(menu->blur);
    sfSprite_destroy(menu->page);
    destroy_button(menu->resume);
    destroy_button(menu->save);
    destroy_button(menu->load_save);
    destroy_button(menu->param);
    destroy_button(menu->quit);
    if (menu->last_frame)
        sfTexture_destroy(menu->last_frame);
    free(menu);
}

static void create_menu_button(ingame_menu_t *menu)
{
    sfSprite_setScale(menu->resume->sprite, (sfVector2f){1.2f, 1.2f});
    sfSprite_setPosition(menu->resume->sprite, (sfVector2f){770, 240});
    sfSprite_setScale(menu->load_save->sprite, (sfVector2f){1.2f, 1.2f});
    sfSprite_setPosition(menu->load_save->sprite, (sfVector2f){815, 555});
    sfSprite_setScale(menu->save->sprite, (sfVector2f){1.2f, 1.2f});
    sfSprite_setPosition(menu->save->sprite, (sfVector2f){815, 635});
    sfSprite_setScale(menu->param->sprite, (sfVector2f){1.2f, 1.2f});
    sfSprite_setPosition(menu->param->sprite, (sfVector2f){815, 715});
    sfSprite_setScale(menu->quit->sprite, (sfVector2f){1.2f, 1.2f});
    sfSprite_setPosition(menu->quit->sprite, (sfVector2f){815,
        795});
}

static void set_button(sfTexture **text_tab, ingame_menu_t *menu)
{
    menu->resume = create_button(text_tab, (int[5]){RESUME_E, RESUME_PRESSED_E,
        RESUME_HOVER_E, RESUME_E, -1});
    init_action_button(&resume_button, NULL, NULL, menu->resume);
    menu->save = create_button(text_tab, (int[5]){B_NSAVE_E,
        B_NSAVE_PRESSED_E, B_NSAVE_HOVER_E, B_NSAVE_E, B_NSAVE_BLOCK_E});
    init_action_button(&nsave_button, NULL, NULL, menu->save);
    menu->load_save = create_button(text_tab, (int[5]){B_SAVE_E,
        B_SAVE_PRESSED_E, B_SAVE_HOVER_E, B_SAVE_E, B_SAVE_BLOCK_E});
    init_action_button(&load_save_button, NULL, NULL, menu->load_save);
    menu->param = create_button(text_tab, (int[5]){PARAM_E, PARAM_PRESSED_E,
        PARAM_HOVER_E, PARAM_E, -1});
    init_action_button(&param_ingame_button, NULL, NULL, menu->param);
    menu->quit = create_button(text_tab, (int[5]){QUIT_E, QUIT_PRESSED_E,
        QUIT_HOVER_E, QUIT_E, -1});
    init_action_button(&quit_game_button, NULL, NULL, menu->quit);
    create_menu_button(menu);
}

ingame_menu_t *create_menu_ingame_struct(rpg_t *rpg)
{
    ingame_menu_t *menu = malloc(sizeof(ingame_menu_t));

    if (!menu)
        return (NULL);
    menu->pos = MENU_1;
    menu->last_frame = NULL;
    menu->blur = sfRectangleShape_create();
    sfRectangleShape_setSize(menu->blur, (sfVector2f){1920, 1080});
    sfRectangleShape_setPosition(menu->blur, (sfVector2f){0, 0});
    menu->background = sfSprite_create();
    sfSprite_setPosition(menu->background, (sfVector2f){0, 0});
    sfSprite_setTexture(menu->background, rpg->text_tab[MENU_1], sfTrue);
    menu->page = sfSprite_create();
    sfSprite_setPosition(menu->page, (sfVector2f){660, 83});
    sfSprite_setTexture(menu->page, rpg->text_tab[MENU_INGAME_E], sfTrue);
    set_button(rpg->text_tab, menu);
    return menu;
}
