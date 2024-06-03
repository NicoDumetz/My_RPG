/*
** EPITECH PROJECT, 2023
** game
** File description:
** rpg.h
*/

#include "rpg.h"

biome_t *set_camp(sfTexture **text_tab)
{
    biome_t *camp = malloc(sizeof(biome_t));

    camp->back = add_background(
        text_tab[CAMP_SPRITE_TEXT], text_tab[CAMP_COLISION_TEXT]);
    camp->bot_data = init_bot_data(text_tab);
    camp->deco_data = NULL;
    return (camp);
}
