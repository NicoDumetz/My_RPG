/*
** EPITECH PROJECT, 2023
** game
** File description:
** rpg.h
*/

#include "rpg.h"

void set_all_texture_next(sfTexture **text_tab)
{
    text_tab[DEATH_TEXT] = sfTexture_createFromFile(DEATH_PATH, NULL);
    text_tab[KNIGHT_TEXT] = sfTexture_createFromFile(KNIGHT_SPRITE, NULL);
    text_tab[ARCHER_TEXT] = sfTexture_createFromFile(ARCHER_SPRITE, NULL);
    text_tab[MINIONS_TEXT] = sfTexture_createFromFile(MINIONS_SPRITE, NULL);
    text_tab[GOBLINS_T_TEXT] = sfTexture_createFromFile(
        GOBLINS_T_SPRITE, NULL);
    text_tab[GOBLINS_B_TEXT] = sfTexture_createFromFile(
        GOBLINS_B_SPRITE, NULL);
    text_tab[GOBLINS_D_TEXT] = sfTexture_createFromFile(
        GOBLINS_D_SPRITE, NULL);
    text_tab[PLAINE_SPRITE_TEXT] = sfTexture_createFromFile(
        PLAINE_SPRITE, NULL);
    text_tab[PLAINE_COLISION_TEXT] = sfTexture_createFromFile(
        PLAINE_COLISION, NULL);
    text_tab[MINE_B_TEXT] = sfTexture_createFromFile(MINE_SPRITE, NULL);
    text_tab[MINE_COLISION_TEXT] = sfTexture_createFromFile(
        MINE_COLISION, NULL);
    text_tab[CAMP_SPRITE_TEXT] = sfTexture_createFromFile(CAMP_SPRITE, NULL);
    text_tab[CAMP_COLISION_TEXT] = sfTexture_createFromFile(
        CAMP_COLISION, NULL);
}

void set_all_texture(sfTexture **text_tab)
{
    text_tab[VILLAGE_SPRITE_TEXT] = sfTexture_createFromFile(
        VILLAGE_SPRITE, NULL);
    text_tab[VILLAGE_COLISION_TEXT] = sfTexture_createFromFile(
        VILLAGE_COLISION, NULL);
    text_tab[CASTLE_SPRITE_TEXT] = sfTexture_createFromFile(
        CASTLE_SPRITE, NULL);
    text_tab[CASTLE_COLISION_TEXT] = sfTexture_createFromFile(
        CASTLE_COLISION, NULL);
    text_tab[KNIGHT_HOUSE_TEXT] = sfTexture_createFromFile(
        KNIGHT_H_SPRITE, NULL);
    text_tab[TREE_SPRITE_TEXT] = sfTexture_createFromFile(TREE_SPRITE, NULL);
    text_tab[MINE_TEXT] = sfTexture_createFromFile(MINE_S, NULL);
    text_tab[LEVEL_UP_TEXT] = sfTexture_createFromFile(LEVEL_UP_PATH, NULL);
    text_tab[BAG_TEXT] = sfTexture_createFromFile(BAG_PATH, NULL);
    set_all_texture_next(text_tab);
}
