/*
** EPITECH PROJECT, 2023
** create_sprite
** File description:
** create_sprite + texture
*/

#include "rpg.h"

void destroy_load_page(save_scene_t *save_scene)
{
    button_t *curr = save_scene->button_list;
    button_t *next = NULL;

    sfSprite_destroy(save_scene->back);
    sfSprite_destroy(save_scene->footer);
    sfSprite_destroy(save_scene->header);
    destroy_button(save_scene->exit);
    while (curr) {
        next = curr->next;
        destroy_button(curr);
        curr = next;
    }
    free(save_scene);
}

void add_load_button_to_list(save_scene_t *save_scene, button_t *button)
{
    button->next = save_scene->button_list;
    if (save_scene->button_list)
        save_scene->button_list->prev = button;
    save_scene->button_list = button;
}

void create_button_load_list(
    save_t *save_list, sfTexture **text_tab, save_scene_t *save_scene)
{
    button_t *new_button = NULL;
    int text_id_save[] = {
        BLUE_LONG_R_TEXT, BLUE_LONG_P_TEXT,
        BUTTON_LONG_H_TEXT, BLUE_LONG_R_TEXT, -1};

    for (save_t *curr = save_list; curr; curr = curr->next) {
        new_button = create_button(text_tab, text_id_save);
        new_button->child = curr;
        add_load_button_to_list(save_scene, new_button);
    }
}

save_scene_t *init_load_page(save_t *save_list, sfTexture **text_tab)
{
    save_scene_t *load_page = malloc(sizeof(save_scene_t));
    int text_exit[] = {EXIT_B_R_TEXT, EXIT_B_P_TEXT, -1, EXIT_B_R_TEXT, -1};

    load_page->back = sfSprite_create();
    sfSprite_setTexture(load_page->back, text_tab[BACK_SAVE_TEXT], sfTrue);
    load_page->footer = sfSprite_create();
    sfSprite_setTexture(load_page->footer, text_tab[FOOTER_SAVE_TEXT], sfTrue);
    load_page->header = sfSprite_create();
    sfSprite_setTexture(load_page->header, text_tab[HEADER_SAVE_TEXT], sfTrue);
    load_page->button_list = NULL;
    load_page->exit = create_button(text_tab, text_exit);
    load_page->from = 0;
    create_button_load_list(save_list, text_tab, load_page);
    return (load_page);
}
