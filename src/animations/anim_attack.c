/*
** EPITECH PROJECT, 2023
** graph.h
** File description:
** macro for CSFML
*/

#include "rpg.h"

static bool is_attack_condition_met(npc_t *npc, float offset_x)
{
    int sprite_center_x = (int)((npc->entity->size.x * offset_x) / 2);
    int sprite_left = (int)(npc->entity->rect_sprite.left);

    if (sprite_center_x == sprite_left && npc->type != ARCHERY)
        return true;
    if ((sprite_left == 384 || sprite_left == 1728) && npc->type == DYNA)
        return true;
    return false;
}

void manage_ticks_attack(npc_t *npc, sfVector2i offset)
{
    npc->end_attack = false;
    npc->entity->rect_sprite.left += npc->entity->size.x;
    if (is_attack_condition_met(npc, offset.x))
        npc->cur_attack = true;
    if (npc->entity->rect_sprite.left >= npc->entity->size.x * offset.x) {
        npc->is_attack = false;
        npc->cur_attack = false;
        npc->end_attack = true;
        npc->entity->rect_sprite.left = 0;
        if (npc->type == EXPLOSIVE)
            npc->cur_attack = true;
        return;
    }
    sfSprite_setTextureRect(npc->entity->sprite, npc->entity->rect_sprite);
}

void reverse_sprite_attack(npc_t *npc, sfVector2i offset, bool ticks)
{
    sfVector2f origin = sfSprite_getOrigin(npc->entity->sprite);

    if (!npc->entity->is_reverse) {
        sfSprite_setScale(npc->entity->sprite, (sfVector2f){-1, 1});
        sfSprite_setOrigin(npc->entity->sprite, (sfVector2f){
                npc->entity->size.x - origin.x, origin.y});
        npc->entity->is_reverse = 1;
    }
    npc->entity->rect_sprite.top = ABS(offset.y) * npc->entity->size.y;
    if (ticks)
        manage_ticks_attack(npc, offset);
}

void right_sprite_attack(npc_t *npc, sfVector2i offset, bool ticks)
{
    sfVector2f origin = sfSprite_getOrigin(npc->entity->sprite);

    if (npc->entity->is_reverse) {
        sfSprite_setScale(npc->entity->sprite, (sfVector2f){1, 1});
        sfSprite_setOrigin(npc->entity->sprite, (sfVector2f){0, origin.y});
        npc->entity->is_reverse = 0;
    }
    npc->entity->rect_sprite.top = ABS(offset.y) * npc->entity->size.y;
    if (ticks)
        manage_ticks_attack(npc, offset);
}

void anim_attack(npc_t *npc, sfVector2i offset, bool ticks)
{
    if (offset.y >= 0)
        right_sprite_attack(npc, offset, ticks);
    else
        reverse_sprite_attack(npc, offset, ticks);
}
