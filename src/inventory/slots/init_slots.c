/*
** EPITECH PROJECT, 2024
** B-MUL-200-LIL-2-1-myrpg-matisse.dufour
** File description:
** init_slots.c
*/

#include "rpg.h"
#include <SFML/Graphics/Rect.h>
#include <SFML/Graphics/RectangleShape.h>
#include <SFML/Graphics/RenderWindow.h>
#include <SFML/Graphics/Sprite.h>
#include <SFML/Graphics/Types.h>
#include <SFML/System/Vector2.h>
#include <SFML/Window/Keyboard.h>
#include <stdio.h>

void destroy_slots(inventory_t *inventory)
{
    sfRectangleShape_destroy(inventory->slot_pos);
    for (unsigned char i = 0; i < NUM_SLOT; i++) {
        destroy_button(inventory->slot[i].button);
    }
}

static void set_inventory_slot_pos(inventory_t *inventory)
{
    sfVector2f back_size = sfRectangleShape_getSize(inventory->slot_pos);
    sfFloatRect button_rect =
    sfSprite_getGlobalBounds(inventory->slot[0].button->sprite);
    float space = (back_size.x - button_rect.width * SLOT_PER_LINE) /
    (SLOT_PER_LINE + 1);
    sfVector2f pos = {0.f, 0.f};

    for (unsigned char i = 0; i < NUM_SLOT; i += SLOT_PER_LINE) {
        pos.y += space;
        for (unsigned char j = 0; j < SLOT_PER_LINE; j++) {
            pos.x += space;
            inventory->slot[i + j].pos = pos;
            pos.x += button_rect.width;
        }
        pos.y += button_rect.width;
        pos.x = 0.f;
    }
}

static void init_slot_pos(inventory_t *inventory)
{
    sfFloatRect back_rect = sfSprite_getGlobalBounds(inventory->background);
    sfVector2f newsize;

    inventory->slot_pos = sfRectangleShape_create();
    sfRectangleShape_setOutlineColor(inventory->slot_pos, sfRed);
    sfRectangleShape_setOutlineThickness(inventory->slot_pos, 2.f);
    sfRectangleShape_setFillColor(inventory->slot_pos, sfTransparent);
    newsize.x = ((back_rect.width - 10.f) / 2.f) * 0.85;
    newsize.y = (back_rect.height - 50.f) * 0.85;
    sfRectangleShape_setSize(inventory->slot_pos, newsize);
    set_inventory_slot_pos(inventory);
}

void init_slots(inventory_t *inventory, sfTexture **texture_tab)
{
    int text_index[5] = {INVENTORY_SLOT_TEXT, -1, -1, -1, -1};

    for (unsigned char i = 0; i < NUM_SLOT; i++) {
        inventory->slot[i].button = create_button(texture_tab, text_index);
        init_action_button(NULL, NULL, NULL, inventory->slot[i].button);
        sfSprite_setScale(inventory->slot[i].button->sprite,
        (sfVector2f){1.0, 1.0});
    }
    init_slot_pos(inventory);
}
