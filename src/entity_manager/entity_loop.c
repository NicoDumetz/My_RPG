/*
** EPITECH PROJECT, 2023
** graph.h
** File description:
** macro for CSFML
*/

#include "rpg.h"

static void which_anim_effect(effect_t *effect, bool ticks)
{
    if (effect->is_short)
        anim_effect_short(effect, ticks);
    else
        anim_effect_long(effect, ticks);
}

static void manage_effect(entity_t *entity, sfRenderWindow *window, bool ticks)
{
    for (int i = 0; entity->effect_tab[i]; i++)
        if (entity->effect_tab[i]->active) {
            sfSprite_setPosition(entity->effect_tab[i]->sprite, entity->pos);
            which_anim_effect(entity->effect_tab[i], ticks);
            sfRenderWindow_drawSprite(
                window, entity->effect_tab[i]->sprite, NULL);
        }
}

void manage_animation_bot(entity_t *entity, bool ticks)
{
    npc_t *npc = (npc_t *)(entity->parent);

    entity->parent = (npc_t *)(entity->parent);
    if (npc->is_attack == false) {
        anim_entity(entity, npc->action[npc->act_action], ticks);
        npc->cur_attack = false;
    }
    if (npc->is_attack == true)
        anim_attack(npc, npc->action[npc->act_action], ticks);
}

void which_entity(entity_t *curr, rpg_t *rpg)
{
    npc_t *npc = NULL;

    npc = curr->type == NPC ? curr->parent : NULL;
    if (npc) {
        if (npc->special == NON_SPEC)
            manage_bot(curr, rpg->heros, rpg);
        manage_animation_bot(curr, rpg->ticks);
    }
    if (!npc) {
        anim_entity(curr, curr->simple_action, rpg->ticks);
    }
    sfRenderWindow_drawSprite(rpg->window, curr->sprite, NULL);
    if (npc && npc->special == NON_SPEC)
        display_projectiles(curr->parent, rpg);
    if (npc && npc->entity->effect_tab)
        manage_effect(curr, rpg->window, rpg->ticks);
}

void entity_loop(
    entity_t *entity_list, rpg_t *rpg)
{
    for (entity_t *curr = entity_list; curr; curr = curr->next)
        which_entity(curr, rpg);
    manage_heros(rpg->heros, rpg);
}
