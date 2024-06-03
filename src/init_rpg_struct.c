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
    rpg->heros = init_heros(
    "tiny_world_asset/Factions/Knights/Troops/Warrior/Blue/Warrior_Blue.png");
    sfRenderWindow_setPosition(rpg->window, (sfVector2i){0, 0});
    rpg->bot_data = init_bot_data();
    init_background(rpg);
    return rpg;
}
