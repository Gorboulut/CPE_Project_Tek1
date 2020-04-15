/*
** EPITECH PROJECT, 2019
** my_realloc
** File description:
** realloc
*/
#include "../../include/my.h"

char *get_realloc(char *fullstr, int len)
{
    char *newstr = NULL;
    int i = 0;

    if (fullstr == NULL)
        return (my_strdup(fullstr));
    newstr = malloc(sizeof(char) + (len + 1));
    while (fullstr[i] != '\0') {
        newstr[i] = fullstr[i];
        i++;
    }
    newstr[i] = '\0';
    return (newstr);
}
