/*
** EPITECH PROJECT, 2023
** graph.h
** File description:
** macro for CSFML
*/

#include "rpg.h"

bool is_position_allowed(sfImage* map_image, sfRectangleShape *colbox)
{
    if (!static_collisions_down(colbox, map_image) &&
        !static_collisions_up(colbox, map_image) &&
        !static_collisions_left(colbox, map_image) &&
        !static_collisions_right(colbox, map_image))
        return true;
    return false;
}

void find_valid_pos(sfImage* map_image, entity_t *entity)
{
    sfVector2u image_size = sfImage_getSize(map_image);
    sfVector2f new_pos = {0, 0};
    npc_t *npc = (npc_t *)(entity->parent);

    new_pos.x = rand() % image_size.x;
    new_pos.y = rand() % image_size.y;
    sfSprite_setPosition(entity->sprite, new_pos);
    set_box(entity->colbox, entity->colbox_dim, entity);
    if (!is_position_allowed(map_image, entity->colbox)) {
        npc->is_alive = false;
    }
}

void bot_generator(biome_t *biome, int *who)
{
    npc_t *new_bot = NULL;
    static int i = 0;
    static int already_do = 0;
    int rand_nbr = rand();

    if (who[i] < 0 || i == 6)
        i = 0;
    if ((rand_nbr % 3) != 0)
        already_do = 0;
    if (biome->nbr_bot < 30 && (rand_nbr % 3) == 0 && already_do == 0) {
        new_bot = create_bot(who[i], biome->bot_data, (sfVector2f){0, 0});
        i++;
        biome->nbr_bot = biome->nbr_bot + 1;
        find_valid_pos(biome->back->collision.col_image, new_bot->entity);
        manage_animation_bot(new_bot->entity, true);
        already_do = 1;
    }
}
