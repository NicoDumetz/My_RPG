/*
** EPITECH PROJECT, 2023
** graph.h
** File description:
** macro for CSFML
*/

#include "rpg.h"

void add_to_list_bot(npc_t *new_bot, npc_t **list)
{
    if (*list != NULL) {
        new_bot->next = *list;
        (*list)->prev = new_bot;
    }
    *list = new_bot;
}

void create_bot(bot_type_t bot_type, bot_data_t *bot_data)
{
    npc_t *(*bot_gen[6])(sfTexture *) = {
        set_goblins,
        set_goblins_d,
        set_goblins_b,
        set_knight,
        set_minions,
        set_archer
    };
    npc_t *new_bot = bot_gen[bot_type](bot_data->bot_texture[bot_type]);

    add_to_list_bot(new_bot, &(bot_data->bot_list[bot_type]));
}
