/*
** EPITECH PROJECT, 2024
** chase
** File description:
** chase
*/

#include "rpg.h"

static void left_chase(npc_t *npc_act, sfVector2f movement_pos, rpg_t *rpg)
{
    sfVector2f pos = sfSprite_getPosition(npc_act->entity->sprite);

    if (pos.x - (-1 * movement_pos.x) < 0 ||
        static_collisions_left(npc_act->entity->colbox, wich_img(rpg)))
        return;
    pos.x += movement_pos.x;
    npc_act->act_action = MOVE_L;
    sfSprite_setPosition(npc_act->entity->sprite, pos);
}

static void right_chase(npc_t *npc_act, sfVector2f movement_pos, rpg_t *rpg)
{
    sfVector2f bounds2 = sfRectangleShape_getSize(rpg->heros->npc->hitbox);
    sfFloatRect bounds = sfSprite_getGlobalBounds(wich_back(rpg));
    sfVector2f pos = sfSprite_getPosition(npc_act->entity->sprite);

    if (pos.x + bounds2.x + (-1 * movement_pos.x) > bounds.width ||
        static_collisions_right(
            npc_act->entity->colbox, wich_img(rpg)))
        return;
    pos.x += movement_pos.x;
    npc_act->act_action = MOVE_R;
    sfSprite_setPosition(npc_act->entity->sprite, pos);
}

static void up_chase(npc_t *npc_act, sfVector2f movement_pos, rpg_t *rpg)
{
    sfVector2f pos = sfSprite_getPosition(npc_act->entity->sprite);

    if (pos.y + movement_pos.y < 0 ||
        static_collisions_up(npc_act->entity->colbox, wich_img(rpg)))
        return;
    pos.y += movement_pos.y;
    if (npc_act->act_action == STAND || npc_act->act_action == MOVE_R)
        npc_act->act_action = MOVE_R;
    else
        npc_act->act_action = MOVE_L;
    sfSprite_setPosition(npc_act->entity->sprite, pos);
}

static void down_chase(npc_t *npc_act, sfVector2f movement_pos, rpg_t *rpg)
{
    sfVector2f bounds2 = sfRectangleShape_getSize(rpg->heros->npc->hitbox);
    sfFloatRect bounds = sfSprite_getGlobalBounds(wich_back(rpg));
    sfVector2f pos = sfSprite_getPosition(npc_act->entity->sprite);

    if (pos.y + (bounds2.y * 2) + (-1 * movement_pos.y) > bounds.height ||
        static_collisions_down(npc_act->entity->colbox, wich_img(rpg)))
        return;
    pos.y += movement_pos.y;
    if (npc_act->act_action == STAND || npc_act->act_action == MOVE_R)
        npc_act->act_action = MOVE_R;
    else
        npc_act->act_action = MOVE_L;
    sfSprite_setPosition(npc_act->entity->sprite, pos);
}

static void move_ia_to_heros(
    npc_t *npc_act, sfVector2f movement_pos, rpg_t *rpg)
{
    if (movement_pos.y < 0 && npc_act->allowed_dir[UP])
        up_chase(npc_act, movement_pos, rpg);
    if (movement_pos.y > 0 && npc_act->allowed_dir[DOWN])
        down_chase(npc_act, movement_pos, rpg);
    if (movement_pos.x < 0 && npc_act->allowed_dir[LEFT])
        left_chase(npc_act, movement_pos, rpg);
    if (movement_pos.x > 0 && npc_act->allowed_dir[RIGHT])
        right_chase(npc_act, movement_pos, rpg);
}

static void chasing(npc_t *npc_act, rpg_t *rpg)
{
    sfVector2f pos_heros = rpg->heros->npc->entity->pos;
    sfVector2f pos = sfSprite_getPosition(npc_act->entity->sprite);
    float movement = 75 * rpg->time;
    sfVector2f direction;
    float distance;
    sfVector2f movement_pos;

    direction.x = pos_heros.x - pos.x;
    direction.y = pos_heros.y - pos.y;
    distance = sqrt(direction.x * direction.x + direction.y * direction.y);
    direction.x /= distance;
    direction.y /= distance;
    movement_pos.x = direction.x * movement;
    movement_pos.y = direction.y * movement;
    move_ia_to_heros(npc_act, movement_pos, rpg);
}

void manage_chase(npc_t *npc_act, rpg_t *rpg, heros_t *heros)
{
    int chase = 0;
    int stand = 0;

    manage_attack_bot(npc_act, heros, &chase, &stand);
    if (stand == 1)
        npc_act->act_action = STAND;
    if (npc_act->is_attack == false && chase == 0 && stand == 0)
        chasing(npc_act, rpg);
}
