/*
** EPITECH PROJECT, 2024
** movements
** File description:
** movements
*/

#include "rpg.h"

static void moov_right(rpg_t *rpg)
{
    sfVector2f pos = sfRectangleShape_getPosition(rpg->heros->npc->hitbox);
    sfFloatRect bounds = sfSprite_getGlobalBounds(wich_back(rpg));
    sfVector2f bounds2 = sfRectangleShape_getSize(rpg->heros->npc->hitbox);
    float window_width = sfRenderWindow_getSize(rpg->window).x;
    const sfView *view = sfRenderWindow_getView(rpg->window);
    sfVector2f viewCenter = sfView_getCenter(view);
    float right = viewCenter.x + window_width / 2;
    float movement = rpg->heros->speed * rpg->time;

    if (pos.x + bounds2.x + movement > bounds.width ||
        static_collisions_right(rpg->heros->npc->entity->colbox, wich_img(rpg)))
        return;
    rpg->heros->npc->entity->pos.x += movement;
    if (pos.x < bounds.width - window_width / 2 && right + movement <
        bounds.width && pos.x + (bounds2.x / 2) >= window_width / 2) {
        sfView_move((sfView *)view, (sfVector2f){+movement, 0.f});
        sfRenderWindow_setView(rpg->window, view);
    }
}

void manage_right(rpg_t *rpg)
{
    rpg->heros->npc->act_action = MOVE_R;
    moov_right(rpg);
}
