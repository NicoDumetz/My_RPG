/*
** EPITECH PROJECT, 2023
** game
** File description:
** rpg.h
*/

#include "rpg.h"

void destroy_obj_list(front_obj_t **obj_list)
{
    front_obj_t *curr = *obj_list;
    front_obj_t *next = NULL;

    while (curr) {
        next = curr->next;
        destroy_front_obj(curr, true);
        curr = next;
    }
    *obj_list = NULL;
}

void destroy_biome(biome_t *biome)
{
    free_bot_data(biome->bot_data);
    if (biome->portal) {
        for (int i = 0; biome->portal[i]; i++)
            destroy_portal(biome->portal[i]);
        free(biome->portal);
        biome->portal = NULL;
    }
    if (biome->quest_giver)
        destroy_quest_giver(biome->quest_giver);
    if (biome->back)
        destroy_background(biome->back);
    if (biome->deco_data)
        free_deco_data(biome->deco_data);
    if (biome->obj_list)
        destroy_obj_list(&(biome->obj_list));
    free(biome);
    biome = NULL;
}

biome_t *create_biome(int biome_type, sfTexture **text_tab, sfFont **font_tab)
{
    biome_t *biome = NULL;
    biome_t *(*biome_gen[5])(sfTexture **text_tab, sfFont **font_tab) = {
        set_plain,
        set_castle,
        set_camp,
        set_village,
        set_mine
    };

    biome = biome_gen[biome_type](text_tab, font_tab);
    biome->text_tab = text_tab;
    biome->nbr_bot = 0;
    biome->obj_list = NULL;
    biome->entity_in_view_head = NULL;
    biome->entity_in_view_tail = NULL;
    if (biome->pos_bot)
        set_bot_donjon(biome, biome->pos_bot);
    return (biome);
}
