/*
** EPITECH PROJECT, 2024
** B-MUL-200-LIL-2-1-myrpg-matisse.dufour
** File description:
** manage_sound_param_button.c
*/

#include "rpg.h"

void mute_p(void *data, button_t *button)
{
    sound_t *sound = (sound_t *)data;

    sound->value_sound_s = sound->value_sound;
    sound->value_sound = 0;
    button->visible = 0;
    sound->no_sound->visible = 1;
    sound->inc_sound->state = BLOCK;
    sound->dec_sound->state = BLOCK;
}

void unmute_p(void *data, button_t *button)
{
    sound_t *sound = (sound_t *)data;

    sound->value_sound = sound->value_sound_s;
    if (sound->value_sound == 0)
        return;
    button->visible = 0;
    sound->sound->visible = 1;
    if (sound->value_sound == 100) {
        sound->inc_sound->state = BLOCK;
        sound->dec_sound->state = NONE;
    } else {
        sound->inc_sound->state = NONE;
        sound->dec_sound->state = NONE;
    }
}

void inc_sound_p(void *data, button_t *button)
{
    sound_t *sound = (sound_t *)data;

    sound->value_sound++;
    sound->value_sound_s = sound->value_sound;
    sound->dec_sound->state = NONE;
    sound->no_sound->visible = 0;
    sound->sound->visible = 1;
    if (sound->value_sound == 100)
        button->state = BLOCK;
}

void dec_sound_p(void *data, button_t *button)
{
    sound_t *sound = (sound_t *)data;

    sound->value_sound--;
    sound->value_sound_s = sound->value_sound;
    sound->inc_sound->state = NONE;
    if (sound->value_sound == 0) {
        button->state = BLOCK;
        sound->no_sound->visible = 1;
        sound->sound->visible = 0;
    }
}
