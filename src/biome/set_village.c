/*
** EPITECH PROJECT, 2023
** game
** File description:
** rpg.h
*/

#include "rpg.h"

biome_t *set_village(void)
{
    biome_t *village = malloc(sizeof(biome_t));

    village->back = add_background(VILLAGE_SPRITE, VILLAGE_COLISION);
    village->bot_data = init_bot_data();
    village->deco_data = NULL;
    return (village);
}
