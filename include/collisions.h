/*
** EPITECH PROJECT, 2023
** graph.h
** File description:
** collisions
*/

#ifndef COL_S
    #define COL_S
    #include "lib.h"
bool static_collisions_up(sfRectangleShape *hitbox, sfImage *collision_image);
bool static_collisions_right(
    sfRectangleShape *hitbox, sfImage *collision_image);
bool static_collisions_left(
    sfRectangleShape *hitbox, sfImage *collision_image);
bool static_collisions_down(
    sfRectangleShape *hitbox, sfImage *collision_image);
bool col_hitbox(sfRectangleShape *hitbox1, sfRectangleShape *hitbox2);
bool dynamique_col_up(sfRectangleShape *hit_up, sfRectangleShape *hitbox);
bool dynamique_col_down(sfRectangleShape *hit_down, sfRectangleShape *hitbox);
bool dynamique_col_left(sfRectangleShape *hit_left, sfRectangleShape *hitbox);
bool dynamique_col_right(
    sfRectangleShape *hit_right, sfRectangleShape *hitbox);
void draw_black_rect_on_image(sfRectangleShape* rectangle, sfImage* image);
void check_dynamic_col(npc_t *npc_one, npc_t *npc_two);
#endif
