/*
** EPITECH PROJECT, 2024
** movements
** File description:
** movements
*/

#include "rpg.h"
#include <SFML/Graphics/Sprite.h>

void destroy_back_obj(back_obj_t *back_obj)
{
    sfSprite_destroy(back_obj->sprite);
    back_obj->sprite = NULL;
    free(back_obj);
    back_obj = NULL;
}

void destroy_front_obj(front_obj_t *front_obj, bool with_back)
{
    sfSprite_destroy(front_obj->sprite);
    front_obj->sprite = NULL;
    if (with_back && front_obj->in) {
        destroy_back_obj(front_obj->in);
        front_obj->in = NULL;
    }
    free(front_obj);
    front_obj = NULL;
}

back_obj_t *create_back_obj(object_drop_t type, sfTexture **text_tab)
{
    back_obj_t *back_obj = malloc(sizeof(back_obj_t));

    back_obj->next = NULL;
    back_obj->prev = NULL;
    back_obj->id = type;
    back_obj->usage = obj_tab[type].usage;
    back_obj->add_live = obj_tab[type].add_live;
    back_obj->add_stamina = obj_tab[type].add_stamina;
    back_obj->add_xp = obj_tab[type].add_xp;
    back_obj->multi_speed = obj_tab[type].multi_speed;
    back_obj->multi_attack = obj_tab[type].multi_attack;
    back_obj->multi_live = obj_tab[type].multi_live;
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
    sfFloatRect sprite_dim;
    float width;
    float height;

    sprite_dim = sfSprite_getGlobalBounds(front_obj->sprite);
    front_obj->frame_nbr = obj_tab[type].rect_quad.x;
    width = sprite_dim.width / obj_tab[type].rect_quad.x;
    height = sprite_dim.height / obj_tab[type].rect_quad.y;
    front_obj->size = (sfVector2f){width, height};
    front_obj->rect_sprite = (sfIntRect){0, 0, width, height};
    front_obj->time_left = obj_tab[type].time_left;
    front_obj->offset = obj_tab[type].offset;
    front_obj->rect_quad = obj_tab[type].rect_quad;
    if (front_obj->rect_quad.x > 1 || front_obj->rect_quad.y > 1) {
    sfSprite_setTextureRect(
        front_obj->sprite, front_obj->rect_sprite);
    }
}

front_obj_t *create_front_obj(
    object_drop_t type, sfTexture **text_tab,
    front_obj_t **obj_list, sfVector2f pos)
{
    front_obj_t *front_obj = malloc(sizeof(front_obj_t));

    front_obj->is_pickable = obj_tab[type].is_pickable;
    front_obj->is_short = obj_tab[type].is_short;
    front_obj->next = NULL;
    front_obj->prev = NULL;
    if (obj_tab[type].text_id_back >= 0)
        front_obj->in = create_back_obj(type, text_tab);
    else
        front_obj->in = NULL;
    front_obj->is_active = true;
    front_obj->sprite = sfSprite_create();
    sfSprite_setTexture(front_obj->sprite,
        text_tab[obj_tab[type].text_id_front], sfTrue);
    sfSprite_setPosition(front_obj->sprite, pos);
    sfSprite_setScale(front_obj->sprite, obj_tab[type].scale);
    create_front_obj_next(front_obj, type);
    put_obj_in_list(front_obj, obj_list);
    return (front_obj);
}
