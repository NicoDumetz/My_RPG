/*
** EPITECH PROJECT, 2023
** game
** File description:
** rpg.h
*/

#include "rpg.h"

void destroy_rpg(rpg_t *rpg)
{
    if (rpg) {
        sfRenderWindow_destroy(rpg->window);
        destroy_heros(rpg->heros);
        sfClock_destroy(rpg->clock);
        for (int i = 0; i <= MINE; i++)
            destroy_biome(rpg->biome[i]);
        free(rpg);
    }
}

rpg_t *create_rpg_struct(void)
{
    rpg_t *rpg = malloc(sizeof(rpg_t));
    sfVideoMode mode = {1920, 1080, 32};

    rpg->clock = sfClock_create();
    rpg->scene = PLAIN;
    rpg->second = 0;
    rpg->time = 0;
    rpg->window = sfRenderWindow_create(mode, "my_rpg", sfClose, NULL);
    rpg->heros = init_heros(KNIGHT_SPRITE);
    rpg->heros->npc->entity->pos = (sfVector2f){1000, 500};
    sfSprite_setPosition(rpg->heros->npc->entity->sprite, rpg->heros->npc->entity->pos );
    sfRenderWindow_setPosition(rpg->window, (sfVector2i){0, 0});
    rpg->ticks = false;
    for (int i = 0; i < 256; i++)
        rpg->key_state[i] = false;
    for (int i = 0; i <= MINE; i++)
        rpg->biome[i] = create_biome(i);
    return rpg;
}
