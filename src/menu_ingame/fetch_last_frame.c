/*
** EPITECH PROJECT, 2024
** B-MUL-200-LIL-2-1-myrpg-matisse.dufour
** File description:
** fetch_last_frame.c
*/

#include "rpg.h"

void fetch_last_frame(rpg_t *rpg)
{
    sfImage *image = NULL;
    sfTexture *text = NULL;
    sfVector2u size = sfRenderWindow_getSize(rpg->window);

    if (rpg->key_state[sfKeyEscape] && (rpg->scene >= PLAIN && rpg->scene <=
        TUTO)) {
        text = sfTexture_create(size.x, size.y);
        sfTexture_updateFromRenderWindow(text, rpg->window, 0, 0);
        image = sfTexture_copyToImage(text);
        if (image) {
            rpg->ingame_menu->last_frame =
            sfTexture_createFromImage(image, NULL);
            sfImage_destroy(image);
        }
        sfTexture_destroy(text);
    }
}
