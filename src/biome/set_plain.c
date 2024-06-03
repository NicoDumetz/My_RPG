/*
** EPITECH PROJECT, 2023
** game
** File description:
** rpg.h
*/

#include "rpg.h"

sfVector2f pos_house_plain[2] = {{100, 100}, {300, 300}};
sfVector2f pos_mine_plain[1] = {{200, 200}};
sfVector2f pos_tree_plain[10] = {
    {200.0f, 200.0f},
    {700.7f, 610.3f},
    {1951.4f, 1487.1f},
    {1119.9f, 839.1f},
    {2916.6f, 2634.3f},
    {2283.8f, 1916.7f},
    {64.7f, 1175.8f},
    {2040.3f, 2810.4f},
    {1710.9f, 63.4f},
    {2384.8f, 2975.8f}
};

void set_deco_data_plain(deco_data_t *deco_data)
{
    deco_data->house_tab = malloc(sizeof(entity_t) * 3);
    deco_data->house_tab[2] = NULL;
    deco_data->mine_tab = malloc(sizeof(entity_t) * 2);
    deco_data->mine_tab[1] = NULL;
    deco_data->tree_tab = malloc(sizeof(entity_t) * 10);
    deco_data->tree_tab[9] = NULL;
    deco_data->text_mine = sfTexture_createFromFile(MINE_S, NULL);
    deco_data->text_tree = sfTexture_createFromFile(TREE_SPRITE, NULL);
    deco_data->text_house = sfTexture_createFromFile(KNIGHT_H_SPRITE, NULL);
    for (int i = 0; i < 2; i++)
        deco_data->house_tab[i] = create_knight_house(
            pos_house_plain[i], deco_data->text_house);
    for (int i = 0; i < 1; i++)
        deco_data->mine_tab[i] = create_mine(
            pos_mine_plain[i], deco_data->text_mine);
    for (int i = 0; i < 9; i++)
        deco_data->tree_tab[i] = create_tree_plain(
        pos_tree_plain[i], deco_data->text_tree);
}

biome_t *set_plain(void)
{
    biome_t *plain = malloc(sizeof(biome_t));

    plain->back = add_background(PLAINE_SPRITE, PLAINE_COLISION);
    plain->bot_data = init_bot_data();
    plain->deco_data = init_deco_data();
    set_deco_data_plain(plain->deco_data);
    return (plain);
}
