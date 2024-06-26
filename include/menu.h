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
    sfSprite *background;
    button_t *play;
    button_t *new;
    button_t *saves;
    button_t *param;
    button_t *quit;
} menu_t;

typedef struct ingame_menu_s {
    int from;
    int pos;
    sfTexture *last_frame;
    sfRectangleShape *blur;
    sfSprite *background;
    sfSprite *page;
    button_t *resume;
    button_t *save;
    button_t *load_save;
    button_t *param;
    button_t *quit;
} ingame_menu_t;

void fetch_last_frame(rpg_t *rpg);
menu_t *create_menu_struct(rpg_t *rpg);
void destroy_menu(menu_t *menu);
void play_button(void *data, button_t *button);
void saves_button(void *data, button_t *button);
void new_button(void *data, button_t *button);
void param_button(void *data, button_t *button);
void quit_button(void *data, button_t *button);

void manage_ingame_menu(rpg_t *rpg);
ingame_menu_t *create_menu_ingame_struct(rpg_t *rpg);
void destroy_menu_ingame(ingame_menu_t *menu);
void menu_ingame(rpg_t *rpg);
void resume_button(void *data, button_t *);
void nsave_button(void *data, button_t *);
void load_save_button(void *data, button_t *);
void param_ingame_button(void *data, button_t *);
void quit_game_button(void *data, button_t *);
#endif /* !MENU_H_ */
