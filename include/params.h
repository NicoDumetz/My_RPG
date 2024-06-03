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
    int value_sound_s;
    int value_sound;
    button_t *sound;
    button_t *no_sound;
    button_t *inc_sound;
    button_t *dec_sound;
    sfText *sound_text;
} sound_t;

typedef struct fps_s {
    int fps;
    button_t *inc_fps;
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

param_t *init_param_struct(sfTexture **text_tab, sfFont **font_tab);
void params_page(rpg_t *rpg);
void quit_params(void *data, button_t *);
void destroy_param_struct(param_t *param);

int set_display_param(param_t *param, sfTexture **text_tab);
void update_param_button_display(rpg_t *rpg, display_t *display);
void display_param_button_display(rpg_t *rpg, display_t *display);
void fullscreen_p(void *data, button_t *button);
void windowed_p(void *data, button_t *button);
void r1920x1080_p(void *data, button_t *);
void r1280x720_p(void *data, button_t *);
void r850x480_p(void *data, button_t *);
void destroy_display_param(param_t *param);

int set_sound_param(param_t *param, sfTexture **text_tab, sfFont **font_tab);
void update_sound_text(sound_t *sound);
void display_param_button_sound(rpg_t *rpg, sound_t *sound);
void update_param_button_sound(rpg_t *rpg, sound_t *sound);
void mute_p(void *data, button_t *button);
void unmute_p(void *data, button_t *button);
void inc_sound_p(void *data, button_t *button);
void dec_sound_p(void *data, button_t *button);
void destroy_sound_param(param_t *param);

int set_fps_param(param_t *param, sfTexture **text_tab, sfFont **font_tab);
void update_fps_text(fps_t *fps);
void display_param_button_fps(rpg_t *rpg, fps_t *fps);
void update_param_button_fps(rpg_t *rpg, fps_t *fps);
void inc_fps_p(void *data, button_t *button);
void dec_fps_p(void *data, button_t *button);
void destroy_fps_param(param_t *param);

#endif /* !PARAMS_H_ */
