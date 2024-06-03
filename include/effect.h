/*
** EPITECH PROJECT, 2023
** graph.h
** File description:
** collisions
*/

#ifndef EFFECT_H
    #define EFFECT_H
    #include "lib.h"

typedef enum heros_effect_e {
    LEVEL_UP_HEROS = 0,
} heros_effect_t;

typedef struct effect_s effect_t;
typedef struct effect_s {
    sfSprite *sprite;
    bool active;
    bool is_short;
    int frame_nbr;
    sfVector2f size;
    sfVector2f sprite_sheet_size;
    sfVector2f pos;
    sfVector2i offset;
    sfIntRect rect_sprite;
} effect_t;
#endif

/**INIT**/
void destroy_effect(effect_t *effect);
effect_t *create_effect(
    sfTexture *texture, bool static_effect, sfVector2i offset);

/**ANIM**/
void anim_effect_long(
    effect_t *effect, bool ticks);
void anim_effect_short(
    effect_t *effect, bool ticks);
