/*
** EPITECH PROJECT, 2023
** game
** File description:
** rpg.h
*/

#include "rpg.h"

biome_t *set_village(sfTexture **text_tab, sfFont **)
{
    biome_t *village = malloc(sizeof(biome_t));

    village->back = add_background(
        text_tab[VILLAGE_SPRITE_TEXT], text_tab[VILLAGE_COLISION_TEXT]);
    village->bot_data = init_bot_data(text_tab);
    village->quest_giver = NULL;
    village->deco_data = NULL;
    village->boss = NULL;
    village->portal = NULL;
    return (village);
}
