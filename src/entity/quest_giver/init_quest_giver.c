/*
** EPITECH PROJECT, 2023
** graph.h
** File description:
** macro for CSFML
*/

#include "rpg.h"

const char *quest_giver_dial[] = {
    "Days are long and nights are dangerous. Always be on your guard.",
    "",
    "Hello, stranger. You seem to be a brave and strong soul.",
    "We desperately need your help.",
    "A goblin camp has taken root in our forest, terrorizing our lands.",
    "These creatures scare away the local wildlife and haunt our nights.",
    "We can no longer live in peace.",
    "To reach their camp, you will need to cross the bridge to the west.",
    "It is a perilous journey, but we believe in your strength and courage.",
    "Can you help us and rid our forest of this menace?",
    "",
    "Thank you for defeating the goblin camp.",
    "However, we have discovered something troubling.",
    "The goblins were cruel because,",
    "they were exploited in a mine to the east.",
    "Knights have been forcing them to work in terrible conditions.",
    "We need your help again to bring true peace to our land.",
    "Please, go to the mine and destroy it to free the goblins.",
    "The mine is located to the east, and it will be a dangerous mission.",
    "We trust in your bravery and strength to help us once more.",
    "",
    "Thank you for destroying the mine and freeing the goblins.",
    "But our troubles are not over yet.",
    "The knights who exploited the goblins are based in a castle.",
    "We need you to eliminate the castle to end their reign of terror.",
    "The castle is located to the north and is heavily guarded.",
    "It will be a difficult task, but we believe in your strength.",
    "Your bravery has brought us this far.",
    "Please, help us once more and destroy the castle to the north.",
    "",
    "You have done it! The castle is defeated and peace is restored.",
    "Our land is free from the terror of the knights.",
    "We are forever grateful for your bravery and strength.",
    "The goblins and villagers can now live in harmony.",
    "You have given us hope and a future.",
    "Thank you, hero, for everything you have done.",
    "We will always remember your heroic deeds.",
    "May you find peace and happiness on your future journeys.",
    ""
};

void destroy_quest_giver(quest_giver_t *quest_giver)
{
    destroy_npc(quest_giver->npc);
    sfText_destroy(quest_giver->dial);
    quest_giver->dial = NULL;
    sfText_destroy(quest_giver->signal);
    quest_giver->signal = NULL;
    free(quest_giver);
    quest_giver = NULL;
}

void set_action_tab_quest_giver(quest_giver_t *quest_giver)
{
    quest_giver->npc->action[ATTACK_F] = (sfVector2i){6, 4};
    quest_giver->npc->action[ATTACK_B] = (sfVector2i){6, 7};
    quest_giver->npc->action[ATTACK_L] = (sfVector2i){6, -2};
    quest_giver->npc->action[ATTACK_R] = (sfVector2i){6, 2};
    quest_giver->npc->action[MOVE_R] = (sfVector2i){6, 1};
    quest_giver->npc->action[MOVE_L] = (sfVector2i){6, -1};
    quest_giver->npc->action[MOVE_F] = (sfVector2i){6, 1};
    quest_giver->npc->action[MOVE_B] = (sfVector2i){6, 1};
    quest_giver->npc->action[STAND] = (sfVector2i){6, 0};
}

void init_quest_giver_next(quest_giver_t *quest_giver,
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
    sfText_setString(quest_giver->dial, quest_giver_dial[1]);
    sfText_setPosition(quest_giver->dial, dial_pos);
    sfText_setPosition(quest_giver->signal, signal_pos);
    sfText_setFont(quest_giver->dial, font_tab[PIXEL]);
    sfText_setFont(quest_giver->signal, font_tab[PIXEL]);
}

quest_giver_t *init_quest_giver_next_two(
    quest_giver_t *quest_giver, back_t *back)
{
    set_box(quest_giver->npc->entity->colbox,
        quest_giver->npc->entity->colbox_dim, quest_giver->npc->entity);
    draw_black_rect_on_image(quest_giver->npc->entity->colbox,
        back->collision.col_image);
    quest_giver->dial_tab = quest_giver_dial;
    return (quest_giver);
}

quest_giver_t *init_quest_giver(
    sfTexture **text_tab, back_t *back, sfFont **font_tab)
{
    quest_giver_t *quest_giver = malloc(sizeof(quest_giver_t));
    sfFloatRect colbox = {40, 60, 80, 95};
    sfFloatRect hitbox = {35, 35, 70, 70};
    sfVector2f pos = {2387.69, 461.96};

    quest_giver->act_quest = -1;
    quest_giver->npc = init_npc(text_tab[MINIONS_TEXT]);
    quest_giver->npc->entity->parent = quest_giver->npc;
    set_offset(quest_giver->npc->entity, (sfVector2i){6, 6});
    set_action_tab_quest_giver(quest_giver);
    quest_giver->npc->special = QUEST_GIVER;
    quest_giver->npc->entity->colbox_dim = colbox;
    quest_giver->npc->hitbox_dim = hitbox;
    quest_giver->npc->view = 100;
    sfSprite_setPosition(quest_giver->npc->entity->sprite, pos);
    quest_giver->npc->entity->pos = pos;
    draw_black_rect_on_image(quest_giver->npc->entity->colbox,
        back->collision.col_image);
    init_quest_giver_next(quest_giver, font_tab, pos);
    return (init_quest_giver_next_two(quest_giver, back));
}
