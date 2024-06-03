/*
** EPITECH PROJECT, 2023
** create_sprite
** File description:
** create_sprite + texture
*/

#include "rpg.h"

void write_bot_data(save_data_t *new_save, rpg_t *rpg, int i)
{
    int k = 0;

    for (int j = 0; j <= ARCHER; j++) {
        for (npc_t *curr = rpg->biome[i]->bot_data->bot_list[j];
            curr && k < 30; curr = curr->next) {
                new_save->save_bot[i][k].id_bot = j;
                new_save->save_bot[i][k].pv = curr->pv;
                new_save->save_bot[i][k].pos_x = curr->entity->pos.x;
                new_save->save_bot[i][k].pos_y = curr->entity->pos.y;
                k++;
            }
    }
}

void write_inv_data(save_data_t *new_save, rpg_t *rpg)
{
    back_obj_t *back_obj = NULL;
    int j = 0;

    for (int i = 0; i < 20; i++) {
        if (rpg->inventory.slot[i]->child == NULL)
            continue;
        back_obj = (back_obj_t *)rpg->inventory.slot[i]->child;
        new_save->object_id_inv[j] = back_obj->id;
        j++;
    }
    for (int i = 0; i < 4; i++) {
        if (rpg->inventory.equipment[i]->child == NULL)
            continue;
        back_obj = (back_obj_t *)rpg->inventory.equipment[i]->child;
        new_save->object_id_equip[j] = back_obj->id;
        j++;
    }
}

void write_quest_data(save_data_t *new_save, rpg_t *rpg)
{
    new_save->act_quest = rpg->biome[PLAIN]->quest_giver->act_quest;
    new_save->dial_quest = rpg->biome[PLAIN]->quest_giver->act_dial;
    new_save->is_interact = rpg->biome[PLAIN]->quest_giver->is_interact;
    for (int i = 0; i <= KILL_CASTLE; i++) {
        new_save->quest_state[i] =
        rpg->quest_tab[i].state;
    }
    new_save->act_skill = rpg->heros->skill->act_skill;
    write_inv_data(new_save, rpg);
}

void write_data_in_save(save_data_t *new_save, rpg_t *rpg)
{
    new_save->heros_pv = rpg->heros->npc->pv;
    new_save->heros_stami = rpg->heros->stamina;
    new_save->id_biome = rpg->scene;
    new_save->heros_xp = rpg->heros->npc->xp;
    for (int i = 0; i <= MINE; i++)
        write_bot_data(new_save, rpg, i);
    new_save->level_heros = rpg->heros->level_act;
    new_save->x_heros = rpg->heros->npc->entity->pos.x;
    new_save->y_heros = rpg->heros->npc->entity->pos.y;
    for (int i = 0; i < 3; i++)
        new_save->skill_level[i] = rpg->heros->skill->skill_level[i];
    new_save->skill_point = rpg->heros->skill_point;
    write_quest_data(new_save, rpg);
    new_save->end_save = 42;
}
