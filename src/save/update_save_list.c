/*
** EPITECH PROJECT, 2023
** create_sprite
** File description:
** create_sprite + texture
*/

#include "rpg.h"

sfText *create_text_save_node(save_data_t *save, sfFont **font_tab)
{
    struct tm *tm_info;
    char date[100];
    sfText *text = sfText_create();
    char name[strlen("Save File : ") + 101];

    sfText_setFont(text, font_tab[PIXEL]);
    tm_info = localtime(&(save->time_last_save));
    strftime(date, 100, "%d-%m-%Y %H:%M:%S", tm_info);
    strcpy(name, "Save File : ");
    strcat(name, date);
    sfText_setString(text, name);
    return text;
}

void update_save_list(save_data_t *save, rpg_t *rpg)
{
    save_t *new_node = malloc(sizeof(save_t));
    button_t *new_button = NULL;
    int text_id_save[] = {
        BLUE_LONG_R_TEXT, BLUE_LONG_P_TEXT,
        BUTTON_LONG_H_TEXT, BLUE_LONG_R_TEXT, -1};
    sfVector2f scale_button = {4, 2};

    new_node->next = NULL;
    new_node->prev = NULL;
    new_node->data = save;
    new_node->name = create_text_save_node(save, rpg->font_tab);
    new_button = create_button(rpg->text_tab, text_id_save);
    new_button->child = new_node;
    new_button->release = save_button_released;
    sfSprite_setScale(new_button->sprite, scale_button);
    add_load_button_to_list(rpg->save_scene, new_button);
    new_node->next = rpg->save_list;
    if (rpg->save_list)
        rpg->save_list->prev = new_node;
    rpg->save_list = new_node;
}
