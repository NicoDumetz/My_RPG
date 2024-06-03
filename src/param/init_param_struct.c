/*
** EPITECH PROJECT, 2024
** B-MUL-200-LIL-2-1-myrpg-matisse.dufour
** File description:
** init_param_struct.c
*/

#include "rpg.h"

void destroy_param_struct(param_t *param)
{
    sfSprite_destroy(param->background);
    sfSprite_destroy(param->page);
    destroy_button(param->quit);
    destroy_display_param(param);
    destroy_sound_param(param);
    destroy_fps_param(param);
    free(param);
}

static void set_page(param_t *param, sfTexture **text_tab)
{
    param->view = (sfVideoMode){1920, 1080, 32};
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

param_t *init_param_struct(sfTexture **text_tab, sfFont **font_tab)
{
    param_t *param = malloc(sizeof(param_t));

    if (!param)
        return (NULL);
    set_page(param, text_tab);
    if (set_display_param(param, text_tab) == 84)
        return (NULL);
    if (set_sound_param(param, text_tab, font_tab) == 84)
        return (NULL);
    if (set_fps_param(param, text_tab, font_tab) == 84)
        return (NULL);
    return param;
}
