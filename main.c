/*
** EPITECH PROJECT, 2023
** graph.h
** File description:
** macro for CSFML
*/

#include "rpg.h"

int check_asset(sfTexture **text_tab, sfFont **font_tab, sfMusic **song_tab)
{
    if (song_tab == NULL)
        return 1;
    for (int i = 0; i <= MINE_TEXT; i++) {
        if (text_tab[i] == NULL)
            return 1;
    }
    for (int i = 0; i < FONT_COUNT; i++) {
        if (font_tab[i] == NULL)
            return 1;
    }
    for (int i = 0; i <= GUTS_S; i++) {
        if (song_tab[i] == NULL)
            return 1;
    }
    return 0;
}

int check_env(char **env)
{
    for (int i = 0; env[i]; i++)
        if (my_strncmp(env[i], "DISPLAY=", 8) == 0)
            return 0;
    return (1);
}

int description(void)
{
    int size_file = 2546;
    char buffer[size_file];
    int size = 0;
    int fd;

    fd = open("README.txt", O_RDONLY);
    if (fd == -1)
        return (84);
    size = read(fd, buffer, size_file);
    buffer[size] = '\0';
    my_putstr(buffer);
    close(fd);
    return (0);
}

int main(int ac, char **av, char **env)
{
    rpg_t *rpg_data;

    if (ac > 2) {
        write(2, "Wrong number of arguments please retry with -h\n", 47);
        return (84);
    }
    if (av[1] && av[1][0] == '-' && av[1][1] == 'h')
        return (description());
    if (check_env(env) != 0)
        return (84);
    rpg_data = create_rpg_struct();
    if (rpg_data == NULL)
        return 84;
    rpg(rpg_data);
    return (0);
}
