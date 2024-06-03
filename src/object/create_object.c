/*
** EPITECH PROJECT, 2024
** movements
** File description:
** movements
*/

#include "rpg.h"

void destroy_back_obj(back_obj_t *back_obj)
{
    sfSprite_destroy(back_obj->sprite);
    free(back_obj);
}

void destroy_front_obj(front_obj_t *front_obj, bool with_back)
{
    destroy_entity(front_obj->entity);
    if (with_back && front_obj->in)
        destroy_back_obj(front_obj->in);
    free(front_obj);
}

back_obj_t *create_back_obj(object_drop_t type, sfTexture **text_tab)
{
    back_obj_t *back_obj = malloc(sizeof(back_obj_t));

    back_obj->next = NULL;
    back_obj->prev = NULL;
    back_obj->sprite = sfSprite_create();
    sfSprite_setTexture(back_obj->sprite,
        text_tab[obj_tab[type].text_id_back], sfTrue);
        back_obj->data = NULL;
    return (back_obj);
}

void put_obj_in_list(front_obj_t *to_put, front_obj_t **list)
{
    if (*list)
        (*list)->prev = to_put;
    to_put->next = *list;
    *list = to_put;
}

static void create_front_obj_next(front_obj_t *front_obj, object_drop_t type)
{
    front_obj->time_left = obj_tab[type].time_left;
    front_obj->entity->simple_action = obj_tab[type].offset;
    set_offset(front_obj->entity, obj_tab[type].rect_quad);
    sfSprite_setTextureRect(
        front_obj->entity->sprite, front_obj->entity->rect_sprite);
}

front_obj_t *create_front_obj(
    object_drop_t type, sfTexture **text_tab,
    front_obj_t **obj_list, sfVector2f pos)
{
    front_obj_t *front_obj = malloc(sizeof(front_obj_t));

    front_obj->entity = init_entity(text_tab[obj_tab[type].text_id_front]);
    front_obj->is_pickable = obj_tab[type].is_pickable;
    front_obj->is_short = obj_tab[type].is_short;
    front_obj->next = NULL;
    front_obj->prev = NULL;
    front_obj->entity->parent = front_obj;
    front_obj->entity->type = OBJ;
    if (obj_tab[type].text_id_back >= 0)
        front_obj->in = create_back_obj(type, text_tab);
    else
        front_obj->in = NULL;
    front_obj->is_active = true;
    sfSprite_setPosition(front_obj->entity->sprite, pos);
    create_front_obj_next(front_obj, type);
    put_obj_in_list(front_obj, obj_list);
    return (front_obj);
}
