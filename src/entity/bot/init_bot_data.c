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
        sfTexture_destroy(bot_data->bot_texture[i]);
        free_bot_list(bot_data->bot_list[i]);
    }
    free(bot_data);
}

void set_texture_bot(bot_data_t *bot_data)
{
    bot_data->bot_texture[GOBLINS_T] = sfTexture_createFromFile(
        GOBLINS_T_SPRITE, NULL);
    bot_data->bot_texture[GOBLINS_B] = sfTexture_createFromFile(
        GOBLINS_B_SPRITE, NULL);
    bot_data->bot_texture[GOBLINS_D] = sfTexture_createFromFile(
        GOBLINS_D_SPRITE, NULL);
    bot_data->bot_texture[KINGHT] = sfTexture_createFromFile(
        KNIGHT_SPRITE, NULL);
    bot_data->bot_texture[ARCHER] = sfTexture_createFromFile(
        ARCHER_SPRITE, NULL);
    bot_data->bot_texture[MINIONS] = sfTexture_createFromFile(
        MINIONS_SPRITE, NULL);
}

bot_data_t *init_bot_data(void)
{
    bot_data_t *bot_data = malloc(sizeof(bot_data_t));

    for (int i = 0; i <= ARCHER; i++)
        bot_data->bot_list[i] = NULL;
    set_texture_bot(bot_data);
    return (bot_data);
}
