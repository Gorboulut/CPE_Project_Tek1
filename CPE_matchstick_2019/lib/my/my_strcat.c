/*
** EPITECH PROJECT, 2019
** my_strcat
** File description:
** concatenates two strings
*/
#include <unistd.h>
#include <string.h>
#include <stdio.h>

char *my_strcat(char *dest, char const *src)
{
    int x = 0;
    int i = 0;

    while (dest[i] != '\0' || src[x] != '\0') {
        while (dest[i] != '\0')
            i++;
        while (src[x] != '\0') {
            dest[i + x] = src[x];
            x++;
        }
    }
    dest[i + x] = '\0';
    return (dest);
}
