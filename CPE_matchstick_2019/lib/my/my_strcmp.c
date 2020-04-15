/*
** EPITECH PROJECT, 2019
** my_strcmp
** File description:
** compare two strings and return an int
*/
#include <stdio.h>
#include "../../include/my.h"

int my_strcmp(char const *s1, char const *s2)
{
    int i = 0;

    while (s1[i] != '\0' && s2[i] != '\0' && s1[i] == s2[i]) {
        i++;
    }
    return (s1[i] - s2[i]);
}
