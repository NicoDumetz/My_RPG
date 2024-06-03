/*
** EPITECH PROJECT, 2024
** B-MUL-200-LIL-2-1-myrpg-matisse.dufour
** File description:
** param_sound.c
*/

#include "../../../include/rpg.h"

void update_param_button_sound(rpg_t *rpg, sound_t *sound)
{
    update_button(sound->sound, &(rpg->mouse_data), sound);
    update_button(sound->no_sound, &(rpg->mouse_data), sound);
    update_button(sound->inc_sound, &(rpg->mouse_data), sound);
    update_button(sound->dec_sound, &(rpg->mouse_data), sound);
    update_sound_text(sound);
}

void display_param_button_sound(rpg_t *rpg, sound_t *sound)
{
    if (sound->sound->visible == 1)
        sfRenderWindow_drawSprite(rpg->window, sound->sound->sprite, NULL);
    if (sound->no_sound->visible == 1)
        sfRenderWindow_drawSprite(rpg->window, sound->no_sound->sprite, NULL);
    sfRenderWindow_drawSprite(rpg->window, sound->inc_sound->sprite, NULL);
    sfRenderWindow_drawSprite(rpg->window, sound->dec_sound->sprite, NULL);
    sfRenderWindow_drawText(rpg->window, sound->sound_text, NULL);
}
