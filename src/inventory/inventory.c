/*
** EPITECH PROJECT, 2024
** B-MUL-200-LIL-2-1-myrpg-matisse.dufour
** File description:
** inventory.c
*/

#include "rpg.h"
#include <SFML/Graphics/Sprite.h>

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

static void inventory_slot_management(inventory_t *inventory,
    mouse_data_t *mouse_data, rpg_t *rpg)
{
    for (unsigned char i = 0; i < NUM_SLOT; i++)
        update_button(inventory->slot[i], mouse_data, rpg);
    for (unsigned char i = 0; i < NUM_EQUIPMENT; i++)
        update_button(inventory->equipment[i], mouse_data, rpg);
}

static void hero_picture(rpg_t *rpg)
{
    sfSprite *hero_sprite = rpg->heros->npc->entity->sprite;
    sfFloatRect equipment_rect =
    sfRectangleShape_getGlobalBounds(rpg->inventory.equipment_pos);
    sfVector2f pos = {equipment_rect.left + equipment_rect.width,
    equipment_rect.top};
    sfVector2f save_scale = sfSprite_getScale(hero_sprite);
    sfVector2f save_pos = sfSprite_getPosition(hero_sprite);
    sfVector2f hero_scale = rpg->inventory.hero_scale;

    sfRectangleShape_setPosition(rpg->inventory.hero_pos, pos);
    sfRenderWindow_drawRectangleShape(rpg->window, rpg->inventory.hero_pos,
    NULL);
    if (save_scale.x < 0)
        hero_scale.x *= -1.f;
    sfSprite_setScale(hero_sprite, hero_scale);
    sfSprite_setPosition(hero_sprite, pos);
    sfRenderWindow_drawSprite(rpg->window, hero_sprite, NULL);
    sfSprite_setScale(hero_sprite, save_scale);
    sfSprite_setPosition(hero_sprite, save_pos);
}

void manage_inventory(rpg_t *rpg)
{
    const sfView *view = sfRenderWindow_getView(rpg->window);
    sfFloatRect pos;

    if (inventory_state(rpg))
        return;
    sfSprite_setPosition(rpg->inventory.background, sfView_getCenter(view));
    pos = sfSprite_getGlobalBounds(rpg->inventory.background);
    sfRenderWindow_drawSprite(rpg->window, rpg->inventory.background, NULL);
    set_slot_pos(rpg, &pos);
    inventory_slot_management(&rpg->inventory, &rpg->mouse_data, rpg);
    draw_slots(rpg, &rpg->inventory);
    hero_picture(rpg);
    set_stats(&rpg->inventory, rpg);
    manage_skill_tree(&rpg->inventory, rpg);
}

button_t *get_free_slot(button_t **list, unsigned char size_list)
{
    for (unsigned char i = 0; i < size_list; i++) {
        if (list[i]->child == NULL)
            return list[i];
    }
    return NULL;
}
