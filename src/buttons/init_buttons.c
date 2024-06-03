/*
** EPITECH PROJECT, 2023
** graph.h
** File description:
** macro for CSFML
*/

#include "../../include/button.h"

void init_action_button(
    on_released_t released,
    on_pressed_t pressed,
    on_hover_t hover,
    button_t *button)
{
    button->pressed = pressed;
    button->release = released;
    button->hover = hover;
}
