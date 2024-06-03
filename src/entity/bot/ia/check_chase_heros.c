/*
** EPITECH PROJECT, 2023
** graph.h
** File description:
** macro for CSFML
*/

#include "rpg.h"

sfVector2f get_center_of_rect(sfFloatRect rect)
{
    sfVector2f center;

    center.x = rect.left + rect.width / 2.0f;
    center.y = rect.top + rect.height / 2.0f;
    return center;
}

float calculate_distance(sfVector2f point1, sfVector2f point2)
{
    float dx = point2.x - point1.x;
    float dy = point2.y - point1.y;

    return sqrt(dx * dx + dy * dy);
}

void check_chase_heros(npc_t *to_check, heros_t *heros)
{
    sfFloatRect rect_hitbox_npc =
        sfRectangleShape_getGlobalBounds(to_check->hitbox);
    sfFloatRect rect_hitbox_hero =
        sfRectangleShape_getGlobalBounds(heros->npc->hitbox);
    sfVector2f mid_npc = get_center_of_rect(rect_hitbox_npc);
    sfVector2f mid_heros = get_center_of_rect(rect_hitbox_hero);

    if (calculate_distance(mid_npc, mid_heros) <= to_check->view)
        to_check->in_chase = true;
}
