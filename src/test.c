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
    sfIntRect rect = {50, 40, 140, 130};

    display_background(rpg);
    sfSprite_setTextureRect(heros->npc->entity->sprite, rect);
    sfRenderWindow_drawSprite(rpg->window,
    rpg->heros->npc->entity->sprite, NULL);
    return;
}
