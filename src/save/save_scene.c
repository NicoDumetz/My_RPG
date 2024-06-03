/*
** EPITECH PROJECT, 2023
** create_sprite
** File description:
** create_sprite + texture
*/

#include "rpg.h"

void load_page(rpg_t *rpg)
{
    sfRenderWindow_drawSprite(rpg->window, rpg->save_scene->back, NULL);
    sfRenderWindow_drawSprite(rpg->window, rpg->save_scene->footer, NULL);
    sfRenderWindow_drawSprite(rpg->window, rpg->save_scene->header, NULL);
}
