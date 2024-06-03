/*
** EPITECH PROJECT, 2024
** movements
** File description:
** movements
*/

#include "rpg.h"

static void moov_down(rpg_t *rpg)
{
    sfVector2f pos = sfRectangleShape_getPosition(rpg->heros->npc->hitbox);
    const sfView *view = sfRenderWindow_getView(rpg->window);
    sfFloatRect bounds = sfSprite_getGlobalBounds(wich_back(rpg));
    sfVector2f bounds2 = sfRectangleShape_getSize(rpg->heros->npc->hitbox);
    float window_height = sfRenderWindow_getSize(rpg->window).y;
    sfVector2f viewCenter = sfView_getCenter(view);
    float bottom = viewCenter.y + window_height / 2;
    float movement = rpg->heros->speed * rpg->time * rpg->heros->multi_speed;

    if (pos.y + (bounds2.y * 2) + movement > bounds.height ||
        static_collisions_down(rpg->heros->npc->entity->colbox, wich_img(rpg)))
        return;
    rpg->heros->npc->entity->pos.y += movement;
    if (pos.y < bounds.height - window_height / 2 && bottom + movement <
        bounds.height && pos.y + (bounds2.x / 2) >= window_height / 2) {
        sfView_move((sfView *)view, (sfVector2f){0.f, movement});
        sfRenderWindow_setView(rpg->window, view);
    }
}

void manage_down(rpg_t *rpg)
{
    if (rpg->heros->npc->is_attack == false) {
        if (rpg->heros->npc->action[MOVE_B].x > 0)
            rpg->heros->npc->act_action = MOVE_B;
        if (rpg->heros->npc->act_action == MOVE_R ||
            rpg->heros->npc->act_action == STAND ||
            rpg->heros->npc->act_action <= ATTACK_R)
            rpg->heros->npc->act_action = MOVE_R;
    }
    moov_down(rpg);
}
