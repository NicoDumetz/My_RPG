/*
** EPITECH PROJECT, 2024
** B-MUL-200-LIL-2-1-myrpg-matisse.dufour
** File description:
** inventory.c
*/

#include "rpg.h"
#include <SFML/Graphics/RenderWindow.h>
#include <SFML/Graphics/Sprite.h>
#include <SFML/Graphics/View.h>
#include <SFML/Window/Keyboard.h>

static bool inventory_state(rpg_t *rpg)
{
    static int open = 0;
    static int pressed = 0;

    if (!rpg->key_state[sfKeyTab])
        pressed = 0;
    if (rpg->key_state[sfKeyTab] && !pressed) {
        pressed = 1;
        open = (open == 0) ? 1 : 0;
    }
    if (open)
        return false;
    return true;
}

void inventory(rpg_t *rpg)
{
    const sfView *view = sfRenderWindow_getView(rpg->window);

    if (inventory_state(rpg))
        return;
    sfSprite_setPosition(rpg->heros->invent.sprite, sfView_getCenter(view));
    sfRenderWindow_drawSprite(rpg->window, rpg->heros->invent.sprite, NULL);
}
