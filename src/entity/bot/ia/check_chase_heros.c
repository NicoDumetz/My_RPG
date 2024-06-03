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

static bool is_pixel_black(sfImage *img, sfVector2f pos)
{
    sfColor color = sfImage_getPixel(img, (unsigned int)pos.x,
    (unsigned int)pos.y);

    if (color.r == 0 && color.g == 0 && color.b == 0 && color.a > 200)
        return true;
    return false;
}

bool raycasting_check(npc_t *to_check, heros_t *heros, sfImage *img)
{
    sfFloatRect rect_npc = sfRectangleShape_getGlobalBounds
    (to_check->hitbox);
    sfFloatRect rect_heros = sfRectangleShape_getGlobalBounds
    (heros->npc->hitbox);
    sfVector2f center_npc = get_center_of_rect(rect_npc);
    sfVector2f center_heros = get_center_of_rect(rect_heros);
    float dx = center_heros.x - center_npc.x;
    float dy = center_heros.y - center_npc.y;
    float distance = sqrt(dx * dx + dy * dy);
    float step = 1.0f;
    float t;
    sfVector2f pos;

    for (float i = 0; i <= distance; i += step) {
        t = i / distance;
        pos = (sfVector2f){center_npc.x + t * dx, center_npc.y + t * dy};
        if (is_pixel_black(img, pos))
            return true;
    }
    return false;
}

bool check_chase_heros(npc_t *to_check, heros_t *heros, sfImage *img)
{
    sfBool chase = false;
    sfFloatRect rect_hitbox_npc =
        sfRectangleShape_getGlobalBounds(to_check->hitbox);
    sfFloatRect rect_hitbox_hero =
        sfRectangleShape_getGlobalBounds(heros->npc->hitbox);
    sfVector2f mid_npc = get_center_of_rect(rect_hitbox_npc);
    sfVector2f mid_heros = get_center_of_rect(rect_hitbox_hero);

    if (calculate_distance(mid_npc, mid_heros) <= to_check->view)
        chase = true;
    if (raycasting_check(to_check, heros, img))
        chase = false;
    return chase;
}
