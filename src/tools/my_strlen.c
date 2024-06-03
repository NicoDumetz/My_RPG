/*
** EPITECH PROJECT, 2023
** my_strlen
** File description:
** Task03
*/

int my_strlen(char const *str)
{
    int i = 0;
    int count = 0;

    for (; str[i] != '\0'; i++){
        count++;
    }
    return (count);
}
