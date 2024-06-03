/*
** EPITECH PROJECT, 2023
** graph.h
** File description:
** macro for CSFML
*/

#include "rpg.h"

void destroy_entity(entity_t *entity)
{
    sfSprite_destroy(entity->sprite);
    sfRectangleShape_destroy(entity->colbox);
    if (entity->effect_tab) {
        for (int i = 0; entity->effect_tab[i]; i++)
            destroy_effect(entity->effect_tab[i]);
        free(entity->effect_tab);
    }
    free(entity);
}

sfRectangleShape *init_colbox_rect(void)
{
    sfRectangleShape *hitbox = sfRectangleShape_create();

    sfRectangleShape_setOutlineColor(hitbox, sfYellow);
    sfRectangleShape_setFillColor(hitbox, sfTransparent);
    sfRectangleShape_setOutlineThickness(hitbox, 2);
    return hitbox;
}

entity_t *init_entity_next(entity_t *entity)
{
    entity->effect_tab = NULL;
    entity->type = WHITOUT;
    return (entity);
}

entity_t *init_entity(sfTexture *asset)
{
    entity_t *entity = malloc(sizeof(entity_t));
    sfFloatRect ss_size;

    entity->pos = (sfVector2f){0, 0};
    entity->size = (sfVector2f){0, 0};
    entity->rect_sprite = (sfIntRect){0, 0, 0, 0};
    entity->frame_nbr = 0;
    entity->sprite = sfSprite_create();
    entity->colbox = init_colbox_rect();
    entity->is_reverse = 0;
    entity->next = NULL;
    entity->prev = NULL;
    entity->parent = NULL;
    entity->level = 0;
    sfSprite_setTexture(entity->sprite, asset, sfTrue);
    entity->simple_action = (sfVector2i){1, 0};
    entity->colbox_dim = (sfFloatRect){0, 0, 0, 0};
    ss_size = sfSprite_getGlobalBounds(entity->sprite);
    entity->sprite_sheet_size = (sfVector2f){ss_size.width, ss_size.height};
    return init_entity_next(entity);
}
