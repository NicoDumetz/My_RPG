/*
** EPITECH PROJECT, 2023
** my_putstr.c
** File description:
** Task02
*/
#include <unistd.h>

void myputchar(char c)
{
    write(1, &c, 1);
}

int my_putstr(char const *str)
{
    for (int i = 0; str[i] != '\0'; i++) {
        myputchar(str[i]);
    }
    return (0);
}
