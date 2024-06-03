/*
** EPITECH PROJECT, 2023
** graph.h
** File description:
** macro for CSFML
*/

#ifndef QUEST_H
    #define QUEST_H
    #include "lib.h"
typedef struct quest_s quest_t;
typedef bool(*start_function_t)(quest_t *self, void *data);
typedef bool(*check_function_t)(quest_t *self, void *data);

typedef enum quest_type_e {
    KILL_CAMP = 0,
    KILL_MINE,
    KILL_CASTLE
} quest_type_t;

typedef enum quest_state_e {
    NOT_BEGIN = 0,
    BEGIN,
    FINISH
} quest_state_t;

typedef struct quest_s {
    sfText *display;
    sfRectangleShape *box;
    start_function_t start_f;
    check_function_t check_f;
    int state;
} quest_t;

/**INIT**/
void init_quest(quest_t *quest_tab, sfFont **font_tab);
void destroy_quest(quest_t *quest_tab);
void set_quest(
    quest_t *quest, char *message, sfFont *font);
void set_func_quest(
    quest_t *quest, start_function_t start_f, check_function_t check_f);


/**DISPLAY**/
void quest_displayer(quest_t *quest_tab, sfRenderWindow *window);
#endif
