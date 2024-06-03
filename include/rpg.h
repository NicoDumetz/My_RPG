/*
** EPITECH PROJECT, 2023
** graph.h
** File description:
** macro for CSFML
*/

#ifndef RPG_H
    #define RPG_H
    #include "button.h"
    #include "lib.h"
typedef enum scene_e {
    MAIN = 0,
}scene_t;
typedef struct rpg_s {
    heros_t *heros;
    int scene;
    sfClock *clock;
    sfEvent event;
    int second;
    float time;
    sfRenderWindow *window;
} rpg_t;

void test(rpg_t *rpg);

/**TOOLS**/
int my_strncmp(char const *s1, char const *s2, int len);
int my_strlen(char const *str);
int my_putstr(char const *str);
void destroy_sprite(sfSprite *sprite);
sfSprite *create_sprite(char *asset);

/**RPG**/
void rpg(rpg_t *rpg);
void destroy_rpg(rpg_t *rpg);
rpg_t *create_rpg_struct(void);

/**EVENT**/
void manage_event(rpg_t *rpg);
#endif
