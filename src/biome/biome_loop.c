/*
** EPITECH PROJECT, 2023
** game
** File description:
** rpg.h
*/

#include "rpg.h"

/**Test creer un bot en 1000, 1000 pour faire des test dessus
 * Ca evite d'attendre qu'un bot spawn*/

void check_portal(biome_t *biome, rpg_t *rpg, heros_t *heros)
{
    static int is_pressed = 0;

    if (!rpg->key_state[sfKeyE])
        is_pressed = 0;
    for (int i = 0; biome->portal[i]; i++) {
        if (is_rect_in_circle(heros->npc->hitbox, biome->portal[i]->zone) &&
            biome->portal[i]->is_open == true)
            heros->can_interact = true;
        if (is_rect_in_circle(heros->npc->hitbox, biome->portal[i]->zone) &&
            rpg->key_state[sfKeyE] && is_pressed == 0 &&
            biome->portal[i]->is_open) {
            switch_biome(biome, biome->portal[i], rpg, heros);
            is_pressed = 1;
        }
    }
}

void manage_test_quest(rpg_t *rpg)
{
    static int test3 = 0;

    if (test3 == 0 && rpg->key_state[sfKeyN]) {
        next_quest(rpg->biome[PLAIN]->quest_giver, rpg->quest_tab);
        test3 = 1;
        return;
    }
    if (!rpg->key_state[sfKeyN])
        test3 = 0;
}

bool manage_test(rpg_t *rpg, biome_t *biome)
{
    static int test2 = 0;

    if (test2 == 0 && rpg->key_state[sfKeyW]) {
        create_save(rpg);
        test2 = 1;
        return true;
    }
    if (!rpg->key_state[sfKeyW])
        test2 = 0;
    if (rpg->key_state[sfKeyC]) {
        set_view(rpg, rpg->save_scene->back, rpg->save_scene->back);
        rpg->save_scene->from = rpg->scene;
        clean_entity_list(biome);
        rpg->scene = SAVE;
        return false;
    }
    return true;
}

void biome_loop(rpg_t *rpg, biome_t *biome)
{
    heros_t *heros = rpg->heros;

    if (!manage_test(rpg, biome))
        return;
    check_open_portal(rpg);
    manage_test_quest(rpg);
    srand(time(NULL));
    display_background(biome->back, rpg->window);
    sort_entity_in_view(biome, rpg->window, heros, rpg);
    entity_loop(biome->entity_in_view_head, rpg);
    check_end_quest(rpg);
    bot_generator(biome, biome->bot_type);
    if (biome->portal)
        check_portal(biome, rpg, rpg->heros);
    if (biome->quest_giver)
        manage_quest_giver(rpg->quest_tab,
        biome->quest_giver, rpg);
    return;
}
