/*
** EPITECH PROJECT, 2024
** manage projectil
** File description:
** manage projectile
*/

#include "rpg.h"

void destroy_projectile(projectile_t *p)
{
    if (p != NULL) {
        sfSprite_destroy(p->sprite);
        sfRectangleShape_destroy(p->hitbox);
        free(p);
    }
}

void display_projectiles(npc_t *npc, rpg_t *rpg)
{
    projectile_t *current = npc->projectile;

    if (current != NULL && current->active == 1) {
        sfSprite_setPosition(current->sprite, current->from);
        sfRenderWindow_drawSprite(rpg->window, current->sprite, NULL);
        sfRectangleShape_setPosition(current->hitbox,
        sfSprite_getPosition(current->sprite));
        sfRenderWindow_drawRectangleShape(rpg->window, current->hitbox, NULL);
    }
}

void set_positions_projectile(npc_t *npc_act, heros_t *heros)
{
    sfVector2f pos_heros;
    sfVector2f pos;
    sfFloatRect bound_h = sfSprite_getGlobalBounds(heros->npc->entity->sprite);
    sfFloatRect bounds = sfSprite_getGlobalBounds(npc_act->entity->sprite);
    float dy;
    float dx;
    float angle;

    pos.x = bounds.left + bounds.width / 2.0f;
    pos.y = bounds.top + bounds.height / 2.0f;
    pos_heros.x = bound_h.left + bound_h.width / 2.0f;
    pos_heros.y = bound_h.top + bound_h.height / 2.0f;
    npc_act->projectile->from = pos;
    npc_act->projectile->target = pos_heros;
    dy = pos_heros.y - pos.y;
    dx = pos_heros.x - pos.x;
    angle = atan2(dy, dx);
    angle = angle * 180.0f / M_PI;
    sfSprite_setRotation(npc_act->projectile->sprite, angle);
    sfRectangleShape_setRotation(npc_act->projectile->hitbox, angle);
}

static void rotation_dyna(projectile_t *proj)
{
    float current_angle = sfSprite_getRotation(proj->sprite);
    float additional_angle = 10.f;

    current_angle -= additional_angle;
    sfSprite_setRotation(proj->sprite, current_angle);
    sfRectangleShape_setRotation(proj->hitbox, current_angle);
}

static void colision_projectile(npc_t *npc, heros_t *heros)
{
    if (col_hitbox(npc->projectile->hitbox, heros->npc->hitbox)) {
        if (absorb_hit(heros->skill->skill_tab[SHIELD], heros)) {
            npc->projectile->active = 0;
            return;
        }
        npc->projectile->active = 0;
        heros->npc->pv -= npc->damage;
        heros->npc->entity->effect_tab[BLOOD_HEROS]->active = true;
    }
    if (npc->type == DYNA)
        rotation_dyna(npc->projectile);
}

void moov_projectile(npc_t *npc, rpg_t *rpg)
{
    projectile_t *proj = npc->projectile;
    sfVector2f direction = {proj->target.x - proj->from.x,
    proj->target.y - proj->from.y};
    float length = sqrt(direction.x * direction.x + direction.y * direction.y);
    float speed = proj->speed * rpg->time;
    sfVector2f movement;
    float margin = 15.0f;

    if (npc->type == ARCHERY || npc->type == DYNA)
        colision_projectile(npc, rpg->heros);
    if (length > 0) {
        direction.x /= length;
        direction.y /= length;
        movement = (sfVector2f){direction.x * speed, direction.y * speed};
        proj->from.x += movement.x;
        proj->from.y += movement.y;
        sfSprite_setPosition(proj->sprite, proj->from);
        if (length <= margin)
            proj->active = 0;
    }
}
