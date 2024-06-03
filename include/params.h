/*
** EPITECH PROJECT, 2024
** B-MUL-200-LIL-2-1-myrpg-matisse.dufour
** File description:
** params.h
*/

#ifndef PARAMS_H_
    #define PARAMS_H_

    #include "lib.h"

typedef struct param_s {
    int fps;
    bool end_scroll;
    sfSprite *background;
    button_t *quit;
    sfSprite *page;
    sfSprite *border_page;
    float begin_button_list;
    button_t *inc_fps;
    button_t *dec_fps;
} param_t;

param_t *init_param_struct(sfTexture **text_tab);
void params_page(rpg_t *rpg);
void quit_params(void *data, button_t *);

#endif /* !PARAMS_H_ */