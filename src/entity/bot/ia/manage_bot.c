/*
** EPITECH PROJECT, 2023
** graph.h
** File description:
** macro for CSFML
*/

#include "rpg.h"

void manage_bot(entity_t *entity, heros_t *heros)
{
    npc_t *npc_act = (npc_t *)(entity->parent);
    npc_t *npc_to_check = NULL;

    check_dynamic_col(npc_act, heros->npc);
    if (npc_act->in_chase == false)
        check_chase_heros(npc_act, heros);
    check_if_heros_attack_me(npc_act, heros);
    for (entity_t *curr = entity; curr; curr = curr->next) {
        npc_to_check = (npc_t *)(curr->parent);
        if (npc_to_check)
            check_dynamic_col(npc_act, npc_to_check);
    }
}
