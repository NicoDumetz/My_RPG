/*
** EPITECH PROJECT, 2024
** B-MUL-200-LIL-2-1-myrpg-matisse.dufour
** File description:
** manage_menu_button.c
*/

#include "rpg.h"

void play_button(void *data, button_t *)
{
    rpg_t *rpg = (rpg_t *)data;
    save_t *save;

    if (rpg->save_scene->button_list == NULL ||
        rpg->save_scene->button_list->child == NULL) {
        rpg->scene = PLAIN;
        set_view(rpg, rpg->heros->npc->entity->sprite, wich_back(rpg));
        return;
    }
    save = rpg->save_scene->button_list->child;
    appli_save(rpg, save->data);
    set_view(rpg, rpg->heros->npc->entity->sprite,
        rpg->biome[save->data->id_biome]->back->sprite.sprite);
    rpg->scene = save->data->id_biome;
}

void new_button(void *data, button_t *)
{
    rpg_t *rpg = (rpg_t *)data;

    rpg->scene = PLAIN;
    set_view(rpg, rpg->heros->npc->entity->sprite, wich_back(rpg));
}

void saves_button(void *data, button_t *)
{
    rpg_t *rpg = (rpg_t *)data;

    rpg->save_scene->from = MENU;
    rpg->scene = SAVE;
}

void param_button(void *data, button_t *)
{
    rpg_t *rpg = (rpg_t *)data;

    rpg->scene = PARAMS;
}

void quit_button(void *data, button_t *)
{
    sfRenderWindow *window = (sfRenderWindow *)data;

    sfRenderWindow_close(window);
}
