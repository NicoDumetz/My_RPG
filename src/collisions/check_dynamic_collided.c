/*
** EPITECH PROJECT, 2023
** graph.h
** File description:
** macro for CSFML
*/

#include "rpg.h"

void which_dir_block(
    npc_t *npc_one, npc_t *npc_two,
    sfRectangleShape *rect_one, sfRectangleShape *rect_two)
{
    if (dynamique_col_right(rect_one, rect_two)) {
        npc_one->allowed_dir[RIGHT] = false;
        npc_two->allowed_dir[LEFT] = false;
    }
    if (dynamique_col_left(rect_one, rect_two)) {
        npc_one->allowed_dir[LEFT] = false;
        npc_two->allowed_dir[RIGHT] = false;
    }
    if (dynamique_col_up(rect_one, rect_two)) {
        npc_one->allowed_dir[UP] = false;
        npc_two->allowed_dir[DOWN] = false;
    }
    if (dynamique_col_down(rect_one, rect_two)) {
        npc_one->allowed_dir[DOWN] = false;
        npc_two->allowed_dir[UP] = false;
    }
}

void check_dynamic_col(npc_t *npc_one, npc_t *npc_two)
{
    sfRectangleShape *rect_one = npc_one->entity->colbox;
    sfRectangleShape *rect_two = npc_two->entity->colbox;

    if (col_hitbox(rect_one, rect_two)) {
        which_dir_block(npc_one, npc_two, rect_one, rect_two);
    }
}
