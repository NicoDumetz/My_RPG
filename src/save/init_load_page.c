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

save_scene_t *init_load_page(sfTexture **text_tab)
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
    load_page->exit->release = exit_button_released;
    load_page->from = 0;
    load_page->begin_button_list = 300;
    return (load_page);
}
