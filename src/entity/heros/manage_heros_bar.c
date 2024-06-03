/*
** EPITECH PROJECT, 2023
** graph.h
** File description:
** macro for CSFML
*/

#include "rpg.h"

void manage_heros_level_display(
    heros_t *heros, int i, sfVector2f pos, sfRenderWindow *window)
{
    sfText *text = heros->bar_tab[i]->text;
    char *level = convert_int_to_str(heros->level_act);

    if (text == NULL) {
        free(level);
        return;
    }
    sfText_setPosition(text, (sfVector2f){pos.x - 20, pos.y -10});
    sfText_setString(text, level);
    sfText_setScale(text, (sfVector2f){1, 1});
    sfRenderWindow_drawText(window, text, NULL);
    free(level);
}

void manage_heros_bar(heros_t *heros, sfRenderWindow *window)
{
    const sfView *view = sfRenderWindow_getView(window);
    sfVector2f center = sfView_getCenter(view);
    sfVector2f size_view = sfView_getSize(view);
    sfVector2f pos = {(center.x - size_view.x / 2) + ((size_view.x / 100) * 3),
        center.y - size_view.y / 2 + ((size_view.x / 100) * 1)};
    float delta = 0;

    heros->bar_tab[LIFE_BAR]->act = heros->npc->pv;
    heros->bar_tab[XP_BAR]->act = heros->npc->xp;
    heros->bar_tab[STAMINA_BAR]->act = heros->stamina;
    for (int i = 0; i <= STAMINA_BAR; i++) {
        delta = heros->bar_tab[i]->size.y + 30;
        update_bar(heros->bar_tab[i], pos);
        sfRenderWindow_drawRectangleShape(
            window, heros->bar_tab[i]->bar, NULL);
        sfRenderWindow_drawSprite(
            window, heros->bar_tab[i]->deco, NULL);
        manage_heros_level_display(heros, i, pos, window);
        pos.y += delta;
    }
}
