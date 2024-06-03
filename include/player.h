/*
** EPITECH PROJECT, 2023
** graph.h
** File description:
** macro for CSFML
*/

#ifndef PLAYER_H
    #define PLAYER_H
    #include "lib.h"
    #include <stdbool.h>
    #include "background.h"

typedef enum direction_e {
    RIGHT = 0,
    LEFT,
    UP,
    DOWN
} direction_t;

typedef enum special_npc_e {
    NON_SPEC = 0,
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

typedef struct heros_s {
    sfTexture *texture_base;
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
heros_t *init_heros(char *asset);
void destroy_heros(heros_t *heros);

/**OFFSET**/
void anim_entity(entity_t *entity, sfVector2i offset, bool ticks);
void anim_attack(npc_t *npc, sfVector2i offset, bool ticks);
void set_offset(entity_t *entity, sfVector2i size_sprite);
void set_box(
    sfRectangleShape *rect, sfFloatRect floatrect, entity_t *entity);
void set_all_box(entity_t *entity, sfRenderWindow *window);
void manage_animation(entity_t *entity, bool ticks);

/**BOT**/
bot_data_t *init_bot_data(void);
npc_t *set_archer(sfTexture *texture);
void free_bot_data(bot_data_t *bot_data);
void free_bot_list(npc_t *npc);
npc_t *create_bot(bot_type_t bot_type, bot_data_t *bot_data_t, sfVector2f pos);
npc_t *set_goblins_b(sfTexture *texture);
npc_t *set_goblins_d(sfTexture *texture);
npc_t *set_goblins(sfTexture *texture);
npc_t *set_knight(sfTexture *texture);
npc_t *set_minions(sfTexture *texture);
void manage_bot(entity_t *entity, heros_t *heros);

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
