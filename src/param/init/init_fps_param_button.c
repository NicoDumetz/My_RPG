/*
** EPITECH PROJECT, 2024
** B-MUL-200-LIL-2-1-myrpg-matisse.dufour
** File description:
** init_fps_param_button.c
*/

#include "rpg.h"

void destroy_fps_param(param_t *param)
{
    sfText_destroy(param->fps->fps_text);
    destroy_button(param->fps->inc_fps);
    destroy_button(param->fps->dec_fps);
    free(param->fps);
}

void update_fps_text(fps_t *fps)
{
    char buffer[32];

    snprintf(buffer, sizeof(buffer), "%d fps", fps->fps);
    sfText_setString(fps->fps_text, buffer);
}

static void set_button_fps_param_next(param_t *param, sfFont **font_tab)
{
    param->fps->fps_text = sfText_create();
    sfText_setFont(param->fps->fps_text, font_tab[VINQUE_E]);
    sfText_setColor(param->fps->fps_text, sfBlack);
    sfText_setCharacterSize(param->fps->fps_text, 26);
    sfText_setPosition(param->fps->fps_text, (sfVector2f){715, 458});
    update_fps_text(param->fps);
}

static void set_button_fps_param(param_t *param, sfTexture **text_tab,
    sfFont **font_tab)
{
    param->fps->inc_fps = create_button(text_tab, (int[5]){BUTTON_PLUS_E,
        BUTTON_PLUS_PRESSED_E, -1, BUTTON_PLUS_E, BUTTON_PLUS_PRESSED_E});
    sfSprite_setPosition(param->fps->inc_fps->sprite, (sfVector2f)
        {1000, 445});
    init_action_button(&inc_fps_p, 0, 0, param->fps->inc_fps);
    param->fps->dec_fps = create_button(text_tab, (int[5]){BUTTON_MINUS_E,
        BUTTON_MINUS_PRESSED_E, -1, BUTTON_MINUS_E, BUTTON_MINUS_PRESSED_E});
    sfSprite_setPosition(param->fps->dec_fps->sprite, (sfVector2f)
        {930, 445});
    init_action_button(&dec_fps_p, 0, 0, param->fps->dec_fps);
    set_button_fps_param_next(param, font_tab);
}

int set_fps_param(param_t *param, sfTexture **text_tab, sfFont **font_tab)
{
    param->fps = malloc(sizeof(display_t));
    if (!param->fps) {
        free(param->display);
        free(param->fps);
        free(param);
        return 84;
    }
    param->fps->fps = 60;
    set_button_fps_param(param, text_tab, font_tab);
    return 0;
}
