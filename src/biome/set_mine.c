/*
** EPITECH PROJECT, 2023
** game
** File description:
** rpg.h
*/

#include "rpg.h"

biome_t *set_mine(void)
{
    biome_t *mine = malloc(sizeof(biome_t));

    mine->back = add_background(MINE_SPRITE, MINE_COLISION);
    mine->bot_data = init_bot_data();
    mine->deco_data = NULL;
    return (mine);
}
