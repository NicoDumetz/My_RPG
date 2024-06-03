/*
** EPITECH PROJECT, 2023
** graph.h
** File description:
** macro for CSFML
*/

#include "rpg.h"

void set_action_tab_goblins_b(npc_t *goblins_b)
{
    goblins_b->action[ATTACK_F] = (sfVector2i){3, 5};
    goblins_b->action[ATTACK_B] = (sfVector2i){3, 5};
    goblins_b->action[ATTACK_L] = (sfVector2i){3, 5};
    goblins_b->action[ATTACK_R] = (sfVector2i){3, 5};
    goblins_b->action[MOVE_R] = (sfVector2i){6, 1};
    goblins_b->action[MOVE_L] = (sfVector2i){6, -1};
    goblins_b->action[MOVE_F] = (sfVector2i){6, 1};
    goblins_b->action[MOVE_B] = (sfVector2i){6, 1};
    goblins_b->action[STAND] = (sfVector2i){1, 0};
}

npc_t *set_goblins_b(sfTexture *texture)
{
    npc_t *goblins_b = init_npc(texture);
    sfFloatRect hitbox = {30, 25, 60, 50};

    goblins_b->pv = 0;
    goblins_b->attack = 0;
    set_offset(goblins_b->entity, (sfVector2i){6, 6});
    set_action_tab_goblins_b(goblins_b);
    goblins_b->entity->hitbox_dim = hitbox;
    return (goblins_b);
}
