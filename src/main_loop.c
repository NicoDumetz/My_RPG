/*
** EPITECH PROJECT, 2023
** game
** File description:
** rpg.h
*/

#include "rpg.h"

void which_scene(rpg_t *rpg)
{
    if (rpg->scene >= PLAIN && rpg->scene <= MINE) {
        biome_loop(rpg, rpg->biome[rpg->scene]);
        manage_heros_bar(rpg->heros, rpg->window);
        quest_displayer(rpg->quest_tab, rpg->window);
        inventory(rpg);
    }
    if (rpg->scene == SAVE) {
        load_page(rpg);
    }
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
    set_view(rpg, rpg->heros->npc->entity->sprite, wich_back(rpg));
    while (sfRenderWindow_isOpen(rpg->window)) {
        while (sfRenderWindow_pollEvent(rpg->window, &(rpg->event))) {
            manage_event(rpg);
        }
        init_clock(rpg);
        rpg->mouse_data.pos = recalculate_mouse_position(
            rpg->window, sfRenderWindow_getView(rpg->window));
        sfRenderWindow_clear(rpg->window, sfWhite);
        which_scene(rpg);
        sfRenderWindow_display(rpg->window);
    }
    destroy_rpg(rpg);
}
