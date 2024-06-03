/*
** EPITECH PROJECT, 2023
** create_sprite
** File description:
** create_sprite + texture
*/

#include "rpg.h"

void write_data_in_save(save_data_t *new_save, rpg_t *rpg)
{
    int j = 0;

    new_save->heros_pv = rpg->heros->npc->pv;
    new_save->heros_stami = rpg->heros->stamina;
    new_save->id_biome = rpg->scene;
    new_save->heros_xp = rpg->heros->npc->xp;
    for (back_obj_t *curr = rpg->heros->inventory; curr; curr = curr->next) {
        new_save->object_id_inv[j] = curr->id;
        j++;
    }
    new_save->level_heros = rpg->heros->level_act;
    new_save->x_heros = rpg->heros->npc->entity->pos.x;
    new_save->y_heros = rpg->heros->npc->entity->pos.y;
    new_save->end_save = 42;
}
