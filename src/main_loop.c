/*
** EPITECH PROJECT, 2023
** game
** File description:
** rpg.h
*/

#include "rpg.h"

void which_scene(rpg_t *rpg)
{
    if (rpg->scene == PLAIN)
        test(rpg);
    if (rpg->scene == MAIN)
        start_menu(rpg);
}

void init_clock(rpg_t *rpg)
{
    sfTime new_time = sfClock_restart(rpg->clock);
    static float accu = 0;
    static float ticks = 0;
    float frec = 1.0 / 10.0;

    rpg->time = sfTime_asSeconds(new_time);
    ticks += rpg->time;
    if (ticks >= frec) {
        rpg->ticks = true;
        ticks = 0;
    } else
        rpg->ticks = false;
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
