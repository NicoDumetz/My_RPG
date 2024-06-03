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
    sfVector2f view_center = sfView_getCenter(view);
    sfVector2f view_size = sfView_getSize(view);
    sfVector2f view_top_left;
    sfVector2i mouse_pixel_pos = sfMouse_getPositionRenderWindow(window);
    sfVector2f mouse_relative_pos;

    view_top_left.x = view_center.x - (view_size.x / 2);
    view_top_left.y = view_center.y - (view_size.y / 2);
    mouse_relative_pos.x = (float)mouse_pixel_pos.x + view_top_left.x;
    mouse_relative_pos.y = (float)mouse_pixel_pos.y + view_top_left.y;
    return mouse_relative_pos;
}
