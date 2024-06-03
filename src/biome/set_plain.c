/*
** EPITECH PROJECT, 2023
** game
** File description:
** rpg.h
*/

#include "rpg.h"

sfVector2f pos_house_plain[2] = {{2960, 3283}, {2181, 301}};
sfVector2f pos_mine_plain[1] = {{3404, 1448}};
sfVector2f pos_tree_plain[17] = {
    {492.0f, 627.0f},
    {506.7f, 1028.3f},
    {289.4f, 1724.1f},
    {430.9f, 2300.1f},
    {1304.6f, 2400.3f},
    {1564.8f, 3144.7f},
    {2035.7f, 2853.8f},
    {1040.3f, 596.4f},
    {1422.9f, 1331.4f},
    {1395.8f, 1920.8f},
    {2482.0f, 1555.0f},
    {2813.7f, 2415.3f},
    {3486.4f, 2215.1f},
    {1742.9f, 719.1f},
    {3085.6f, 1456.3f},
    {2821.8f, 583.7f},
    {3155.7f, 206.8f}
};

void set_deco_data_plain(
    deco_data_t *deco_data, back_t *back, sfTexture **text_tab)
{
    deco_data->deco_entity[HOUSE_DECO] = malloc(sizeof(entity_t) * 3);
    deco_data->deco_entity[HOUSE_DECO][2] = NULL;
    deco_data->deco_entity[MINE_DECO] = malloc(sizeof(entity_t) * 2);
    deco_data->deco_entity[MINE_DECO][1] = NULL;
    deco_data->deco_entity[TREE_DECO] = malloc(sizeof(entity_t) * 10);
    deco_data->deco_entity[TREE_DECO][17] = NULL;
    deco_data->texture[MINE_DECO] = text_tab[MINE_TEXT];
    deco_data->texture[TREE_DECO] = text_tab[TREE_SPRITE_TEXT];
    deco_data->texture[HOUSE_DECO] = text_tab[KNIGHT_HOUSE_TEXT];
    for (int i = 0; i < 2; i++)
        deco_data->deco_entity[HOUSE_DECO][i] = create_knight_house(
            pos_house_plain[i], deco_data->texture[HOUSE_DECO], back);
    for (int i = 0; i < 1; i++)
        deco_data->deco_entity[MINE_DECO][i] = create_mine(
            pos_mine_plain[i], deco_data->texture[MINE_DECO], back);
    for (int i = 0; i < 17; i++)
        deco_data->deco_entity[TREE_DECO][i] = create_tree_plain(
        pos_tree_plain[i], deco_data->texture[TREE_DECO], back);
}

portal_t **create_portal_plain(void)
{
    portal_t **portal = malloc(sizeof(portal_t *) * 4);

    portal[0] = create_portal((sfVector2f){62, 780}, CAMP);
    portal[1] = create_portal((sfVector2f){1690, 0}, CASTLE);
    portal[2] = create_portal((sfVector2f){3449, 1496}, MINE);
    portal[3] = NULL;
    return portal;
}

biome_t *set_plain(sfTexture **text_tab, sfFont **font_tab)
{
    biome_t *plain = malloc(sizeof(biome_t));
    int bot_type[6] = {GOBLINS_B, GOBLINS_D, GOBLINS_T, KNIGHT, ARCHER, -1};

    plain->back = add_background(
        text_tab[PLAINE_SPRITE_TEXT], text_tab[PLAINE_COLISION_TEXT]);
    plain->bot_data = init_bot_data(text_tab);
    plain->deco_data = init_deco_data();
    plain->portal = create_portal_plain();
    plain->last_pos = (sfVector2f){1700.0, 200.0};
    plain->quest_giver = init_quest_giver(text_tab, plain->back, font_tab);
    for (int i = 0; i < 6; i++)
        plain->bot_type[i] = bot_type[i];
    set_deco_data_plain(plain->deco_data, plain->back, text_tab);
    return (plain);
}
