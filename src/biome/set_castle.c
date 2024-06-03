/*
** EPITECH PROJECT, 2023
** game
** File description:
** rpg.h
*/

#include "rpg.h"

sfVector2f pos_bot_castle[] = {
    {608, 2280},
    {635, 2562},
    {930, 1683},
    {286, 1774},
    {489, 1841},
    {811, 1413},
    {1441, 1252},
    {1750, 1252},
    {1642, 1520},
    {1441, 1828},
    {1790, 1774},
    {2327, 1893},
    {2393, 2175},
    {2648, 2255},
    {1897, 2739},
    {1657, 2405},
    {2006, 2405},
    {2742, 1170},
    {2568, 1358},
    {2352, 633},
    {1977, 727},
    {1628, 526},
    {1682, 217},
    {2354, 498},
    {2756, 620},
    {181, 245},
    {343, 916},
    {933, 728},
    {799, 233},
    {0, 0}
};

npc_t *set_castle_boss(sfTexture **text_tab, biome_t *biome)
{
    npc_t *castle_boss = set_knight(text_tab[CASTLE_BOSS_TEXT]);

    castle_boss->pv = 800;
    castle_boss->damage = 150;
    castle_boss->xp = 600;
    castle_boss->entity->effect_tab = set_effect_bot(
        text_tab, castle_boss->entity->sprite);
    castle_boss->entity->pos = (sfVector2f){1000, 1500};
    castle_boss->pv_bar =
        create_info_bar(sfRed, (sfVector2f){100, 7}, castle_boss->pv, NULL);
    castle_boss->pv_bar->act = castle_boss->pv;
    sfSprite_setPosition(castle_boss->entity->sprite, (sfVector2f){500, 500});
    add_to_list_bot(castle_boss, &(biome->bot_data->bot_list[KNIGHT]));
    manage_animation_bot(castle_boss->entity, true);
    return (castle_boss);
}

portal_t **create_portal_castle(void)
{
    portal_t **portal = malloc(sizeof(portal_t *) * 2);

    portal[0] = create_portal((sfVector2f){1333, 2776}, PLAIN);
    portal[1] = NULL;
    return portal;
}

biome_t *set_castle(sfTexture **text_tab, sfFont **)
{
    biome_t *castle = malloc(sizeof(biome_t));
    int bot_type[6] = {KNIGHT, ARCHER, -1, -1, -1, -1};

    castle->back = add_background(
        text_tab[CASTLE_SPRITE_TEXT], text_tab[CASTLE_COLISION_TEXT]);
    castle->bot_data = init_bot_data(text_tab);
    castle->quest_giver = NULL;
    castle->deco_data = NULL;
    castle->portal = create_portal_castle();
    castle->last_pos = (sfVector2f){1333, 2776};
    for (int i = 0; i < 6; i++)
        castle->bot_type[i] = bot_type[i];
    castle->boss = set_castle_boss(text_tab, castle);
    castle->pos_bot = pos_bot_castle;
    return (castle);
}
