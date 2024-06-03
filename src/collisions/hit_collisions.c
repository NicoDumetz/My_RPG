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

    if (rect1.left + rect1.width < rect2.left ||
        rect2.left + rect2.width < rect1.left)
        return false;
    if (rect1.top + rect1.height < rect2.top ||
        rect2.top + rect2.height < rect1.top)
        return false;
    return true;
}

bool dynamique_col_up(sfRectangleShape *hit_up, sfRectangleShape *hitbox)
{
    sfVector2f pos_up = sfRectangleShape_getPosition(hit_up);
    sfVector2f pos = sfRectangleShape_getPosition(hitbox);

    if (pos_up.y >= pos.y) {
        return true;
    } else {
        return false;
    }
}

bool dynamique_col_down(sfRectangleShape *hit_down, sfRectangleShape *hitbox)
{
    sfVector2f pos_down = sfRectangleShape_getPosition(hit_down);
    sfVector2f pos = sfRectangleShape_getPosition(hitbox);

    if (pos_down.y <= pos.y) {
        return true;
    } else {
        return false;
    }
}

bool dynamique_col_left(sfRectangleShape *hit_left, sfRectangleShape *hitbox)
{
    sfVector2f pos_left = sfRectangleShape_getPosition(hit_left);
    sfVector2f pos = sfRectangleShape_getPosition(hitbox);

    if (pos_left.x >= pos.x) {
        return true;
    } else {
        return false;
    }
}

bool dynamique_col_right(sfRectangleShape *hit_right, sfRectangleShape *hitbox)
{
    sfVector2f pos_right = sfRectangleShape_getPosition(hit_right);
    sfVector2f pos = sfRectangleShape_getPosition(hitbox);

    if (pos_right.x <= pos.x) {
        return true;
    } else {
        return false;
    }
}
