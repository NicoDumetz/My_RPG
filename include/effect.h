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
    EXPLO_HEROS,
    BLOOD_HEROS,
    SHIELD_HEROS,
    PICK_HEROS,
} heros_effect_t;

typedef enum bot_effect_e {
    BLOOD_BOT = 0,
    EXPLO_BOT,
} bot_effect_t;

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
    sfTexture *texture,
    bool static_effect, sfVector2i offset, sfSprite * to_match);
void resize_sprite_to_match(
    sfSprite* sprite_to_resize, sfSprite* reference_sprite);

/**BOT**/
effect_t **set_effect_bot(sfTexture **text_tab, sfSprite *bot_sprite);

/**ANIM**/
void anim_effect_long(
    effect_t *effect, bool ticks);
void anim_effect_short(
    effect_t *effect, bool ticks);
