/*
** EPITECH PROJECT, 2023
** game
** File description:
** rpg.h
*/

#include "rpg.h"

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
    return (castle);
}
