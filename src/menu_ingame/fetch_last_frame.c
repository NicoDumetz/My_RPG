/*
** EPITECH PROJECT, 2024
** B-MUL-200-LIL-2-1-myrpg-matisse.dufour
** File description:
** fetch_last_frame.c
*/

#include "rpg.h"

void fetch_last_frame(rpg_t *rpg)
{
    sfImage* image = NULL;

    if (rpg->key_state[sfKeyEscape] && (rpg->scene >= PLAIN && rpg->scene <=
        TUTO)) {
        image = sfRenderWindow_capture(rpg->window);
        rpg->ingame_menu->last_frame = sfTexture_createFromImage(image, NULL);
        sfImage_destroy(image);
    }
}
