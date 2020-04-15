/*
** EPITECH PROJECT, 2019
** my_strcpy
** File description:
** copy a string in another
*/
#include <unistd.h>
#include <stdio.h>
#include <string.h>

char *my_strcpy(char *dest, char const *src)
{
    int i = 0;

    if (*src == '\0')
        return (dest);
    while (*src != '\0') {
        dest[i] = src[i++];
    }
    dest[i] = '\0';
    return (dest);
}
