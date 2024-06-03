/*
** EPITECH PROJECT, 2023
** graph.h
** File description:
** macro for CSFML
*/

#include "rpg.h"

void skip_released(void *data, button_t *)
{
    rpg_t *rpg = (rpg_t *)(data);

    rpg->scene = PLAIN;
    sfSprite_setPosition(
        rpg->heros->npc->entity->sprite, rpg->biome[PLAIN]->last_pos);
    set_view(rpg, rpg->heros->npc->entity->sprite,
        rpg->biome[PLAIN]->back->sprite.sprite);
    clean_entity_list(rpg->tuto->biome);
}
