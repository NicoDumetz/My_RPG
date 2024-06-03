/*
** EPITECH PROJECT, 2023
** graph.h
** File description:
** macro for CSFML
*/

#include "rpg.h"

static void reset_npc(entity_t *entity, sfRenderWindow *window)
{
    npc_t *npc = NULL;

    if (entity->type == NPC) {
        npc = (npc_t *)entity->parent;
        set_all_box(entity, window);
        for (int i = 0; i < 4; i++)
            npc->allowed_dir[i] = true;
    }
}

static void begin_from_head(entity_t *head, entity_t *entity)
{
    entity_t *curr = head->next;

    for (; curr; curr = curr->next) {
        if (entity->level <= curr->level) {
            entity->prev = curr->prev;
            entity->next = curr;
            curr->prev->next = entity;
            curr->prev = entity;
            return;
        }
    }
}

static void begin_from_tail(entity_t *tail, entity_t *entity)
{
    entity_t *curr = tail->prev;

    for (; curr; curr = curr->prev) {
        if (entity->level >= curr->level) {
            entity->next = curr->next;
            entity->prev = curr;
            curr->next->prev = entity;
            curr->next = entity;
            return;
        }
    }
}

static void which_side_to_put_entity(entity_t *entity, biome_t *biome)
{
    int diff_head = entity->level - biome->entity_in_view_head->level;
    int diff_tail = biome->entity_in_view_tail->level - entity->level;

    if (diff_head < diff_tail)
        begin_from_head(biome->entity_in_view_head, entity);
    else if (diff_head > diff_tail)
        begin_from_tail(biome->entity_in_view_tail, entity);
}

void remove_entity_from_list(entity_t *entity, biome_t *biome)
{
    if (entity == NULL || biome == NULL)
        return;
    if (entity == biome->entity_in_view_tail) {
        if (entity->prev)
            entity->prev->next = NULL;
        biome->entity_in_view_tail = entity->prev;
    }
    if (entity == biome->entity_in_view_head) {
        if (entity->next)
            entity->next->prev = NULL;
        biome->entity_in_view_head = entity->next;
    }
    if (entity->prev != NULL)
        entity->prev->next = entity->next;
    if (entity->next != NULL)
        entity->next->prev = entity->prev;
    entity->prev = NULL;
    entity->next = NULL;
}

void insert_entity_in_view_list(entity_t *entity, biome_t *biome)
{
    remove_entity_from_list(entity, biome);
    if (biome->entity_in_view_head == NULL) {
        biome->entity_in_view_head = entity;
        biome->entity_in_view_tail = entity;
        return;
    }
    if (entity->level <= biome->entity_in_view_head->level) {
        entity->next = biome->entity_in_view_head;
        biome->entity_in_view_head->prev = entity;
        biome->entity_in_view_head = entity;
    } else if (entity->level >= biome->entity_in_view_tail->level) {
        entity->prev = biome->entity_in_view_tail;
        biome->entity_in_view_tail->next = entity;
        biome->entity_in_view_tail = entity;
    } else {
        which_side_to_put_entity(entity, biome);
    }
}

void check_entity_insert_in_view_list(entity_t *entity, biome_t *biome)
{
    sfFloatRect col_data = sfRectangleShape_getGlobalBounds(entity->colbox);

    entity->level = col_data.top + col_data.height;
    if ((entity->next == NULL && entity->prev == NULL) ||
        (entity->next && entity->next->level < entity->level) ||
        (entity->prev && entity->prev->level > entity->level)) {
        insert_entity_in_view_list(entity, biome);
    }
}

void put_entity_in_view_list(
    entity_t *entity, biome_t *biome, sfRenderWindow *window)
{
    const sfView *view = sfRenderWindow_getView(window);
    sfVector2f center = sfView_getCenter(view);
    sfVector2f size = sfView_getSize(view);
    sfFloatRect rect;

    entity->pos = sfSprite_getPosition(entity->sprite);
    rect.left = center.x - size.x / 2;
    rect.top = center.y - size.y / 2;
    rect.width = size.x;
    rect.height = size.y;
    if (sprite_is_in_float_rect(entity->sprite, rect) == sfTrue) {
        reset_npc(entity, window);
        check_entity_insert_in_view_list(entity, biome);
    } else
        remove_entity_from_list(entity, biome);
}
