/*
** EPITECH PROJECT, 2024
** init
** File description:
** init
*/

#include "rpg.h"

void destroy_background(back_t *back)
{
    sfSprite_destroy(back->collision.sprite);
    back->collision.sprite = NULL;
    if (back->collision.col_image != NULL) {
        sfImage_destroy(back->collision.col_image);
        back->collision.col_image = NULL;
    }
    sfSprite_destroy(back->sprite.sprite);
    back->sprite.sprite = NULL;
    free(back);
    back = NULL;
}

back_t *add_background(sfTexture *file, sfTexture *collision)
{
    back_t *new = malloc(sizeof(back_t));

    new->sprite.texture = file;
    new->sprite.sprite = sfSprite_create();
    new->sprite.pos = (sfVector2f){0, 0};
    sfSprite_setPosition(new->sprite.sprite, new->sprite.pos);
    sfSprite_setTexture(new->sprite.sprite, new->sprite.texture, sfTrue);
    new->collision.texture = collision;
    new->collision.sprite = sfSprite_create();
    sfSprite_setPosition(new->collision.sprite, new->sprite.pos);
    sfSprite_setTexture(new->collision.sprite, new->collision.texture, sfTrue);
    new->collision.col_image = sfTexture_copyToImage(new->collision.texture);
    return (new);
}

void display_background(back_t *back, sfRenderWindow *window)
{
    sfRenderWindow_drawSprite(window, back->sprite.sprite, NULL);
}
