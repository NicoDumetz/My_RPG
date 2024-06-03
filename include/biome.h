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
} biome_t;
#endif

biome_t *create_biome(int biome_type);
void destroy_biome(biome_t *biome);

/**BIOME_GEN**/
biome_t *set_village(void);
biome_t *set_camp(void);
biome_t *set_plain(void);
biome_t *set_castle(void);
biome_t *set_mine(void);
