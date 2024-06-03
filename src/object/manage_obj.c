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

static void set_obj_scale(inventory_t *inventory, back_obj_t *obj)
{
    float min_slot = (inventory->slot_rect.width);
    sfFloatRect rect_obj = sfSprite_getLocalBounds(obj->sprite);
    float min_obj = (rect_obj.width > rect_obj.height) ?
    rect_obj.width : rect_obj.height;
    float ratio = min_slot / min_obj;

    sfSprite_setScale(obj->sprite, (sfVector2f){ratio, ratio});
}

void delete_from_list(back_obj_t *obj, back_obj_t **list)
{
    back_obj_t *prev = obj->prev;
    back_obj_t *next = obj->next;

    if (prev == NULL) {
        *list = next;
        if (next)
            next->prev = prev;
    } else {
        prev->next = next;
        if (next)
            next->prev = prev;
    }
    obj->prev = NULL;
    obj->next = NULL;
}

bool add_to_inventory(back_obj_t **inventory, front_obj_t *obj, rpg_t *rpg)
{
    button_t *slot = get_free_slot(rpg->inventory.slot, NUM_SLOT);

    if (slot == NULL)
        return true;
    slot->child = obj->in;
    set_obj_scale(&rpg->inventory, obj->in);
    if (*inventory)
        (*inventory)->prev = obj->in;
    obj->in->next = *inventory;
    *inventory = obj->in;
    obj->in = NULL;
    return false;
}

void manage_obj(front_obj_t *obj, rpg_t *rpg, heros_t *heros)
{
    bool obj_state = false;

    if (sprite_is_in_float_rect(obj->sprite,
        sfRectangleShape_getGlobalBounds(heros->npc->hitbox)) &&
        obj->is_pickable && rpg->key_state[sfKeyE]) {
        heros->npc->entity->effect_tab[PICK_HEROS]->active = true;
        if (obj->in)
            obj_state = add_to_inventory(&(heros->inventory), obj, rpg);
        obj->is_active = obj_state;
    }
    if (obj->is_short == false && obj->time_left <= 0)
        obj->is_active = false;
    if (rpg->ticks)
        obj->time_left = obj->time_left - 1;
    return;
}
