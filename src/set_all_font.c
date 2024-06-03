/*
** EPITECH PROJECT, 2023
** game
** File description:
** rpg.h
*/

#include "rpg.h"

void set_all_font(sfFont **font_tab)
{
    font_tab[PIXEL] = sfFont_createFromFile(PIXEL_F_PATH);
}
