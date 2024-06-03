/*
** EPITECH PROJECT, 2023
** game
** File description:
** rpg.h
*/

#include "rpg.h"

bool manage_test_tuto(rpg_t *rpg, biome_t *)
{
    if (rpg->key_state[sfKeyC]) {
        set_view(rpg, rpg->save_scene->back, rpg->save_scene->back);
        rpg->save_scene->from = rpg->scene;
        clean_entity_list(rpg->tuto->biome);
        rpg->scene = SAVE;
        return false;
    }
    return true;
}

void tuto_loop(rpg_t *rpg)
{
    heros_t *heros = rpg->heros;
    biome_t *biome = rpg->tuto->biome;

    if (!manage_test_tuto(rpg, NULL))
        return;
    display_background(biome->back, rpg->window);
    sort_entity_in_view(biome, rpg->window, heros, rpg);
    entity_loop(biome->entity_in_view_head, rpg);
    manage_skip_button(rpg->tuto->skip_button, rpg);
    if (biome->quest_giver)
        manage_quest_giver(rpg->tuto->quest_tab,
        biome->quest_giver, rpg);
    manage_quest_tuto(rpg->tuto, rpg);
    quest_displayer(rpg->tuto->quest_tab, rpg->window);
    return;
}
