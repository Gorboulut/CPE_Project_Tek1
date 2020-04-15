/*
** EPITECH PROJECT, 2019
** my_strdup
** File description:
** allocate memory of a string
*/
#include "../../include/my.h"
#include <stdlib.h>
#include <stdio.h>

char *my_strdup(char const *src)
{
    char *str;
    int i = 0;

    str = malloc(sizeof(char const *) + my_strlen(src) + 1);
    while (src[i] != '\0') {
        str[i] = src[i];
        i++;
    }
    str[i] = '\0';
    return (str);
}
