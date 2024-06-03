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
        p->sprite = NULL;
        sfRectangleShape_destroy(p->hitbox);
        p->hitbox = NULL;
        free(p);
        p = NULL;
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

static bool check_pixel_angle(sfVector2f top_mid, sfVector2u img_size,
    sfImage *collision_image)
{
    unsigned int x = (unsigned int)top_mid.x;
    unsigned int y = (unsigned int)top_mid.y;
    sfColor color;

    if (x < img_size.x && y < img_size.y) {
        color = sfImage_getPixel(collision_image, x, y);
        if (color.r == 0 && color.g == 0 && color.b == 0 && color.a == 255)
            return true;
    }
    return false;
}

static bool static_collisions_angle(sfRectangleShape *hitbox,
    sfImage *collision_image)
{
    sfVector2u img_size = sfImage_getSize(collision_image);
    sfVector2f size = sfRectangleShape_getSize(hitbox);
    sfVector2f pos = sfRectangleShape_getPosition(hitbox);
    sfVector2f origin = sfRectangleShape_getOrigin(hitbox);
    float angle = sfRectangleShape_getRotation(hitbox) * (M_PI / 180.0);
    sfVector2f center = {pos.x + origin.x, pos.y + origin.y};
    sfVector2f top_mid;

    top_mid.x = center.x + (size.x / 2.0f) *
    cos(angle) - (size.y / 2.0f) * sin(angle);
    top_mid.y = center.y + (size.x / 2.0f) *
    sin(angle) + (size.y / 2.0f) * cos(angle);
    return check_pixel_angle(top_mid, img_size, collision_image);
}

static void check_target(sfVector2f direction, float length,
    projectile_t *proj, rpg_t *rpg)
{
    float margin = 15.0f;
    sfVector2f movement;
    float speed = proj->speed * rpg->time;

    direction.x /= length;
    direction.y /= length;
    movement = (sfVector2f){direction.x * speed, direction.y * speed};
    proj->from.x += movement.x;
    proj->from.y += movement.y;
    sfSprite_setPosition(proj->sprite, proj->from);
    if (length <= margin)
        proj->active = 0;
}

void moov_projectile(npc_t *npc, rpg_t *rpg)
{
    projectile_t *proj = npc->projectile;
    sfVector2f direction = {proj->target.x - proj->from.x,
    proj->target.y - proj->from.y};
    float length = sqrt(direction.x * direction.x + direction.y * direction.y);

    if (static_collisions_angle(npc->projectile->hitbox, wich_img(rpg))) {
        npc->projectile->active = 0;
        return;
    }
    if (npc->type == ARCHERY || npc->type == DYNA)
        colision_projectile(npc, rpg->heros);
    if (length > 0)
        check_target(direction, length, proj, rpg);
}
