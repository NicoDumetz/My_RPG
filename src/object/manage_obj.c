/*
** EPITECH PROJECT, 2024
** movements
** File description:
** movements
*/

#include "rpg.h"

void manage_animation_obj(front_obj_t *obj, bool ticks)
{
    if (obj->is_short == false)
        anim_obj_long(obj, obj->offset, ticks);
    if (obj->is_short == true)
        anim_obj_short(obj, obj->offset, ticks);
}

void add_to_inventory(back_obj_t **inventory, front_obj_t *obj)
{
    if (*inventory)
        (*inventory)->prev = obj->in;
    obj->in->next = *inventory;
    *inventory = obj->in;
    obj->in = NULL;
}

void manage_obj(front_obj_t *obj, rpg_t *rpg, heros_t *heros)
{
    if (sprite_is_in_float_rect(obj->sprite,
        sfRectangleShape_getGlobalBounds(heros->npc->hitbox)) &&
        obj->is_pickable && rpg->key_state[sfKeyE]) {
        heros->npc->entity->effect_tab[PICK_HEROS]->active = true;
        if (obj->in)
            add_to_inventory(&(heros->inventory), obj);
        obj->is_active = false;
    }
    if (obj->is_short == false && obj->time_left <= 0)
        obj->is_active = false;
    if (rpg->ticks)
        obj->time_left = obj->time_left - 1;
    return;
}
