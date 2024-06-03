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
    for (int i = 0; biome->portal[i]; i++)
        if (is_rect_in_circle(heros->npc->hitbox, biome->portal[i]->zone) &&
            rpg->key_state[sfKeyE] && is_pressed == 0) {
            switch_biome(biome, biome->portal[i], rpg, heros);
            is_pressed = 1;
        }
}

void biome_loop(rpg_t *rpg, biome_t *biome)
{
    heros_t *heros = rpg->heros;
    static int test = 0;
    static int i = 0;

    if (rpg->ticks)
        i++;
    if (test == 0) {
        create_bot(GOBLINS_T, biome->bot_data,
        (sfVector2f){1000, 1000}, rpg->text_tab);
        test++;
    }
    srand(time(NULL));
    display_background(biome->back, rpg->window);
    sort_entity_in_view(biome, rpg->window, heros, rpg);
    entity_loop(biome->entity_in_view_head, rpg);
    bot_generator(biome, biome->bot_type);
    if (biome->portal)
        check_portal(biome, rpg, rpg->heros);
    return;
}
