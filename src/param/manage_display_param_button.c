/*
** EPITECH PROJECT, 2024
** B-MUL-200-LIL-2-1-myrpg-matisse.dufour
** File description:
** manage_display_param_button.c
*/

#include "rpg.h"

void fullscreen_p(void *data, button_t *button)
{
    rpg_t *rpg = (rpg_t *)data;

    rpg->params->display->visible = 0;
    rpg->params->display->r1920x1080->visible = 0;
    rpg->params->display->r1280x720->visible = 0;
    rpg->params->display->r850x480->visible = 0;
    button->state = BLOCK;
    rpg->params->display->windowed->state = NONE;
    rpg->params->view = (sfVideoMode){1920, 1080, 32};
    sfRenderWindow_destroy(rpg->window);
    rpg->window = sfRenderWindow_create(rpg->params->view, "My_RPG",
        sfFullscreen, NULL);
}

void windowed_p(void *data, button_t *button)
{
    rpg_t *rpg = (rpg_t *)data;

    rpg->params->display->visible = 1;
    rpg->params->display->r1920x1080->visible = 1;
    rpg->params->display->r1280x720->visible = 1;
    rpg->params->display->r850x480->visible = 1;
    button->state = BLOCK;
    rpg->params->display->fullscreen->state = NONE;
    rpg->params->view = (sfVideoMode){1920, 1080, 32};
    sfRenderWindow_destroy(rpg->window);
    rpg->window = sfRenderWindow_create(rpg->params->view, "My_RPG",
        sfClose, NULL);
    sfSprite_setScale(rpg->params->display->selection, (sfVector2f){1, 1});
    sfSprite_setPosition(rpg->params->display->selection,
        (sfVector2f){rpg->params->view.width * 0.25, rpg->params->view.height
        * 0.2176});
}

void r1920x1080_p(void *data, button_t *)
{
    rpg_t *rpg = (rpg_t *)data;

    rpg->params->view = (sfVideoMode){1920, 1080, 32};
    sfSprite_setPosition(rpg->params->display->selection,
                         (sfVector2f){480, 235});
    sfRenderWindow_setSize(rpg->window, (sfVector2u){1920, 1080});
//    sfSprite_setScale(rpg->params->display->selection, (sfVector2f){1, 1});

}

void r1280x720_p(void *data, button_t *)
{
    rpg_t *rpg = (rpg_t *)data;

    rpg->params->view = (sfVideoMode){1280, 720, 32};
    sfSprite_setPosition(rpg->params->display->selection,
                         (sfVector2f){710, 235});
    sfRenderWindow_setSize(rpg->window, (sfVector2u){1280, 720});
//    sfSprite_setScale(rpg->params->display->selection, (sfVector2f){2 / 3, 2 / 3});
}

void r850x480_p(void *data, button_t *)
{
    rpg_t *rpg = (rpg_t *)data;

    rpg->params->view = (sfVideoMode){853, 480, 32};
    sfSprite_setPosition(rpg->params->display->selection,
                         (sfVector2f){940, 235});
    sfRenderWindow_setSize(rpg->window, (sfVector2u){853, 480});
//    sfSprite_setScale(rpg->params->display->selection, (sfVector2f){0.4442,
//        0.4442});

}
