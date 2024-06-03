/*
** EPITECH PROJECT, 2023
** graph.h
** File description:
** macro for CSFML
*/

#include "../../include/button.h"

void free_state_sprite(sprite_state_t *sprite_state)
{
    if (sprite_state->sprite_on_block != NULL)
        destroy_sprite(sprite_state->sprite_on_block);
    if (sprite_state->sprite_on_click != NULL)
        destroy_sprite(sprite_state->sprite_on_click);
    if (sprite_state->sprite_on_hover != NULL)
        destroy_sprite(sprite_state->sprite_on_hover);
    if (sprite_state->sprite_on_released != NULL)
        destroy_sprite(sprite_state->sprite_on_released);
    free(sprite_state);
}

sprite_state_t *init_sprite_button(
    sfSprite *on_release,
    sfSprite *on_click,
    sfSprite *on_hover,
    sfSprite *on_block)
{
    sprite_state_t *new_state = malloc(sizeof(sprite_state_t));

    new_state->sprite_on_block = on_block;
    new_state->sprite_on_click = on_click;
    new_state->sprite_on_hover = on_hover;
    new_state->sprite_on_released = on_release;
    return (new_state);
}

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
