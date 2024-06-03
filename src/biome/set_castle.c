/*
** EPITECH PROJECT, 2023
** game
** File description:
** rpg.h
*/

#include "rpg.h"

biome_t *set_castle(sfTexture **text_tab)
{
    biome_t *castle = malloc(sizeof(biome_t));

    castle->back = add_background(
        text_tab[CASTLE_SPRITE_TEXT], text_tab[CASTLE_COLISION_TEXT]);
    castle->bot_data = init_bot_data(text_tab);
    castle->deco_data = NULL;
    return (castle);
}
