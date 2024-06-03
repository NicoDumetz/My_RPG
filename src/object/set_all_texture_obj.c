/*
** EPITECH PROJECT, 2024
** movements
** File description:
** movements
*/

#include "rpg.h"

void set_texture_obj_next(sfTexture **text_tab)
{
    text_tab[GREAVES_LVL_2_TEXT] =
        sfTexture_createFromFile(GREAVES_LVL_2_PATH, NULL);
    text_tab[GREAVES_LVL_3_TEXT] =
        sfTexture_createFromFile(GREAVES_LVL_3_PATH, NULL);
    text_tab[SHOES_LVL_1_TEXT] =
        sfTexture_createFromFile(SHOES_LVL_1_PATH, NULL);
    text_tab[SHOES_LVL_2_TEXT] =
        sfTexture_createFromFile(SHOES_LVL_2_PATH, NULL);
    text_tab[SHOES_LVL_3_TEXT] =
        sfTexture_createFromFile(SHOES_LVL_3_PATH, NULL);
    text_tab[STAMI_LVL_1_TEXT] =
        sfTexture_createFromFile(STAMI_LVL_1_PATH, NULL);
    text_tab[STAMI_LVL_2_TEXT] =
        sfTexture_createFromFile(STAMI_LVL_2_PATH, NULL);
    text_tab[STEAK_TEXT] = sfTexture_createFromFile(STEAK_PATH, NULL);
    text_tab[XP_LVL_1_TEXT] = sfTexture_createFromFile(XP_LVL_1_PATH, NULL);
    text_tab[MUSHROOMS_TEXT] =
        sfTexture_createFromFile(MUSHROOMS_PATH, NULL);
}

void set_all_texture_obj(sfTexture **text_tab)
{
    text_tab[PV_LVL_1_TEXT] = sfTexture_createFromFile(PV_LVL_1_PATH, NULL);
    text_tab[PV_LVL_2_TEXT] = sfTexture_createFromFile(PV_LVL_2_PATH, NULL);
    text_tab[PV_LVL_3_TEXT] = sfTexture_createFromFile(PV_LVL_3_PATH, NULL);
    text_tab[HELMET_LVL_1_TEXT] =
        sfTexture_createFromFile(HELMET_LVL_1_PATH, NULL);
    text_tab[HELMET_LVL_2_TEXT] =
        sfTexture_createFromFile(HELMET_LVL_2_PATH, NULL);
    text_tab[HELMET_LVL_3_TEXT] =
        sfTexture_createFromFile(HELMET_LVL_3_PATH, NULL);
    text_tab[BREASTPLATE_LVL_1_TEXT] =
        sfTexture_createFromFile(BREASTPLATE_LVL_1_PATH, NULL);
    text_tab[BREASTPLATE_LVL_2_TEXT] =
        sfTexture_createFromFile(BREASTPLATE_LVL_2_PATH, NULL);
    text_tab[BREASTPLATE_LVL_3_TEXT] =
        sfTexture_createFromFile(BREASTPLATE_LVL_3_PATH, NULL);
    text_tab[GLOVES_LVL_2_TEXT] =
        sfTexture_createFromFile(GLOVES_LVL_2_PATH, NULL);
    text_tab[GLOVES_LVL_3_TEXT] =
        sfTexture_createFromFile(GLOVES_LVL_3_PATH, NULL);
    set_texture_obj_next(text_tab);
}
