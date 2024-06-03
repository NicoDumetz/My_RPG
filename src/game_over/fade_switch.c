/*
** EPITECH PROJECT, 2024
** fade switch
** File description:
** fade switch
*/

#include "rpg.h"

static void set_position_game_over(rpg_t *rpg)
{
    game_over_t *game = rpg->end;
    const sfView *view = sfRenderWindow_getView(rpg->window);
    sfVector2f center = sfView_getCenter(view);
    sfVector2f size = sfView_getSize(view);

    sfRectangleShape_setSize(game->rect, size);
    sfRectangleShape_setPosition(game->rect,
    (sfVector2f){center.x - size.x / 2.0f, center.y - size.y / 2.0f});
}

void init_switch(rpg_t *rpg)
{
    game_over_t *game = rpg->end;

    game->alpha = 0;
    set_position_game_over(rpg);
    game->active = TUTO_FADE;
}

int unfade_rect(game_over_t *game, rpg_t *rpg)
{
    float speed = rpg->time * 5;
    sfColor color;

    if (game->active == TUTO_FADE && game->alpha > 0.0f) {
        game->alpha -= 20.0f * speed;
        if (game->alpha < 0.0f)
            game->alpha = 0.0f;
        color = sfRectangleShape_getFillColor(game->rect);
        color.a = (sfUint8)game->alpha;
        sfRectangleShape_setFillColor(game->rect, color);
        return 1;
    }
    return 0;
}

static void skip_tuto(rpg_t *rpg)
{
    int act = rpg->heros->level_act;

    rpg->heros->pv_max = level_tab[act].pv_max;
    rpg->heros->stamina_max = level_tab[act].stamina_max;
    rpg->heros->stamina = level_tab[act].stamina_max;
    rpg->heros->pv_max = level_tab[act].pv_max;
    rpg->heros->npc->pv = level_tab[act].pv_max;
    rpg->heros->bar_tab[LIFE_BAR]->max = level_tab[act].pv_max;
    rpg->heros->bar_tab[STAMINA_BAR]->max = level_tab[act].stamina_max;
    rpg->heros->bar_tab[XP_BAR]->max = level_tab[act].xp_to_reach;
    rpg->heros->stami_per_sec = level_tab[act].stami_per_sec;
    rpg->heros->npc->attack = level_tab[act].attack;
    rpg->scene = PLAIN;
    sfSprite_setPosition(
        rpg->heros->npc->entity->sprite, rpg->biome[PLAIN]->last_pos);
    set_view(rpg, rpg->heros->npc->entity->sprite,
        rpg->biome[PLAIN]->back->sprite.sprite);
    clean_entity_list(rpg->tuto->biome);
    set_position_game_over(rpg);
}

void manage_switch_fade(game_over_t *game, rpg_t *rpg)
{
    static int fade = 1;

    if (game->active == TUTO_FADE)
        sfRenderWindow_drawRectangleShape(rpg->window, game->rect, NULL);
    if (fade == 0) {
        if (unfade_rect(game, rpg) == 0) {
            fade = 1;
            game->active = OFF;
        }
    }
    if (fade == 1) {
        if (update_rect(game, rpg) == 0) {
            fade = 0;
            skip_tuto(rpg);
        }
    }
}
