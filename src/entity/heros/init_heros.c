/*
** EPITECH PROJECT, 2023
** graph.h
** File description:
** macro for CSFML
*/

#include "rpg.h"

static void destroy_obj(back_obj_t **list)
{
    back_obj_t *next = NULL;
    back_obj_t *curr = *list;

    while (curr) {
        next = curr->next;
        destroy_back_obj(curr);
        curr = next;
    }
    *list = NULL;
}

void destroy_heros(heros_t *heros)
{
    if (heros->inventory)
        destroy_obj(&(heros->inventory));
    for (int i = 0; i <= STAMINA_BAR; i++)
        destroy_info_bar(heros->bar_tab[i]);
    sfText_destroy(heros->interact);
    destroy_skill(heros->skill);
    destroy_npc(heros->npc);
    free(heros);
}

void set_action_tab_heros(heros_t *heros)
{
    heros->npc->action[ATTACK_F] = (sfVector2i){6, 6};
    heros->npc->action[ATTACK_B] = (sfVector2i){6, 5};
    heros->npc->action[ATTACK_L] = (sfVector2i){6, -3};
    heros->npc->action[ATTACK_R] = (sfVector2i){6, 3};
    heros->npc->action[MOVE_R] = (sfVector2i){6, 1};
    heros->npc->action[MOVE_L] = (sfVector2i){6, -1};
    heros->npc->action[MOVE_F] = (sfVector2i){-1, 0};
    heros->npc->action[MOVE_B] = (sfVector2i){-1, 0};
    heros->npc->action[STAND] = (sfVector2i){6, 0};
}

void set_attbox_dim_heros(npc_t *npc)
{
    npc->attbox_dim[ATTACK_F] = (sfFloatRect){15, 15, 30, 70};
    npc->attbox_dim[ATTACK_B] = (sfFloatRect){20, 50, 25, 65};
    npc->attbox_dim[ATTACK_L] = (sfFloatRect){5, 30, 40, 55};
    npc->attbox_dim[ATTACK_R] = (sfFloatRect){35, 30, 40, 55};
}

effect_t **create_effect_tab_heros(
    sfTexture **text_tab, sfSprite *heros_sprite)
{
    effect_t **effect_tab = malloc(sizeof(effect_t *) * 6);

    effect_tab[LEVEL_UP_HEROS] = create_effect(
        text_tab[LEVEL_UP_TEXT], true, (sfVector2i){7, 1}, heros_sprite);
    effect_tab[BLOOD_HEROS] = create_effect(
        text_tab[BLOOD_TEXT], true, (sfVector2i){8, 1}, heros_sprite);
    effect_tab[PICK_HEROS] = create_effect(
        text_tab[COIN_TEXT], true, (sfVector2i){7, 1}, heros_sprite);
    effect_tab[EXPLO_HEROS] = create_effect(
        text_tab[EXPLO_TEXT], true, (sfVector2i){9, 1}, heros_sprite);
    effect_tab[SHIELD_HEROS] = create_effect(
        text_tab[SHIELD_TEXT], false, (sfVector2i){12, 1}, heros_sprite);
    effect_tab[5] = NULL;
    return (effect_tab);
}

static void init_heros_next_two(
    heros_t *heros, sfTexture **, sfFont **font_tab)
{
    heros->can_interact = false;
    heros->interact = sfText_create();
    sfText_setString(heros->interact, "Press \"Key E\"");
    sfText_setFont(heros->interact, font_tab[PIXEL]);
    sfText_setOutlineColor(heros->interact, sfBlack);
    sfText_setOutlineThickness(heros->interact, 2);
    heros->skill = init_skill();
    heros->multi_speed = 1;
    heros->restore = false;
    heros->skill_point = 0;
}

static heros_t *init_heros_next(
    heros_t *heros, sfTexture **text_tab, sfFont **font_tab)
{
    heros->level_act = 0;
    heros->bar_tab[LIFE_BAR] =
        create_info_bar(sfRed, (sfVector2f){300, 20},
            level_tab[0].pv_max, text_tab[LIFE_B_TEXT]);
    heros->bar_tab[XP_BAR] =
        create_info_bar(sfBlue,
        (sfVector2f){300, 20}, level_tab[0].xp_to_reach, text_tab[XP_B_TEXT]);
    heros->bar_tab[STAMINA_BAR] =
        create_info_bar(sfYellow,
        (sfVector2f){300, 20},
            level_tab[0].stamina_max, text_tab[ENERGY_B_TEXT]);
    heros->bar_tab[XP_BAR]->text = sfText_create();
    sfText_setFont(heros->bar_tab[XP_BAR]->text, font_tab[PIXEL]);
    heros->stamina = level_tab[0].stamina_max;
    heros->npc->xp = 0;
    heros->pv_max = level_tab[0].pv_max;
    heros->stamina_max = level_tab[0].stamina_max;
    heros->stami_per_sec = level_tab[0].stami_per_sec;
    init_heros_next_two(heros, text_tab, font_tab);
    return (heros);
}

static void set_variable_heros(heros_t *heros)
{
    sfFloatRect hitbox = {30, 25, 55, 55};
    sfFloatRect colbox = {40, 60, 80, 90};

    heros->inventory = NULL;
    heros->npc->special = HEROS;
    heros->npc->entity->colbox_dim = colbox;
    heros->npc->hitbox_dim = hitbox;
    heros->npc->projectile = NULL;
}

static void init_heros_fire(sfTexture **text_tab, heros_t *heros)
{
    heros->npc->type = FIRE;
    init_npc_projectiles(heros->npc, text_tab);
}

heros_t *init_heros(sfTexture **text_tab, sfFont **font_tab)
{
    heros_t *heros = malloc(sizeof(heros_t));

    heros->speed = 300.f;
    heros->texture_base = text_tab[KNIGHT_TEXT];
    heros->npc = init_npc(heros->texture_base);
    heros->npc->attack = level_tab[0].attack;
    heros->npc->pv = level_tab[0].pv_max;
    heros->npc->entity->parent = heros->npc;
    set_offset(heros->npc->entity, (sfVector2i){6, 8});
    set_action_tab_heros(heros);
    set_attbox_dim_heros(heros->npc);
    heros->npc->entity->effect_tab = create_effect_tab_heros(
        text_tab, heros->npc->entity->sprite);
    set_variable_heros(heros);
    init_heros_fire(text_tab, heros);
    return init_heros_next(heros, text_tab, font_tab);
}
