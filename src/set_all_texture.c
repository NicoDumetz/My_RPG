/*
** EPITECH PROJECT, 2023
** game
** File description:
** rpg.h
*/

#include "rpg.h"
#include <SFML/Graphics/Texture.h>

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

void set_all_texture_next_two(sfTexture **text_tab)
{
    text_tab[HEADER_SAVE_TEXT] = sfTexture_createFromFile(
        HEADER_SAVE_PATH, NULL);
    text_tab[EXIT_B_P_TEXT] = sfTexture_createFromFile(
        EXIT_BUTTON_PRESS, NULL);
    text_tab[EXIT_B_R_TEXT] = sfTexture_createFromFile(
        EXIT_BUTTON_RELEASED, NULL);
    text_tab[FOOTER_SAVE_TEXT] = sfTexture_createFromFile(
        FOOTER_SAVE_PATH, NULL);
    text_tab[BLUE_LONG_P_TEXT] = sfTexture_createFromFile(
        BLUE_LONG_PRESS, NULL);
    text_tab[BLUE_LONG_R_TEXT] = sfTexture_createFromFile(
        BLUE_LONG_REL, NULL);
    text_tab[BUTTON_LONG_H_TEXT] = sfTexture_createFromFile(
        HOVER_LONG_BUT, NULL);
    text_tab[BACK_SAVE_TEXT] = sfTexture_createFromFile(BACK_SAVE_PATH, NULL);
    text_tab[LIFE_B_TEXT] = sfTexture_createFromFile(
        LIFE_BAR_PATH, NULL);
    text_tab[ENERGY_B_TEXT] = sfTexture_createFromFile(
        ENERGY_BAR_PATH, NULL);
}

void set_all_texture_next_three(sfTexture **text_tab)
{
    text_tab[XP_B_TEXT] = sfTexture_createFromFile(
        XP_BAR_PATH, NULL);
    text_tab[INVENTORY_TEXT] = sfTexture_createFromFile(INVENTORY_BACK, NULL);
    text_tab[INVENTORY_SLOT_TEXT] = sfTexture_createFromFile(INVENTORY_SLOT,
    NULL);
    text_tab[MINE_BOSS_TEXT] = sfTexture_createFromFile(
        MINE_BOSS_PATH, NULL);
    text_tab[CAMP_BOSS_TEXT] = sfTexture_createFromFile(
        CAMP_BOSS_PATH, NULL);
    text_tab[CASTLE_BOSS_TEXT] = sfTexture_createFromFile(
        CASTLE_BOSS_PATH, NULL);
    text_tab[ARENE_COL_TEXT] = sfTexture_createFromFile(
        ARENE_COL_PATH, NULL);
    text_tab[ARENE_TEXT] = sfTexture_createFromFile(
        ARENE_PATH, NULL);
    text_tab[EXPLO_TEXT] = sfTexture_createFromFile(EXPLO_PATH, NULL);
    text_tab[ARROW_TEXT] = sfTexture_createFromFile(ARROWS, NULL);
    text_tab[DYNA_TEXT] = sfTexture_createFromFile(DYNAMITE, NULL);
    text_tab[SHIELD_TEXT] = sfTexture_createFromFile(SHIELD_PATH, NULL);
}

static void set_all_texture_next_four(sfTexture **text_tab)
{
    text_tab[HEARTH_POTION_TEXT] =
    sfTexture_createFromFile(HEARTH_POTION_PATH, NULL);
    text_tab[HELMET_TEXT] = sfTexture_createFromFile(HELMET_PATH, NULL);
    text_tab[BACK_INVENTORY_HERO] = sfTexture_createFromFile(BACK_HERO, NULL);
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
    text_tab[BLOOD_TEXT] = sfTexture_createFromFile(BLOOD_PATH, NULL);
    text_tab[COIN_TEXT] = sfTexture_createFromFile(COIN_PATH, NULL);
    set_all_texture_next_four(text_tab);
    set_all_texture_next_three(text_tab);
    set_all_texture_next_two(text_tab);
    set_all_texture_next(text_tab);
}
