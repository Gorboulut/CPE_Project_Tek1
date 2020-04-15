/*
** EPITECH PROJECT, 2020
** strtab
** File description:
** str to word tab
*/
#include "include/solver.h"

int size_lign(char *s, char c)
{
    int x = 0;

    for (int i = 0; s[i] != '\0'  && s[i] != c; i++)
        x++;
    return (x + 1);
}

int count_lign(char *s, char c)
{
    int x = 0;

    for (int i = 0; s[i]; i++)
        if (s[i] == c)
            x++;
    return (x + 1);
}

char **str_to_word_tab(char *s, char c)
{
    char **result = malloc(sizeof(char *) * (count_lign(s, c) + 1));
    int x = 0;
    int y = 0;

    result[x] = malloc(sizeof(char) * size_lign(s, c) + 1);
    for (int i = 0; s[i] != '\0'; i++) {
        if (s[i] == c) {
            for (; s[i] == c && s[i] != '\0'; i++);
            result[x][y] = '\0';
            x++;
            result[x] = malloc(sizeof(char) * size_lign(s, c) + 1);
            y = 0;
        } result[x][y] = s[i];
        y++;
    } result[x + 1] = NULL;
    result[x][y] = '\0';
    return (result);
}
