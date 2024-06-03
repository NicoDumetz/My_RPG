/*
** EPITECH PROJECT, 2024
** check_collisions
** File description:
** check_collisions
*/

#include "rpg.h"

bool static_collisions_up(sfRectangleShape *hitbox, sfImage *collision_image)
{
    sfVector2u imgSize = sfImage_getSize(collision_image);
    sfVector2f cornerPos = sfRectangleShape_getPosition(hitbox);
    sfVector2f size = sfRectangleShape_getSize(hitbox);
    unsigned int x = (unsigned int)cornerPos.x + (size.x / 2);
    unsigned int y = (unsigned int)cornerPos.y;
    sfColor color;

    if (x < imgSize.x && y < imgSize.y) {
        color = sfImage_getPixel(collision_image, x, y);
        if (color.r == 0 && color.g == 0 && color.b == 0 && color.a > 200) {
            return true;
        }
    }
    return false;
}

bool static_collisions_left(sfRectangleShape *hitbox, sfImage *collision_image)
{
    sfVector2u imgSize = sfImage_getSize(collision_image);
    sfVector2f cornerPos = sfRectangleShape_getPosition(hitbox);
    sfVector2f size = sfRectangleShape_getSize(hitbox);
    unsigned int x = (unsigned int)cornerPos.x;
    unsigned int y = (unsigned int)cornerPos.y + (size.y / 2);
    sfColor color;

    if (x < imgSize.x && y < imgSize.y) {
        color = sfImage_getPixel(collision_image, x, y);
        if (color.r == 0 && color.g == 0 && color.b == 0 && color.a > 200) {
            return true;
        }
    }
    return false;
}

bool static_collisions_right(
    sfRectangleShape *hitbox, sfImage *collision_image)
{
    sfVector2u imgSize = sfImage_getSize(collision_image);
    sfVector2f cornerPos = sfRectangleShape_getPosition(hitbox);
    sfVector2f size = sfRectangleShape_getSize(hitbox);
    unsigned int x = (unsigned int)cornerPos.x + size.x;
    unsigned int y = (unsigned int)cornerPos.y + (size.y / 2);
    sfColor color;

    if (x < imgSize.x && y < imgSize.y) {
        color = sfImage_getPixel(collision_image, x, y);
        if (color.r == 0 && color.g == 0 && color.b == 0 && color.a > 200) {
            return true;
        }
    }
    return false;
}

bool static_collisions_down(sfRectangleShape *hitbox, sfImage *collision_image)
{
    sfVector2u imgSize = sfImage_getSize(collision_image);
    sfVector2f cornerPos = sfRectangleShape_getPosition(hitbox);
    sfVector2f size = sfRectangleShape_getSize(hitbox);
    unsigned int x = (unsigned int)cornerPos.x + (size.x / 2);
    unsigned int y = (unsigned int)cornerPos.y + size.y;
    sfColor color;

    if (x < imgSize.x && y < imgSize.y) {
        color = sfImage_getPixel(collision_image, x, y);
        if (color.r == 0 && color.g == 0 && color.b == 0 && color.a > 200) {
            return true;
        }
    }
    return false;
}
