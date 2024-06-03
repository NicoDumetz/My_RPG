/*
** EPITECH PROJECT, 2023
** graph.h
** File description:
** macro for CSFML
*/

#include "rpg.h"

effect_t **set_effect_bot(sfTexture **text_tab, sfSprite *bot_sprite)
{
    effect_t **effect_tab = malloc(sizeof(effect_t *) * 3);

    effect_tab[BLOOD_BOT] = create_effect(
        text_tab[BLOOD_TEXT], true, (sfVector2i){8, 1}, bot_sprite);
    effect_tab[EXPLO_BOT] = create_effect(
        text_tab[EXPLO_TEXT], true, (sfVector2i){9, 1}, bot_sprite);
    effect_tab[2] = NULL;
    return (effect_tab);
}
