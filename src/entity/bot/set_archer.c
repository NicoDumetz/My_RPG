/*
** EPITECH PROJECT, 2023
** graph.h
** File description:
** macro for CSFML
*/

#include "rpg.h"

void set_action_tab_archer(npc_t *archer)
{
    archer->action[ATTACK_F] = (sfVector2i){8, 2};
    archer->action[ATTACK_B] = (sfVector2i){8, 6};
    archer->action[ATTACK_L] = (sfVector2i){8, -4};
    archer->action[ATTACK_R] = (sfVector2i){8, 4};
    archer->action[MOVE_R] = (sfVector2i){6, 1};
    archer->action[MOVE_L] = (sfVector2i){6, -1};
    archer->action[MOVE_F] = (sfVector2i){6, 1};
    archer->action[MOVE_B] = (sfVector2i){6, 1};
    archer->action[STAND] = (sfVector2i){6, 0};
}

void set_attbox_dim_archer(npc_t *npc)
{
    npc->attbox_dim[ATTACK_F] = (sfFloatRect){100, 100, 100, 100};
    npc->attbox_dim[ATTACK_B] = (sfFloatRect){100, 100, 100, 100};
    npc->attbox_dim[ATTACK_L] = (sfFloatRect){0, 0, 50, 0};
    npc->attbox_dim[ATTACK_R] = (sfFloatRect){50, 0, 50, 0};
}

npc_t *set_archer(sfTexture *texture)
{
    npc_t *archer = init_npc(texture);
    sfFloatRect colbox = {40, 60, 80, 90};
    sfFloatRect hitbox = {30, 30, 60, 60};

    archer->pv = 50;
    archer->attack = 0;
    archer->entity->parent = archer;
    set_offset(archer->entity, (sfVector2i){8, 7});
    set_action_tab_archer(archer);
    set_attbox_dim_archer(archer);
    archer->entity->colbox_dim = colbox;
    archer->xp = 30;
    archer->hitbox_dim = hitbox;
    archer->view = 500;
    return (archer);
}
