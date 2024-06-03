/*
** EPITECH PROJECT, 2024
** movements
** File description:
** movements
*/

#include "rpg.h"

static void moov_right(rpg_t *rpg)
{
    sfVector2f pos = rpg->heros->npc->entity->pos;
    sfFloatRect bounds = sfSprite_getGlobalBounds(rpg->back->sprite.sprite);
    sfFloatRect bounds2 = sfSprite_getGlobalBounds
    (rpg->heros->npc->entity->sprite);
    float window_width = sfRenderWindow_getSize(rpg->window).x;
    const sfView *view = sfRenderWindow_getView(rpg->window);
    sfVector2f viewcenter = sfView_getCenter(view);
    float right = viewcenter.x + window_width / 2;

    if (pos.x + bounds2.width + rpg->heros->speed > bounds.width)
        return;
    rpg->heros->npc->entity->pos.x += rpg->heros->speed;
    if (pos.x < bounds.width - window_width / 2 && right + rpg->heros->speed
        < bounds.width && pos.x + (bounds2.width / 2) >= window_width / 2) {
        sfView_move((sfView *)view, (sfVector2f){+rpg->heros->speed, 0.f});
        sfRenderWindow_setView(rpg->window, view), (sfVector2f)
        {+rpg->heros->speed, 0.f};
    }
}

static void moov_left(rpg_t *rpg)
{
    sfVector2f pos = rpg->heros->npc->entity->pos;
    float window_width = sfRenderWindow_getSize(rpg->window).x;
    sfFloatRect bounds = sfSprite_getGlobalBounds(rpg->back->sprite.sprite);
    sfFloatRect bounds2 = sfSprite_getGlobalBounds
    (rpg->heros->npc->entity->sprite);
    const sfView *view = sfRenderWindow_getView(rpg->window);
    sfVector2f viewcenter = sfView_getCenter(view);
    float left = viewcenter.x - window_width / 2;

    if (pos.x + rpg->heros->speed < 0)
        return;
    rpg->heros->npc->entity->pos.x -= rpg->heros->speed;
    if (left > 0 && pos.x - rpg->heros->speed + (bounds2.width / 2) <
        bounds.width - (window_width / 2)) {
        sfView_move((sfView *)view, (sfVector2f){-rpg->heros->speed, 0.f});
        sfRenderWindow_setView(rpg->window, view), (sfVector2f)
        {-rpg->heros->speed, 0.f};
    }
}

static void moov_up(rpg_t *rpg)
{
    sfVector2f pos = rpg->heros->npc->entity->pos;
    const sfView *view = sfRenderWindow_getView(rpg->window);
    sfFloatRect bounds = sfSprite_getGlobalBounds(rpg->back->sprite.sprite);
    sfFloatRect bounds2 = sfSprite_getGlobalBounds
    (rpg->heros->npc->entity->sprite);
    float window_height = sfRenderWindow_getSize(rpg->window).y;
    sfVector2f viewCenter = sfView_getCenter(view);
    float top = viewCenter.y - window_height / 2;

    if (pos.y + rpg->heros->speed < 0)
        return;
    rpg->heros->npc->entity->pos.y -= rpg->heros->speed;
    if (top > 0 && pos.y - rpg->heros->speed + (bounds2.height / 2) <
        bounds.height - (window_height / 2)) {
        sfView_move((sfView *)view, (sfVector2f){0.f, -rpg->heros->speed});
        sfRenderWindow_setView(rpg->window, view), (sfVector2f)
        {0.f, -rpg->heros->speed};
    }
}

static void moov_down(rpg_t *rpg)
{
    sfVector2f pos = rpg->heros->npc->entity->pos;
    const sfView *view = sfRenderWindow_getView(rpg->window);
    sfFloatRect bounds = sfSprite_getGlobalBounds(rpg->back->sprite.sprite);
    sfFloatRect bounds2 = sfSprite_getGlobalBounds
    (rpg->heros->npc->entity->sprite);
    float window_height = sfRenderWindow_getSize(rpg->window).y;
    sfVector2f viewCenter = sfView_getCenter(view);
    float bottom = viewCenter.y + window_height / 2;

    if (pos.y + bounds2.height + rpg->heros->speed > bounds.height)
        return;
    rpg->heros->npc->entity->pos.y += rpg->heros->speed;
    if (pos.y < bounds.height - window_height / 2 && bottom + rpg->heros->speed
        < bounds.height && pos.y + (bounds2.height / 2) >= window_height / 2) {
        sfView_move((sfView *)view, (sfVector2f){0.f, +rpg->heros->speed});
        sfRenderWindow_setView(rpg->window, view), (sfVector2f)
        {0.f, +rpg->heros->speed};
    }
}

void manage_movements(rpg_t *rpg, sfEvent *event)
{
    if (event->key.code == sfKeyD)
        moov_right(rpg);
    if (event->key.code == sfKeyQ)
        moov_left(rpg);
    if (event->key.code == sfKeyZ)
        moov_up(rpg);
    if (event->key.code == sfKeyS)
        moov_down(rpg);
    sfSprite_setPosition(rpg->heros->npc->entity->sprite,
    rpg->heros->npc->entity->pos);
}
