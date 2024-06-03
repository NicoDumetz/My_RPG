/*
** EPITECH PROJECT, 2024
** perso_rpg
** File description:
** init_inventory.c
*/
#include "rpg.h"

void destroy_inventory(inventory_t *inventory)
{
    sfRectangleShape_destroy(inventory->hero_pos);
    inventory->hero_pos = NULL;
    sfSprite_destroy(inventory->background);
    inventory->background = NULL;
    destroy_slots(inventory);
    destroy_stats(inventory);
}

void flush_inventory(inventory_t *inventory, heros_t *hero)
{
    for (unsigned char i = 0; i < NUM_SLOT; i++) {
        if (inventory->slot[i]->child == NULL)
            continue;
        delete_from_list(inventory->slot[i]->child, &hero->inventory);
        destroy_back_obj(inventory->slot[i]->child);
        inventory->slot[i]->child = NULL;
    }
    for (unsigned char i = 0; i < NUM_EQUIPMENT; i++) {
        if (inventory->equipment[i]->child == NULL)
            continue;
        delete_from_list(inventory->equipment[i]->child, &hero->inventory);
        destroy_back_obj(inventory->equipment[i]->child);
        inventory->equipment[i]->child = NULL;
    }
}

static void init_heros_square(inventory_t *inventory, sfTexture **texture_tab,
    rpg_t *rpg)
{
    sfFloatRect hero =
    sfSprite_getLocalBounds(rpg->heros->npc->entity->sprite);
    sfFloatRect equip_pos =
    sfRectangleShape_getGlobalBounds(inventory->equipment_pos);
    float hero_scale = equip_pos.height / hero.height;

    inventory->hero_scale = (sfVector2f){hero_scale, hero_scale};
    inventory->hero_pos = sfRectangleShape_create();
    sfRectangleShape_setOutlineColor(inventory->hero_pos, sfRed);
    sfRectangleShape_setOutlineThickness(inventory->hero_pos, 2.f);
    sfRectangleShape_setSize(inventory->hero_pos,
    (sfVector2f){hero.width * hero_scale, equip_pos.height});
    sfRectangleShape_setTexture(inventory->hero_pos,
    texture_tab[BACK_INVENTORY_HERO], sfTrue);
}

void init_inventory(inventory_t *inventory, sfTexture **texture_tab,
    rpg_t *rpg)
{
    sfVector2u size = sfTexture_getSize(texture_tab[INVENTORY_TEXT]);

    inventory->background = sfSprite_create();
    sfSprite_setTexture(inventory->background, texture_tab[INVENTORY_TEXT],
    sfTrue);
    sfSprite_setOrigin(inventory->background, (sfVector2f){size.x / 2.f,
    size.y / 2.f + 10.f});
    sfSprite_scale(inventory->background, (sfVector2f){3.f, 3.f});
    init_slots(inventory, texture_tab);
    init_heros_square(inventory, texture_tab, rpg);
    init_stats(inventory, rpg->font_tab);
}
