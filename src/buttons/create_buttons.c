/*
** EPITECH PROJECT, 2023
** graph.h
** File description:
** macro for CSFML
*/

#include "button.h"

void destroy_button(button_t *button)
{
    sfSprite_destroy(button->sprite);
    free(button);
}

button_t *create_button(sfTexture **text_tab, int *text_id)
{
    button_t *button = malloc(sizeof(button_t));

    if (button == NULL)
        return (NULL);
    memset(button, 0, sizeof(button_t));
    button->pos = (sfVector2f){0, 0};
    button->visible = 1;
    button->child = NULL;
    for (int i = 0; i < 5; i++) {
        if (text_id[i] >= 0)
            button->texture_state[i] = text_tab[text_id[i]];
        else
            button->texture_state[i] = NULL;
    }
    button->sprite = sfSprite_create();
    sfSprite_setTexture(button->sprite, text_tab[text_id[NONE]], sfTrue);
    return (button);
}
