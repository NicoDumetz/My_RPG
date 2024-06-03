/*
** EPITECH PROJECT, 2023
** graph.h
** File description:
** macro for CSFML
*/

#include "rpg.h"

int check_asset(rpg_t *rpg)
{
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
    if (rpg_data == NULL || check_asset(rpg_data)) {
        destroy_rpg(rpg_data);
        return 84;
    }
    rpg(rpg_data);
    return (0);
}
