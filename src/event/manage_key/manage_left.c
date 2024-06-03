/*
** EPITECH PROJECT, 2024
** movements
** File description:
** movements
*/

#include "rpg.h"

static void moov_left(rpg_t *rpg)
{
    sfVector2f pos = sfRectangleShape_getPosition(rpg->heros->npc->hitbox);
    float window_width = sfRenderWindow_getSize(rpg->window).x;
    sfFloatRect bounds = sfSprite_getGlobalBounds(wich_back(rpg));
    sfVector2f bounds2 = sfRectangleShape_getSize(rpg->heros->npc->hitbox);
    const sfView *view = sfRenderWindow_getView(rpg->window);
    sfVector2f viewCenter = sfView_getCenter(view);
    float left = viewCenter.x - window_width / 2;
    float movement = rpg->heros->speed * rpg->time;

    if (pos.x - movement < 0)
        return;
    rpg->heros->npc->entity->pos.x -= movement;
    if (left - movement > 0 && pos.x - movement + (bounds2.x / 2) <
        bounds.width - (window_width / 2)) {
        sfView_move((sfView *)view, (sfVector2f){-movement, 0.f});
        sfRenderWindow_setView(rpg->window, view);
    }
}

void manage_left(rpg_t *rpg)
{
    rpg->heros->npc->act_action = MOVE_L;
    moov_left(rpg);
}
