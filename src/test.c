/*
** EPITECH PROJECT, 2023
** game
** File description:
** rpg.h
*/

#include "rpg.h"

void test(rpg_t *rpg)
{
    heros_t *heros = rpg->heros;

    anim_entity(rpg->bot_data->bot_list[GOBLINS_B]->entity, rpg->bot_data->bot_list[GOBLINS_B]->action[MOVE_F], rpg->time);
    sfSprite_setPosition(rpg->bot_data->bot_list[GOBLINS_B]->entity->sprite, (sfVector2f){500, 500});
    sfRenderWindow_drawSprite(
        rpg->window, rpg->bot_data->bot_list[GOBLINS_B]->entity->sprite, NULL);
}
