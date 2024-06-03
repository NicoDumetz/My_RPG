/*
** EPITECH PROJECT, 2023
** game
** File description:
** rpg.h
*/

#include "rpg.h"

static void biome_scene(rpg_t *rpg)
{
    biome_loop(rpg, rpg->biome[rpg->scene]);
    manage_heros_bar(rpg->heros, rpg->window);
    quest_displayer(rpg->quest_tab, rpg->window);
    manage_particules(rpg);
    manage_inventory(rpg);
}

void which_scene(rpg_t *rpg)
{
    if (rpg->scene >= PLAIN && rpg->scene <= MINE) {
        biome_scene(rpg);
        update_game_over(rpg->end, rpg);
    }
    if (rpg->scene == SAVE)
        load_page(rpg);
    if (rpg->scene == MENU)
        start_menu(rpg);
    if (rpg->scene == PARAMS)
        params_page(rpg);
    if (rpg->scene == TUTO) {
        tuto_loop(rpg);
        manage_heros_bar(rpg->heros, rpg->window);
        manage_inventory(rpg);
    }
    if (rpg->end->active == TUTO_FADE)
        manage_switch_fade(rpg->end, rpg);
    manage_ingame_menu(rpg);
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

static void clear_window(rpg_t *rpg)
{
    sfColor blue = sfColor_fromRGB(71, 171, 169);

    if (rpg->scene != PLAIN)
        sfRenderWindow_clear(rpg->window, sfBlack);
    else
        sfRenderWindow_clear(rpg->window, blue);
}

void rpg(rpg_t *rpg)
{
    sfRenderWindow_setFramerateLimit(rpg->window, 60);
    while (sfRenderWindow_isOpen(rpg->window)) {
        while (sfRenderWindow_pollEvent(rpg->window, &(rpg->event))) {
            manage_event(rpg);
        }
        init_clock(rpg);
        fetch_last_frame(rpg);
        set_all_volume(rpg, rpg->params->sound->value_sound);
        rpg->mouse_data.pos = recalculate_mouse_position(
            rpg->window, sfRenderWindow_getView(rpg->window));
        clear_window(rpg);
        which_scene(rpg);
        sfRenderWindow_display(rpg->window);
    }
    destroy_rpg(rpg);
}
