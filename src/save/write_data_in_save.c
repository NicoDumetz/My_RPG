/*
** EPITECH PROJECT, 2023
** create_sprite
** File description:
** create_sprite + texture
*/

#include "rpg.h"

static int is_champ(rpg_t *rpg, save_bot_t *save_bot, npc_t *curr, int j)
{
    if (curr != rpg->biome[CAMP]->boss &&
        curr != rpg->biome[CASTLE]->boss &&
        curr != rpg->biome[MINE]->boss) {
        save_bot->id_bot = j;
        save_bot->pv = curr->pv;
        save_bot->pos_x = curr->entity->pos.x;
        save_bot->pos_y = curr->entity->pos.y;
        return 1;
    }
    return 0;
}

static void write_bot_data(save_data_t *new_save, rpg_t *rpg, int i)
{
    int k = 0;

    for (int j = 0; j <= ARCHER; j++) {
        for (npc_t *curr = rpg->biome[i]->bot_data->bot_list[j];
            curr && k < 30; curr = curr->next) {
                k += is_champ(rpg, &(new_save->save_bot[i][k]), curr, j);
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
    j = 0;
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

void unappli_all_multi(rpg_t *rpg)
{
    back_obj_t *back = NULL;

    for (int i = 0; i < 4; i++) {
        back = (back_obj_t *)rpg->inventory.equipment[i]->child;
        if (back)
            unappli_multi_equip(rpg->heros, back);
    }
}

void appli_all_multi(rpg_t *rpg)
{
    back_obj_t *back = NULL;

    for (int i = 0; i < 4; i++) {
        back = (back_obj_t *)rpg->inventory.equipment[i]->child;
        if (back)
            appli_multi_equip(rpg->heros, back);
    }
}

void write_data_in_save(save_data_t *new_save, rpg_t *rpg)
{
    unappli_all_multi(rpg);
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
    appli_all_multi(rpg);
}
