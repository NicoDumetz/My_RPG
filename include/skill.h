/*
** EPITECH PROJECT, 2023
** graph.h
** File description:
** macro for CSFML
*/

#ifndef SKILL_H
    #define SKILL_H
typedef struct heros_s heros_t;
typedef struct rpg_s rpg_t;
typedef void(*skill_func_t)(heros_t *heros, rpg_t *rpg, void *skill_data);
typedef enum skill_type_e {
    FIRE_BALL = 0,
    SHIELD,
    RUN
} skill_type_t;

typedef struct shield_s {
    int nbr_of_hit;
    int hit_before_desactive;
    int active;
    int stamina;
} shield_t;

typedef struct fire_ball_s {
    int stamina;
} fire_ball_t;

typedef struct run_s {
    bool active;
    float speed_multi;
    int stamina;
} run_t;

typedef struct skill_s {
    int act_skill;
    int skill_level[3];
    void *skill_tab[3];
    skill_func_t skill_funct_tab[3];
} skill_t;

extern shield_t shield_tab[];
extern run_t run_tab[];
extern fire_ball_t fireball_tab[];

/**INIT**/
void destroy_fire_ball(fire_ball_t *fire_ball);
void fire_ball_function(heros_t *heros, rpg_t *rpg, void *skill_data);
fire_ball_t *init_fire_ball(void);
void destroy_shield(shield_t *shield);
void shield_function(heros_t *heros, rpg_t *rpg, void *skill_data);
shield_t *init_shield(void);
void destroy_run(run_t *run);
void run_function(heros_t *heros, rpg_t *rpg, void *skill_data);
run_t *init_run(void);
skill_t *init_skill(void);
void destroy_skill(skill_t *skill);
void manage_skill(heros_t *heros, rpg_t *rpg);

/**SHIELD**/
bool absorb_hit(void *skill_data, heros_t *heros);
#endif
