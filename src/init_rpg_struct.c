/*
** EPITECH PROJECT, 2023
** game
** File description:
** rpg.h
*/

#include "rpg.h"

void destroy_rpg(rpg_t *rpg)
{
    if (rpg) {
        sfRenderWindow_destroy(rpg->window);
        destroy_heros(rpg->heros);
        sfClock_destroy(rpg->clock);
        for (int i = 0; i <= MINE; i++)
            destroy_biome(rpg->biome[i]);
        free(rpg);
    }
}

//static void add_sprite_loop(sprite_loop_t **begin, char *path)
//{
//    sprite_loop_t *new = malloc(sizeof(sprite_loop_t));
//    sprite_loop_t *tmp = *begin;
//
//    new->sprite = sfSprite_create();
//    new->texture = sfTexture_createFromFile(path, NULL);
//    sfSprite_setTexture(new->sprite, new->texture, sfTrue);
//    sfSprite_setPosition(new->sprite, (sfVector2f){0, 0});
//    new->next = NULL;
//    if (!tmp) {
//        printf("tmp is null\n");
//        *begin = new;
//        new->next = new;
//        return;
//    }
//    while (tmp->next != *begin)
//        tmp = tmp->next;
//    tmp->next = new;
//    new->next = *begin;
//}

static void add_sprite_tab(menu_t *menu, char *path, int index)
{
    menu->sprite[index] = sfSprite_create();
    menu->texture[index] = sfTexture_createFromFile(path, NULL);
    sfSprite_setTexture(menu->sprite[index], menu->texture[index], true);
    sfSprite_setPosition(menu->sprite[index], (sfVector2f){0, 0});
}

static void set_background(menu_t *menu)
{
    add_sprite_tab(menu, "menu_asset/menu1.png", 0);
    add_sprite_tab(menu, "menu_asset/menu2.png", 1);
    add_sprite_tab(menu, "menu_asset/menu3.png", 2);
    add_sprite_tab(menu, "menu_asset/menu4.png", 3);
    add_sprite_tab(menu, "menu_asset/menu5.png", 4);
    add_sprite_tab(menu, "menu_asset/menu6.png", 5);
    add_sprite_tab(menu, "menu_asset/menu7.png", 6);
    add_sprite_tab(menu, "menu_asset/menu8.png", 7);
    add_sprite_tab(menu, "menu_asset/menu3.png", 8);
    add_sprite_tab(menu, "menu_asset/menu4.png", 9);
    add_sprite_tab(menu, "menu_asset/menu5.png", 10);
    add_sprite_tab(menu, "menu_asset/menu6.png", 11);
}

static menu_t *create_menu_struct(void)
{
    menu_t *menu = malloc(sizeof(menu_t));

    if (!menu) {
        return (NULL);
    }
    menu->pos = 0;
    menu->sprite = malloc(sizeof(sfSprite *) * 12);
    menu->texture = malloc(sizeof(sfTexture *) * 12);
    set_background(menu);
    return menu;
}

rpg_t *create_rpg_struct(void)
{
    rpg_t *rpg = malloc(sizeof(rpg_t));
    sfVideoMode mode = {1920, 1080, 32};

    rpg->start_menu = create_menu_struct();
    rpg->clock = sfClock_create();
    rpg->scene = MAIN;
    rpg->second = 0;
    rpg->time = 0;
    rpg->window = sfRenderWindow_create(mode, "my_rpg", sfClose, NULL);
    rpg->heros = init_heros(KNIGHT_SPRITE);
    rpg->heros->npc->entity->pos = (sfVector2f){1000, 500};
    sfSprite_setPosition(rpg->heros->npc->entity->sprite, rpg->heros->npc->entity->pos);
    sfRenderWindow_setPosition(rpg->window, (sfVector2i){0, 0});
    rpg->ticks = false;
    for (int i = 0; i < 256; i++)
        rpg->key_state[i] = false;
    for (int i = 0; i <= MINE; i++)
        rpg->biome[i] = create_biome(i);
    return rpg;
}
