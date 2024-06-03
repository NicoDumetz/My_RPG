/*
** EPITECH PROJECT, 2023
** create_sprite
** File description:
** create_sprite + texture
*/

#include "rpg.h"

void set_finished(quest_t *quest)
{
    sfColor color = {120, 120, 120, 120};

    sfText_setColor(quest->display, color);
    sfRectangleShape_setFillColor(quest->box, sfGreen);
}

void set_not_finished(quest_t *quest)
{
    sfText_setColor(quest->display, sfWhite);
    sfRectangleShape_setFillColor(quest->box, sfTransparent);
}

void check_boss_state(rpg_t *rpg, quest_t *quest_tab)
{
    if (quest_tab[KILL_CAMP].state != FINISH)
        rpg->biome[CAMP]->boss =
            set_camp_boss(rpg->text_tab, rpg->biome[CAMP]);
    if (quest_tab[KILL_MINE].state != FINISH)
        rpg->biome[MINE]->boss =
            set_mine_boss(rpg->text_tab, rpg->biome[MINE]);
    if (quest_tab[KILL_CASTLE].state != FINISH)
        rpg->biome[CASTLE]->boss =
            set_castle_boss(rpg->text_tab, rpg->biome[CASTLE]);
}

void appli_save_quest(rpg_t *rpg, save_data_t *save)
{
    quest_giver_t *quest_g = rpg->biome[PLAIN]->quest_giver;

    for (int i = 0; i <= KILL_CASTLE; i++) {
        if (save->quest_state[i] == FINISH)
            set_finished(&(rpg->quest_tab[i]));
        else
            set_not_finished(&(rpg->quest_tab[i]));
        rpg->quest_tab[i].state = save->quest_state[i];
    }
    quest_g->act_dial = save->dial_quest;
    quest_g->act_quest = save->act_quest;
    quest_g->is_interact = save->is_interact;
    check_boss_state(rpg, rpg->quest_tab);
    sfText_setString(quest_g->dial, quest_g->dial_tab[quest_g->act_dial]);
}
