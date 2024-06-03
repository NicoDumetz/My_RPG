/*
** EPITECH PROJECT, 2023
** graph.h
** File description:
** macro for CSFML
*/

#include "rpg.h"

static void where_drop(npc_t *curr, biome_t *biome)
{
    sfVector2f center = curr->entity->pos;
    object_drop_t to_drop = NOTHING + rand() % (OBJ_COUNT - NOTHING);

    create_front_obj(
            DEATH, biome->text_tab, &(biome->obj_list),
            (sfVector2f){center.x + 20, center.y + 25});
    create_front_obj(
            to_drop, biome->text_tab,
            &(biome->obj_list),
            (sfVector2f){center.x + 55, center.y + 25});
}

void check_is_alive(npc_t **curr, npc_t **head, biome_t *biome)
{
    if ((*curr)->is_alive == false) {
        if ((*curr)->entity->pos.x != 0 && (*curr)->entity->pos.y != 0)
            where_drop(*curr, biome);
        remove_entity_from_list((*curr)->entity, biome);
        if ((*curr)->prev == NULL)
            *head = (*curr)->next;
        if ((*curr)->prev)
            (*curr)->prev->next = (*curr)->next;
        if ((*curr)->next)
            (*curr)->next->prev = (*curr)->prev;
        destroy_npc(*curr);
        *curr = NULL;
        biome->nbr_bot = biome->nbr_bot - 1;
    }
}

npc_t *bot_loop_sort(
    npc_t *curr, biome_t *biome, sfRenderWindow *window, int i)
{
    npc_t *next = curr->next;

    check_is_alive(&curr, &(biome->bot_data->bot_list[i]), biome);
    if (curr != NULL)
        put_entity_in_view_list(curr->entity, biome, window);
    return next;
}

void check_is_active(front_obj_t **curr, front_obj_t **head, biome_t *biome)
{
    if ((*curr)->is_active == false) {
        if ((*curr)->prev == NULL)
            *head = (*curr)->next;
        if ((*curr)->prev)
            (*curr)->prev->next = (*curr)->next;
        if ((*curr)->next)
            (*curr)->next->prev = (*curr)->prev;
        if ((*curr)->in)
            destroy_front_obj(*curr, true);
        else
            destroy_front_obj(*curr, false);
        *curr = NULL;
        biome->nbr_bot = biome->nbr_bot - 1;
    }
}

front_obj_t *obj_loop_sort(
    front_obj_t *curr, biome_t *biome, rpg_t *rpg)
{
    front_obj_t *next = curr->next;

    check_is_active(&curr, &(biome->obj_list), biome);
    if (curr != NULL) {
        manage_obj(curr, rpg, rpg->heros);
        manage_animation_obj(curr, rpg->ticks);
        sfRenderWindow_drawSprite(rpg->window, curr->sprite, NULL);
    }
    return next;
}

static void sort_deco_in_view_list(biome_t *biome, sfRenderWindow *window)
{
    for (int i = 0; i <= MINE_DECO; i++)
        for (int j = 0; biome->deco_data->deco_entity[i][j]; j++)
            put_entity_in_view_list(
                biome->deco_data->deco_entity[i][j], biome, window);
}

void sort_entity_in_view(
    biome_t *biome, sfRenderWindow *window, heros_t *heros, rpg_t *rpg)
{
    put_entity_in_view_list(heros->npc->entity, biome, window);
    if (biome->quest_giver)
        put_entity_in_view_list(
            biome->quest_giver->npc->entity, biome, window);
    for (front_obj_t *curr = biome->obj_list; curr;) {
        curr = obj_loop_sort(curr, biome, rpg);
    }
    if (biome->deco_data)
        sort_deco_in_view_list(biome, window);
    for (int i = 0; i <= ARCHER; i++) {
        for (npc_t *curr =
            biome->bot_data->bot_list[i]; curr;) {
            curr = bot_loop_sort(curr, biome, window, i);
        }
    }
}
