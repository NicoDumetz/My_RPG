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

void create_bot(npc_t **list, sfTexture *texture, bot_type_t bot_type)
{
    npc_t *(*bot_gen[6])(sfTexture *) = {
        set_goblins,
        set_goblins_d,
        set_goblins_b,
        set_knight,
        set_minions,
        set_archer
    };
    npc_t *new_bot = bot_gen[bot_type](texture);

    add_to_list_bot(new_bot, list);
}
