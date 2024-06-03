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

    #define PV_LVL_3_PATH "MF_Items/pv_level_3.png"
    #define HELMET_LVL_3_PATH "MF_Items/Helmet_level_3.png"
    #define PV_LVL_1_PATH "MF_Items/pv_level_1.png"
    #define HELMET_LVL_1_PATH "MF_Items/helmet_level_1.png"
    #define PV_LVL_2_PATH "MF_Items/pv_level_2.png"
    #define HELMET_LVL_2_PATH "MF_Items/helmet_level_2.png"
    #define BREASTPLATE_LVL_1_PATH "MF_Items/haut_level_1.png"
    #define BREASTPLATE_LVL_2_PATH "MF_Items/haut_level_2.png"
    #define BREASTPLATE_LVL_3_PATH "MF_Items/haut_level_3.png"
    #define GLOVES_LVL_2_PATH "MF_Items/gant_level_2.png"
    #define GLOVES_LVL_3_PATH "MF_Items/gant_level_3.png"
    #define GREAVES_LVL_2_PATH "MF_Items/jean_level_2.png"
    #define GREAVES_LVL_3_PATH "MF_Items/jean_level_3.png"
    #define SHOES_LVL_1_PATH "MF_Items/shoes_level_1.png"
    #define SHOES_LVL_2_PATH "MF_Items/shoes_level_2.png"
    #define SHOES_LVL_3_PATH "MF_Items/shoes_level_3.png"
    #define STEAK_PATH "MF_Items/steak.png"
    #define MUSHROOMS_PATH "MF_Items/mushrooms.png"
    #define STAMI_LVL_1_PATH "MF_Items/stami_level_1.png"
    #define STAMI_LVL_2_PATH "MF_Items/stami_level_2.png"
    #define XP_LVL_1_PATH "MF_Items/xp_level_1.png"

typedef enum object_drop_e {
    DEATH = 0,
    NOTHING,
    PV_LVL_3,
    HELMET_LVL_3,
    PV_LVL_1,
    HELMET_LVL_1,
    PV_LVL_2,
    HELMET_LVL_2,
    BREASTPLATE_LVL_1,
    BREASTPLATE_LVL_2,
    BREASTPLATE_LVL_3,
    GLOVES_LVL_2,
    GLOVES_LVL_3,
    GREAVES_LVL_2,
    GREAVES_LVL_3,
    SHOES_LVL_1,
    SHOES_LVL_2,
    SHOES_LVL_3,
    STEAK,
    MUSHROOMS,
    STAMI_LVL_1,
    STAMI_LVL_2,
    XP_LVL_1,
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
    float multi_speed;
    float multi_live;
    float multi_attack;
    float add_stamina;
    float add_live;
    float add_xp;
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
    float multi_speed;
    float multi_live;
    float multi_attack;
    float add_stamina;
    float add_live;
    float add_xp;
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
void set_all_texture_obj(sfTexture **text_tab);

/**ANIM**/
void anim_obj_short(
    front_obj_t *obj, sfVector2i offset, bool ticks);
void anim_obj_long(
    front_obj_t *obj, sfVector2i offset, bool ticks);
void manage_animation_obj(front_obj_t *obj, bool ticks);

/**MANAGER**/
void manage_obj(front_obj_t *obj, rpg_t *rpg, heros_t *heros);
void delete_from_list(back_obj_t *obj, back_obj_t **list);
void appli_multi_equip(heros_t *heros, back_obj_t *back);
void unappli_multi_equip(heros_t *heros, back_obj_t *back);
#endif
