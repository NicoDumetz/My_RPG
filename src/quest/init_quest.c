/*
** EPITECH PROJECT, 2023
** game
** File description:
** rpg.h
*/

#include "rpg.h"

void destroy_quest(quest_t *quest_tab)
{
    for (int i = 0; quest_tab[i].display != NULL; i++) {
        sfRectangleShape_destroy(quest_tab[i].box);
        quest_tab[i].box = NULL;
        sfText_destroy(quest_tab[i].display);
        quest_tab[i].display = NULL;
    }
}

void set_func_quest(
    quest_t *quest, start_function_t start_f, check_function_t check_f)
{
    quest->start_f = start_f;
    quest->check_f = check_f;
}

sfText *set_display_quest(char *message, sfFont *font)
{
    sfText *text = sfText_create();

    sfText_setFont(text, font);
    sfText_setString(text, message);
    sfText_setOutlineColor(text, sfBlack);
    sfText_setOutlineThickness(text, 5);
    sfText_setFillColor(text, sfWhite);
    return (text);
}

void set_quest(
    quest_t *quest, char *message, sfFont *font)
{
    quest->display = set_display_quest(message, font);
    quest->box = sfRectangleShape_create();
    quest->state = NOT_BEGIN;
    quest->start_f = NULL;
    quest->check_f = NULL;
    sfRectangleShape_setSize(quest->box, (sfVector2f){10, 10});
    sfRectangleShape_setFillColor(quest->box, sfTransparent);
    sfRectangleShape_setOutlineColor(quest->box, sfBlack);
    sfRectangleShape_setOutlineThickness(quest->box, 5);
}

void init_quest(quest_t *quest_tab, sfFont **font_tab)
{
    char *message[4] = {
        "Kill the Camp's Boss",
        "Kill the Mine's Boss",
        "Kill the Castle's Boss",
    };

    for (int i = 0; i <= KILL_CASTLE; i++)
        set_quest(&(quest_tab[i]), message[i], font_tab[PIXEL]);
    quest_tab[3].display = NULL;
}
