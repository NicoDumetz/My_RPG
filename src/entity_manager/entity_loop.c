/*
** EPITECH PROJECT, 2023
** graph.h
** File description:
** macro for CSFML
*/

#include "rpg.h"

void which_anim_effect(effect_t *effect, bool ticks)
{
    if (effect->is_short)
        anim_effect_short(effect, ticks);
    else
        anim_effect_long(effect, ticks);
}

void manage_effect(entity_t *entity, sfRenderWindow *window, bool ticks)
{
    for (int i = 0; entity->effect_tab[i]; i++)
        if (entity->effect_tab[i]->active) {
            sfSprite_setPosition(entity->effect_tab[i]->sprite, entity->pos);
            which_anim_effect(entity->effect_tab[i], ticks);
            sfRenderWindow_drawSprite(
                window, entity->effect_tab[i]->sprite, NULL);
        }
}

void manage_animation(entity_t *entity, bool ticks)
{
    npc_t *npc = (npc_t *)(entity->parent);

    if (npc == NULL)
        anim_entity(entity, entity->simple_action, ticks);
    if (npc != NULL) {
        entity->parent = (npc_t *)(entity->parent);
        if (npc->is_attack == false)
            anim_entity(entity, npc->action[npc->act_action], ticks);
        if (npc->is_attack == true)
            anim_attack(npc, npc->action[npc->act_action], ticks);
    }
}

void entity_loop(
    entity_t *entity_list, rpg_t *rpg)
{
    npc_t *npc = NULL;

    for (entity_t *curr = entity_list; curr; curr = curr->next) {
        npc = curr->parent;
        if (npc && npc->special == NON_SPEC)
            manage_bot(curr, rpg->heros);
        manage_animation(curr, rpg->ticks);
        sfRenderWindow_drawSprite(rpg->window, curr->sprite, NULL);
        if (npc && npc->entity->effect_tab)
            manage_effect(curr, rpg->window, rpg->ticks);
    }
    manage_heros(rpg->heros, rpg);
}
