/*
** EPITECH PROJECT, 2024
** movements
** File description:
** movements
*/

#include "rpg.h"

sfSprite *wich_back(rpg_t *rpg)
{
    if (rpg->scene == TUTO)
        return (rpg->tuto->biome->back->sprite.sprite);
    else if (rpg->biome[rpg->scene]->back)
        return (rpg->biome[rpg->scene]->back->sprite.sprite);
    return NULL;
}

sfImage *wich_img(rpg_t *rpg)
{
    if (rpg->scene == TUTO)
        return (rpg->tuto->biome->back->collision.col_image);
    else if (rpg->biome[rpg->scene]->back)
        return (rpg->biome[rpg->scene]->back->collision.col_image);
    return NULL;
}

void manage_movements(rpg_t *rpg)
{
    if (rpg->end->active != OFF)
        return;
    if (rpg->key_state[sfKeyD] && rpg->heros->npc->allowed_dir[RIGHT])
        manage_right(rpg);
    if (rpg->key_state[sfKeyQ] && rpg->heros->npc->allowed_dir[LEFT])
        manage_left(rpg);
    if (rpg->key_state[sfKeyZ] && rpg->heros->npc->allowed_dir[UP])
        manage_up(rpg);
    if (rpg->key_state[sfKeyS] && rpg->heros->npc->allowed_dir[DOWN])
        manage_down(rpg);
    if (!rpg->key_state[sfKeyS] && !rpg->key_state[sfKeyD] &&
        !rpg->key_state[sfKeyZ] && !rpg->key_state[sfKeyQ] &&
        rpg->heros->npc->is_attack == false)
        rpg->heros->npc->act_action = STAND;
    sfSprite_setPosition(rpg->heros->npc->entity->sprite,
    rpg->heros->npc->entity->pos);
}
