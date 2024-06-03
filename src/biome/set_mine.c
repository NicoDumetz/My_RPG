/*
** EPITECH PROJECT, 2023
** game
** File description:
** rpg.h
*/

#include "rpg.h"

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
    int bot_type[6] = {KNIGHT, ARCHER, GOBLINS_D, GOBLINS_B, -1, -1};

    mine->back = add_background(
        text_tab[MINE_B_TEXT], text_tab[MINE_COLISION_TEXT]);
    mine->bot_data = init_bot_data(text_tab);
    mine->portal = create_portal_mine();
    mine->quest_giver = NULL;
    mine->last_pos = (sfVector2f){1994, 0};
    for (int i = 0; i < 6; i++)
        mine->bot_type[i] = bot_type[i];
    mine->deco_data = NULL;
    return (mine);
}
