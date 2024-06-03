/*
** EPITECH PROJECT, 2024
** B-MUL-200-LIL-2-1-myrpg-matisse.dufour
** File description:
** manage_menu_button.c
*/

#include "rpg.h"

void resume_button(void *data, button_t *)
{
    rpg_t *rpg = (rpg_t *)data;

    rpg->scene = rpg->ingame_menu->from;
    sfTexture_destroy(rpg->ingame_menu->last_frame);
    rpg->ingame_menu->last_frame = NULL;
    set_view(rpg, rpg->heros->npc->entity->sprite, wich_back(rpg));
}

void nsave_button(void *data, button_t *)
{
    rpg_t *rpg = (rpg_t *)data;

    rpg->scene = rpg->ingame_menu->from;
    if (rpg->end->active == OFF)
        create_save(rpg);
    rpg->scene = INGAME_MENU;
}

void load_save_button(void *data, button_t *)
{
    rpg_t *rpg = (rpg_t *)data;

    set_view(rpg, rpg->save_scene->back, rpg->save_scene->back);
    rpg->save_scene->from = INGAME_MENU;
    rpg->scene = SAVE;
}

void param_ingame_button(void *data, button_t *)
{
    rpg_t *rpg = (rpg_t *)data;

    rpg->scene = PARAMS;
    rpg->params->from = INGAME_MENU;
}

void quit_game_button(void *data, button_t *)
{
    rpg_t *rpg = (rpg_t *)data;

    sfTexture_destroy(rpg->ingame_menu->last_frame);
    rpg->ingame_menu->last_frame = NULL;
    unappli_all_multi(rpg);
    rpg->heros->multi_speed = 1;
    rpg->scene = MENU;
}
