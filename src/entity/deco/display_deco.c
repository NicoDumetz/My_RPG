/*
** EPITECH PROJECT, 2023
** graph.h
** File description:
** macro for CSFML
*/

#include "rpg.h"

static void deco_anim_loop(
    entity_t **entity_tab, sfRenderWindow *window, bool ticks)
{
    for (int i = 0; entity_tab[i]; i++) {
        sfRenderWindow_drawSprite(
            window, entity_tab[i]->sprite, NULL);
        anim_entity(entity_tab[i], (sfVector2i){3, 0}, ticks);
        set_colbox(entity_tab[i]);
        sfRenderWindow_drawRectangleShape(
            window, entity_tab[i]->colbox, NULL);
    }
}

static void deco_static_loop(entity_t **entity_tab, sfRenderWindow *window)
{
    for (int i = 0; entity_tab[i]; i++) {
        sfRenderWindow_drawSprite(
            window, entity_tab[i]->sprite, NULL);
        set_colbox(entity_tab[i]);
        sfRenderWindow_drawRectangleShape(
            window, entity_tab[i]->colbox, NULL);
    }
}

void display_deco(deco_data_t *deco_data, sfRenderWindow *window, bool ticks)
{
    for (int i = 0; i <= MINE_DECO; i++) {
        if (i == TREE_DECO)
            deco_anim_loop(deco_data->deco_entity[i], window, ticks);
        else
            deco_static_loop(deco_data->deco_entity[i], window);
    }
}
