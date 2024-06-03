/*
** EPITECH PROJECT, 2024
** B-MUL-200-LIL-2-1-myrpg-matisse.dufour
** File description:
** params.h
*/

#ifndef PARAMS_H_
    #define PARAMS_H_

    #include "lib.h"

typedef struct display_s {
    int visible;
    button_t *fullscreen;
    button_t *windowed;
    button_t *r1920x1080;
    button_t *r1280x720;
    button_t *r850x480;
    sfSprite *selection;
} display_t;

typedef struct sound_s {
    button_t *sound;
    button_t *inc_sound;
    button_t *dec_sound;
    sfText *sound_text;
} sound_t;

typedef struct fps_s {
    button_t *inc_fps;
    int fps;
    button_t *dec_fps;
    sfText *fps_text;
} fps_t;

typedef struct param_s {
    sfVideoMode view;
    sfSprite *background;
    button_t *quit;
    sfSprite *page;
    display_t *display;
    sound_t *sound;
    fps_t *fps;
} param_t;

param_t *init_param_struct(sfTexture **text_tab);
void params_page(rpg_t *rpg);
void quit_params(void *data, button_t *);
void update_param_button_display(rpg_t *rpg, display_t *display);
void display_param_button_display(rpg_t *rpg, display_t *display);

void fullscreen_p(void *data, button_t *button);
void windowed_p(void *data, button_t *button);
void r1920x1080_p(void *data, button_t *);
void r1280x720_p(void *data, button_t *);
void r850x480_p(void *data, button_t *);

#endif /* !PARAMS_H_ */