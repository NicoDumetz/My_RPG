/*
** EPITECH PROJECT, 2023
** graph.h
** File description:
** macro for CSFML
*/

#ifndef BIOME_S
    #define BIOME_S
    #include "lib.h"
typedef enum scene_e scene_t;

typedef struct portal_s {
    bool is_open;
    sfCircleShape *zone;
    sfVector2f pos;
    int scene;
} portal_t;

typedef struct biome_s {
    back_t *back;
    npc_t *boss;
    bot_data_t *bot_data;
    deco_data_t *deco_data;
    quest_giver_t *quest_giver;
    int bot_type[6];
    int nbr_bot;
    sfVector2f last_pos;
    quest_t *quest;
    portal_t **portal;
    front_obj_t *obj_list;
    entity_t *entity_in_view_head;
    entity_t *entity_in_view_tail;
    sfTexture **text_tab;
} biome_t;

biome_t *create_biome(int biome_type,
    sfTexture **text_tab, sfFont **font_tab);
void destroy_biome(biome_t *biome);

/**SORTING**/
void sort_entity_in_view(
    biome_t *biome, sfRenderWindow *window, heros_t *heros, rpg_t *rpg);
void put_entity_in_view_list(
    entity_t *entity, biome_t *biome, sfRenderWindow *window);
void remove_entity_from_list(entity_t *entity, biome_t *biome);

/**BIOME_GEN**/
biome_t *set_village(sfTexture **text_tab, sfFont **font_tab);
biome_t *set_camp(sfTexture **text_tab, sfFont **font_tab);
biome_t *set_plain(sfTexture **text_tab, sfFont **font_tab);
biome_t *set_castle(sfTexture **text_tab, sfFont **font_tab);
biome_t *set_mine(sfTexture **text_tab, sfFont **font_tab);

/**BOT**/
void bot_generator(biome_t *biome, int *who);

/**PORTAL**/
portal_t *create_portal(sfVector2f pos, int scene);
void destroy_portal(portal_t *portal);

/**SWITCH**/
void switch_biome(biome_t *from, portal_t *portal, rpg_t *rpg, heros_t *heros);
void clean_entity_list(biome_t *biome);

/**BOSS**/
npc_t *set_camp_boss(sfTexture **text_tab, biome_t *biome);
npc_t *set_mine_boss(sfTexture **text_tab, biome_t *biome);
npc_t *set_castle_boss(sfTexture **text_tab, biome_t *biome);
#endif
