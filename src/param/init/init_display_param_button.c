/*
** EPITECH PROJECT, 2024
** B-MUL-200-LIL-2-1-myrpg-matisse.dufour
** File description:
** init_display_param_button.c
*/

#include "rpg.h"

void destroy_display_param(param_t *param)
{
    destroy_button(param->display->fullscreen);
    destroy_button(param->display->windowed);
    destroy_button(param->display->r1920x1080);
    destroy_button(param->display->r1280x720);
    destroy_button(param->display->r850x480);
    sfSprite_destroy(param->display->selection);
    free(param->display);
}

static void set_button_display_param_next(param_t *param, sfTexture **text_tab)
{
    sfSprite_setPosition(param->display->r1920x1080->sprite, (sfVector2f)
        {505, 260});
    init_action_button(&r1920x1080_p, 0, 0, param->display->r1920x1080);
    param->display->r1280x720 = create_button(text_tab, (int[5]){R1280x720_E,
        -1, -1, R1280x720_E, -1});
    sfSprite_setPosition(param->display->r1280x720->sprite, (sfVector2f)
        {735, 260});
    init_action_button(&r1280x720_p, 0, 0, param->display->r1280x720);
    param->display->r850x480 = create_button(text_tab, (int[5]){R850x480_E,
        -1, -1, R850x480_E, -1});
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
    param->display->fullscreen = create_button(text_tab, (int[5]){
        BUTTON_FULL_E, BUTTON_FULL_PRESSED_E, -1, BUTTON_FULL_E,
        BUTTON_FULL_PRESSED_E});
    sfSprite_setPosition(param->display->fullscreen->sprite, (sfVector2f)
        {1025, 165});
    init_action_button(&fullscreen_p, 0, 0,
        param->display->fullscreen);
    param->display->windowed = create_button(text_tab, (int[5]){
        BUTTON_WINDOW_E, BUTTON_WINDOW_PRESSED_E, -1, BUTTON_WINDOW_E,
        BUTTON_WINDOW_PRESSED_E});
    sfSprite_setPosition(param->display->windowed->sprite, (sfVector2f)
        {670, 165});
    init_action_button(&windowed_p, 0, 0, param->display->windowed);
    param->display->windowed->state = BLOCK;
    param->display->r1920x1080 = create_button(text_tab, (int[5]){R1920x1080_E,
        -1, -1, R1920x1080_E, -1});
    set_button_display_param_next(param, text_tab);
}

int set_display_param(param_t *param, sfTexture **text_tab)
{
    param->display = malloc(sizeof(display_t));
    if (!param->display) {
        free(param);
        return 84;
    }
    set_button_display_param(param, text_tab);
    return 0;
}
