/*
** EPITECH PROJECT, 2024
** hitbox collisions
** File description:
** lerkk
*/

#include "rpg.h"

bool col_hitbox(sfRectangleShape *hitbox1, sfRectangleShape *hitbox2)
{
    sfFloatRect rect1 = sfRectangleShape_getGlobalBounds(hitbox1);
    sfFloatRect rect2 = sfRectangleShape_getGlobalBounds(hitbox2);

    if (sfFloatRect_intersects(&rect1, &rect2, NULL))
        return true;
    else
        return false;
}

bool dynamique_col_up(sfRectangleShape *hit_up, sfRectangleShape *hitbox)
{
    sfFloatRect bounds_up = sfRectangleShape_getGlobalBounds(hit_up);
    sfFloatRect bounds = sfRectangleShape_getGlobalBounds(hitbox);

    if (bounds_up.top <= bounds.top + bounds.height &&
        bounds_up.top >= bounds.top &&
        bounds_up.left + bounds_up.width >= bounds.left &&
        bounds_up.left <= bounds.left + bounds.width)
        return true;
    else
        return false;
}

bool dynamique_col_down(sfRectangleShape *hit_down, sfRectangleShape *hitbox)
{
    sfFloatRect bounds_down = sfRectangleShape_getGlobalBounds(hit_down);
    sfFloatRect bounds = sfRectangleShape_getGlobalBounds(hitbox);

    if (bounds_down.top + bounds_down.height >= bounds.top &&
        bounds_down.top + bounds_down.height <= bounds.top + bounds.height &&
        bounds_down.left + bounds_down.width >= bounds.left &&
        bounds_down.left <= bounds.left + bounds.width) {
        return true;
    } else {
        return false;
    }
}

bool dynamique_col_left(sfRectangleShape *hit_left, sfRectangleShape *hitbox)
{
    sfFloatRect bounds_left = sfRectangleShape_getGlobalBounds(hit_left);
    sfFloatRect bounds = sfRectangleShape_getGlobalBounds(hitbox);

    if (bounds_left.left <= bounds.left + bounds.width &&
        bounds_left.left >= bounds.left &&
        bounds_left.top + bounds_left.height >= bounds.top &&
        bounds_left.top <= bounds.top + bounds.height) {
        return true;
    } else {
        return false;
    }
}

bool dynamique_col_right(sfRectangleShape *hit_right, sfRectangleShape *hitbox)
{
    sfFloatRect bounds_right = sfRectangleShape_getGlobalBounds(hit_right);
    sfFloatRect bounds = sfRectangleShape_getGlobalBounds(hitbox);

    if (bounds_right.left + bounds_right.width >= bounds.left &&
        bounds_right.left + bounds_right.width <= bounds.left + bounds.width &&
        bounds_right.top + bounds_right.height >= bounds.top &&
        bounds_right.top <= bounds.top + bounds.height) {
        return true;
    } else {
        return false;
    }
}
