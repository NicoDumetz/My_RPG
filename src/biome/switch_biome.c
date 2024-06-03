/*
** EPITECH PROJECT, 2023
** game
** File description:
** rpg.h
*/

#include "rpg.h"

void clean_entity_list(biome_t *biome)
{
    entity_t *curr = biome->entity_in_view_head;
    entity_t *next = NULL;

    while (curr) {
        next = curr->next;
        curr->prev = NULL;
        curr->next = NULL;
        curr = next;
    }
    biome->entity_in_view_head = NULL;
        biome->entity_in_view_tail = NULL;
}

void switch_biome(biome_t *from, portal_t *portal, rpg_t *rpg, heros_t *heros)
{
    const sfView *view = sfRenderWindow_getView(rpg->window);

    clean_entity_list(from);
    from->last_pos = heros->npc->entity->pos;
    rpg->scene = portal->scene;
    heros->npc->entity->pos = rpg->biome[portal->scene]->last_pos;
    sfSprite_setPosition(heros->npc->entity->sprite,
        rpg->biome[portal->scene]->last_pos);
    sfView_setCenter((sfView *)view, rpg->biome[portal->scene]->last_pos);
    sfRenderWindow_setView(rpg->window, (sfView *)view);
}
