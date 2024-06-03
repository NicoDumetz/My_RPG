/*
** EPITECH PROJECT, 2023
** graph.h
** File description:
** macro for CSFML
*/

#include "rpg.h"

void recovery_stamina(heros_t *heros, float time)
{
    run_t *run = (run_t *)heros->skill->skill_tab[RUN];

    if (heros->stamina < 1)
        heros->restore = true;
    if (heros->stamina > heros->stamina_max / 4)
        heros->restore = false;
    if (heros->stamina < heros->stamina_max && !(run->active)) {
        heros->stamina += heros->stami_per_sec * time;
        if (heros->stamina > heros->stamina_max)
            heros->stamina = heros->stamina_max;
    }
}

void appli_level_up(heros_t *heros, int act)
{
    heros->level_act += 1;
    heros->stamina_max = level_tab[act].stamina_max;
    heros->stamina = level_tab[act].stamina_max;
    heros->pv_max = level_tab[act].pv_max;
    heros->npc->pv = level_tab[act].pv_max;
    heros->bar_tab[LIFE_BAR]->max = level_tab[act].pv_max;
    heros->bar_tab[STAMINA_BAR]->max = level_tab[act].stamina_max;
    heros->bar_tab[XP_BAR]->max = level_tab[act].xp_to_reach;
    heros->stami_per_sec = level_tab[act].stami_per_sec;
    heros->npc->attack = level_tab[act].attack;
    heros->npc->entity->effect_tab[LEVEL_UP_HEROS]->active = true;
    heros->skill_point += 1;
}

void check_level_up(heros_t *heros)
{
    int act = heros->level_act;

    if (heros->npc->xp >= level_tab[act].xp_to_reach && act < 10) {
        act++;
        appli_level_up(heros, act);
        if (heros->npc->xp > level_tab[act - 1].xp_to_reach) {
            heros->npc->xp = heros->npc->xp - level_tab[act - 1].xp_to_reach;
            check_level_up(heros);
        }
    }
}

void manage_interact(heros_t *heros, sfRenderWindow *window)
{
    sfVector2f pos = {heros->npc->entity->pos.x, heros->npc->entity->pos.y};

    sfText_setPosition(heros->interact, pos);
    sfRenderWindow_drawText(window, heros->interact, NULL);
}

void manage_heros(heros_t *heros, rpg_t *rpg)
{
    manage_skill(heros, rpg);
    manage_movements(rpg);
    manage_heros_attack(heros, rpg->key_state);
    if (heros->can_interact)
        manage_interact(heros, rpg->window);
    recovery_stamina(heros, rpg->time);
    check_level_up(heros);
    if ((heros->level_act) == 10)
        heros->npc->xp = 0;
    heros->can_interact = false;
}
