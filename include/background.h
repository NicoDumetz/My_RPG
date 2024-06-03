/*
** EPITECH PROJECT, 2024
** background
** File description:
** background
*/

#ifndef BACK_H
    #define BACK_H
    #include "lib.h"
    #include "rpg.h"

typedef struct rpg_s rpg_t;
typedef struct sprite_back_t {
    sfTexture *texture;
    sfSprite *sprite;
    sfVector2f pos;
    sfVector2f scale;
} sprite_back_t;

typedef struct background {
    int scene;
    sprite_back_t sprite;
    sprite_back_t collision;
    struct background *next;
} back_t;

/*manage background*/
void init_background(rpg_t *rpg);
void display_background(rpg_t *rpg);

/*manage movements*/
void manage_movements(rpg_t *rpg, sfEvent *event);
#endif
