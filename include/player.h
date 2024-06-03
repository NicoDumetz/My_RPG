/*
** EPITECH PROJECT, 2023
** graph.h
** File description:
** macro for CSFML
*/

#ifndef PLAYER_H
    #define PLAYER_H
    #include "lib.h"

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
    int action[9];
} npc_t;

typedef struct heros_s {
    npc_t *npc;
} heros_t;

/**ENTITY**/
entity_t *init_entity(char *asset);
void destroy_entity(entity_t *entity);

/**NPC**/
npc_t *init_npc(char *asset);
void destroy_npc(npc_t *npc);

/**HEROS**/
heros_t *init_heros(char *asset);
void destroy_heros(heros_t *heros);

/**OFFSET**/
void anim_entity(entity_t *entity, int offset, float time);
void set_offset(entity_t *entity, sfVector2i size_sprite);
#endif
