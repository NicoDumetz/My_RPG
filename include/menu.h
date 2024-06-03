/*
** EPITECH PROJECT, 2024
** B-MUL-200-LIL-2-1-myrpg-matisse.dufour
** File description:
** menu.h
*/

#ifndef MENU_H_
    #define MENU_H_
    #include "lib.h"

typedef struct menu_s {
    int pos;
    sfTexture **texture;
    sfSprite **sprite;
} menu_t;

#endif /* !MENU_H_ */
