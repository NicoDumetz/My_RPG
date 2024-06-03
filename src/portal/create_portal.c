/*
** EPITECH PROJECT, 2024
** movements
** File description:
** movements
*/

#include "rpg.h"

void destroy_portal(portal_t *portal)
{
    sfCircleShape_destroy(portal->zone);
    free(portal);
}

sfCircleShape *create_portal_zone(sfVector2f pos)
{
    sfCircleShape *circle = sfCircleShape_create();

    sfCircleShape_setFillColor(circle, sfTransparent);
    sfCircleShape_setOutlineColor(circle, sfGreen);
    sfCircleShape_setOutlineThickness(circle, 10);
    sfCircleShape_setRadius(circle, 100);
    sfCircleShape_setPosition(circle, pos);
    return (circle);
}

portal_t *create_portal(sfVector2f pos, int scene)
{
    portal_t *portal = malloc(sizeof(portal_t));

    portal->is_open = true;
    portal->scene = scene;
    portal->pos = pos;
    portal->zone = create_portal_zone(pos);
    return portal;
}
