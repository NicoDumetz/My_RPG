/*
** EPITECH PROJECT, 2023
** graph.h
** File description:
** macro for CSFML
*/

#ifndef OBJ_H
    #define OBJ_H
    #include "lib.h"
typedef struct entity_s entity_t;
typedef struct heros_s heros_t;
typedef struct rpg_s rpg_t;

    #define HEARTH_POTION_PATH "MF_Items/hearth_potion.png"
    #define HELMET_PATH "MF_Items/Helmet.png"

typedef enum object_drop_e {
    DEATH = 0,
    NOTHING,
    HEARTH_POTION,
    HELMET,
    OBJ_COUNT
} object_drop_t;

typedef enum object_usage_e {
    NO_USAGE = 0,
    CONSOMABLE,
    EQUIPABLE
} object_usage_t;

typedef struct obj_template_s {
    int text_id_front;
    int text_id_back;
    int time_left;
    bool is_pickable;
    bool is_short;
    int multi_speed;
    int multi_live;
    int multi_attack;
    int add_stamina;
    int add_live;
    int add_xp;
    sfVector2i rect_quad;
    sfVector2i offset;
    sfVector2f scale;
    object_usage_t usage;
} obj_template_t;

extern obj_template_t obj_tab[];

typedef struct back_obj_s {
    sfSprite *sprite;
    object_usage_t usage;
    object_drop_t id;
    int multi_speed;
    int multi_live;
    int multi_attack;
    int add_stamina;
    int add_live;
    int add_xp;
    struct back_obj_s *next;
    struct back_obj_s *prev;
    void *data;
} back_obj_t;

typedef struct front_obj_s {
    int time_left;
    bool is_pickable;
    bool is_short;
    back_obj_t *in;
    struct front_obj_s *next;
    struct front_obj_s *prev;
    sfVector2i rect_quad;
    bool is_active;
    int frame_nbr;
    sfSprite *sprite;
    sfVector2f size;
    sfVector2f sprite_sheet_size;
    sfVector2f pos;
    sfVector2i offset;
    sfIntRect rect_sprite;
} front_obj_t;

/**INIT**/
front_obj_t *create_front_obj(
    object_drop_t type, sfTexture **text_tab,
    front_obj_t **obj_list, sfVector2f pos);
back_obj_t *create_back_obj(object_drop_t type, sfTexture **text_tab);
void destroy_front_obj(front_obj_t *front_obj, bool with_back);
void destroy_back_obj(back_obj_t *back_obj);

/**ANIM**/
void anim_obj_short(
    front_obj_t *obj, sfVector2i offset, bool ticks);
void anim_obj_long(
    front_obj_t *obj, sfVector2i offset, bool ticks);
void manage_animation_obj(front_obj_t *obj, bool ticks);

/**MANAGER**/
void manage_obj(front_obj_t *obj, rpg_t *rpg, heros_t *heros);
void delete_from_list(back_obj_t *obj, back_obj_t **list);
#endif
