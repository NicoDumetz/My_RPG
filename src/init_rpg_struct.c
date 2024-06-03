/*
** EPITECH PROJECT, 2023
** game
** File description:
** rpg.h
*/

#include "rpg.h"

void destroy_save_list(rpg_t *rpg)
{
    save_t *curr = rpg->save_list;
    save_t *next = NULL;

    while (curr) {
        next = curr->next;
        sfText_destroy(curr->name);
        free(curr->data);
        free(curr);
        curr = next;
    }
}

void destroy_rpg(rpg_t *rpg)
{
    if (rpg) {
        sfRenderWindow_destroy(rpg->window);
        destroy_quest(rpg->quest_tab);
        destroy_heros(rpg->heros);
        sfClock_destroy(rpg->clock);
        if (rpg->save_list)
            destroy_save_list(rpg);
        for (int i = 0; i <= MINE; i++)
            destroy_biome(rpg->biome[i]);
        for (int i = 0; i <= MINE_TEXT; i++)
            sfTexture_destroy(rpg->text_tab[i]);
        for (int i = 0; i <= PIXEL; i++)
            sfFont_destroy(rpg->font_tab[i]);
        destroy_load_page(rpg->save_scene);
        free(rpg);
    }
}

rpg_t *init_rpg_next(rpg_t *rpg)
{
    rpg->ticks = false;
    init_quest(rpg->quest_tab, rpg->font_tab);
    rpg->save_scene = init_load_page(rpg->text_tab);
    memset(&(rpg->mouse_data), 0, sizeof(mouse_data_t));
    rpg->save_list = NULL;
    create_file_list(rpg);
    return (rpg);
}

rpg_t *create_rpg_struct(void)
{
    rpg_t *rpg = malloc(sizeof(rpg_t));
    sfVideoMode mode = {1920, 1080, 32};

    rpg->clock = sfClock_create();
    rpg->scene = PLAIN;
    rpg->second = 0;
    rpg->time = 0;
    set_all_font(rpg->font_tab);
    rpg->window = sfRenderWindow_create(mode, "my_rpg", sfClose, NULL);
    sfRenderWindow_setPosition(rpg->window, (sfVector2i){0, 0});
    set_all_texture(rpg->text_tab);
    rpg->heros = init_heros(rpg->text_tab, rpg->font_tab);
    for (int i = 0; i < 256; i++)
        rpg->key_state[i] = false;
    for (int i = 0; i <= MINE; i++)
        rpg->biome[i] = create_biome(i, rpg->text_tab, rpg->font_tab);
    rpg->heros->npc->entity->pos = rpg->biome[PLAIN]->last_pos;
    sfSprite_setPosition(
    rpg->heros->npc->entity->sprite, rpg->biome[PLAIN]->last_pos);
    return init_rpg_next(rpg);
}
