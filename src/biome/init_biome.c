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
    if (biome->deco_data)
        free_deco_data(biome->deco_data);
    free(biome);
}

biome_t *create_biome(int biome_type, sfTexture **text_tab)
{
    biome_t *biome = NULL;
    biome_t *(*biome_gen[5])(sfTexture **text_tab) = {
        set_plain,
        set_castle,
        set_camp,
        set_village,
        set_mine
    };

    biome = biome_gen[biome_type](text_tab);
    biome->nbr_bot = 0;
    biome->entity_in_view_head = NULL;
    biome->entity_in_view_tail = NULL;
    return (biome);
}
