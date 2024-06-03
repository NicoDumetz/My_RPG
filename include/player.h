/*
** EPITECH PROJECT, 2023
** graph.h
** File description:
** macro for CSFML
*/

#ifndef PLAYER_H
    #define PLAYER_H
    #include "lib.h"

typedef enum bot_type_e {
    GOBLINS_T = 0,
    GOBLINS_D,
    GOBLINS_B,
    KINGHT,
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
    sfIntRect rect;
    int frame_nbr;
} entity_t;

typedef struct npc_s {
    entity_t *entity;
    action_t act_action;
    int pv;
    int attack;
    struct npc_s *next;
    struct npc_s *prev;
    sfVector2i action[9];
} npc_t;

typedef struct bot_data_s {
    npc_t *bot_list[6];
    sfTexture *bot_texture[6];
} bot_data_t;

typedef struct heros_s {
    sfTexture *texture_base;
    npc_t *npc;
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
void anim_entity(entity_t *entity, sfVector2i offset, float time);
void set_offset(entity_t *entity, sfVector2i size_sprite);

/**BOT**/
bot_data_t *init_bot_data(void);
npc_t *set_archer(sfTexture *texture);
void free_bot_data(bot_data_t *bot_data);
void free_bot_list(npc_t *npc);
void create_bot(npc_t **list, sfTexture *texture, bot_type_t bot_type);
npc_t *set_goblins_b(sfTexture *texture);
npc_t *set_goblins_d(sfTexture *texture);
npc_t *set_goblins(sfTexture *texture);
npc_t *set_knight(sfTexture *texture);
npc_t *set_minions(sfTexture *texture);
#endif
