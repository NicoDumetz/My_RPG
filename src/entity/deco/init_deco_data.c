/*
** EPITECH PROJECT, 2023
** graph.h
** File description:
** macro for CSFML
*/

#include "rpg.h"

void free_deco_data(deco_data_t *deco_data)
{
    if (deco_data->house_tab) {
        for (int i = 0; deco_data->house_tab[i]; i++)
            destroy_entity(deco_data->house_tab[i]);
        free(deco_data->house_tab);
    }
    if (deco_data->mine_tab) {
        for (int i = 0; deco_data->mine_tab[i]; i++)
            destroy_entity(deco_data->mine_tab[i]);
        free(deco_data->mine_tab);
    }
    if (deco_data->tree_tab) {
        for (int i = 0; deco_data->tree_tab[i]; i++)
            destroy_entity(deco_data->tree_tab[i]);
        free(deco_data->tree_tab);
    }
    sfTexture_destroy(deco_data->text_mine);
    sfTexture_destroy(deco_data->text_house);
    sfTexture_destroy(deco_data->text_tree);
    free(deco_data);
}

deco_data_t *init_deco_data(void)
{
    deco_data_t *deco_data = malloc(sizeof(deco_data_t));

    deco_data->tree_tab = NULL;
    deco_data->house_tab = NULL;
    deco_data->mine_tab = NULL;
    deco_data->text_house = NULL;
    deco_data->text_tree = NULL;
    deco_data->text_mine = NULL;
    return deco_data;
}
