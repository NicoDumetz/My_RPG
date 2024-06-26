/*
** EPITECH PROJECT, 2023
** graph.h
** File description:
** macro for CSFML
*/

#include "rpg.h"

void set_action_tab_goblins(npc_t *goblins)
{
    goblins->action[ATTACK_F] = (sfVector2i){6, 4};
    goblins->action[ATTACK_B] = (sfVector2i){6, 3};
    goblins->action[ATTACK_L] = (sfVector2i){6, -2};
    goblins->action[ATTACK_R] = (sfVector2i){6, 2};
    goblins->action[MOVE_R] = (sfVector2i){6, 1};
    goblins->action[MOVE_L] = (sfVector2i){6, -1};
    goblins->action[MOVE_F] = (sfVector2i){6, 1};
    goblins->action[MOVE_B] = (sfVector2i){6, 1};
    goblins->action[STAND] = (sfVector2i){7, 0};
}

void set_attbox_dim_goblins(npc_t *npc)
{
    npc->attbox_dim[ATTACK_F] = (sfFloatRect){20, 15, 40, 70};
    npc->attbox_dim[ATTACK_B] = (sfFloatRect){20, 50, 40, 65};
    npc->attbox_dim[ATTACK_L] = (sfFloatRect){10, 25, 40, 55};
    npc->attbox_dim[ATTACK_R] = (sfFloatRect){30, 25, 40, 55};
}

npc_t *set_goblins(sfTexture *texture)
{
    npc_t *goblins = init_npc(texture);
    sfFloatRect colbox = {37, 60, 73, 90};
    sfFloatRect hitbox = {30, 25, 65, 55};

    goblins->pv = 80;
    goblins->attack = 0;
    goblins->entity->parent = goblins;
    set_offset(goblins->entity, (sfVector2i){7, 5});
    set_action_tab_goblins(goblins);
    set_attbox_dim_goblins(goblins);
    goblins->entity->colbox_dim = colbox;
    goblins->xp = 50;
    goblins->hitbox_dim = hitbox;
    goblins->view = 500;
    goblins->stamina = 10;
    goblins->max_stamina = 10;
    goblins->damage = 60;
    goblins->type = MELEE;
    return (goblins);
}
