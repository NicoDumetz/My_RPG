/*
** EPITECH PROJECT, 2023
** my_strcmp
** File description:
** Task06
*/

int which_is_shorter(char const *s1, char const *s2)
{
    int s1len = my_strlen(s1);
    int s2len = my_strlen(s2);

    if (s1len > s2len)
        return (s2len);
    if (s1len < s2len)
        return (s1len);
    if (s1len == s2len)
        return (s2len);
    return (0);
}

int my_strcmp(char const *s1, char const *s2)
{
    int len = which_is_shorter(s1, s2);

    for (int i = 0; i <= len; i++) {
        if (s1[i] != s2[i])
            return (s1[i] - s2[i]);
    }
    return (0);
}
