/*
** EPITECH PROJECT, 2023
** graph.h
** File description:
** macro for CSFML
*/

#include "rpg.h"

sfVector2f recalculate_mouse_position(
    sfRenderWindow* window, const sfView* view)
{
    sfVector2i mouse_pixel_pos = sfMouse_getPositionRenderWindow(window);
    sfVector2f mouse_relative_pos = sfRenderWindow_mapPixelToCoords(window,
        mouse_pixel_pos, view);

    return mouse_relative_pos;
}
