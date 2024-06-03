/*
** EPITECH PROJECT, 2023
** game
** File description:
** rpg.h
*/

#include "rpg.h"

biome_t *set_castle(void)
{
    biome_t *castle = malloc(sizeof(biome_t));

    castle->back = add_background(CASTLE_SPRITE, CASTLE_COLISION);
    castle->bot_data = init_bot_data();
    castle->deco_data = NULL;
    return (castle);
}
