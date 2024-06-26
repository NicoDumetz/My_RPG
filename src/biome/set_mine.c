/*
** EPITECH PROJECT, 2023
** game
** File description:
** rpg.h
*/

#include "rpg.h"

sfVector2f pos_bot_mine[] = {
    {2540, 413},
    {2540, 282},
    {2430, 782},
    {1833, 524},
    {2092, 550},
    {1645, 1255},
    {2008, 1141},
    {2307, 1651},
    {1230, 2459},
    {562, 1375},
    {998, 1358},
    {1213, 2066},
    {432, 704},
    {304, 459},
    {1026, 520},
    {1314, 188},
    {1314, 507},
    {288, 1762},
    {204, 2557},
    {556, 2702},
    {1951, 2070},
    {2686, 2077},
    {2612, 2694},
    {0, 0}
};

npc_t *set_mine_boss(sfTexture **text_tab, biome_t *biome)
{
    npc_t *mine_boss = set_goblins_d(text_tab[MINE_BOSS_TEXT]);

    mine_boss->pv = 600;
    mine_boss->damage = 160;
    init_npc_projectiles(mine_boss, text_tab);
    mine_boss->stamina = 10;
    mine_boss->max_stamina = 10;
    mine_boss->xp = 400;
    mine_boss->entity->effect_tab = set_effect_bot(
        text_tab, mine_boss->entity->sprite);
    mine_boss->entity->pos = (sfVector2f){1000, 1500};
    mine_boss->pv_bar =
        create_info_bar(sfRed, (sfVector2f){100, 7}, mine_boss->pv, NULL);
    mine_boss->pv_bar->act = mine_boss->pv;
    sfSprite_setPosition(mine_boss->entity->sprite, (sfVector2f){1900, 1900});
    add_to_list_bot(mine_boss, &(biome->bot_data->bot_list[GOBLINS_D]));
    manage_animation_bot(mine_boss->entity, true);
    return (mine_boss);
}

portal_t **create_portal_mine(void)
{
    portal_t **portal = malloc(sizeof(portal_t *) * 2);

    portal[0] = create_portal((sfVector2f){1994, 0}, PLAIN);
    portal[1] = NULL;
    return portal;
}

biome_t *set_mine(sfTexture **text_tab, sfFont **)
{
    biome_t *mine = malloc(sizeof(biome_t));
    int bot_type[6] = {KNIGHT, ARCHER, GOBLINS_D, GOBLINS_T, -1, -1};

    mine->back = add_background(
        text_tab[MINE_B_TEXT], text_tab[MINE_COLISION_TEXT]);
    mine->bot_data = init_bot_data(text_tab);
    mine->portal = create_portal_mine();
    mine->quest_giver = NULL;
    mine->last_pos = (sfVector2f){1994, 0};
    for (int i = 0; i < 6; i++)
        mine->bot_type[i] = bot_type[i];
    mine->deco_data = NULL;
    mine->boss = set_mine_boss(text_tab, mine);
    mine->pos_bot = pos_bot_mine;
    return (mine);
}
