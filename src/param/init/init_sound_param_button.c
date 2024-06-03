/*
** EPITECH PROJECT, 2024
** B-MUL-200-LIL-2-1-myrpg-matisse.dufour
** File description:
** iniit_sound_param_button.c
*/

#include "rpg.h"

void destroy_sound_param(param_t *param)
{
    destroy_button(param->sound->sound);
    destroy_button(param->sound->no_sound);
    destroy_button(param->sound->inc_sound);
    destroy_button(param->sound->dec_sound);
    sfText_destroy(param->sound->sound_text);
    free(param->sound);
}

void update_sound_text(sound_t *sound)
{
    char buffer[32];

    snprintf(buffer, sizeof(buffer), "%d %%", sound->value_sound);
    sfText_setString(sound->sound_text, buffer);
}

static void set_button_sound_param_next(param_t *param, sfTexture **text_tab,
    sfFont **font_tab)
{
    param->sound->dec_sound = create_button(text_tab, (int[5]){BUTTON_MINUS_E,
        BUTTON_MINUS_PRESSED_E, -1, BUTTON_MINUS_E, BUTTON_MINUS_PRESSED_E});
    sfSprite_setPosition(param->sound->dec_sound->sprite, (sfVector2f)
        {1090, 350});
    init_action_button(0, &dec_sound_p, 0, param->sound->dec_sound);
    param->sound->sound_text = sfText_create();
    sfText_setFont(param->sound->sound_text, font_tab[VINQUE_E]);
    sfText_setColor(param->sound->sound_text, sfBlack);
    sfText_setCharacterSize(param->sound->sound_text, 24);
    sfText_setPosition(param->sound->sound_text, (sfVector2f){890, 360});
    update_sound_text(param->sound);
}

static void set_button_sound_param(param_t *param, sfTexture **text_tab,
    sfFont **font_tab)
{
    param->sound->sound = create_button(text_tab, (int[5]){BUTTON_SOUND_E,
        -1, -1, BUTTON_SOUND_E, -1});
    sfSprite_setPosition(param->sound->sound->sprite, (sfVector2f)
        {680, 350});
    init_action_button(&mute_p, 0, 0, param->sound->sound);
    param->sound->no_sound = create_button(text_tab, (int[5]){
        BUTTON_SOUND_PRESSED_E, -1, -1, BUTTON_SOUND_PRESSED_E, -1});
    param->sound->no_sound->visible = 0;
    sfSprite_setPosition(param->sound->no_sound->sprite, (sfVector2f)
        {680, 350});
    init_action_button(&unmute_p, 0, 0, param->sound->no_sound);
    param->sound->inc_sound = create_button(text_tab, (int[5]){BUTTON_PLUS_E,
        BUTTON_PLUS_PRESSED_E, -1, BUTTON_PLUS_E, BUTTON_PLUS_PRESSED_E});
    sfSprite_setPosition(param->sound->inc_sound->sprite, (sfVector2f)
        {1155, 350});
    init_action_button(0, &inc_sound_p, 0, param->sound->inc_sound);
    set_button_sound_param_next(param, text_tab, font_tab);
}

int set_sound_param(param_t *param, sfTexture **text_tab, sfFont **font_tab)
{
    param->sound = malloc(sizeof(display_t));
    if (!param->sound) {
        free(param->display);
        free(param);
        return 84;
    }
    param->sound->value_sound = 50;
    text_tab[BUTTON_SOUND_E] = sfTexture_createFromFile(BUTTON_SOUND, NULL);
    text_tab[BUTTON_SOUND_PRESSED_E] = sfTexture_createFromFile
        (BUTTON_SOUND_PRESSED, NULL);
    text_tab[BUTTON_PLUS_E] = sfTexture_createFromFile(BUTTON_PLUS, NULL);
    text_tab[BUTTON_PLUS_PRESSED_E] = sfTexture_createFromFile
        (BUTTON_PLUS_PRESSED, NULL);
    text_tab[BUTTON_MINUS_E] = sfTexture_createFromFile(BUTTON_MINUS, NULL);
    text_tab[BUTTON_MINUS_PRESSED_E] = sfTexture_createFromFile
        (BUTTON_MINUS_PRESSED, NULL);
    font_tab[VINQUE_E] = sfFont_createFromFile(VINQUE);
    set_button_sound_param(param, text_tab, font_tab);
    return 0;
}
