/*
** EPITECH PROJECT, 2023
** graph.h
** File description:
** macro for CSFML
*/

#include "rpg.h"

void destroy_info_bar(info_bar_t *info_bar)
{
    sfRectangleShape_destroy(info_bar->bar);
    free(info_bar);
}

sfRectangleShape *set_rect_bar(sfColor color, sfVector2f size)
{
    sfRectangleShape *bar = sfRectangleShape_create();

    sfRectangleShape_setSize(bar, size);
    sfRectangleShape_setOutlineColor(bar, sfBlack);
    sfRectangleShape_setOutlineThickness(bar, 2);
    sfRectangleShape_setFillColor(bar, color);
    return (bar);
}

info_bar_t *create_info_bar(sfColor color, sfVector2f size, float max)
{
    info_bar_t *info_bar = malloc(sizeof(info_bar_t));

    info_bar->bar = set_rect_bar(color, size);
    info_bar->act = 0;
    info_bar->max = max;
    info_bar->size.x = size.x;
    info_bar->size.y = size.y;
    return (info_bar);
}
