/*
** EPITECH PROJECT, 2019
** itoafunc
** File description:
** itoafunc
*/
#include "../../include/my.h"

char *itoa(int n)
{
    int i = 0;
    int sign = n;
    char *s = malloc(1000);

    if (n < 0)
        n = -n;
    do
        s[i++] = n % 10 + '0';
    while ((n /= 10) > 0);
    if (sign < 0)
        s[i++] = '-';
    s[i] = '\0';
    my_revstr(s);
    return (s);
}
