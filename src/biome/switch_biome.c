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

void set_view(rpg_t *rpg, sfSprite* sprite, sfSprite *limit)
{
    const sfView *view = sfRenderWindow_getView(rpg->window);
    sfFloatRect bounds = sfSprite_getGlobalBounds(limit);
    sfFloatRect bounds_sprite = sfSprite_getGlobalBounds(sprite);
    sfVector2f pos;
    sfVector2f check;
    sfVector2u size = sfRenderWindow_getSize(rpg->window);

    pos.x = bounds_sprite.left + bounds_sprite.width / 2;
    pos.y = bounds_sprite.top + bounds_sprite.height / 2;
    check = (sfVector2f){pos.x - (size.x / 2), pos.y - (size.y / 2)};
    pos.x = check.x < 0 ? size.x / 2 : pos.x;
    pos.y = check.y < 0 ? size.y / 2 : pos.y;
    if (check.x + size.x > bounds.width)
        pos.x = bounds.width - (size.x / 2);
    if (check.y + size.y > bounds.height)
        pos.y = bounds.height - (size.y / 2);
    sfView_setCenter((sfView *)view, pos);
    sfRenderWindow_setView(rpg->window, (sfView *)view);
}

void switch_biome(biome_t *from, portal_t *portal, rpg_t *rpg, heros_t *heros)
{
    clean_entity_list(from);
    from->last_pos = heros->npc->entity->pos;
    rpg->scene = portal->scene;
    heros->npc->entity->pos = rpg->biome[portal->scene]->last_pos;
    sfSprite_setPosition(heros->npc->entity->sprite,
    rpg->biome[portal->scene]->last_pos);
    set_view(rpg, heros->npc->entity->sprite, wich_back(rpg));
}
