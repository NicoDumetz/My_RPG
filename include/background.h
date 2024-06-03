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

typedef enum action_end_e {
    OFF,
    ACTIVE
} action_end_t;


typedef struct game_over_s {
    sfRectangleShape *rect;
    action_end_t active;
    sfText *text;
    float alpha;
    float alpha_text;
} game_over_t;

/*manage background*/
back_t *add_background(sfTexture *file, sfTexture *collision);
void display_background(back_t *back, sfRenderWindow *window);
void destroy_background(back_t *back);
void set_view(rpg_t *rpg, sfSprite* sprite, sfSprite *limite);

/*manage game over*/
void init_game_over(rpg_t *rpg);
void free_game_over(game_over_t *g);
void lunch_end(rpg_t *rpg);
void update_game_over(game_over_t *game, rpg_t *rpg);
void display_game_over(game_over_t *game, rpg_t *rpg);
#endif
