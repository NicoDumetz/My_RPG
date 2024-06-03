/*
** EPITECH PROJECT, 2023
** graph.h
** File description:
** macro for CSFML
*/

#ifndef PLAYER_H
    #define PLAYER_H
    #include "inventory.h"
    #include "lib.h"
    #include <stdbool.h>
    #include "background.h"

typedef enum entity_type_e {
    WHITOUT = 0,
    NPC,
    OBJ
}entity_type_t;

typedef enum direction_e {
    RIGHT = 0,
    LEFT,
    UP,
    DOWN
} direction_t;

typedef enum special_npc_e {
    NON_SPEC = 0,
    QUEST_GIVER,
    HEROS
}special_npc_t;

typedef enum deco_type_e {
    HOUSE_DECO = 0,
    TREE_DECO,
    MINE_DECO
} deco_type_t;

typedef enum bot_type_e {
    GOBLINS_T = 0,
    GOBLINS_D,
    GOBLINS_B,
    KNIGHT,
    MINIONS,
    ARCHER,
} bot_type_t;

typedef enum action_e {
    ATTACK_F = 0,
    ATTACK_B,
    ATTACK_L,
    ATTACK_R,
    MOVE_R,
    MOVE_L,
    MOVE_F,
    MOVE_B,
    STAND
} action_t;

typedef struct entity_s {
    sfSprite *sprite;
    sfVector2f size;
    sfVector2f sprite_sheet_size;
    sfVector2f pos;
    effect_t **effect_tab;
    int level;
    sfIntRect rect_sprite;
    sfRectangleShape *colbox;
    sfFloatRect colbox_dim;
    void *parent;
    sfVector2i simple_action;
    struct entity_s *prev;
    struct entity_s *next;
    int is_reverse;
    int frame_nbr;
    entity_type_t type;

} entity_t;

typedef struct npc_s {
    entity_t *entity;
    action_t act_action;
    int pv;
    int attack;
    bool is_attack;
    bool cur_attack;
    bool is_alive;
    bool allowed_dir[4];
    bool in_chase;
    int view;
    float xp;
    info_bar_t *pv_bar;
    sfRectangleShape *attbox[4];
    sfRectangleShape *hitbox;
    sfFloatRect attbox_dim[4];
    sfFloatRect hitbox_dim;
    struct npc_s *next;
    struct npc_s *prev;
    sfVector2i action[9];
    special_npc_t special;
} npc_t;

typedef struct deco_data_s {
    entity_t **deco_entity[3];
    sfTexture *texture[3];
} deco_data_t;

typedef struct bot_data_s {
    npc_t *bot_list[6];
    sfTexture *bot_texture[6];
} bot_data_t;

typedef struct quest_giver_s {
    npc_t *npc;
    float interact_zone;
    const char **dial_tab;
    bool is_interact;
    sfText *dial;
    int act_dial;
    sfText *signal;
    int act_quest;
} quest_giver_t;

typedef struct heros_s {
    sfTexture *texture_base;
    sfText *interact;
    bool can_interact;
    int level_act;
    float stamina;
    float stamina_max;
    float stami_per_sec;
    float pv_max;
    inventory_t invent;
    back_obj_t *inventory;
    info_bar_t *bar_tab[3];
    npc_t *npc;
    float speed;
} heros_t;

/**ENTITY**/
entity_t *init_entity(sfTexture *asset);
void destroy_entity(entity_t *entity);

/**NPC**/
npc_t *init_npc(sfTexture *asset);
void destroy_npc(npc_t *npc);

/**HEROS**/
heros_t *init_heros(sfTexture **texture, sfFont **font_tab);
void destroy_heros(heros_t *heros);
void manage_heros_bar(heros_t *heros, sfRenderWindow *window);

/**QUEST_GIVER**/
quest_giver_t *init_quest_giver(
    sfTexture **text_tab, back_t *back, sfFont **font_tab);
void destroy_quest_giver(quest_giver_t *quest_giver);
void next_quest(quest_giver_t *quest_g, quest_t *quest_tab);

/**OFFSET**/
void anim_entity(entity_t *entity, sfVector2i offset, bool ticks);
void anim_attack(npc_t *npc, sfVector2i offset, bool ticks);
void set_offset(entity_t *entity, sfVector2i size_sprite);
void set_box(
    sfRectangleShape *rect, sfFloatRect floatrect, entity_t *entity);
void set_all_box(entity_t *entity, sfRenderWindow *window);

/**BOT**/
bot_data_t *init_bot_data(sfTexture **text_tab);
npc_t *set_archer(sfTexture *texture);
void free_bot_data(bot_data_t *bot_data);
void free_bot_list(npc_t *npc);
npc_t *create_bot(
    bot_type_t bot_type, bot_data_t *bot_data_t,
    sfVector2f pos, sfTexture **text_tab);
npc_t *set_goblins_b(sfTexture *texture);
npc_t *set_goblins_d(sfTexture *texture);
npc_t *set_goblins(sfTexture *texture);
npc_t *set_knight(sfTexture *texture);
npc_t *set_minions(sfTexture *texture);
void manage_bot(entity_t *entity, heros_t *heros, rpg_t *rpg);
void manage_random_moov(npc_t *npc_act, rpg_t *rpg);
void manage_chase(npc_t *npc_act, rpg_t *rpg);
void check_if_heros_attack_me(npc_t *to_check, heros_t *heros);
bool check_chase_heros(npc_t *to_check, heros_t *heros);
void manage_animation_bot(entity_t *entity, bool ticks);

/**DECO**/
deco_data_t *init_deco_data(void);
void free_deco_data(deco_data_t *deco_data);
entity_t *create_knight_house(
    sfVector2f pos, sfTexture *texture, back_t *back);
entity_t *create_mine(sfVector2f pos, sfTexture *texture, back_t *back);
entity_t *create_tree_plain(sfVector2f pos, sfTexture *texture, back_t *back);
void display_deco(deco_data_t *deco_data, sfRenderWindow *window, bool ticks);
    #define KNIGHT_BUILDINGS "tiny_world_asset/Factions/Knights/Buildings/"
    #define TREE_SPRITE "tiny_world_asset/Resources/Trees/Tree.png"
    #define KNIGHT_H_SPRITE KNIGHT_BUILDINGS "House/House_Blue.png"
    #define MINE_S "tiny_world_asset/Resources/Gold Mine/GoldMine_Active.png"
#endif
