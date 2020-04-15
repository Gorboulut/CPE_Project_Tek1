/*
** EPITECH PROJECT, 2019
** my putstr
** File description:
** display a *str
*/
#include <unistd.h>
#include "../../include/my.h"

int my_putstr(char const *str)
{
    write (1, str, my_strlen(str));
    return (0);
}
