/*
** EPITECH PROJECT, 2019
** my number
** File description:
** conv a char into an int
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int my_number(char *str)
{
    int result = 0;

    while (*str == ' ')
        str += 1;
    while (*str >= '0' && *str <= '9') {
        result = result * 10 + (*str - '0');
        str += 1;
    }
    return (result);
}
