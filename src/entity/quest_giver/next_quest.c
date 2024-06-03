/*
** EPITECH PROJECT, 2023
** graph.h
** File description:
** macro for CSFML
*/

#include "rpg.h"

void next_quest(quest_giver_t *quest_g, quest_t *quest_tab)
{
    int act_q = quest_g->act_quest;
    sfColor color = {120, 120, 120, 120};

    if (act_q < 0)
        return;
    quest_tab[act_q].state = FINISH;
    sfText_setColor(quest_tab[act_q].display, color);
    sfRectangleShape_setFillColor(quest_tab[act_q].box, sfGreen);
    quest_g->is_interact = true;
}
