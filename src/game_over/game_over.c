/*
** EPITECH PROJECT, 2024
** game_over
** File description:
** game_over
*/

#include "rpg.h"

void init_game_over(rpg_t *rpg)
{
    game_over_t *new = malloc(sizeof(game_over_t));

    new->active = OFF;
    new->rect = sfRectangleShape_create();
    sfRectangleShape_setFillColor(new->rect, sfBlack);
    new->text = sfText_create();
    sfText_setString(new->text, "You died");
    sfText_setFont(new->text, rpg->font_tab[PIXEL]);
    sfText_setCharacterSize(new->text, 100);
    sfText_setFillColor(new->text, sfRed);
    new->alpha = 0.0f;
    new->alpha_text = 0.0f;
    rpg->end = new;
}

void lunch_end(rpg_t *rpg)
{
    game_over_t *game = rpg->end;
    const sfView *view = sfRenderWindow_getView(rpg->window);
    sfVector2f center = sfView_getCenter(view);
    sfVector2f size = sfView_getSize(view);
    sfFloatRect rect = sfText_getLocalBounds(game->text);

    game->alpha = 0;
    game->alpha_text = 0;
    sfText_setOrigin(game->text, (sfVector2f)
    {rect.width / 2.0f, rect.height / 2.0f});
    sfText_setPosition(game->text, (sfVector2f){center.x, center.y});
    sfRectangleShape_setSize(game->rect, size);
    sfRectangleShape_setPosition(game->rect,
    (sfVector2f){center.x - size.x / 2.0f, center.y - size.y / 2.0f});
    game->active = ACTIVE;
}

int update_rect(game_over_t *game, rpg_t *rpg)
{
    float speed = rpg->time * 5;
    sfColor color;

    rpg->heros->npc->act_action = STAND;
    if ((game->active == ACTIVE || game->active == TUTO_FADE)
        && game->alpha < 255.0f) {
        game->alpha += 20.0f * speed;
        if (game->alpha > 255.0f)
            game->alpha = 255.0f;
        color = sfRectangleShape_getFillColor(game->rect);
        color.a = (sfUint8)game->alpha;
        sfRectangleShape_setFillColor(game->rect, color);
        return 1;
    }
    return 0;
}

static void update_text(game_over_t *game, rpg_t *rpg)
{
    float speed = rpg->time * 5;
    sfColor color;

    if (game->alpha_text < 255.0f) {
        game->alpha_text += 20.0f * speed;
        if (game->alpha_text > 255.0f)
            game->alpha_text = 255.0f;
        color = sfText_getFillColor(game->text);
        color.a = (sfUint8)game->alpha_text;
        sfText_setFillColor(game->text, color);
    }
}

void update_game_over(game_over_t *game, rpg_t *rpg)
{
    if (game->active != ACTIVE)
        return;
    update_rect(game, rpg);
    if (game->alpha >= 255)
        update_text(game, rpg);
    display_game_over(game, rpg);
}

void free_game_over(game_over_t *g)
{
    if (g->rect)
        sfRectangleShape_destroy(g->rect);
    if (g->text)
        sfText_destroy(g->text);
    if (g)
        free(g);
}
