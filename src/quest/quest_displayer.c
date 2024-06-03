/*
** EPITECH PROJECT, 2023
** game
** File description:
** rpg.h
*/

#include "rpg.h"

void set_position_quest(quest_t *quest, sfVector2f pos)
{
    sfVector2f rect_size = sfRectangleShape_getSize(quest->box);
    sfVector2f text_pos = {pos.x + rect_size.x + 10, pos.y - rect_size.y};

    sfRectangleShape_setPosition(quest->box, pos);
    sfText_setPosition(quest->display, text_pos);
}

void quest_displayer(quest_t *quest_tab, sfRenderWindow *window)
{
    const sfView *view = sfRenderWindow_getView(window);
    sfVector2f center = sfView_getCenter(view);
    sfVector2f size_view = sfView_getSize(view);
    sfVector2f pos =
        {(center.x - size_view.x / 2) + ((size_view.x / 100) * 80),
        center.y - size_view.y / 2 + ((size_view.x / 100) * 1)};
    float delta = 0;

    for (int i = 0; i <= KILL_CASTLE; i++) {
        if (quest_tab[i].state != NOT_BEGIN) {
            delta = 40;
            set_position_quest(&(quest_tab[i]), pos);
            sfRenderWindow_drawRectangleShape(
            window, quest_tab[i].box, NULL);
            sfRenderWindow_drawText(
            window, quest_tab[i].display, NULL);
        pos.y += delta;
        }
    }
}
