/*
** EPITECH PROJECT, 2023
** graph.h
** File description:
** macro for CSFML
*/

#include "rpg.h"

void set_box(
    sfRectangleShape *rect, sfFloatRect floatrect, entity_t *entity)
{
    float padded_top = (entity->size.y * floatrect.top) / 100.0;
    float padded_left = (entity->size.x * floatrect.left) / 100.0;
    float padded_right = (entity->size.x * floatrect.width) / 100.0;
    float padded_bottom = (entity->size.y * floatrect.height) / 100.0;
    sfFloatRect pos = sfSprite_getGlobalBounds(entity->sprite);
    sfFloatRect hitbox = {
        pos.left + padded_left,
        pos.top + padded_top,
        entity->size.x - padded_right,
        entity->size.y - padded_bottom
    };

    sfRectangleShape_setSize(
        rect, (sfVector2f){hitbox.width, hitbox.height});
    sfRectangleShape_setPosition(
        rect, (sfVector2f){hitbox.left, hitbox.top});
}

void set_all_box(entity_t *entity, sfRenderWindow *window)
{
    npc_t *npc = (npc_t *)entity->parent;

    if (!npc)
        return;
    set_box(npc->hitbox, npc->hitbox_dim, npc->entity);
    set_box(npc->entity->colbox, npc->entity->colbox_dim, npc->entity);
    for (int i = 0; i <= ATTACK_R; i++) {
        set_box(npc->attbox[i], npc->attbox_dim[i], npc->entity);
        sfRenderWindow_drawRectangleShape(
            window, npc->attbox[i], NULL);
    }
    sfRenderWindow_drawRectangleShape(
        window, npc->entity->colbox, NULL);
    sfRenderWindow_drawRectangleShape(
        window, npc->hitbox, NULL);
}
