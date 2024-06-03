/*
** EPITECH PROJECT, 2023
** game
** File description:
** rpg.h
*/

#include "rpg.h"

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
    int bot_type[6] = {GOBLINS_B, GOBLINS_D, GOBLINS_T, -1, -1, -1};

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
    return (camp);
}
