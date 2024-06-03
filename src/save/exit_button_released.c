/*
** EPITECH PROJECT, 2023
** create_sprite
** File description:
** create_sprite + texture
*/

#include "rpg.h"

void exit_button_released(void *data, button_t *)
{
    rpg_t *rpg = (rpg_t *)(data);

    if (rpg->save_scene->from <= MINE) {
        set_view(rpg, rpg->heros->npc->entity->sprite,
        rpg->biome[rpg->save_scene->from]->back->sprite.sprite);
    }
    rpg->scene = rpg->save_scene->from;
}
