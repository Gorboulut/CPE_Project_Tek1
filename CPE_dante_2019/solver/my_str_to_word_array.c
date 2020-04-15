/*
** EPITECH PROJECT, 2020
** aegae
** File description:
** str to array
*/

#include "include/solver.h"

static char *get_word(char *str, int i, int size)
{
    char *new = 0;

    i -= size;
    printf("size : %d\n", size);
    new = malloc(sizeof(char) * (size + 1));
    if (new == NULL)
        return (NULL);
    new = memset(new, 0, size + 1);
    new[size] = '\0';
    for (int j = 0; j < size; j++) {
        new[j] = str[i + j];
    }
    return (new);
}

char **u_str_to_word_tab(char *str, char c)
{
    int size = 0;
    int word = 0;
    char **res;

    for (int i = 0; str[i] != '\0'; i++)
        if ((str[i] == c && str[i + 1] != c) ||
            (str[i] != c && str[i + 1] == '\0'))
            size++;
    res = malloc(sizeof(char *) * (size + 1));
    if (res == NULL)
        return (NULL);
    size = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        if ((str[i] != c && str[i + 1] == c) ||
            (str[i] != c && str[i + 1] == '\0')) {
            res[word] = get_word(str, i + 1, size + 1);
            word++;
            size = 0;
        } else if (str[i] != c)
            size++;
    } return (res);
}
