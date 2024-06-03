/*
** EPITECH PROJECT, 2023
** graph.h
** File description:
** macro for CSFML
*/

#include "rpg.h"

void set_func_quest_tuto(quest_t *quest_tab)
{
    set_func_quest(&(quest_tab[MOVEMENT_T]), NULL, check_quest_move_tuto);
    set_func_quest(&(quest_tab[ATTACK_T]), NULL, check_quest_attack_tuto);
    set_func_quest(
        &(quest_tab[KILL_T]), start_kill_goblins, check_if_kill_bot);
    set_func_quest(&(quest_tab[TAKE_T]), NULL, check_if_take);
    set_func_quest(&(quest_tab[HEAL_T]), NULL, check_if_consume);
    set_func_quest(&(quest_tab[EQUIP_T]), NULL, check_if_equip);
    set_func_quest(&(quest_tab[DROP_T]), NULL, check_if_drop);
    set_func_quest(&(quest_tab[TEST_T]), start_final_test, check_test_quest);
}

void init_quest_tuto(quest_t *quest_tab, sfFont *font)
{
    char *message[9] = {
        "Deplacez vous à l'aide de ZQSD",
        "Attaquez grace à IJKL",
        "Tuez les goblin",
        "Ramasser l'objet grâce à E",
        "Ouvrer votre inventaire grâce à TAB et prenez une potion",
        "Equipez vous un Objet",
        "Jetez un objet",
        "Passez le test",
        NULL
    };

    for (int i = 0; i <= TEST_T; i++)
        set_quest(&(quest_tab[i]), message[i], font);
    quest_tab[TEST_T + 1].display = NULL;
    set_func_quest_tuto(quest_tab);
}
