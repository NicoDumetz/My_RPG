/*
** EPITECH PROJECT, 2023
** game
** File description:
** rpg.h
*/

#include "rpg.h"
#include <SFML/Graphics/Font.h>
#include <SFML/Graphics/Texture.h>

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

static void destroy_rpg_next(rpg_t *rpg)
{
    destroy_load_page(rpg->save_scene);
    destroy_menu(rpg->start_menu);
    destroy_param_struct(rpg->params);
    destroy_inventory(&rpg->inventory);
    free_game_over(rpg->end);
    destroy_menu_ingame(rpg->ingame_menu);
    destroy_particules(rpg);
}

void destroy_rpg(rpg_t *rpg)
{
    if (rpg) {
        sfRenderWindow_destroy(rpg->window);
        destroy_quest(rpg->quest_tab);
        destroy_heros(rpg->heros);
        sfClock_destroy(rpg->clock);
        destroy_tuto(rpg->tuto);
        if (rpg->save_list)
            destroy_save_list(rpg);
        for (int i = 0; i <= MINE; i++)
            destroy_biome(rpg->biome[i]);
        for (int i = 0; i <= MINE_TEXT; i++)
            sfTexture_destroy(rpg->text_tab[i]);
        for (int i = 0; i < FONT_COUNT; i++) {
            sfFont_destroy(rpg->font_tab[i]);
        }
        destroy_rpg_next(rpg);
        free(rpg);
    }
}

static void reinitialize_rpg_next(rpg_t *rpg)
{
    destroy_inventory(&rpg->inventory);
    init_inventory(&rpg->inventory, rpg->text_tab, rpg);
}

void reinitalize_rpg(rpg_t *rpg)
{
    destroy_heros(rpg->heros);
    rpg->heros = init_heros(rpg->text_tab, rpg->font_tab);
    rpg->heros->npc->entity->pos = rpg->tuto->biome->last_pos;
    sfSprite_setPosition(
        rpg->heros->npc->entity->sprite, rpg->tuto->biome->last_pos);
    for (int i = 0; i <= MINE; i++)
        destroy_biome(rpg->biome[i]);
    for (int i = 0; i <= MINE; i++)
        rpg->biome[i] = create_biome(i, rpg->text_tab, rpg->font_tab);
    destroy_tuto(rpg->tuto);
    rpg->tuto = create_tuto(rpg->text_tab, rpg->font_tab);
    destroy_quest(rpg->quest_tab);
    init_quest(rpg->quest_tab, rpg->font_tab);
    reinitialize_rpg_next(rpg);
}

rpg_t *init_rpg_next(rpg_t *rpg)
{
    for (int i = 0; i <= MINE; i++)
        rpg->biome[i] = create_biome(i, rpg->text_tab, rpg->font_tab);
    rpg->tuto = create_tuto(rpg->text_tab, rpg->font_tab);
    rpg->heros->npc->entity->pos = rpg->tuto->biome->last_pos;
    sfSprite_setPosition(
        rpg->heros->npc->entity->sprite, rpg->tuto->biome->last_pos);
    srand(time(NULL));
    rpg->ticks = false;
    init_quest(rpg->quest_tab, rpg->font_tab);
    rpg->save_scene = init_load_page(rpg->text_tab);
    memset(&(rpg->mouse_data), 0, sizeof(mouse_data_t));
    rpg->save_list = NULL;
    create_file_list(rpg);
    init_inventory(&rpg->inventory, rpg->text_tab, rpg);
    rpg->second = 0;
    rpg->time = 0;
    init_game_over(rpg);
    init_particules(rpg);
    return (rpg);
}

static bool init_ressources(sfFont **font_tab, sfTexture **texture_tab,
    rpg_t *rpg)
{
    set_all_font(font_tab);
    set_all_texture(texture_tab);
    if (!check_asset(texture_tab, font_tab))
        return false;
    for (int i = 0; i <= MINE_TEXT; i++) {
        if (texture_tab[i])
            sfTexture_destroy(texture_tab[i]);
    }
    for (int i = 0; i < FONT_COUNT; i++) {
        if (font_tab[i])
            sfFont_destroy(font_tab[i]);
    }
    free(rpg);
    return true;
}

rpg_t *create_rpg_struct(void)
{
    rpg_t *rpg = malloc(sizeof(rpg_t));
    sfVideoMode mode = {1920, 1080, 32};

    if (init_ressources(rpg->font_tab, rpg->text_tab, rpg))
        return NULL;
    rpg->start_menu = create_menu_struct(rpg);
    rpg->params = init_param_struct(rpg->text_tab, rpg->font_tab);
    rpg->ingame_menu = create_menu_ingame_struct(rpg);
    rpg->clock = sfClock_create();
    rpg->scene = MENU;
    rpg->second = 0;
    rpg->time = 0;
    rpg->window = sfRenderWindow_create(mode, "my_rpg", sfClose, NULL);
    sfRenderWindow_setPosition(rpg->window, (sfVector2i){0, 0});
    rpg->heros = init_heros(rpg->text_tab, rpg->font_tab);
    for (int i = 0; i < 256; i++)
        rpg->key_state[i] = false;
    return init_rpg_next(rpg);
}
