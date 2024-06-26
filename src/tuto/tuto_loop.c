/*
** EPITECH PROJECT, 2023
** game
** File description:
** rpg.h
*/

#include "rpg.h"

static void tuto_next(rpg_t *rpg)
{
    manage_particules(rpg);
    if (rpg->heros->npc->pv <= 0 && rpg->end->active == OFF)
        init_switch(rpg);
    if (rpg->end->active == TUTO_FADE)
        manage_switch_fade(rpg->end, rpg);
}

void tuto_loop(rpg_t *rpg)
{
    heros_t *heros = rpg->heros;
    biome_t *biome = rpg->tuto->biome;

    srand(time(NULL));
    display_background(biome->back, rpg->window);
    sort_entity_in_view(biome, rpg->window, heros, rpg);
    entity_loop(biome->entity_in_view_head, rpg);
    manage_skip_button(rpg->tuto->skip_button, rpg);
    if (biome->quest_giver)
        manage_quest_giver(rpg->tuto->quest_tab,
        biome->quest_giver, rpg);
    manage_quest_tuto(rpg->tuto, rpg);
    quest_displayer(rpg->tuto->quest_tab, rpg->window);
    tuto_next(rpg);
    return;
}
