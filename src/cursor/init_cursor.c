/*
** EPITECH PROJECT, 2023
** graph.h
** File description:
** macro for CSFML
*/

#include "rpg.h"

void destroy_cursor(rpg_t *rpg)
{
    sfCursor_destroy(rpg->cursor);
    sfImage_destroy(rpg->cursor_image);
}

void init_cursor(rpg_t *rpg)
{
    sfVector2u image_size;

    rpg->cursor_image = sfImage_createFromFile(CURSOR_PATH);
    if (rpg->cursor_image == NULL)
        exit(84);
    image_size = sfImage_getSize(rpg->cursor_image);
    rpg->cursor = sfCursor_createFromPixels(
        sfImage_getPixelsPtr(rpg->cursor_image),
        image_size, (sfVector2u){0, 0});
    if (rpg->cursor == NULL) {
        sfImage_destroy(rpg->cursor_image);
        exit(84);
    }
    sfRenderWindow_setMouseCursor(rpg->window, rpg->cursor);
}
