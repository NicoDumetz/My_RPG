/*
** EPITECH PROJECT, 2024
** B-MUL-200-LIL-2-1-myrpg-matisse.dufour
** File description:
** stats.c
*/

#include "rpg.h"
#include <stdio.h>

static void set_text(sfText *text, char *categorie, int actual, int max)
{
    char str[255] = "Error";
    char data[64] = "Error";

    if (max > 0)
        snprintf(data, 64, "%d/%d", actual, max);
    else
        snprintf(data, 64, "%d", actual);
    snprintf(str, 255, "%-7s %7s", categorie, data);
    sfText_setString(text, str);
}

static sfVector2f set_back_pos(inventory_t *inventory, rpg_t *rpg)
{
    sfFloatRect hero_pos =
    sfRectangleShape_getGlobalBounds(inventory->hero_pos);
    sfVector2f pos = {hero_pos.left + hero_pos.width + 10.f, hero_pos.top};

    sfRectangleShape_setPosition(inventory->stats_pos, pos);
    sfRenderWindow_drawRectangleShape(rpg->window, inventory->stats_pos, NULL);
    return pos;
}

void set_stats(inventory_t *inventory, rpg_t *rpg)
{
    sfVector2f back_pos = set_back_pos(inventory, rpg);
    sfVector2f pos = back_pos;

    set_text(inventory->stats[PV_STAT].text, "PV", rpg->heros->npc->pv,
    rpg->heros->pv_max);
    set_text(inventory->stats[XP_STAT].text, "XP", rpg->heros->npc->xp,
    level_tab[rpg->heros->level_act].xp_to_reach);
    set_text(inventory->stats[SPEED_STAT].text, "Speed",
    rpg->heros->speed * rpg->heros->multi_speed, -1);
    set_text(inventory->stats[STAMINA_STAT].text, "Stamina",
    rpg->heros->stamina, rpg->heros->stamina_max);
    set_text(inventory->stats[ATTACK_STAT].text, "Attack",
    rpg->heros->npc->attack, -1);
    for (unsigned i = 0; i < COUNT_STATS; i++) {
        pos.x += inventory->stats[i].pos.x;
        pos.y += inventory->stats[i].pos.y;
        sfText_setPosition(inventory->stats[i].text, pos);
        sfRenderWindow_drawText(rpg->window, inventory->stats[i].text, NULL);
        pos = back_pos;
    }
}

void destroy_stats(inventory_t *inventory)
{
    sfRectangleShape_destroy(inventory->stats_pos);
    for (unsigned char i = 0; i < COUNT_STATS; i++)
        sfText_destroy(inventory->stats[i].text);
}

static void init_texts_stat(inventory_t *inventory, sfFont **font_tab)
{
    sfVector2f pos = {0.f, 0.f};
    unsigned int size = 30;
    sfFloatRect back_rect =
    sfRectangleShape_getGlobalBounds(inventory->stats_pos);
    float padding = (back_rect.height - (size * COUNT_STATS)) /
    (COUNT_STATS - 1);

    for (unsigned char i = 0; i < COUNT_STATS; i++) {
        inventory->stats[i].text = sfText_create();
        sfText_setFont(inventory->stats[i].text, font_tab[PIXEL]);
        sfText_setOutlineThickness(inventory->stats[i].text, 0.8);
        sfText_setOutlineColor(inventory->stats[i].text, sfBlack);
        sfText_setCharacterSize(inventory->stats[i].text, size);
        inventory->stats[i].pos = pos;
        pos.y += padding;
    }
}

void init_stats(inventory_t *inventory, sfFont **font_tab)
{
    sfFloatRect hero_pos =
    sfRectangleShape_getGlobalBounds(inventory->hero_pos);

    inventory->stats_pos = sfRectangleShape_create();
    sfRectangleShape_setOutlineColor(inventory->stats_pos, sfRed);
    sfRectangleShape_setOutlineThickness(inventory->stats_pos, 2.f);
    sfRectangleShape_setFillColor(inventory->stats_pos, sfTransparent);
    sfRectangleShape_setSize(inventory->stats_pos,
    (sfVector2f){200.f, hero_pos.height});
    init_texts_stat(inventory, font_tab);
    sfText_setColor(inventory->stats[PV_STAT].text, sfRed);
    sfText_setColor(inventory->stats[XP_STAT].text, sfBlue);
    sfText_setColor(inventory->stats[SPEED_STAT].text, sfYellow);
    sfText_setColor(inventory->stats[ATTACK_STAT].text,
    sfColor_fromRGB(168, 35, 35));
    sfText_setColor(inventory->stats[STAMINA_STAT].text,
    sfColor_fromRGB(163, 106, 0));
}
