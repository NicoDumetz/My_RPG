/*
** EPITECH PROJECT, 2024
** B-MUL-200-LIL-2-1-myrpg-matisse.dufour
** File description:
** set_slots.c
*/

#include "rpg.h"
#include <SFML/Graphics/RenderWindow.h>
#include <SFML/Graphics/Sprite.h>
#include <SFML/System/Vector2.h>
#include <stdio.h>

void set_slot_pos(rpg_t *rpg, sfFloatRect *background_pos)
{
    sfVector2f pos;
    sfVector2f button_pos;

    pos.x = background_pos->left + background_pos->width * 0.07;
    pos.y = background_pos->top + background_pos->height * 0.05;
    sfRectangleShape_setPosition(rpg->inventory.slot_pos, pos);
    sfRenderWindow_drawRectangleShape(rpg->window, rpg->inventory.slot_pos,
    NULL);
    for (unsigned char i = 0; i < NUM_SLOT; i++) {
        button_pos = rpg->inventory.slot[i].pos;
        button_pos.x += pos.x;
        button_pos.y += pos.y;
        sfSprite_setPosition(rpg->inventory.slot[i].button->sprite,
        button_pos);
        sfRenderWindow_drawSprite(rpg->window,
        rpg->inventory.slot[i].button->sprite, NULL);
    }
}
