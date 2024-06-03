/*
** EPITECH PROJECT, 2023
** game
** File description:
** rpg.h
*/

#include "rpg.h"

void destroy_biome(biome_t *biome)
{
    free_bot_data(biome->bot_data);
    if (biome->back)
        destroy_background(biome->back);
    free(biome);
}

biome_t *create_biome(int biome_type)
{
    biome_t *(*biome_gen[5])() = {
        set_plain,
        set_castle,
        set_camp,
        set_village,
        set_mine
    };

    return biome_gen[biome_type]();
}
