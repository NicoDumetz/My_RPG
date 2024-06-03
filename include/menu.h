/*
** EPITECH PROJECT, 2024
** B-MUL-200-LIL-2-1-myrpg-matisse.dufour
** File description:
** menu.h
*/

#ifndef MENU_H_
    #define MENU_H_
    #include "lib.h"

typedef struct menu_s {
    int pos;
    int save;
    sfSprite *background;
    button_t *play;
    button_t *new;
    button_t *saves;
    button_t *param;
    button_t *quit;
} menu_t;

menu_t *create_menu_struct(rpg_t *rpg);
void destroy_menu(menu_t *menu);
void play_button(void *data, button_t *button);
void saves_button(void *data, button_t *button);
void new_button(void *data, button_t *button);
void param_button(void *data, button_t *button);
void quit_button(void *data, button_t *button);
#endif /* !MENU_H_ */
