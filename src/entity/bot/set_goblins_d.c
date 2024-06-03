/*
** EPITECH PROJECT, 2023
** graph.h
** File description:
** macro for CSFML
*/

#include "rpg.h"

void set_action_tab_goblins_d(npc_t *goblins_d)
{
    goblins_d->action[ATTACK_F] = (sfVector2i){7, 2};
    goblins_d->action[ATTACK_B] = (sfVector2i){7, 2};
    goblins_d->action[ATTACK_L] = (sfVector2i){7, -2};
    goblins_d->action[ATTACK_R] = (sfVector2i){7, 2};
    goblins_d->action[MOVE_R] = (sfVector2i){6, 1};
    goblins_d->action[MOVE_L] = (sfVector2i){6, -1};
    goblins_d->action[MOVE_F] = (sfVector2i){6, 1};
    goblins_d->action[MOVE_B] = (sfVector2i){6, 1};
    goblins_d->action[STAND] = (sfVector2i){6, 0};
}

void set_attbox_dim_goblins_d(npc_t *npc)
{
    npc->attbox_dim[ATTACK_F] = (sfFloatRect){100, 100, 100, 100};
    npc->attbox_dim[ATTACK_B] = (sfFloatRect){100, 100, 100, 100};
    npc->attbox_dim[ATTACK_L] = (sfFloatRect){0, 0, 50, 0};
    npc->attbox_dim[ATTACK_R] = (sfFloatRect){50, 0, 50, 0};
}

npc_t *set_goblins_d(sfTexture *texture)
{
    npc_t *goblins_d = init_npc(texture);
    sfFloatRect hitbox = {30, 35, 60, 65};
    sfFloatRect colbox = {35, 60, 72, 90};

    goblins_d->pv = 50;
    goblins_d->attack = 0;
    goblins_d->entity->parent = goblins_d;
    set_offset(goblins_d->entity, (sfVector2i){7, 3});
    set_action_tab_goblins_d(goblins_d);
    set_attbox_dim_goblins_d(goblins_d);
    goblins_d->entity->colbox_dim = colbox;
    goblins_d->xp = 2000;
    goblins_d->hitbox_dim = hitbox;
    goblins_d->view = 500;
    goblins_d->stamina = 50;
    goblins_d->max_stamina = 50;
    goblins_d->damage = 50;
    goblins_d->type = DYNA;
    return (goblins_d);
}
