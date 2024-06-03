/*
** EPITECH PROJECT, 2024
** B-MUL-200-LIL-2-1-myrpg-matisse.dufour
** File description:
** init_param_struct.c
*/

#include "rpg.h"

static void set_page(param_t *param, sfTexture **text_tab)
{
    param->view = (sfVideoMode){1920, 1080, 32};
    text_tab[BACK_PARAM_E] = sfTexture_createFromFile(BACK_PARAM, NULL);
    text_tab[RIBBONS_PARAM_E] = sfTexture_createFromFile(RIBBONS_PARAM, NULL);
    text_tab[RIBBONS_PARAM_PRESSED_E] = sfTexture_createFromFile(RIBBONS_PARAM_PRESSED, NULL);
    text_tab[PAGE_PARAM_E] = sfTexture_createFromFile(PAGE_PARAM, NULL);
    param->background = sfSprite_create();
    sfSprite_setTexture(param->background, text_tab[BACK_PARAM_E], sfTrue);
    param->page = sfSprite_create();
    sfSprite_setTexture(param->page, text_tab[PAGE_PARAM_E], sfTrue);
    sfSprite_setPosition(param->page, (sfVector2f){382, 82});
    param->quit = create_button(text_tab, (int[5]){RIBBONS_PARAM_E,
        RIBBONS_PARAM_PRESSED_E, -1, RIBBONS_PARAM_E, -1});
    sfSprite_setPosition(param->quit->sprite, (sfVector2f){282, 178});
    init_action_button(&quit_params, 0, 0, param->quit);
}

static void set_button_display_param_next(param_t *param, sfTexture **text_tab)
{
    param->display->r1280x720 = create_button(text_tab, (int[5]){R1280x720_E,
        -1, -1,  R1280x720_E, -1});
    sfSprite_setPosition(param->display->r1280x720->sprite, (sfVector2f)
        {735, 260});
    init_action_button(&r1280x720_p, 0, 0, param->display->r1280x720);
    param->display->r850x480 = create_button(text_tab, (int[5]){R850x480_E,
        -1, -1,  R850x480_E, -1});
    sfSprite_setPosition(param->display->r850x480->sprite, (sfVector2f)
        {970, 260});
    init_action_button(&r850x480_p, 0, 0, param->display->r850x480);
    param->display->selection = sfSprite_create();
    sfSprite_setTexture(param->display->selection, text_tab[RES_SELECTION_E],
                        sfTrue);
    sfSprite_setPosition(param->display->selection, (sfVector2f){480, 235});
    param->display->visible = 1;
}

static void set_button_display_param(param_t *param, sfTexture **text_tab)
{
    param->display->fullscreen = create_button(text_tab, (int[5]){BUTTON_FULL_E,
        BUTTON_FULL_PRESSED_E, -1,  BUTTON_FULL_E, BUTTON_FULL_PRESSED_E});
    sfSprite_setPosition(param->display->fullscreen->sprite, (sfVector2f)
        {1025, 165});
    init_action_button(&fullscreen_p, 0, 0, param->display->fullscreen);
    param->display->windowed = create_button(text_tab, (int[5]){BUTTON_WINDOW_E,
        BUTTON_WINDOW_PRESSED_E, -1,  BUTTON_WINDOW_E, BUTTON_WINDOW_PRESSED_E});
    sfSprite_setPosition(param->display->windowed->sprite, (sfVector2f)
        {670, 165});
    init_action_button(&windowed_p, 0, 0, param->display->windowed);
    param->display->windowed->state = BLOCK;
    param->display->r1920x1080 = create_button(text_tab, (int[5]){R1920x1080_E,
        -1, -1,  R1920x1080_E, -1});
    sfSprite_setPosition(param->display->r1920x1080->sprite, (sfVector2f)
        {505, 260});
    init_action_button(&r1920x1080_p, 0, 0, param->display->r1920x1080);
    set_button_display_param_next(param, text_tab);
}

static int set_display_param(param_t *param, sfTexture **text_tab)
{
    param->display = malloc(sizeof(display_t));
    if (!param->display) {
        free(param);
        return 84;
    }
    text_tab[BUTTON_FULL_E] = sfTexture_createFromFile(BUTTON_FULL, NULL);
    text_tab[BUTTON_FULL_PRESSED_E] = sfTexture_createFromFile
        (BUTTON_FULL_PRESSED, NULL);
    text_tab[BUTTON_WINDOW_E] = sfTexture_createFromFile(BUTTON_WINDOW, NULL);
    text_tab[BUTTON_WINDOW_PRESSED_E] = sfTexture_createFromFile
        (BUTTON_WINDOW_PRESSED, NULL);
    text_tab[R1920x1080_E] = sfTexture_createFromFile(BUTTON_1920x1080, NULL);
    text_tab[R1280x720_E] = sfTexture_createFromFile(BUTTON_1280x720, NULL);
    text_tab[R850x480_E] = sfTexture_createFromFile(BUTTON_850x480, NULL);
    text_tab[RES_SELECTION_E] = sfTexture_createFromFile(RES_SELECTION, NULL);
    set_button_display_param(param, text_tab);
    return 0;
}

param_t *init_param_struct(sfTexture **text_tab)
{
    param_t *param = malloc(sizeof(param_t));

    if (!param)
        return (NULL);
    set_page(param, text_tab);
    if (set_display_param(param, text_tab) == 84)
        return (NULL);
    return param;
}