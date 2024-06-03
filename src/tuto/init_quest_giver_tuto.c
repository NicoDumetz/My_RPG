/*
** EPITECH PROJECT, 2023
** graph.h
** File description:
** macro for CSFML
*/

#include "rpg.h"

const char *quest_giver_dial_tuto[] = {
    "",
    "Welcome, recruit. I am here to guide you on your journey.",
    "Your first task is to master basic movement.",
    "Use the ZQSD keys to move around.",
    "Z to move forward, S to move backward.",
    "Q to move left, and D to move right.",
    "Practice these movements until you feel comfortable.",
    "Once you are ready, come back to me for your next task.",
    "Remember, a strong foundation is key to success.",
    "",
    "Well done mastering movement, recruit.",
    "Now, it's time to learn the basics of combat.",
    "Use the IJKL keys to attack.",
    "I to attack upward, K to attack downward.",
    "J to attack left, and L to attack right.",
    "Practice these attacks on the training dummy.",
    "Once you are confident, return to me for further instruction.",
    "Mastering combat techniques is crucial for your success.",
    "",
    "Excellent work with your combat skills, recruit.",
    "Your next task is to put your training to the test.",
    "There are weakened goblins nearby that you need to eliminate.",
    "Use your movement and combat skills to defeat them.",
    "Remember to stay alert and use your attacks wisely.",
    "Once you have defeated the goblins,",
    "return to me for further instructions.",
    "This will test your ability to handle real combat situations.",
    "Good luck, recruit. Show no mercy to the goblins.",
    "",
    "Well done defeating the goblins, recruit.",
    "Now, it's time to collect the items they dropped.",
    "You need to be close to the items to pick them up.",
    "Use the E key to collect items from the ground.",
    "Search the area and gather everything the goblins left behind.",
    "Once you have collected all the items, return to me.",
    "This will teach you the importance of scavenging after battles.",
    "Good luck, recruit. Make sure to check everywhere.",
    "",
    "Good job collecting the items, recruit.",
    "Now, let's learn how to manage your inventory.",
    "Press the Tab key to open your inventory.",
    "You will see a potion among the items you collected.",
    "To consume the potion, left-click on it.",
    "Drinking the potion will give you experience points.",
    "Once you have used the potion, close the inventory.",
    "This will help you understand how to use items effectively.",
    "Great work, recruit. Continue to grow stronger.",
    "",
    "Excellent progress, recruit.",
    "Now, let's learn how to equip items.",
    "Open your inventory by pressing the Tab key.",
    "You will find a glove among your items.",
    "Left-click on the glove to equip it.",
    "To unequip the glove, simply left-click on it again.",
    "Equipping items can enhance your abilities.",
    "Practice equipping and unequipping the glove.",
    "Once you are comfortable, close the inventory.",
    "Great job, recruit. Continue to improve your skills.",
    "",
    "You're doing great, recruit.",
    "Now, let's learn how to manage harmful items.",
    "Open your inventory by pressing the Tab key.",
    "You will find a mushroom that is dangerous to consume.",
    "To avoid losing health, you need to discard it.",
    "Hold the Ctrl key and left-click on the mushroom to throw it away.",
    "This will teach you how to handle dangerous items.",
    "Once you have discarded the mushroom, close your inventory.",
    "Well done, recruit. Managing your inventory is key to survival.",
    "",
    "Recruit, you have learned everything you need to know.",
    "But now, a grave threat has emerged.",
    "An army of goblins has infiltrated our castle.",
    "You must eliminate all the goblins within the castle walls.",
    "If you fail, you will be banished from our order.",
    "Use all your skills and knowledge to defeat them.",
    "This is your most important task yet.",
    "Return to me once the castle is secure.",
    "Our future depends on your success. Good luck, recruit.",
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
    sfVector2f pos = {600, 500};

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
