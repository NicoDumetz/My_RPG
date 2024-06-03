/*
** EPITECH PROJECT, 2023
** game
** File description:
** rpg.h
*/

#include "rpg.h"

sfVector2f pos_bot_camp[] = {
    {2268, 1425},
    {2215, 1867},
    {1823, 2456},
    {2117, 2348},
    {681, 2389},
    {989, 2389},
    {1323, 2389},
    {114, 1866},
    {409, 1692},
    {303, 1034},
    {358, 617},
    {2505, 213},
    {2493, 804},
    {1552, 455},
    {880, 1072},
    {1659, 1716},
    {0, 0},
};

npc_t *set_camp_boss(sfTexture **text_tab, biome_t *biome)
{
    npc_t *camp_boss = set_goblins(text_tab[CAMP_BOSS_TEXT]);

    camp_boss->entity->effect_tab = set_effect_bot(
        text_tab, camp_boss->entity->sprite);
    camp_boss->entity->pos = (sfVector2f){1000, 1500};
    camp_boss->pv_bar =
        create_info_bar(sfRed, (sfVector2f){100, 7}, camp_boss->pv, NULL);
    camp_boss->pv_bar->act = camp_boss->pv;
    sfSprite_setPosition(camp_boss->entity->sprite, (sfVector2f){1000, 1500});
    add_to_list_bot(camp_boss, &(biome->bot_data->bot_list[GOBLINS_T]));
    manage_animation_bot(camp_boss->entity, true);
    return (camp_boss);
}

portal_t **create_portal_camp(void)
{
    portal_t **portal = malloc(sizeof(portal_t *) * 2);

    portal[0] = create_portal((sfVector2f){2846, 1414}, PLAIN);
    portal[1] = NULL;
    return portal;
}

biome_t *set_camp(sfTexture **text_tab, sfFont **)
{
    biome_t *camp = malloc(sizeof(biome_t));
    int bot_type[6] = {GOBLINS_D, GOBLINS_T, -1, -1, -1, -1};

    camp->back = add_background(
        text_tab[CAMP_SPRITE_TEXT], text_tab[CAMP_COLISION_TEXT]);
    camp->portal = NULL;
    camp->quest_giver = NULL;
    camp->bot_data = init_bot_data(text_tab);
    camp->last_pos = (sfVector2f){2846, 1414};
    camp->portal = create_portal_camp();
    for (int i = 0; i < 6; i++)
        camp->bot_type[i] = bot_type[i];
    camp->deco_data = NULL;
    camp->pos_bot = pos_bot_camp;
    camp->boss = set_camp_boss(text_tab, camp);
    return (camp);
}
