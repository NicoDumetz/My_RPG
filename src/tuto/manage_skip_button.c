/*
** EPITECH PROJECT, 2023
** graph.h
** File description:
** macro for CSFML
*/

#include "rpg.h"

sfVector2f align_centers(sfFloatRect target, sfFloatRect reference)
{
    float center_x = reference.left + (reference.width / 2.0f);
    float center_y = reference.top + (reference.height / 2.0f);
    sfVector2f new_position;

    new_position.x = center_x - (target.width / 2.0f);
    new_position.y = center_y - (target.height / 2.0f);
    return new_position;
}

void manage_skip_button(button_t *button, rpg_t *rpg)
{
    const sfView *view = sfRenderWindow_getView(rpg->window);
    sfVector2f center = sfView_getCenter(view);
    sfVector2f s_view = sfView_getSize(view);
    sfVector2f pos = {(center.x - s_view.x / 2) + ((s_view.x / 100) * 88),
        center.y - s_view.y / 2 + ((s_view.y / 100) * 90)};
    sfVector2f pos_but;

    update_button(button, &(rpg->mouse_data), rpg);
    sfSprite_setPosition(button->sprite, pos);
    pos_but = align_centers(
        sfText_getGlobalBounds((sfText*)(button->child)),
        sfSprite_getGlobalBounds(button->sprite));
    sfText_setPosition((sfText*)(button->child),
        (sfVector2f){pos_but.x, pos_but.y - 15});
    sfRenderWindow_drawSprite(rpg->window, button->sprite, NULL);
    sfRenderWindow_drawText(
        rpg->window, (sfText*)(button->child), NULL);
}
