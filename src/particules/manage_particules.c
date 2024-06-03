/*
** EPITECH PROJECT, 2024
** manage particules
** File description:
** manage particules
*/

#include "rpg.h"


void init_particules(rpg_t *rpg)
{
    rpg->part = malloc(sizeof(all_part_t));

    rpg->part->vertex = sfVertexArray_create();
    sfVertexArray_setPrimitiveType(rpg->part->vertex, sfQuads);
    rpg->part->clock = sfClock_create();
    for (int i = 0; i < NUM_PARTICULES; ++i) {
        rpg->part->particules[i].pos = (sfVector2f){0.0f, 0.0f};
        rpg->part->particules[i].velo = (sfVector2f){0.0f, 0.0f};
        rpg->part->particules[i].lifetime = 0.0f;
        rpg->part->particules[i].active = 0;
    }
    rpg->part->active = 0;
}

void destroy_particules(rpg_t *rpg)
{
    if (rpg->part != NULL) {
        if (rpg->part->vertex != NULL)
            sfVertexArray_destroy(rpg->part->vertex);
        if (rpg->part->clock != NULL)
            sfClock_destroy(rpg->part->clock);
        free(rpg->part);
        rpg->part = NULL;
    }
}

static void add_particule_to_array(rpg_t *rpg, int i)
{
    float size = 2.5f;
    sfVector2f pos = rpg->part->particules[i].pos;
    sfColor color = sfColor_fromRGBA(255, rand() % 256, 0, 255);
    sfVertex top_left = {{pos.x - size / 2, pos.y - size / 2}, color, {0, 0}};
    sfVertex top_right = {{pos.x + size / 2, pos.y - size / 2}, color, {0, 0}};
    sfVertex bottom_right = {{pos.x + size / 2, pos.y + size / 2}, color, {0, 0}};
    sfVertex bottom_left = {{pos.x - size / 2, pos.y + size / 2}, color, {0, 0}};

    sfVertexArray_append(rpg->part->vertex, top_left);
    sfVertexArray_append(rpg->part->vertex, top_right);
    sfVertexArray_append(rpg->part->vertex, bottom_right);
    sfVertexArray_append(rpg->part->vertex, bottom_left);
}

static void display_particules(rpg_t *rpg)
{
    if (rpg->part->active == 0)
        return;
    sfVertexArray_clear(rpg->part->vertex);
    for (int i = 0; i < NUM_PARTICULES; i++) {
        if (rpg->part->particules[i].active == 1)
            add_particule_to_array(rpg, i);
    }
    sfRenderWindow_drawVertexArray(rpg->window, rpg->part->vertex, NULL);
}

static void set_particules(all_part_t *part, int i, sfVector2f size_rect,
    sfVector2f pos_rect)
{
    part->particules[i].pos.x = pos_rect.x + (rand() % (int)size_rect.x);
    part->particules[i].pos.y = pos_rect.y + (rand() % (int)size_rect.y);
    part->particules[i].velo.x = ((float)rand() / RAND_MAX - 0.5f) * 20.0f;
    part->particules[i].velo.y = -100.0f - ((float)rand() / RAND_MAX) * 50.0f;
    part->particules[i].lifetime = 5.0f;
    part->particules[i].active = 1;
}

void launch_particules(rpg_t *rpg)
{
    all_part_t *part = rpg->part;
    sfVector2f pos_rect = sfRectangleShape_getPosition(rpg->heros->npc->hitbox);
    sfVector2f size_rect = sfRectangleShape_getSize(rpg->heros->npc->hitbox);

    part->active = 1;
    for (int i = 0; i < NUM_PARTICULES; i++)
        set_particules(part, i, size_rect, pos_rect);
}

static void move_particules(all_part_t *part, int i, float delta_time)
{
    part->particules[i].lifetime -= delta_time;
    if (part->particules[i].lifetime <= 0)
        part->particules[i].active = 0;
    part->particules[i].pos.x += part->particules[i].velo.x * delta_time;
    part->particules[i].pos.y += part->particules[i].velo.y * delta_time;
}

void update_part(rpg_t *rpg)
{
    all_part_t *part = rpg->part;
    float delta_time = sfTime_asSeconds(sfClock_restart(part->clock));
    int compt = 0;

    for (int i = 0; i < NUM_PARTICULES; i++) {
        if (part->particules[i].active == 1)
            move_particules(part, i, delta_time);
    }
    for (int i = 0; i < NUM_PARTICULES; i++)
        compt = part->particules[i].active == 0 ? compt + 1 : compt;
    if (compt == NUM_PARTICULES)
        part->active = 0;
}

void manage_particules(rpg_t *rpg)
{
    update_part(rpg);
    display_particules(rpg);
}