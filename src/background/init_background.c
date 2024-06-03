/*
** EPITECH PROJECT, 2024
** init
** File description:
** init
*/

#include "rpg.h"

void destroy_background(back_t *back)
{
    sfTexture_destroy(back->collision.texture);
    sfSprite_destroy(back->collision.sprite);
    sfTexture_destroy(back->sprite.texture);
    if (back->collision.col_image != NULL)
        sfImage_destroy(back->collision.col_image);
    sfSprite_destroy(back->sprite.sprite);
    free(back);
}

back_t *add_background(char *file, char *collision)
{
    back_t *new = malloc(sizeof(back_t));

    new->sprite.texture = sfTexture_createFromFile(file, NULL);
    new->sprite.sprite = sfSprite_create();
    new->sprite.pos = (sfVector2f){0, 0};
    sfSprite_setPosition(new->sprite.sprite, new->sprite.pos);
    sfSprite_setTexture(new->sprite.sprite, new->sprite.texture, sfTrue);
    new->collision.texture = sfTexture_createFromFile(collision, NULL);
    new->collision.sprite = sfSprite_create();
    sfSprite_setPosition(new->collision.sprite, new->sprite.pos);
    sfSprite_setTexture(new->collision.sprite, new->collision.texture, sfTrue);
    new->collision.col_image = sfTexture_copyToImage(new->collision.texture);
    return (new);
}

void display_background(back_t *back, sfRenderWindow *window)
{
    sfRenderWindow_drawSprite(window, back->sprite.sprite, NULL);
    sfRenderWindow_drawSprite(window, back->collision.sprite, NULL);
}
