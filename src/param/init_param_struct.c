/*
** EPITECH PROJECT, 2024
** B-MUL-200-LIL-2-1-myrpg-matisse.dufour
** File description:
** init_param_struct.c
*/

#include "rpg.h"

static void set_page(param_t *param, sfTexture **text_tab)
{
    text_tab[BACK_PARAM_E] = sfTexture_createFromFile(BACK_PARAM, NULL);
    text_tab[RIBBONS_PARAM_E] = sfTexture_createFromFile(RIBBONS_PARAM, NULL);
    text_tab[RIBBONS_PARAM_PRESSED_E] = sfTexture_createFromFile(RIBBONS_PARAM_PRESSED, NULL);
    text_tab[PAGE_BORDER_PARAM_E] = sfTexture_createFromFile(PAGE_BORDER_PARAM, NULL);
    text_tab[PAGE_PARAM_E] = sfTexture_createFromFile(PAGE_PARAM, NULL);
    param->background = sfSprite_create();
    sfSprite_setTexture(param->background, text_tab[BACK_PARAM_E], sfTrue);
    param->page = sfSprite_create();
    sfSprite_setTexture(param->page, text_tab[PAGE_PARAM_E], sfTrue);
    sfSprite_setPosition(param->page, (sfVector2f){432, 137});
    param->border_page = sfSprite_create();
    sfSprite_setTexture(param->border_page, text_tab[PAGE_BORDER_PARAM_E], sfTrue);
    sfSprite_setPosition(param->border_page, (sfVector2f){375, 78});
    param->quit = create_button(text_tab, (int[5]){RIBBONS_PARAM_E,
        RIBBONS_PARAM_PRESSED_E, -1, RIBBONS_PARAM_E, -1});
    sfSprite_setPosition(param->quit->sprite, (sfVector2f){282, 178});
    init_action_button(&quit_params, 0, 0, param->quit);
}

param_t *init_param_struct(sfTexture **text_tab)
{
    param_t *param = malloc(sizeof(param_t));

    if (!param)
        return (NULL);
    param->fps = 60;
    set_page(param, text_tab);
    return param;
}