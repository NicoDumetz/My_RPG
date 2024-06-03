/*
** EPITECH PROJECT, 2024
** background
** File description:
** background
*/

#ifndef BACK_H
    #define BACK_H
    #include "lib.h"

typedef struct sprite_back_t {
    sfTexture *texture;
    sfSprite *sprite;
    sfVector2f pos;
    sfVector2f scale;
    sfImage *col_image;
} sprite_back_t;

typedef struct background_s {
    sprite_back_t sprite;
    sprite_back_t collision;
} back_t;

/*manage background*/
back_t *add_background(char *file, char *collision);
void display_background(back_t *back, sfRenderWindow *window);
void destroy_background(back_t *back);

#endif
