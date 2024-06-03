/*
** EPITECH PROJECT, 2023
** graph.h
** File description:
** macro for CSFML
*/

#include "rpg.h"

void manage_heros_bar(heros_t *heros, sfRenderWindow *window)
{
    const sfView *view = sfRenderWindow_getView(window);
    sfVector2f center = sfView_getCenter(view);
    sfVector2f size_view = sfView_getSize(view);
    sfVector2f pos = {(center.x - size_view.x / 2) + ((size_view.x / 100) * 1),
        center.y - size_view.y / 2 + ((size_view.x / 100) * 1)};
    float delta = 0;

    heros->bar_tab[LIFE_BAR]->act = heros->npc->pv;
    heros->bar_tab[XP_BAR]->act = heros->npc->xp;
    heros->bar_tab[STAMINA_BAR]->act = heros->stamina;
    for (int i = 0; i <= STAMINA_BAR; i++) {
        delta = heros->bar_tab[i]->size.y + 10;
        update_bar(heros->bar_tab[i], pos);
        sfRenderWindow_drawRectangleShape(
            window, heros->bar_tab[i]->bar, NULL);
        pos.y += delta;
    }
}
