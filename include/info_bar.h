/*
** EPITECH PROJECT, 2023
** graph.h
** File description:
** collisions
*/

#ifndef INFO_BAR_H
    #define INFO_BAR_H
    #include "lib.h"

typedef enum bar_heros_e {
    LIFE_BAR = 0,
    XP_BAR,
    STAMINA_BAR
} bar_heros_t;

typedef struct info_bar_s {
    sfRectangleShape *bar;
    float max;
    float act;
    sfVector2f size;
} info_bar_t;

/**INIT**/
info_bar_t *create_info_bar(sfColor color, sfVector2f size, float max);
void destroy_info_bar(info_bar_t *info_bar);

/**UPDATE**/
void update_bar(info_bar_t *info, sfVector2f pos);
#endif
