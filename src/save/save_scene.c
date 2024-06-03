/*
** EPITECH PROJECT, 2023
** create_sprite
** File description:
** create_sprite + texture
*/

#include "rpg.h"

void check_end_scroll(button_t *to_check,
    save_scene_t *save_scene, sfVector2f view_center)
{
    sfFloatRect pos_button = sfSprite_getGlobalBounds(to_check->sprite);

    if (pos_button.top + pos_button.height < view_center.y) {
        save_scene->end_scroll = false;
    } else
        save_scene->end_scroll = true;
}

float update_begin_list(
    save_scene_t *save_scene,
    mouse_data_t *mouse_data, float time, sfVector2f view_center)
{
    float speed = 400 * time;

    if (mouse_data->scroll_up && save_scene->end_scroll)
        save_scene->begin_button_list -= speed;
    if (mouse_data->scroll_down &&
        save_scene->begin_button_list < view_center.y)
        save_scene->begin_button_list += speed;
    return (save_scene->begin_button_list);
}

void manage_load_button(
    rpg_t *rpg, save_scene_t *save_scene,
    sfVector2f view_center)
{
    sfFloatRect button_size =
        sfSprite_getGlobalBounds(save_scene->button_list->sprite);
    float y = update_begin_list(
        save_scene, &(rpg->mouse_data), rpg->time, view_center);
    sfVector2f next_pos = {view_center.x - (button_size.width / 2), y};
    save_t *save = NULL;

    for (button_t *curr = save_scene->button_list; curr; curr = curr->next) {
        sfSprite_setPosition(curr->sprite, next_pos);
        save = (save_t *)curr->child;
            update_button(curr, &(rpg->mouse_data), rpg);
            sfRenderWindow_drawSprite(rpg->window, curr->sprite, NULL);
            sfText_setPosition(save->name,
                (sfVector2f){next_pos.x + 150, next_pos.y + 30});
            sfRenderWindow_drawText(rpg->window, save->name, NULL);
        if (curr->next == NULL)
            check_end_scroll(curr, save_scene, view_center);
        next_pos.y += button_size.height + 50;
    }
}

void manage_exit_button(
    rpg_t *rpg, save_scene_t *save_scene, sfVector2f view_size)
{
    sfVector2f exit_pos = {(view_size.x / 100) * 90, (view_size.y / 100) * 5};
    sfVector2f scale = {1.5, 1.5};

    sfSprite_setPosition(save_scene->exit->sprite, exit_pos);
    sfSprite_setScale(save_scene->exit->sprite, scale);
    update_button(save_scene->exit, &(rpg->mouse_data), rpg);
    sfRenderWindow_drawSprite(rpg->window, save_scene->exit->sprite, NULL);
}

void load_page(rpg_t *rpg)
{
    save_scene_t *save_scene = rpg->save_scene;
    const sfView *view = sfRenderWindow_getView(rpg->window);
    sfVector2f view_size = sfView_getSize(view);
    sfVector2f view_center = sfView_getCenter(view);

    sfRenderWindow_drawSprite(rpg->window, rpg->save_scene->back, NULL);
    if (save_scene->button_list)
        manage_load_button(rpg, save_scene, view_center);
    sfRenderWindow_drawSprite(rpg->window, rpg->save_scene->footer, NULL);
    sfRenderWindow_drawSprite(rpg->window, rpg->save_scene->header, NULL);
    manage_exit_button(rpg, save_scene, view_size);
}
