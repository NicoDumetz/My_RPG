/*
** EPITECH PROJECT, 2023
** game
** File description:
** rpg.h
*/

#include "rpg.h"

void destroy_rpg(rpg_t *rpg)
{
    if (rpg) {
        sfRenderWindow_destroy(rpg->window);
        destroy_heros(rpg->heros);
        sfClock_destroy(rpg->clock);
        free_bot_data(rpg->bot_data);
        destroy_background(rpg->back);
        free(rpg);
    }
}

rpg_t *create_rpg_struct(void)
{
    rpg_t *rpg = malloc(sizeof(rpg_t));
    sfVideoMode mode = {1920, 1080, 32};

    rpg->clock = sfClock_create();
    rpg->scene = MAIN;
    rpg->second = 0;
    rpg->time = 0;
    rpg->window = sfRenderWindow_create(mode, "my_rpg", sfClose, NULL);
    rpg->heros = init_heros(KNIGHT_SPRITE);
    rpg->bot_data = init_bot_data();
    rpg->ticks = false;
    for (int i = 0; i < 256; i++)
        rpg->key_state[i] = false;
    rpg->back = add_background("maptest.png", "colisiontest.png");
    return rpg;
}
