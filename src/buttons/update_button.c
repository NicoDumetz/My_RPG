/*
** EPITECH PROJECT, 2023
** graph.h
** File description:
** macro for CSFML
*/

#include "../../include/button.h"

#include <SFML/Graphics.h>
#include <SFML/Window.h>

#include <SFML/Graphics.h>
#include <SFML/Window.h>

void button_is_press(button_t *button, void *data)
{
    button->state = CLICK;
    if (button->texture_state[CLICK])
        sfSprite_setTexture(button->sprite,
            button->texture_state[CLICK], sfTrue);
    if (button->pressed) {
        button->pressed(data, button);
    }
}

void button_is_not_press(button_t *button, void *data)
{
    if (button->state == CLICK) {
        button->state = RELEASE;
        sfSprite_setTexture(button->sprite,
            button->texture_state[RELEASE], sfTrue);
        if (button->release)
            button->release(data, button);
        return;
    }
    if (button->state != CLICK) {
        button->state = HOVER;
        if (button->texture_state[HOVER])
            sfSprite_setTexture(button->sprite,
            button->texture_state[HOVER], sfTrue);
        if (button->hover)
            button->hover(data, button);
        return;
    }
}

int case_is_over(button_t *button, void *data, int mouse_over, int mouse_state)
{
    if (mouse_over) {
        if (mouse_state == 1)
            button_is_press(button, data);
        if (mouse_state == 0)
            button_is_not_press(button, data);
        return (1);
    }
    return (0);
}

int is_block(button_t *button)
{
    if (button->state == BLOCK) {
        if (button->texture_state[BLOCK])
            sfSprite_setTexture(button->sprite,
                button->texture_state[BLOCK], sfTrue);
        return (1);
    }
    return (0);
}

void update_button(
    button_t *button, mouse_data_t *mouse_data, void *data)
{
    sfVector2f mouse_pos = mouse_data->pos;
    int mouse_state = mouse_data->left ? 1 : 0;
    sfFloatRect button_bounds = sfSprite_getGlobalBounds(button->sprite);
    int mouse_over =
        sfFloatRect_contains(&button_bounds, mouse_pos.x, mouse_pos.y);

    if (mouse_state == 1 && button->state == CLICK) {
        button_is_press(button, data);
        return;
    }
    if (button->visible == 0 || is_block(button) == 1)
        return;
    if (case_is_over(button, data, mouse_over, mouse_state) == 0 &&
        ((!mouse_over && button->state != CLICK) || mouse_state == 0)) {
        button->state = NONE;
        sfSprite_setTexture(button->sprite,
            button->texture_state[NONE], sfTrue);
    }
}
