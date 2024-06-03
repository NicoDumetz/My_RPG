/*
** EPITECH PROJECT, 2023
** graph.h
** File description:
** macro for CSFML
*/

#ifndef RPG_H
    #define RPG_H
    #include "button.h"
    #include "lib.h"

typedef enum scene_e {
    MAIN = 0,
}scene_t;
typedef struct rpg_s {
    heros_t *heros;
    back_t *back;
    bot_data_t *bot_data;
    int scene;
    sfClock *clock;
    sfEvent event;
    bool ticks;
    bool key_state[256];
    int second;
    float time;
    sfRenderWindow *window;
} rpg_t;

    #define GOBLINS_T_LIST rpg->bot_data->bot_list[GOBLINS_T]
    #define GOBLINS_B_LIST rpg->bot_data->bot_list[GOBLINS_B]
    #define GOBLINS_D_LIST rpg->bot_data->bot_list[GOBLINS_D]
    #define ARCHER_LIST rpg->bot_data->bot_list[ARCHER]
    #define KNIGHT_LIST rpg->bot_data->bot_list[KINGHT]
    #define MINIONS_LIST rpg->bot_data->bot_list[MINIONS]

void test(rpg_t *rpg);

/**TOOLS**/
int my_strncmp(char const *s1, char const *s2, int len);
int my_strlen(char const *str);
int my_putstr(char const *str);
void destroy_sprite(sfSprite *sprite);
sfSprite *create_sprite(char *asset);

/**RPG**/
void rpg(rpg_t *rpg);
void destroy_rpg(rpg_t *rpg);
rpg_t *create_rpg_struct(void);

/**EVENT**/
void manage_event(rpg_t *rpg);
void manage_movements(rpg_t *rpg);
sfSprite *wich_back(rpg_t *rpg);
void manage_right(rpg_t *rpg);
void manage_left(rpg_t *rpg);
void manage_down(rpg_t *rpg);
void manage_up(rpg_t *rpg);
#endif
