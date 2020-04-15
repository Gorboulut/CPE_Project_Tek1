/*
** EPITECH PROJECT, 2019
** my_revstr
** File description:
** reverse a string
*/
#include <stdio.h>

int my_strlen(char *str)
{
    int i = 0;
    while (str[i] != '\0')
        i++;
    return (i);
}

char *my_revstr(char *str)
{
    int i = my_strlen(str) - 1;
    int x = 0;
    char c;

    if (i == -1)
        return ("");
    while (i >= x) {
        c = str[i];
        str[i] = str[x];
        str[x] = c;
        i--;
        x++;
    }
    return (str);
}
