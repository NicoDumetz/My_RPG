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
    #include "menu.h"

typedef enum font_type_e {
    PIXEL = 0
} font_type_t;

typedef enum texture_type_e {
    DEATH_TEXT = 0,
    LEVEL_UP_TEXT,
    BLOOD_TEXT,
    COIN_TEXT,
    KNIGHT_TEXT,
    ARCHER_TEXT,
    MINIONS_TEXT,
    GOBLINS_T_TEXT,
    GOBLINS_B_TEXT,
    GOBLINS_D_TEXT,
    PLAINE_SPRITE_TEXT,
    PLAINE_COLISION_TEXT,
    MINE_B_TEXT,
    MINE_COLISION_TEXT,
    CAMP_SPRITE_TEXT,
    CAMP_COLISION_TEXT,
    VILLAGE_SPRITE_TEXT,
    VILLAGE_COLISION_TEXT,
    CASTLE_SPRITE_TEXT,
    CASTLE_COLISION_TEXT,
    KNIGHT_HOUSE_TEXT,
    TREE_SPRITE_TEXT,
    BAG_TEXT,
    BACK_SAVE_TEXT,
    FOOTER_SAVE_TEXT,
    HEADER_SAVE_TEXT,
    EXIT_B_P_TEXT,
    EXIT_B_R_TEXT,
    BLUE_LONG_P_TEXT,
    BLUE_LONG_R_TEXT,
    BUTTON_LONG_H_TEXT,
    LIFE_B_TEXT,
    ENERGY_B_TEXT,
    XP_B_TEXT,
    MINE_TEXT
} texture_type_t;

typedef enum scene_e {
    PLAIN = 0,
    CASTLE,
    CAMP,
    VILLAGE,
    MINE,
    SAVE,
    MENU,
    MAIN
}scene_t;

typedef struct rpg_s {
    heros_t *heros;
    save_t *save_list;
    biome_t *biome[5];
    menu_t *start_menu;
    save_scene_t *save_scene;
    mouse_data_t mouse_data;
    quest_t quest_tab[3];
    int scene;
    sfClock *clock;
    sfEvent event;
    bool ticks;
    bool key_state[256];
    int second;
    float time;
    sfTexture *text_tab[63];
    sfFont *font_tab[1];
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
void start_menu(rpg_t *rpg);

/**TOOLS**/
int my_strncmp(char const *s1, char const *s2, int len);
int my_strlen(char const *str);
int my_putstr(char const *str);
sfBool sprite_is_in_float_rect(sfSprite *sprite, sfFloatRect rect);
void destroy_sprite(sfSprite *sprite);
sfSprite *create_sprite(char *asset);
bool is_rect_in_circle(sfRectangleShape* rectangle, sfCircleShape* circle);
char *convert_int_to_str(int nbr);
sfVector2f recalculate_mouse_position(
    sfRenderWindow* window, const sfView* view);

/**SAVE**/
void write_data_in_save(save_data_t *new_save, rpg_t *rpg);
void update_save_list(save_data_t *save, rpg_t *rpg);
void create_save(rpg_t *rpg);
void create_file_list(rpg_t *rpg);
void load_page(rpg_t *rpg);
void remake_bot_list(save_data_t *save, rpg_t *rpg);
void appli_save_quest(rpg_t *rpg, save_data_t *save);

/**RPG**/
void rpg(rpg_t *rpg);
void destroy_rpg(rpg_t *rpg);
rpg_t *create_rpg_struct(void);
void manage_heros(heros_t *heros, rpg_t *rpg);
void set_all_texture(sfTexture **text_tab);
void set_all_font(sfFont **font_tab);

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

/**OPTI**/
void biome_loop(rpg_t *rpg, biome_t *biome);
void entity_loop(
    entity_t *entity_list, rpg_t *rpg);

/**QUEST_GIVER**/
void manage_quest_giver(
    quest_t *quest_tab, quest_giver_t *quest_g, rpg_t *rpg);
#endif
