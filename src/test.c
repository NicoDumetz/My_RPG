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

    anim_entity(heros->npc->entity, heros->npc->action[ATTACK_R], rpg->time);
    sfSprite_setPosition(heros->npc->entity->sprite, (sfVector2f){500, 500});
    sfRenderWindow_drawSprite(
        rpg->window, rpg->heros->npc->entity->sprite, NULL);
}
