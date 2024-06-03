/*
** EPITECH PROJECT, 2023
** create_sprite
** File description:
** create_sprite + texture
*/

#include "rpg.h"

int find_len(int nbr)
{
    int count = 0;
    int save_nbr = nbr;

    if (nbr < 0)
        save_nbr = -save_nbr;
    while (save_nbr >= 10) {
        save_nbr /= 10;
        count++;
    }
    return (count);
}

char *convert_int_to_str(int nbr)
{
    int len = find_len(nbr);
    int start = 0;
    int save_len = len;
    char *scr = malloc(sizeof(char) * len + 2);

    if (nbr < 0){
        scr[0] = '-';
        nbr = -nbr;
        start = 1;
        len++;
    }
    while (start <= len) {
        scr[start] = (nbr / (int)pow(10, save_len)) + '0';
        nbr %= (int)pow(10, save_len);
        save_len--;
        start++;
    }
    scr[start] = '\0';
    return (scr);
}
