/*
** EPITECH PROJECT, 2023
** graph.h
** File description:
** macro for CSFML
*/

#include "rpg.h"

static void deco_anim_loop(
    entity_t *entity, sfRenderWindow *window, bool ticks)
{
    sfRenderWindow_drawSprite(
        window, entity->sprite, NULL);
    anim_entity(entity, (sfVector2i){3, 0}, ticks);
    set_colbox(entity);
    sfRenderWindow_drawRectangleShape(
        window, entity->colbox, NULL);
}

static void deco_static_loop(entity_t *entity, sfRenderWindow *window)
{
    sfRenderWindow_drawSprite(
        window, entity->sprite, NULL);
    set_colbox(entity);
    sfRenderWindow_drawRectangleShape(
        window, entity->colbox, NULL);
}

void display_deco(deco_data_t *deco_data, sfRenderWindow *window, bool ticks)
{
    for (int i = 0; deco_data->house_tab[i]; i++)
        deco_static_loop(deco_data->house_tab[i], window);
    for (int i = 0; deco_data->tree_tab[i]; i++)
        deco_anim_loop(deco_data->tree_tab[i], window, ticks);
    for (int i = 0; deco_data->mine_tab[i]; i++)
        deco_static_loop(deco_data->mine_tab[i], window);
}
