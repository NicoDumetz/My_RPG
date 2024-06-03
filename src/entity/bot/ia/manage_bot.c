/*
** EPITECH PROJECT, 2023
** graph.h
** File description:
** macro for CSFML
*/

#include "rpg.h"

void manage_bot_pv_bar(npc_t *npc, sfRenderWindow *window)
{
    sfVector2f sprite_center = {
        npc->entity->pos.x + npc->entity->rect_sprite.width / 2.0f,
        npc->entity->pos.y + npc->entity->rect_sprite.height / 5.0
    };
    sfVector2f rect_pos = {
        sprite_center.x - npc->pv_bar->size.x / 2.0f,
        sprite_center.y - npc->pv_bar->size.y
    };

    npc->pv_bar->act = npc->pv;
    update_bar(npc->pv_bar, rect_pos);
    sfRenderWindow_drawRectangleShape(window, npc->pv_bar->bar, NULL);
}

void manage_bot(entity_t *entity, heros_t *heros, rpg_t *rpg)
{
    npc_t *npc_act = (npc_t *)(entity->parent);
    npc_t *npc_to_check = NULL;

    check_dynamic_col(npc_act, heros->npc);
    if (npc_act->in_chase == false) {
        manage_random_moov(npc_act, rpg);
        npc_act->in_chase = check_chase_heros(npc_act, heros);
    } else
        manage_chase(npc_act, rpg);
    check_if_heros_attack_me(npc_act, heros);
    manage_bot_pv_bar(npc_act, rpg->window);
    for (entity_t *curr = entity; curr; curr = curr->next) {
        npc_to_check = (npc_t *)(curr->parent);
        if (npc_to_check && entity->type == NPC)
            check_dynamic_col(npc_act, npc_to_check);
    }
}
