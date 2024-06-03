/*
** EPITECH PROJECT, 2023
** create_sprite
** File description:
** create_sprite + texture
*/

#include "rpg.h"

void appli_save(rpg_t *rpg, save_data_t *save)
{
    rpg->heros->npc->pv = save->heros_pv;
    rpg->heros->stamina = save->heros_stami;
    rpg->heros->npc->xp = save->heros_xp;
    rpg->heros->level_act = save->level_heros;
    rpg->heros->npc->entity->pos = (sfVector2f){save->x_heros, save->y_heros};
    sfSprite_setPosition(
        rpg->heros->npc->entity->sprite, rpg->heros->npc->entity->pos);
    remake_bot_list(save, rpg);
}

void save_button_released(void *data, button_t *button)
{
    rpg_t *rpg = (rpg_t *)(data);
    save_t *save = (save_t *)(button->child);

    appli_save(rpg, save->data);
    set_view(rpg,
    rpg->heros->npc->entity->sprite,
    rpg->biome[save->data->id_biome]->back->sprite.sprite);
    rpg->scene = save->data->id_biome;
}
