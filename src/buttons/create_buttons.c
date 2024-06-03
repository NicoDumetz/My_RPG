/*
** EPITECH PROJECT, 2023
** graph.h
** File description:
** macro for CSFML
*/

#include "../../include/button.h"

void destroy_button(button_t *button)
{
    free_state_sprite(button->sprite_state);
    free(button);
}

button_t *create_button(sfSprite *sprite, int x, int y)
{
    button_t *button = malloc(sizeof(button_t));
    sprite_state_t *sprite_state =
        init_sprite_button(sprite, NULL, NULL, NULL);

    if (button == NULL)
        return (NULL);
    memset(button, 0, sizeof(button_t));
    button->pos = (sfVector2f){x, y};
    button->visible = 1;
    button->sprite_state = sprite_state;
    button->sprite = sprite;
    return (button);
}
