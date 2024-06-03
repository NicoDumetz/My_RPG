/*
** EPITECH PROJECT, 2023
** game
** File description:
** rpg.h
*/

#include "rpg.h"

void set_bot_donjon(biome_t *biome, sfVector2f *pos_list)
{
    npc_t *new_bot = NULL;
    static int i = 0;

    for (int j = 0; pos_list[j].x != 0; j++) {
        if (biome->bot_type[i] < 0 || i == 6)
            i = 0;
        create_bot(biome->bot_type[i],
            biome->bot_data, pos_list[j], biome->text_tab);
        i++;
    }
}
