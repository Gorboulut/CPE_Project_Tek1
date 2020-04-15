/*
** EPITECH PROJECT, 2020
** date
** File description:
** maze generator
*/
#include "include/generator.h"

char **malloc_map(int x, int y)
{
    char **map = NULL;

    map = malloc(sizeof(char *) * (y + 1));
    for (int i = 0; i < y + 1; i++)
        map[i] = malloc(sizeof(char) * (x + 1));
    if (map == NULL)
        return (NULL);
    return (map);
}

void beginning_algo(int x_2, int y_2, char **map)
{
    if (y_2 % 2 == 0 && x_2 % 2 == 0)
        map[y_2][x_2] = '*';
    else
        map[y_2][x_2] = 'X';
}

char **create_map(int x, int y)
{
    char **map = malloc_map(x, y);
    int y_2 = 0;
    int x_2 = 0;

    for (; y_2 < y; y_2++) {
        for (; x_2 < x; x_2++)
            beginning_algo(x_2, y_2, map);
        map[y_2][x_2] = '\0';
        x_2 = 0;
    }
    map[y_2] = NULL;
    return (map);
}
