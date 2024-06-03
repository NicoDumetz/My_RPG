/*
** EPITECH PROJECT, 2023
** graph.h
** File description:
** macro for CSFML
*/

#include "rpg.h"

void destroy_npc(npc_t *npc)
{
    destroy_entity(npc->entity);
    sfRectangleShape_destroy(npc->hitbox);
    for (int i = 0; i <= ATTACK_R; i++)
        sfRectangleShape_destroy(npc->attbox[i]);
    free(npc);
}

sfRectangleShape *init_hitbox_rect(void)
{
    sfRectangleShape *hitbox = sfRectangleShape_create();

    sfRectangleShape_setOutlineColor(hitbox, sfRed);
    sfRectangleShape_setFillColor(hitbox, sfTransparent);
    sfRectangleShape_setOutlineThickness(hitbox, 2);
    return hitbox;
}

sfRectangleShape *init_attbox_rect(void)
{
    sfRectangleShape *attbox = sfRectangleShape_create();

    sfRectangleShape_setOutlineColor(attbox, sfBlue);
    sfRectangleShape_setFillColor(attbox, sfTransparent);
    sfRectangleShape_setOutlineThickness(attbox, 2);
    return attbox;
}

void init_npc_next(npc_t *npc)
{
    for (int i = ATTACK_F; i <= STAND; i++)
        npc->action[i] = (sfVector2i){0, 0};
    for (int i = 0; i < 4; i++)
        npc->allowed_dir[i] = true;
}

npc_t *init_npc(sfTexture *asset)
{
    npc_t *npc = malloc(sizeof(npc_t));

    npc->attack = 0;
    npc->pv = 0;
    npc->entity = init_entity(asset);
    npc->act_action = STAND;
    npc->is_attack = false;
    npc->next = NULL;
    npc->prev = NULL;
    npc->cur_attack = false;
    npc->hitbox = init_hitbox_rect();
    npc->hitbox_dim = (sfFloatRect){0, 0, 0, 0};
    npc->special = NON_SPEC;
    npc->is_alive = true;
    for (int i = 0; i <= ATTACK_R; i++) {
        npc->attbox[i] = init_attbox_rect();
        npc->attbox_dim[i] = (sfFloatRect){0, 0, 0, 0};
    }
    init_npc_next(npc);
    return npc;
}
