/*
** EPITECH PROJECT, 2023
** graph.h
** File description:
** macro for CSFML
*/

#ifndef BIOME_S
    #define BIOME_S
    #include "lib.h"

typedef struct biome_s {
    back_t *back;
    bot_data_t *bot_data;
    deco_data_t *deco_data;
    int bot_type[6];
    int nbr_bot;
    entity_t *entity_in_view_head;
    entity_t *entity_in_view_tail;
} biome_t;

biome_t *create_biome(int biome_type);
void destroy_biome(biome_t *biome);

/**SORTING**/
void sort_entity_in_view(
    biome_t *biome, sfRenderWindow *window, heros_t *heros);
void put_entity_in_view_list(
    entity_t *entity, biome_t *biome, sfRenderWindow *window);
void remove_entity_from_list(entity_t *entity, biome_t *biome);

/**BIOME_GEN**/
biome_t *set_village(void);
biome_t *set_camp(void);
biome_t *set_plain(void);
biome_t *set_castle(void);
biome_t *set_mine(void);

/**BOT**/
void bot_generator(biome_t *biome, int *who);
#endif
