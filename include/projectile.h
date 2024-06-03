/*
** EPITECH PROJECT, 2024
** projectile
** File description:
** projectile.h
*/

#ifndef PROJ_S
    #define PROJ_S
    #include "lib.h"

typedef struct projectile_s {
    sfSprite *sprite;
    sfVector2f target;
    sfVector2f from;
    float speed;
    int active;
    sfRectangleShape *hitbox;
} projectile_t;


projectile_t *init_projectile(sfTexture *texture, float speed,
    attack_type_t type);
void destroy_projectile(projectile_t *p);
void display_projectiles(npc_t *npc, rpg_t *rpg);
void init_npc_projectiles(npc_t *npc, sfTexture **text_tab);
void init_archery_proj(projectile_t *new);
void set_positions_projectile(npc_t *npc_act, heros_t *heros);
void moov_projectile(npc_t *npc, rpg_t *rpg);
#endif
