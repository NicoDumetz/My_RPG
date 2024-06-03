/*
** EPITECH PROJECT, 2023
** game
** File description:
** rpg.h
*/

#include "rpg.h"

biome_t *set_plain(void)
{
    biome_t *plain = malloc(sizeof(biome_t));

    plain->back = add_background(PLAINE_SPRITE, PLAINE_COLISION);
    plain->bot_data = init_bot_data();
    return (plain);
}
