/*
** EPITECH PROJECT, 2023
** graph.h
** File description:
** macro for CSFML
*/

#include "rpg.h"

void check_start_funtion(quest_t *quest, rpg_t *rpg)
{
    if (quest->start_f) {
        quest->start_f(quest, rpg);
    }
}

bool manage_dialogue(rpg_t *rpg,
    quest_giver_t *quest_g, quest_t *quest)
{
    static int spam = 0;

    if (rpg->key_state[sfKeyE] && spam == 0) {
        quest_g->act_dial++;
        sfText_setString(quest_g->dial, quest_g->dial_tab[quest_g->act_dial]);
        if (strcmp(quest_g->dial_tab[quest_g->act_dial], "") == 0) {
            quest_g->act_quest++;
            quest[quest_g->act_quest].state = BEGIN;
            quest_g->is_interact = false;
            check_start_funtion(&(quest[quest_g->act_quest]), rpg);
            return false;
        }
        spam++;
    }
    if (!rpg->key_state[sfKeyE])
        spam = 0;
    return true;
}

void manage_quest_giver(
    quest_t *quest_tab, quest_giver_t *quest_g, rpg_t *rpg)
{
    static bool is_dial = false;

    if (rpg->key_state[sfKeyE])
        is_dial = true;
    set_all_box(quest_g->npc->entity, rpg->window);
    quest_g->npc->in_chase = check_chase_heros(quest_g->npc, rpg->heros,
    wich_img(rpg));
    if (quest_g->npc->in_chase && quest_g->is_interact)
        rpg->heros->can_interact = true;
    if (quest_g->is_interact)
        sfRenderWindow_drawText(rpg->window, quest_g->signal, NULL);
    if (quest_g->npc->in_chase && is_dial && quest_g->is_interact) {
        is_dial = manage_dialogue(rpg, quest_g, quest_tab);
        sfRenderWindow_drawText(rpg->window, quest_g->dial, NULL);
    }
}
