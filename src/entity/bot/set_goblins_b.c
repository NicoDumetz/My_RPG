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
    sfFloatRect colbox = {30, 65, 60, 90};
    sfFloatRect hitbox = {30, 25, 60, 50};

    goblins_b->pv = 50;
    goblins_b->attack = 0;
    goblins_b->entity->parent = goblins_b;
    set_offset(goblins_b->entity, (sfVector2i){6, 6});
    set_action_tab_goblins_b(goblins_b);
    goblins_b->entity->colbox_dim = colbox;
    goblins_b->xp = 2000;
    goblins_b->hitbox_dim = hitbox;
    goblins_b->view = 500;
    goblins_b->stamina = 50;
    goblins_b->max_stamina = 50;
    goblins_b->damage = 50;
    goblins_b->type = EXPLOSIVE;
    return (goblins_b);
}
