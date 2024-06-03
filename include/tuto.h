/*
** EPITECH PROJECT, 2023
** graph.h
** File description:
** macro for CSFML
*/

#ifndef TUTO_H
    #define TUTO_H
    #include "lib.h"
typedef struct rpg_s rpg_t;
typedef enum tuto_type_e {
    MOVEMENT_T = 0,
    ATTACK_T,
    KILL_T,
    TAKE_T,
    HEAL_T,
    EQUIP_T,
    TEST_T
} tuto_type_t;

typedef enum move_check_e {
    KEY_Z = 0,
    KEY_Q,
    KEY_S,
    KEY_D
} move_check_t;

typedef enum attack_check_e {
    KEY_I = 0,
    KEY_J,
    KEY_K,
    KEY_L
} attack_check_t;

typedef enum tuto_quest_e {
    TEST = 0,
} tuto_quest_t;

typedef struct tuto_s {
    biome_t *biome;
    bool move_tab[4];
    bool attack_tab[4];
    quest_t quest_tab[TEST_T + 2];
    button_t *skip_button;
} tuto_t;

/**INIT**/
void destroy_tuto(tuto_t *tuto);
tuto_t *create_tuto(sfTexture **text_tab, sfFont **font_tab);

/**QUEST**/
quest_giver_t *init_quest_giver_tuto(
    sfTexture **text_tab, back_t *back, sfFont **font_tab);
void init_quest_tuto(quest_t *quest_tab, sfFont *font);
bool start_kill_goblins(quest_t *, void *data);
bool default_check(quest_t *, void *);
bool check_if_kill_bot(quest_t *quest, void *data);
bool check_quest_attack_tuto(quest_t *quest, void *data);
bool check_quest_move_tuto(quest_t *quest, void *data);
void check_if_pressed_key(tuto_t *tuto, bool *key_tab);
void manage_quest_tuto(tuto_t *tuto, rpg_t *rpg);
bool start_final_test(quest_t *, void *data);
bool check_test_quest(quest_t *quest, void *data);

/**BUTTON**/
void skip_released(void *data, button_t *button);
#endif
