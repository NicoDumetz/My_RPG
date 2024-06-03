/*
** EPITECH PROJECT, 2023
** my_strcmp
** File description:
** Task06
*/

int my_strncmp(char const *s1, char const *s2, int nb)
{
    for (int i = 0; i < nb; i++) {
        if (s1[i] == '\0' && s2[i] == '\0')
            return (0);
        if (s1[i] != s2[i])
            return (s1[i] - s2[i]);
    }
    return (0);
}
