/*
** EPITECH PROJECT, 2023
** game
** File description:
** rpg.h
*/

#include "rpg.h"

/**Test creer un bot en 1000, 1000 pour faire des test dessus
 * Ca evite d'attendre qu'un bot spawn*/

void biome_loop(rpg_t *rpg, biome_t *biome)
{
    heros_t *heros = rpg->heros;
    static int test = 0;

    if (test == 0) {
        create_bot(GOBLINS_T, biome->bot_data, (sfVector2f){1000, 1000});
        test++;
    }
    srand(time(NULL));
    display_background(biome->back, rpg->window);
    sort_entity_in_view(biome, rpg->window, heros);
    entity_loop(biome->entity_in_view_head, rpg);
    bot_generator(biome, biome->bot_type);
    return;
}
