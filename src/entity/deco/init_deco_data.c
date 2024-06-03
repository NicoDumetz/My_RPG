/*
** EPITECH PROJECT, 2023
** graph.h
** File description:
** macro for CSFML
*/

#include "rpg.h"

void free_deco_data(deco_data_t *deco_data)
{
    for (int i = 0; i <= MINE_DECO; i++) {
        for (int j = 0; deco_data->deco_entity[i][j]; j++)
            destroy_entity(deco_data->deco_entity[i][j]);
        free(deco_data->deco_entity[i]);
        sfTexture_destroy(deco_data->texture[i]);
    }
    free(deco_data);
}

deco_data_t *init_deco_data(void)
{
    deco_data_t *deco_data = malloc(sizeof(deco_data_t));

    for (int i = 0; i <= MINE_DECO; i++) {
        deco_data->deco_entity[i] = NULL;
        deco_data->texture[i] = NULL;
    }
    return deco_data;
}
