/*
** EPITECH PROJECT, 2023
** graph.h
** File description:
** macro for CSFML
*/

#include "rpg.h"

void destroy_cursor(rpg_t *rpg)
{
    sfSprite_destroy(rpg->cursor);
}

void manage_cursor(rpg_t *rpg)
{
    sfSprite_setPosition(rpg->cursor, rpg->mouse_data.pos);
    sfRenderWindow_drawSprite(rpg->window, rpg->cursor, NULL);
}

void init_cursor(rpg_t *rpg)
{
    rpg->cursor = sfSprite_create();
    sfSprite_setTexture(rpg->cursor, rpg->text_tab[CURSOR_TEXT], sfTrue);
    sfRenderWindow_setMouseCursorVisible(rpg->window, sfFalse);
}
