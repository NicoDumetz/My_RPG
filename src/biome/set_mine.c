/*
** EPITECH PROJECT, 2023
** game
** File description:
** rpg.h
*/

#include "rpg.h"

biome_t *set_mine(sfTexture **text_tab)
{
    biome_t *mine = malloc(sizeof(biome_t));

    mine->back = add_background(
        text_tab[MINE_B_TEXT], text_tab[MINE_COLISION_TEXT]);
    mine->bot_data = init_bot_data(text_tab);
    mine->deco_data = NULL;
    return (mine);
}
