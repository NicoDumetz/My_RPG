/*
** EPITECH PROJECT, 2023
** game
** File description:
** rpg.h
*/

#include "rpg.h"

void destroy_tuto(tuto_t *tuto)
{
    destroy_biome(tuto->biome);
    sfText_destroy((sfText *)(tuto->skip_button->child));
    destroy_button(tuto->skip_button);
    destroy_quest(tuto->quest_tab);
    free(tuto);
}

void create_tuto_next(sfTexture **text_tab, sfFont **, tuto_t *tuto)
{
    tuto->biome->boss = NULL;
    tuto->biome->text_tab = text_tab;
    tuto->biome->nbr_bot = 0;
    tuto->biome->obj_list = NULL;
    tuto->biome->entity_in_view_head = NULL;
    tuto->biome->entity_in_view_tail = NULL;
    for (int i = 0; i < 4; i++) {
        tuto->move_tab[i] = false;
        tuto->attack_tab[i] = false;
    }
}

button_t *create_skip_button(sfTexture **text_tab, sfFont **font_tab)
{
    int tab[] = {BLUE_LONG_R_TEXT,
        BLUE_LONG_P_TEXT, BUTTON_LONG_H_TEXT, BLUE_LONG_R_TEXT, -1};
    button_t *button = create_button(text_tab, tab);
    sfText *but_text = sfText_create();

    button->release = skip_released;
    sfText_setString(but_text, "SKIP");
    sfText_setFont(but_text, font_tab[PIXEL]);
    sfText_setOutlineThickness(but_text, 5);
    sfText_setOutlineColor(but_text, sfBlack);
    sfText_setFillColor(but_text, sfWhite);
    button->child = but_text;
    return button;
}

tuto_t *create_tuto(sfTexture **text_tab, sfFont **font_tab)
{
    tuto_t *tuto = malloc(sizeof(tuto_t));
    int bot_type[6] = {KNIGHT, ARCHER, -1, -1, -1, -1};

    tuto->biome = malloc(sizeof(biome_t));
    tuto->biome->back = add_background(
        text_tab[ARENE_TEXT], text_tab[ARENE_COL_TEXT]);
    tuto->biome->bot_data = init_bot_data(text_tab);
    tuto->biome->deco_data = NULL;
    tuto->biome->portal = NULL;
    tuto->biome->last_pos = (sfVector2f){500.0, 500.0};
    tuto->biome->deco_data = NULL;
    for (int i = 0; i < 6; i++)
    tuto->biome->bot_type[i] = bot_type[i];
    tuto->biome->quest_giver = init_quest_giver_tuto(text_tab,
        tuto->biome->back, font_tab);
    tuto->skip_button = create_skip_button(text_tab, font_tab);
    create_tuto_next(text_tab, font_tab, tuto);
    init_quest_tuto(tuto->quest_tab, font_tab[PIXEL]);
    return (tuto);
}
