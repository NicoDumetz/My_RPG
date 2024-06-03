/*
** EPITECH PROJECT, 2023
** graph.h
** File description:
** macro for CSFML
*/

#include "rpg.h"

void set_action_tab_knight(npc_t *knight)
{
    knight->action[ATTACK_F] = (sfVector2i){6, 6};
    knight->action[ATTACK_B] = (sfVector2i){6, 5};
    knight->action[ATTACK_L] = (sfVector2i){6, -3};
    knight->action[ATTACK_R] = (sfVector2i){6, 3};
    knight->action[MOVE_R] = (sfVector2i){6, 1};
    knight->action[MOVE_L] = (sfVector2i){6, -1};
    knight->action[MOVE_F] = (sfVector2i){-1, 0};
    knight->action[MOVE_B] = (sfVector2i){-1, 0};
    knight->action[STAND] = (sfVector2i){6, 0};
}

void set_attbox_dim_knight(npc_t *npc)
{
    npc->attbox_dim[ATTACK_F] = (sfFloatRect){15, 15, 30, 70};
    npc->attbox_dim[ATTACK_B] = (sfFloatRect){20, 50, 25, 65};
    npc->attbox_dim[ATTACK_L] = (sfFloatRect){5, 30, 40, 55};
    npc->attbox_dim[ATTACK_R] = (sfFloatRect){35, 30, 40, 55};
}

npc_t *set_knight(sfTexture *texture)
{
    npc_t *knight = init_npc(texture);
    sfFloatRect hitbox = {30, 25, 55, 55};
    sfFloatRect colbox = {40, 60, 80, 90};

    knight->pv = 50;
    knight->attack = 0;
    knight->entity->parent = knight;
    set_offset(knight->entity, (sfVector2i){6, 8});
    set_action_tab_knight(knight);
    set_attbox_dim_knight(knight);
    knight->xp = 2000;
    knight->hitbox_dim = hitbox;
    knight->entity->colbox_dim = colbox;
    knight->view = 500;
    knight->stamina = 20;
    knight->max_stamina = 20;
    knight->damage = 40;
    knight->type = MELEE;
    return (knight);
}
