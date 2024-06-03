/*
** EPITECH PROJECT, 2023
** game
** File description:
** rpg.h
*/

#include "rpg.h"

/*
typedef struct fire_ball_s {
    int level;
    int stamina;
} fire_ball_t;
*/

fire_ball_t fireball_tab[] = {
    {0},
    {80},
    {60},
    {40},
};

void destroy_fire_ball(fire_ball_t *fire_ball)
{
    free(fire_ball);
}

static int calc_angle(sfVector2f pos, sfVector2f pos_final)
{
    float dy;
    float dx;
    float angle;

    dy = pos_final.y - pos.y;
    dx = pos_final.x - pos.x;
    angle = atan2(dy, dx);
    angle = angle * 180.0f / M_PI;
    return angle;
}

void set_positions_fire_ball(npc_t *npc_act, sfVector2f pos_final)
{
    sfVector2f pos;
    sfFloatRect bounds = sfSprite_getGlobalBounds(npc_act->entity->sprite);
    float angle;

    pos.x = bounds.left + bounds.width / 2.0f;
    pos.y = bounds.top + bounds.height / 2.0f;
    npc_act->projectile->target = pos_final;
    angle = calc_angle(pos, pos_final);
    if (angle >= -90.0f && angle <= 90.0f)
        pos.y -= 20;
    else
        pos.y += 50;
    if (angle >= 0.0f && angle <= 180.0f)
        pos.x += 50;
    else
        pos.x -= 30;
    angle = calc_angle(pos, pos_final);
    npc_act->projectile->from = pos;
    sfSprite_setRotation(npc_act->projectile->sprite, angle);
    sfRectangleShape_setRotation(npc_act->projectile->hitbox, angle);
}

static void set_direction_fire(heros_t *heros, rpg_t *rpg)
{
    sfVector2f spr_pos = sfSprite_getPosition(heros->npc->entity->sprite);
    sfFloatRect bounds = sfSprite_getGlobalBounds(heros->npc->entity->sprite);
    sfVector2f pos = {spr_pos.x + bounds.width / 2.0f,
    spr_pos.y + bounds.height / 2.0f};

    if (rpg->key_state[sfKeyQ])
        pos = (sfVector2f){pos.x - 400, pos.y + 50};
    if (rpg->key_state[sfKeyD] || heros->npc->act_action == STAND)
        pos = (sfVector2f){pos.x + 400, pos.y - 20};
    if (rpg->key_state[sfKeyZ])
        pos = (sfVector2f){pos.x - 30, pos.y - 400};
    if (rpg->key_state[sfKeyS])
        pos = (sfVector2f){pos.x + 50, pos.y + 400};
    set_positions_fire_ball(heros->npc, pos);
    heros->npc->projectile->active = 1;
    sfSprite_setPosition(heros->npc->projectile->sprite,
    heros->npc->projectile->from);
    sfRectangleShape_setPosition(heros->npc->projectile->hitbox,
        sfSprite_getPosition(heros->npc->projectile->sprite));
}

void fire_ball_function(heros_t *heros, rpg_t *rpg, void *skill_data)
{
    fire_ball_t *data = (fire_ball_t *)skill_data;

    if (heros->stamina > data->stamina &&
        heros->npc->projectile->active == 0) {
        launch_particules(rpg);
        heros->stamina -= data->stamina;
        set_direction_fire(heros, rpg);
    }
}
