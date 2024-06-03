/*
** EPITECH PROJECT, 2023
** game
** File description:
** rpg.h
*/

#include "rpg.h"

biome_t *set_camp(void)
{
    biome_t *camp = malloc(sizeof(biome_t));

    camp->back = add_background(CAMP_SPRITE, CAMP_COLISION);
    camp->bot_data = init_bot_data();
    camp->deco_data = NULL;
    return (camp);
}
