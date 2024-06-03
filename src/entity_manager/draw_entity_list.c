/*
** EPITECH PROJECT, 2023
** graph.h
** File description:
** macro for CSFML
*/

#include "rpg.h"

void manage_animation(entity_t *entity, bool ticks)
{
    npc_t *npc = (npc_t *)(entity->parent);

    if (npc == NULL)
        anim_entity(entity, entity->simple_action, ticks);
    if (npc != NULL) {
        entity->parent = (npc_t *)(entity->parent);
        if (npc->is_attack == true)
            anim_attack(npc, npc->action[npc->act_action], ticks);
        if (npc->is_attack == false) {
        anim_entity(entity, npc->action[npc->act_action], ticks);
        }
    }
}

void draw_entity_list(
    entity_t *entity_list, sfRenderWindow *window, bool ticks)
{
    for (entity_t *curr = entity_list; curr; curr = curr->next) {
        manage_animation(curr, ticks);
        sfRenderWindow_drawSprite(window, curr->sprite, NULL);
    }
}
