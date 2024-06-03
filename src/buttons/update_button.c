/*
** EPITECH PROJECT, 2023
** graph.h
** File description:
** macro for CSFML
*/

#include "../../include/button.h"

void button_is_press(button_t *button, void *data)
{
    button->state = CLICK;
    if (button->sprite_state->sprite_on_click)
        button->sprite = button->sprite_state->sprite_on_click;
    if (button->pressed) {
        button->pressed(data);
    }
}

void button_is_not_press(button_t *button, void *data)
{
    if (button->state == CLICK) {
        button->state = RELEASE;
        button->sprite = button->sprite_state->sprite_on_released;
        if (button->release)
            button->release(data);
        return;
    }
    if (button->state != CLICK) {
        button->state = HOVER;
        if (button->sprite_state->sprite_on_hover)
            button->sprite = button->sprite_state->sprite_on_hover;
        if (button->hover)
            button->hover(data);
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
        if (button->sprite_state->sprite_on_block)
            button->sprite = button->sprite_state->sprite_on_block;
        return (1);
    }
    return (0);
}

void update_button(
    button_t *button, sfRenderWindow *window, int mouse_state, void *data)
{
    sfVector2i mousePos = sfMouse_getPositionRenderWindow(window);
    sfFloatRect buttonBounds = sfSprite_getGlobalBounds(button->sprite);
    int mouse_over =
        sfFloatRect_contains(&buttonBounds, mousePos.x, mousePos.y);

    if (mouse_state == 1 && button->state == CLICK) {
        button_is_press(button, data);
        return;
    }
    if (button->visible == 0 || is_block(button) == 1)
        return;
    if (case_is_over(button, data, mouse_over, mouse_state) == 0 &&
        ((!mouse_over && button->state != CLICK) || mouse_state == 0)) {
        button->state = NONE;
        button->sprite = button->sprite_state->sprite_on_released;
    }
}
