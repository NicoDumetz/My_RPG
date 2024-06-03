/*
** EPITECH PROJECT, 2024
** movements
** File description:
** movements
*/

#include "rpg.h"

/*
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
*/

obj_template_t obj_tab[] = {
    {DEATH_TEXT, -1, -1, false, true, 1, 1, 1, 0, 0, 0,
        (sfVector2i){7, 2}, (sfVector2i){7, 0},
        (sfVector2f){1.f, 1.f}, NO_USAGE},
    {BAG_TEXT, -1, 500, true, false, 1, 1, 1, 0, 0, 0,
        (sfVector2i){7, 1}, (sfVector2i){7, 0},
        (sfVector2f){1.f, 1.f}, NO_USAGE},
    {PV_LVL_3_TEXT, PV_LVL_3_TEXT, 500, true, false,
        1, 1, 1, 0, 75, 0, (sfVector2i){1, 1},
        (sfVector2i){0, 0}, (sfVector2f){2.5, 2.5},
        CONSOMABLE},
    {HELMET_LVL_3_TEXT, HELMET_LVL_3_TEXT, 500, true, false,
        1, 1.6, 1, 0, 0, 0, (sfVector2i){1, 1},
        (sfVector2i){0, 0}, (sfVector2f){2.5, 2.5}, EQUIPABLE},
    {PV_LVL_1_TEXT, PV_LVL_1_TEXT, 500, true, false,
        1, 1, 1, 0, 25, 0, (sfVector2i){1, 1},
        (sfVector2i){0, 0}, (sfVector2f){2.5, 2.5},
        CONSOMABLE},
    {HELMET_LVL_1_TEXT, HELMET_LVL_1_TEXT, 500, true, false,
        1, 1.2, 1, 0, 0, 0, (sfVector2i){1, 1},
        (sfVector2i){0, 0}, (sfVector2f){2.5, 2.5}, EQUIPABLE},
    {PV_LVL_2_TEXT, PV_LVL_2_TEXT, 500, true, false,
        1, 1, 1, 0, 50, 0, (sfVector2i){1, 1},
        (sfVector2i){0, 0}, (sfVector2f){2.5, 2.5},
        CONSOMABLE},
    {HELMET_LVL_2_TEXT, HELMET_LVL_2_TEXT, 500, true, false,
        1, 1.4, 1, 0, 0, 0, (sfVector2i){1, 1},
        (sfVector2i){0, 0}, (sfVector2f){2.5, 2.5}, EQUIPABLE},
    {BREASTPLATE_LVL_1_TEXT, BREASTPLATE_LVL_1_TEXT, 500, true, false,
        1, 1.2, 1, 0, 0, 0, (sfVector2i){1, 1},
        (sfVector2i){0, 0}, (sfVector2f){2.5, 2.5}, EQUIPABLE},
    {BREASTPLATE_LVL_2_TEXT, BREASTPLATE_LVL_2_TEXT, 500, true, false,
        1, 1.4, 1, 0, 0, 0, (sfVector2i){1, 1},
        (sfVector2i){0, 0}, (sfVector2f){2.5, 2.5}, EQUIPABLE},
    {BREASTPLATE_LVL_3_TEXT, BREASTPLATE_LVL_3_TEXT, 500, true, false,
        1, 1.6, 1, 0, 0, 0, (sfVector2i){1, 1},
        (sfVector2i){0, 0}, (sfVector2f){2.5, 2.5}, EQUIPABLE},
    {GLOVES_LVL_2_TEXT, GLOVES_LVL_2_TEXT, 500, true, false,
        1, 1.1, 1.2, 0, 0, 0, (sfVector2i){1, 1},
        (sfVector2i){0, 0}, (sfVector2f){2.5, 2.5}, EQUIPABLE},
    {GLOVES_LVL_3_TEXT, GLOVES_LVL_3_TEXT, 500, true, false,
        1, 1.2, 1.4, 0, 0, 0, (sfVector2i){1, 1},
        (sfVector2i){0, 0}, (sfVector2f){2.5, 2.5}, EQUIPABLE},
    {GREAVES_LVL_2_TEXT, GREAVES_LVL_2_TEXT, 500, true, false,
        1, 1.1, 1, 0, 0, 0, (sfVector2i){1, 1},
        (sfVector2i){0, 0}, (sfVector2f){2.5, 2.5}, EQUIPABLE},
    {GREAVES_LVL_3_TEXT, GREAVES_LVL_3_TEXT, 500, true, false,
        1, 1.2, 1, 0, 0, 0, (sfVector2i){1, 1},
        (sfVector2i){0, 0}, (sfVector2f){2.5, 2.5}, EQUIPABLE},
    {SHOES_LVL_1_TEXT, SHOES_LVL_1_TEXT, 500, true, false,
        1.1, 1, 1, 0, 0, 0, (sfVector2i){1, 1},
        (sfVector2i){0, 0}, (sfVector2f){2.5, 2.5}, EQUIPABLE},
    {SHOES_LVL_2_TEXT, SHOES_LVL_2_TEXT, 500, true, false,
        1.15, 1, 1, 0, 0, 0, (sfVector2i){1, 1},
        (sfVector2i){0, 0}, (sfVector2f){2.5, 2.5}, EQUIPABLE},
    {SHOES_LVL_3_TEXT, SHOES_LVL_3_TEXT, 500, true, false,
        1.2, 1.1, 1, 0, 0, 0, (sfVector2i){1, 1},
        (sfVector2i){0, 0}, (sfVector2f){2.5, 2.5}, EQUIPABLE},
    {STEAK_TEXT, STEAK_TEXT, 500, true, false,
        1, 1, 1, 15, 0, 0, (sfVector2i){1, 1},
        (sfVector2i){0, 0}, (sfVector2f){2.5, 2.5},
        CONSOMABLE},
    {MUSHROOMS_TEXT, MUSHROOMS_TEXT, 500, true, false,
        1, 1, 1, 0, -10, 0, (sfVector2i){1, 1},
        (sfVector2i){0, 0}, (sfVector2f){2.5, 2.5},
        CONSOMABLE},
    {STAMI_LVL_1_TEXT, STAMI_LVL_1_TEXT, 500, true, false,
        1, 1, 1, 30, 0, 0, (sfVector2i){1, 1},
        (sfVector2i){0, 0}, (sfVector2f){2.5, 2.5},
        CONSOMABLE},
    {STAMI_LVL_2_TEXT, STAMI_LVL_2_TEXT, 500, true, false,
        1, 1, 1, 60, 0, 0, (sfVector2i){1, 1},
        (sfVector2i){0, 0}, (sfVector2f){2.5, 2.5},
        CONSOMABLE},
    {XP_LVL_1_TEXT, XP_LVL_1_TEXT, 500, true, false,
        1, 1, 1, 0, 0, 200, (sfVector2i){1, 1},
        (sfVector2i){0, 0}, (sfVector2f){2.5, 2.5},
        CONSOMABLE}
};
