/*
** EPITECH PROJECT, 2023
** graph.h
** File description:
** macro for CSFML
*/

#ifndef BUTTON_H
    #define BUTTON_H
    #include "lib.h"
typedef struct button_s button_t;
typedef void (*on_pressed_t)(void *);
typedef void (*on_hover_t)(void *);
typedef void (*on_released_t)(void *);
typedef enum state_e {
    NONE = 0,
    CLICK,
    HOVER,
    RELEASE,
    BLOCK,
}state_t;
typedef struct sprite_state_s {
    sfSprite *sprite_on_released;
    sfSprite *sprite_on_click;
    sfSprite *sprite_on_hover;
    sfSprite *sprite_on_block;
} sprite_state_t;
typedef struct button_s {
    int visible;
    sfVector2f pos;
    state_t state;
    sfSprite *sprite;
    sprite_state_t *sprite_state;
    on_hover_t hover;
    on_pressed_t pressed;
    on_released_t release;
    button_t *next;
    button_t *previous;
} button_t;
void update_button(
    button_t *button, sfRenderWindow *window, int mouse_state, void *data);
void init_action_button(
    on_released_t released,
    on_pressed_t pressed,
    on_hover_t hover,
    button_t *button);
sprite_state_t *init_sprite_button(
    sfSprite *on_release,
    sfSprite *on_click,
    sfSprite *on_hover,
    sfSprite *on_block);
void destroy_sprite(sfSprite *sprite);
void free_state_sprite(sprite_state_t *sprite_state);
button_t *create_button(sfSprite *sprite, int x, int y);
void destroy_button(button_t *button);
#endif
