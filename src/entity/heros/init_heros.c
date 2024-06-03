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
    heros->npc->action[ATTACK_F] = (sfVector2i){6, 4};
    heros->npc->action[ATTACK_B] = (sfVector2i){6, 7};
    heros->npc->action[ATTACK_L] = (sfVector2i){6, -1};
    heros->npc->action[ATTACK_R] = (sfVector2i){6, 2};
    heros->npc->action[MOVE_R] = (sfVector2i){6, 1};
    heros->npc->action[MOVE_L] = (sfVector2i){6, -1};
    heros->npc->action[MOVE_F] = (sfVector2i){6, 1};
    heros->npc->action[MOVE_B] = (sfVector2i){6, 1};
    heros->npc->action[STAND] = (sfVector2i){6, 0};
}

heros_t *init_heros(char *asset)
{
    heros_t *heros = malloc(sizeof(heros_t));

    heros->texture_base = sfTexture_createFromFile(asset, NULL);
    heros->npc = init_npc(heros->texture_base);
    set_offset(heros->npc->entity, (sfVector2i){6, 8});
    set_action_tab_heros(heros);
    return heros;
}
