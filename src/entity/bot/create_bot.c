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

npc_t *create_bot(
    bot_type_t bot_type, bot_data_t *bot_data,
    sfVector2f pos, sfTexture **text_tab)
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

    init_npc_projectiles(new_bot, text_tab);
    new_bot->entity->effect_tab = set_effect_bot(
        text_tab, new_bot->entity->sprite);
    new_bot->entity->pos = pos;
    new_bot->pv_bar =
        create_info_bar(sfRed, (sfVector2f){100, 7}, new_bot->pv, NULL);
    new_bot->pv_bar->act = new_bot->pv;
    sfSprite_setPosition(new_bot->entity->sprite, pos);
    add_to_list_bot(new_bot, &(bot_data->bot_list[bot_type]));
    return (new_bot);
}
