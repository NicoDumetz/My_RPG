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
typedef void (*on_pressed_t)(void *, button_t *);
typedef void (*on_hover_t)(void *, button_t *);
typedef void (*on_released_t)(void *, button_t *);
typedef enum state_e {
    NONE = 0,
    CLICK,
    HOVER,
    RELEASE,
    BLOCK,
}state_t;

typedef struct mouse_data_s {
    sfVector2f pos;
    bool right;
    bool left;
    bool scroll_up;
    bool scroll_down;
} mouse_data_t;

typedef struct button_s {
    int visible;
    sfVector2f pos;
    state_t state;
    sfSprite *sprite;
    sfTexture *texture_state[5];
    on_hover_t hover;
    on_pressed_t pressed;
    on_released_t release;
    void *child;
    button_t *next;
    button_t *prev;
} button_t;

void update_button(
    button_t *button, mouse_data_t *mouse_data, void *data);
void init_action_button(
    on_released_t released,
    on_pressed_t pressed,
    on_hover_t hover,
    button_t *button);

button_t *create_button(sfTexture **text_tab, int *text_id);
void destroy_button(button_t *button);
#endif
