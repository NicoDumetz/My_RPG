/*
** EPITECH PROJECT, 2023
** graph.h
** File description:
** macro for CSFML
*/

#include "rpg.h"

void destroy_heros(heros_t *heros)
{
    destroy_npc(heros->npc);
    sfTexture_destroy(heros->texture_base);
    free(heros);
}

void set_action_tab_heros(heros_t *heros)
{
    heros->npc->action[ATTACK_F] = (sfVector2i){6, 6};
    heros->npc->action[ATTACK_B] = (sfVector2i){6, 5};
    heros->npc->action[ATTACK_L] = (sfVector2i){6, -3};
    heros->npc->action[ATTACK_R] = (sfVector2i){6, 3};
    heros->npc->action[MOVE_R] = (sfVector2i){6, 1};
    heros->npc->action[MOVE_L] = (sfVector2i){6, -1};
    heros->npc->action[MOVE_F] = (sfVector2i){-1, 0};
    heros->npc->action[MOVE_B] = (sfVector2i){-1, 0};
    heros->npc->action[STAND] = (sfVector2i){6, 0};
}

void set_attbox_dim_heros(npc_t *npc)
{
    npc->attbox_dim[ATTACK_F] = (sfFloatRect){15, 15, 30, 70};
    npc->attbox_dim[ATTACK_B] = (sfFloatRect){20, 50, 25, 65};
    npc->attbox_dim[ATTACK_L] = (sfFloatRect){5, 30, 40, 55};
    npc->attbox_dim[ATTACK_R] = (sfFloatRect){35, 30, 40, 55};
}

heros_t *init_heros(char *asset)
{
    heros_t *heros = malloc(sizeof(heros_t));
    sfFloatRect hitbox = {30, 25, 55, 55};
    sfFloatRect colbox = {40, 60, 80, 90};

    heros->speed = 200.f;
    heros->texture_base = sfTexture_createFromFile(asset, NULL);
    heros->npc = init_npc(heros->texture_base);
    set_offset(heros->npc->entity, (sfVector2i){6, 8});
    set_action_tab_heros(heros);
    set_attbox_dim_heros(heros->npc);
    heros->npc->entity->colbox_dim = colbox;
    heros->npc->hitbox_dim = hitbox;
    return heros;
}
