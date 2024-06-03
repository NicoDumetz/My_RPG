/*
** EPITECH PROJECT, 2023
** game
** File description:
** rpg.h
*/

#include "rpg.h"

void which_scene(rpg_t *rpg)
{
    if (rpg->scene == MAIN)
        test(rpg);
}

void init_clock(rpg_t *rpg)
{
    sfTime new_time = sfClock_restart(rpg->clock);
    static float accu = 0;

    rpg->time = sfTime_asSeconds(new_time);
    accu += rpg->time;
    rpg->second = (int)accu;
}

void rpg(rpg_t *rpg)
{
    sfRenderWindow_setFramerateLimit(rpg->window, 60);
    while (sfRenderWindow_isOpen(rpg->window)) {
        while (sfRenderWindow_pollEvent(rpg->window, &(rpg->event))) {
            manage_event(rpg);
        }
        init_clock(rpg);
        sfRenderWindow_clear(rpg->window, sfWhite);
        which_scene(rpg);
        sfRenderWindow_display(rpg->window);
    }
    destroy_rpg(rpg);
}
