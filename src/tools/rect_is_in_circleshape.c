/*
** EPITECH PROJECT, 2023
** my_strcmp
** File description:
** Task06
*/

#include "rpg.h"


#include <SFML/Graphics.h>
#include <math.h>

bool is_rect_in_circle(sfRectangleShape* rectangle, sfCircleShape* circle)
{
    sfVector2f circle_pos = sfCircleShape_getPosition(circle);
    float circle_radius = sfCircleShape_getRadius(circle);
    sfFloatRect rect_bounds = sfRectangleShape_getGlobalBounds(rectangle);
    sfVector2f rect_center = {
        rect_bounds.left + rect_bounds.width / 2.0f,
        rect_bounds.top + rect_bounds.height / 2.0f
    };
    float center_x = circle_pos.x + circle_radius;
    float center_y = circle_pos.y + circle_radius;
    float dx = rect_center.x - center_x;
    float dy = rect_center.y - center_y;
    float distance = sqrt(dx * dx + dy * dy);

    if (distance <= circle_radius)
        return true;
    else
        return false;
}
