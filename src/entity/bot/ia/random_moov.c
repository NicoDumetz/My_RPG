/*
** EPITECH PROJECT, 2024
** random moov
** File description:
** random moov
*/

#include "rpg.h"


static void left_bot(sfVector2f pos, npc_t *npc_act, rpg_t *rpg)
{
    float movement = 50 * rpg->time;

    if (pos.x - movement < 0 ||
        static_collisions_left(npc_act->entity->colbox, wich_img(rpg)))
        return;
    pos.x -= movement;
    npc_act->act_action = MOVE_L;
    sfSprite_setPosition(npc_act->entity->sprite, pos);
}

static void right_bot(sfVector2f pos, npc_t *npc_act, rpg_t *rpg)
{
    float movement = 50 * rpg->time;
    sfVector2f bounds2 = sfRectangleShape_getSize(rpg->heros->npc->hitbox);
    sfFloatRect bounds = sfSprite_getGlobalBounds(wich_back(rpg));

    if (pos.x + bounds2.x + movement > bounds.width ||
        static_collisions_right(
            npc_act->entity->colbox, wich_img(rpg)))
        return;
    pos.x += movement;
    npc_act->act_action = MOVE_R;
    sfSprite_setPosition(npc_act->entity->sprite, pos);
}

static void down_bot(sfVector2f pos, npc_t *npc_act, rpg_t *rpg)
{
    float movement = 50 * rpg->time;
    sfVector2f bounds2 = sfRectangleShape_getSize(rpg->heros->npc->hitbox);
    sfFloatRect bounds = sfSprite_getGlobalBounds(wich_back(rpg));

    if (pos.y + (bounds2.y * 2) + movement > bounds.height ||
        static_collisions_down(npc_act->entity->colbox, wich_img(rpg)))
        return;
    pos.y += movement;
    if (npc_act->act_action == STAND || npc_act->act_action == MOVE_R)
        npc_act->act_action = MOVE_R;
    else
        npc_act->act_action = MOVE_L;
    sfSprite_setPosition(npc_act->entity->sprite, pos);
}

static void up_bot(sfVector2f pos, npc_t *npc_act, rpg_t *rpg)
{
    float movement = 50 * rpg->time;

    if (pos.y - movement < 0 ||
        static_collisions_up(npc_act->entity->colbox, wich_img(rpg)))
        return;
    pos.y -= movement;
    if (npc_act->act_action == STAND || npc_act->act_action == MOVE_R)
        npc_act->act_action = MOVE_R;
    else
        npc_act->act_action = MOVE_L;
    sfSprite_setPosition(npc_act->entity->sprite, pos);
}

void manage_random_moov(npc_t *npc_act, heros_t *heros, rpg_t *rpg)
{
    sfVector2f pos = sfSprite_getPosition(npc_act->entity->sprite);
    int rand_nbr = rand() % 6;

    if (rand_nbr == 0 && npc_act->allowed_dir[RIGHT])
        right_bot(pos, npc_act, rpg);
    if (rand_nbr == 1 && npc_act->allowed_dir[LEFT])
        left_bot(pos, npc_act, rpg);
    if (rand_nbr == 2 && npc_act->allowed_dir[DOWN])
        down_bot(pos, npc_act, rpg);
    if (rand_nbr == 3 && npc_act->allowed_dir[UP])
        up_bot(pos, npc_act, rpg);
    if (rand_nbr > 3)
        npc_act->act_action = STAND;
}
