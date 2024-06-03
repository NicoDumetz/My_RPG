/*
** EPITECH PROJECT, 2024
** init
** File description:
** init
*/

#include "rpg.h"

static void add_background(char *file, char *collision, rpg_t *rpg, int scene)
{
    back_t *new = malloc(sizeof(back_t));

    new->sprite.texture = sfTexture_createFromFile(file, NULL);
    new->sprite.sprite = sfSprite_create();
    new->sprite.pos = (sfVector2f){0, 0};
    new->scene = scene;
    sfSprite_setPosition(new->sprite.sprite, new->sprite.pos);
    sfSprite_setTexture(new->sprite.sprite, new->sprite.texture, sfTrue);
    sfSprite_setScale(new->sprite.sprite, (sfVector2f){3.5, 3.5});
    new->collision.texture = sfTexture_createFromFile(collision, NULL);
    new->collision.sprite = sfSprite_create();
    sfSprite_setPosition(new->collision.sprite, new->sprite.pos);
    sfSprite_setTexture(new->collision.sprite, new->collision.texture, sfTrue);
    sfSprite_setScale(new->collision.sprite, (sfVector2f){3.5, 3.5});
    new->next = rpg->back;
    rpg->back = new;
}

void init_background(rpg_t *rpg)
{
    rpg->back = NULL;
    add_background("maptest.png", "colisiontest.png", rpg, MAIN);
}

void display_background(rpg_t *rpg)
{
    back_t *current = rpg->back;

    for (; current; current = current->next) {
        if (current->scene == rpg->scene) {
            sfRenderWindow_drawSprite(rpg->window,
            current->sprite.sprite, NULL);
            sfRenderWindow_drawSprite(rpg->window,
            current->collision.sprite, NULL);
        }
    }
}
