/*
** EPITECH PROJECT, 2020
** dante
** File description:
** algorithm for the solver of dante
*/
#include "include/solver.h"

int start_algo(solver_t *s, int x, int y)
{
    if (x == s->max_x && y == s->max_y) {
        s->map[y][x] = 'o';
        return (0);
    }
    else if (x >= 0 && y >= 0 && x <= s->max_x && y <= s->max_y
        && s->map[y][x] == '*') {
        s->map[y][x] = 'o';
        if (start_algo(s, x + 1, y) == 0)
            return (0);
        if (start_algo(s, x, y + 1) == 0)
            return (0);
        if (start_algo(s, x - 1, y) == 0)
            return (0);
        if (start_algo(s, x, y - 1) == 0)
            return (0);
        s->map[y][x] = '*';
        return (1);
    }
    else
        return (1);
}
