/*
** EPITECH PROJECT, 2023
** game
** File description:
** rpg.h
*/

#include "rpg.h"

/*typedef struct run_s {
    int level;
    bool active;
    float speed_multi;
    int stamina;
} run_t;
*/

run_t run_tab[] = {
    {false, 1, 0},
    {false, 1.15, 20},
    {false, 1.30, 18},
    {false, 1.45, 16}
};


void destroy_run(run_t *run)
{
    free(run);
}

void run_function(heros_t *heros, rpg_t *rpg, void *skill_data)
{
    run_t *data = (run_t *)skill_data;

    if (heros->stamina > 1 && heros->restore == false) {
        heros->stamina -= data->stamina * rpg->time;
        if (!data->active) {
            data->active = true;
            heros->multi_speed *= data->speed_multi;
        }
    }
    if (heros->stamina < 1 && data->active) {
        heros->multi_speed /= data->speed_multi;
        data->active = false;
    }
}
