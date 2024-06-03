/*
** EPITECH PROJECT, 2023
** graph.h
** File description:
** macro for CSFML
*/

#include "rpg.h"

void free_bot_list(npc_t *npc)
{
    npc_t *next = NULL;
    npc_t *current = npc;

    while (current) {
        next = current->next;
        destroy_npc(current);
        current = next;
    }
}

void free_bot_data(bot_data_t *bot_data)
{
    for (int i = 0; i <= ARCHER; i++) {
        free_bot_list(bot_data->bot_list[i]);
    }
    free(bot_data);
}

void set_texture_bot(bot_data_t *bot_data, sfTexture **text_tab)
{
    bot_data->bot_texture[GOBLINS_T] = text_tab[GOBLINS_T_TEXT];
    bot_data->bot_texture[GOBLINS_B] = text_tab[GOBLINS_B_TEXT];
    bot_data->bot_texture[GOBLINS_D] = text_tab[GOBLINS_D_TEXT];
    bot_data->bot_texture[KNIGHT] = text_tab[KNIGHT_TEXT];
    bot_data->bot_texture[ARCHER] = text_tab[ARCHER_TEXT];
    bot_data->bot_texture[MINIONS] = text_tab[MINIONS_TEXT];
}

bot_data_t *init_bot_data(sfTexture **text_tab)
{
    bot_data_t *bot_data = malloc(sizeof(bot_data_t));

    for (int i = 0; i <= ARCHER; i++)
        bot_data->bot_list[i] = NULL;
    set_texture_bot(bot_data, text_tab);
    return (bot_data);
}
