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

void entity_loop(
    entity_t *entity_list, rpg_t *rpg)
{
    npc_t *npc = NULL;

    for (entity_t *curr = entity_list; curr; curr = curr->next) {
        npc = curr->parent;
        if (npc && npc->special == NON_SPEC)
            manage_bot(curr, rpg->heros);
        manage_animation(curr, rpg->ticks);
        sfRenderWindow_drawSprite(rpg->window, curr->sprite, NULL);
    }
    manage_heros(rpg->heros, rpg);
}
