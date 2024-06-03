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
    PLAIN = 0,
    CASTLE,
    CAMP,
    VILLAGE,
    MINE,
    MAIN
}scene_t;
typedef struct rpg_s {
    heros_t *heros;
    biome_t *biome[5];
    int scene;
    sfClock *clock;
    sfEvent event;
    bool ticks;
    bool key_state[256];
    int second;
    float time;
    sfRenderWindow *window;
} rpg_t;

    #define GOBLINS_T_LIST_PLA rpg->biome[PLAIN]->bot_data->bot_list[GOBLINS_T]
    #define GOBLINS_D_LIST_PLA rpg->biome[PLAIN]->bot_data->bot_list[GOBLINS_D]
    #define GOBLINS_B_LIST_PLA rpg->biome[PLAIN]->bot_data->bot_list[GOBLINS_B]
    #define ARCHER_LIST_PLA rpg->biome[PLAIN]->bot_data->bot_list[ARCHER]
    #define KNIGHT_LIST_PLA rpg->biome[PLAIN]->bot_data->bot_list[KNIGHT]
    #define MINIONS_LIST_PLA rpg->biome[PLAIN]->bot_data->bot_list[MINIONS]

    #define GOBLIN_T_LIST_MIN rpg->biome[MINE]->bot_data->bot_list[GOBLINS_T]
    #define GOBLIN_D_LIST_MIN rpg->biome[MINE]->bot_data->bot_list[GOBLINS_D]
    #define GOBLIN_B_LIST_MIN rpg->biome[MINE]->bot_data->bot_list[GOBLINS_B]
    #define ARCHER_LIST_MIN rpg->biome[MINE]->bot_data->bot_list[ARCHER]
    #define KNIGHT_LIST_MIN rpg->biome[MINE]->bot_data->bot_list[KNIGHT]
    #define MINIONS_LIST_MIN rpg->biome[MINE]->bot_data->bot_list[MINIONS]

    #define GOBLIN_T_LIST_CAS rpg->biome[CASTLE]->bot_data->bot_list[GOBLINS_T]
    #define GOBLIN_D_LIST_CAS rpg->biome[CASTLE]->bot_data->bot_list[GOBLINS_D]
    #define GOBLIN_B_LIST_CAS rpg->biome[CASTLE]->bot_data->bot_list[GOBLINS_B]
    #define ARCHER_LIST_CAS rpg->biome[CASTLE]->bot_data->bot_list[ARCHER]
    #define KNIGHT_LIST_CAS rpg->biome[CASTLE]->bot_data->bot_list[KNIGHT]
    #define MINIONS_LIST_CAS rpg->biome[CASTLE]->bot_data->bot_list[MINIONS]

    #define GOBLIN_T_LIST_V rpg->biome[VILLAGE]->bot_data->bot_list[GOBLINS_T]
    #define GOBLIN_D_LIST_V rpg->biome[VILLAGE]->bot_data->bot_list[GOBLINS_D]
    #define GOBLIN_B_LIST_V rpg->biome[VILLAGE]->bot_data->bot_list[GOBLINS_B]
    #define ARCHER_LIST_V rpg->biome[VILLAGE]->bot_data->bot_list[ARCHER]
    #define KNIGHT_LIST_V rpg->biome[VILLAGE]->bot_data->bot_list[KNIGHT]
    #define MINIONS_LIST_V rpg->biome[VILLAGE]->bot_data->bot_list[MINIONS]

    #define GOBLINS_T_LIST_CAM rpg->biome[CAMP]->bot_data->bot_list[GOBLINS_T]
    #define GOBLINS_D_LIST_CAM rpg->biome[CAMP]->bot_data->bot_list[GOBLINS_D]
    #define GOBLINS_B_LIST_CAM rpg->biome[CAMP]->bot_data->bot_list[GOBLINS_B]
    #define ARCHER_LIST_CAM rpg->biome[CAMP]->bot_data->bot_list[ARCHER]
    #define KNIGHT_LIST_CAM rpg->biome[CAMP]->bot_data->bot_list[KNIGHT]
    #define MINIONS_LIST_CAM rpg->biome[CAMP]->bot_data->bot_list[MINIONS]

void test(rpg_t *rpg);

/**TOOLS**/
int my_strncmp(char const *s1, char const *s2, int len);
int my_strlen(char const *str);
int my_putstr(char const *str);
sfBool sprite_is_in_float_rect(sfSprite *sprite, sfFloatRect rect);
void destroy_sprite(sfSprite *sprite);
sfSprite *create_sprite(char *asset);

/**RPG**/
void rpg(rpg_t *rpg);
void destroy_rpg(rpg_t *rpg);
rpg_t *create_rpg_struct(void);

/**EVENT**/
void manage_event(rpg_t *rpg);
void manage_movements(rpg_t *rpg);
void manage_heros_attack(heros_t *heros, bool *key_code);
sfSprite *wich_back(rpg_t *rpg);
sfImage *wich_img(rpg_t *rpg);
void manage_right(rpg_t *rpg);
void manage_left(rpg_t *rpg);
void manage_down(rpg_t *rpg);
void manage_up(rpg_t *rpg);
#endif
