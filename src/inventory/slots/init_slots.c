/*
** EPITECH PROJECT, 2024
** B-MUL-200-LIL-2-1-myrpg-matisse.dufour
** File description:
** init_slots.c
*/

#include "rpg.h"

void destroy_slots(inventory_t *inventory)
{
    sfRectangleShape_destroy(inventory->slot_pos);
    sfRectangleShape_destroy(inventory->equipment_pos);
    for (unsigned char i = 0; i < NUM_SLOT; i++)
        destroy_button(inventory->slot[i]);
    for (unsigned char i = 0; i < NUM_EQUIPMENT; i++)
        destroy_button(inventory->equipment[i]);
}

static void set_inventory_slot_pos(inventory_t *inventory)
{
    sfVector2f back_size = sfRectangleShape_getSize(inventory->slot_pos);
    sfFloatRect button_rect =
    sfSprite_getGlobalBounds(inventory->slot[0]->sprite);
    float space = (back_size.x - button_rect.width * SLOT_PER_LINE) /
    (SLOT_PER_LINE + 1);
    sfVector2f pos = {0.f, 0.f};

    for (unsigned char i = 0; i < NUM_SLOT; i += SLOT_PER_LINE) {
        pos.y += space;
        for (unsigned char j = 0; j < SLOT_PER_LINE; j++) {
            pos.x += space;
            inventory->slot[i + j]->pos = pos;
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
    newsize.x = ((back_rect.width - 10.f) / 2.f) * 0.65;
    newsize.y = (back_rect.height - 50.f) * 0.85;
    sfRectangleShape_setSize(inventory->slot_pos, newsize);
    set_inventory_slot_pos(inventory);
}

static sfFloatRect init_equipment_pos(inventory_t *inventory)
{
    sfFloatRect back_rect = sfSprite_getGlobalBounds(inventory->background);
    sfVector2f newsize;
    sfVector2f pos = {0.f, 0.f};

    inventory->equipment_pos = sfRectangleShape_create();
    sfRectangleShape_setOutlineColor(inventory->equipment_pos, sfRed);
    sfRectangleShape_setOutlineThickness(inventory->equipment_pos, 2.f);
    sfRectangleShape_setFillColor(inventory->equipment_pos, sfTransparent);
    newsize.x = inventory->slot_rect.width;
    newsize.y = back_rect.height / 2.5;
    sfRectangleShape_setSize(inventory->equipment_pos, newsize);
    sfRectangleShape_setPosition(inventory->equipment_pos, pos);
    return sfRectangleShape_getGlobalBounds(inventory->equipment_pos);
}

static void init_equipment(inventory_t *inventory, sfTexture **text_tab,
    int text_index[5], sfVector2f button_scale)
{
    sfVector2f pos = {0.f, 0.f};
    sfFloatRect back_rect = init_equipment_pos(inventory);
    float padding = (back_rect.height -
    NUM_EQUIPMENT * inventory->slot_rect.height) / (NUM_EQUIPMENT - 1);

    for (unsigned char i = 0; i < NUM_EQUIPMENT; i++) {
        inventory->equipment[i] = create_button(text_tab, text_index);
        init_action_button(NULL, NULL, NULL, inventory->equipment[i]);
        init_action_button(unequip_equipment, NULL, NULL,
        inventory->equipment[i]);
        sfSprite_setScale(inventory->equipment[i]->sprite, button_scale);
        inventory->equipment[i]->pos = pos;
        pos.y += inventory->slot_rect.height + padding;
    }
}

void init_slots(inventory_t *inventory, sfTexture **texture_tab)
{
    int text_index[5] = {INVENTORY_SLOT_TEXT, -1, -1, -1, -1};
    sfVector2f button_scale = {1.2, 1.2};

    for (unsigned char i = 0; i < NUM_SLOT; i++) {
        inventory->slot[i] = create_button(texture_tab, text_index);
        init_action_button(use_item, NULL, NULL, inventory->slot[i]);
        sfSprite_setScale(inventory->slot[i]->sprite, button_scale);
    }
    init_slot_pos(inventory);
    inventory->slot_rect =
    sfSprite_getGlobalBounds(inventory->slot[0]->sprite);
    init_equipment(inventory, texture_tab, text_index, button_scale);
}
