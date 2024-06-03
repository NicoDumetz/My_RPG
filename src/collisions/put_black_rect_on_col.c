/*
** EPITECH PROJECT, 2023
** game
** File description:
** rpg.h
*/

#include "rpg.h"

void draw_black_rect_on_image(sfRectangleShape* rectangle, sfImage* image)
{
    sfVector2f position = sfRectangleShape_getPosition(rectangle);
    sfVector2f size = sfRectangleShape_getSize(rectangle);
    int rectX = (int)position.x;
    int rectY = (int)position.y;
    int rectWidth = (int)size.x;
    int rectHeight = (int)size.y;
    sfColor blackColor = sfColor_fromRGB(0, 0, 0);

    for (int x = rectX; x < rectX + rectWidth; x++)
        for (int y = rectY; y < rectY + rectHeight; y++)
            sfImage_setPixel(image, x, y, blackColor);
}
