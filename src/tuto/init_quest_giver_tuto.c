/*
** EPITECH PROJECT, 2023
** graph.h
** File description:
** macro for CSFML
*/

#include "rpg.h"

const char *quest_giver_dial_tuto[] = {
    "",
    "",
    "Welcome, recruit.",
    "The path of the warrior is strewn with trials and victories.",
    "Are you ready to begin your training?",
    "",
    "The first lesson is posture.",
    "Keep your body balanced and your feet firmly on the ground.",
    "",
    "Now let's move on to technique.",
    "Approach and strike the dummy with your sword.",
    "Do not hesitate to apply your full strength.",
    "",
    "Well done!",
    "But a true fighter must also know how to defend.",
    "Block my next blow with your shield.",
    "",
    "Excellent! You learn quickly.",
    "Now, let's try a series of attacks.",
    "Combine quick strikes with powerful blows.",
    "",
    "You are doing well.",
    "But real combat is unpredictable.",
    "Stay vigilant and adapt to every situation.",
    "",
    "To finish, we will practice dueling.",
    "Prepare yourself, I will not hold back this time.",
    "",
    "Your progress is impressive.",
    "Continue to practice, and one day.",
    "You will be a knight worthy of the name.",
    "",
    "Debrouille toi mon bezot",
    ""
};

void set_action_tab_quest_giver_tuto(quest_giver_t *quest_giver)
{
    quest_giver->npc->action[ATTACK_F] = (sfVector2i){6, 6};
    quest_giver->npc->action[ATTACK_B] = (sfVector2i){6, 5};
    quest_giver->npc->action[ATTACK_L] = (sfVector2i){6, -3};
    quest_giver->npc->action[ATTACK_R] = (sfVector2i){6, 3};
    quest_giver->npc->action[MOVE_R] = (sfVector2i){6, 1};
    quest_giver->npc->action[MOVE_L] = (sfVector2i){6, -1};
    quest_giver->npc->action[MOVE_F] = (sfVector2i){-1, 0};
    quest_giver->npc->action[MOVE_B] = (sfVector2i){-1, 0};
    quest_giver->npc->action[STAND] = (sfVector2i){6, 0};
}

void init_quest_giver_next_tuto(quest_giver_t *quest_giver,
    sfFont **font_tab, sfVector2f pos)
{
    sfVector2f dial_pos = {pos.x - 200, pos.y + 125};
    sfVector2f signal_pos = {pos.x + 90, pos.y - 5};

    quest_giver->act_dial = 1;
    quest_giver->dial = sfText_create();
    quest_giver->is_interact = true;
    quest_giver->signal = sfText_create();
    sfText_setFillColor(quest_giver->signal, sfYellow);
    sfText_setScale(quest_giver->signal, (sfVector2f){2, 2});
    sfText_setOutlineColor(quest_giver->signal, sfBlack);
    sfText_setOutlineThickness(quest_giver->signal, 2);
    sfText_setFillColor(quest_giver->dial, sfWhite);
    sfText_setOutlineColor(quest_giver->signal, sfBlack);
    sfText_setOutlineThickness(quest_giver->dial, 6);
    sfText_setString(quest_giver->signal, "!");
    sfText_setString(quest_giver->dial, quest_giver_dial_tuto[1]);
    sfText_setPosition(quest_giver->dial, dial_pos);
    sfText_setPosition(quest_giver->signal, signal_pos);
    sfText_setFont(quest_giver->dial, font_tab[PIXEL]);
    sfText_setFont(quest_giver->signal, font_tab[PIXEL]);
}

quest_giver_t *init_quest_giver_next_two_tuto(
    quest_giver_t *quest_giver, back_t *back)
{
    set_box(quest_giver->npc->entity->colbox,
        quest_giver->npc->entity->colbox_dim, quest_giver->npc->entity);
    draw_black_rect_on_image(quest_giver->npc->entity->colbox,
        back->collision.col_image);
    quest_giver->dial_tab = quest_giver_dial_tuto;
    quest_giver->npc->view = 100;
    quest_giver->act_dial = 0;
    return (quest_giver);
}

quest_giver_t *init_quest_giver_tuto(
    sfTexture **text_tab, back_t *back, sfFont **font_tab)
{
    quest_giver_t *quest_giver = malloc(sizeof(quest_giver_t));
    sfFloatRect hitbox = {30, 25, 55, 55};
    sfFloatRect colbox = {40, 60, 80, 90};
    sfVector2f pos = {700, 700};

    quest_giver->act_quest = -1;
    quest_giver->npc = init_npc(text_tab[KNIGHT_TEXT]);
    quest_giver->npc->entity->parent = quest_giver->npc;
    set_offset(quest_giver->npc->entity, (sfVector2i){6, 8});
    set_action_tab_quest_giver_tuto(quest_giver);
    quest_giver->npc->special = QUEST_GIVER;
    quest_giver->npc->entity->colbox_dim = colbox;
    quest_giver->npc->hitbox_dim = hitbox;
    quest_giver->npc->view = 100;
    sfSprite_setPosition(quest_giver->npc->entity->sprite, pos);
    quest_giver->npc->entity->pos = pos;
    draw_black_rect_on_image(quest_giver->npc->entity->colbox,
        back->collision.col_image);
    init_quest_giver_next_tuto(quest_giver, font_tab, pos);
    return (init_quest_giver_next_two_tuto(quest_giver, back));
}
