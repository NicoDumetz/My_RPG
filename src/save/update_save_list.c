/*
** EPITECH PROJECT, 2023
** create_sprite
** File description:
** create_sprite + texture
*/

#include "rpg.h"

void update_save_list(save_t *save, rpg_t *rpg)
{
    save->next = NULL;
    save->prev = NULL;
    save->next = rpg->save_list;
    if (rpg->save_list)
        rpg->save_list->prev = save;
    rpg->save_list = save;
}
