/*
** EPITECH PROJECT, 2024
** B-MUL-200-LIL-2-1-myrpg-matisse.dufour
** File description:
** stats.c
*/

#include "rpg.h"

static void set_text(sfText *text, char *categorie, int actual, int max)
{
    char str[255];

    snprintf(str, 255, "%-5s %5d/%d", categorie, actual, max);
    sfText_setString(text, str);
}

static sfVector2f set_back_pos(inventory_t *inventory, rpg_t *rpg)
{
    sfFloatRect hero_pos =
    sfRectangleShape_getGlobalBounds(inventory->hero_pos);
    sfVector2f pos = {hero_pos.left + hero_pos.width, hero_pos.top};

    sfRectangleShape_setPosition(inventory->stats.stats_pos, pos);
    sfRenderWindow_drawRectangleShape(rpg->window, inventory->stats.stats_pos,
    NULL);
    return pos;
}

void set_stats(inventory_t *inventory, rpg_t *rpg)
{
    sfVector2f back_pos = set_back_pos(inventory, rpg);
    sfVector2f pos = back_pos;

    set_text(inventory->stats.pv, "PV", rpg->heros->npc->pv,
    rpg->heros->pv_max);
    pos.x += inventory->stats.pv_pos.x;
    pos.y += inventory->stats.pv_pos.y;
    sfText_setPosition(inventory->stats.pv, pos);
    sfRenderWindow_drawText(rpg->window, inventory->stats.pv, NULL);
    set_text(inventory->stats.xp, "XP", rpg->heros->npc->xp,
    level_tab[rpg->heros->level_act].xp_to_reach);
    pos = back_pos;
    pos.x += inventory->stats.xp_pox.x;
    pos.y += inventory->stats.xp_pox.y;
    sfText_setPosition(inventory->stats.xp, pos);
    sfRenderWindow_drawText(rpg->window, inventory->stats.xp, NULL);
}

void destroy_stats(inventory_t *inventory)
{
    sfRectangleShape_destroy(inventory->stats.stats_pos);
    sfText_destroy(inventory->stats.pv);
    sfText_destroy(inventory->stats.xp);
}

static void init_texts_stat(inventory_t *inventory, sfFont **font_tab)
{
    sfVector2f pos = {0.f, 0.f};
    unsigned int size = 30;
    sfFloatRect back_rect =
    sfRectangleShape_getGlobalBounds(inventory->stats.stats_pos);
    float padding = back_rect.height - (size * 2);

    inventory->stats.pv = sfText_create();
    sfText_setFont(inventory->stats.pv, font_tab[PIXEL]);
    sfText_setCharacterSize(inventory->stats.pv, size);
    sfText_setColor(inventory->stats.pv, sfRed);
    inventory->stats.pv_pos = pos;
    pos.y += padding;
    inventory->stats.xp = sfText_create();
    sfText_setFont(inventory->stats.xp, font_tab[PIXEL]);
    sfText_setCharacterSize(inventory->stats.xp, size);
    sfText_setColor(inventory->stats.xp, sfBlue);
    inventory->stats.xp_pox = pos;
}

void init_stats(inventory_t *inventory, sfFont **font_tab)
{
    inventory->stats.stats_pos = sfRectangleShape_create();
    sfRectangleShape_setOutlineColor(inventory->stats.stats_pos, sfRed);
    sfRectangleShape_setOutlineThickness(inventory->stats.stats_pos, 2.f);
    sfRectangleShape_setFillColor(inventory->stats.stats_pos, sfTransparent);
    sfRectangleShape_setSize(inventory->stats.stats_pos,
    (sfVector2f){200.f, 100.f});
    init_texts_stat(inventory, font_tab);
}
