/*
** EPITECH PROJECT, 2024
** int
** File description:
** int
*/

#include "rpg.h"

void init_archery_proj(projectile_t *new)
{
    sfIntRect rect = {0, 0, 64, 128 / 2};

    sfSprite_setTextureRect(new->sprite, rect);
    sfSprite_setScale(new->sprite, (sfVector2f){0.7, 0.7});
    sfRectangleShape_setSize(new->hitbox, (sfVector2f)
    {64 * 0.7, (128 / 2) * 0.7});
}

void init_dyna_proj(projectile_t *new)
{
    sfIntRect rect = {0, 0, 384 / 6, 64};

    sfSprite_setTextureRect(new->sprite, rect);
    sfSprite_setScale(new->sprite, (sfVector2f){0.7, 0.7});
    sfRectangleShape_setSize(new->hitbox,
    (sfVector2f){(384 / 6) * 0.7, 64 * 0.7});
}

void init_npc_projectiles(npc_t *npc, sfTexture **text_tab)
{
    if (npc->type == ARCHERY)
        npc->projectile = init_projectile(text_tab[ARROW_TEXT], 400, ARCHERY);
    if (npc->type == DYNA)
        npc->projectile = init_projectile(text_tab[DYNA_TEXT], 400, DYNA);
}

projectile_t *init_projectile(sfTexture *texture, float speed,
    attack_type_t type)
{
    projectile_t *new = malloc(sizeof(projectile_t));

    new->sprite = sfSprite_create();
    sfSprite_setTexture(new->sprite, texture, true);
    new->target = (sfVector2f){0, 0};
    new->from = (sfVector2f){0, 0};
    new->speed = speed;
    new->hitbox = init_hitbox_rect();
    new->active = 0;
    if (type == ARCHERY)
        init_archery_proj(new);
    if (type == DYNA)
        init_dyna_proj(new);
    return new;
}
