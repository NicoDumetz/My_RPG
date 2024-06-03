/*
** EPITECH PROJECT, 2023
** graph.h
** File description:
** collisions
*/

#ifndef EFFECT_H
    #define EFFECT_H
    #include "lib.h"
typedef struct effect_s effect_t;
typedef void(effect_funct_t)(effect_t *effect, void *parent);
typedef struct effect_s {
    sfSprite *sprite;
    bool active;
    bool static_effect;
    effect_funct_t *active_effect;
} effect_t;
#endif

/**INIT**/
void destroy_effect(effect_t *effect);
effect_t *create_effect(
    sfTexture *texture, effect_funct_t function, bool static_effect);
