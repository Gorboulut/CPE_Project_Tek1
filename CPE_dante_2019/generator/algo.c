/*
** EPITECH PROJECT, 2020
** algo
** File description:
** algo
*/

#include "include/generator.h"

void check_other_wall(dante_t *s, int i, int x, int random)
{
    if (i - 1 >= 0 && s->x == 1 && s->y == 0)
        s->map[i - 1][x] = '*';
    if (x - 1 >= 0 && s->x == 0 && s->y == 1)
        s->map[i][x - 1] = '*';
    if (s->x == 1 && s->y == 1) {
        random = rand() % 2;
        if (x - 1 >= 0 && random == 0)
            s->map[i][x - 1] = '*';
        else if (i - 1 >= 0 && random == 1)
            s->map[i - 1][x] = '*';
    }
}

void algo_lets_dante(dante_t *s, int i, int x)
{

    if (i == 0)
        s->map[i][x] = '*';
    if (i - 1 >= 0 && s->map[i - 1][x] == 'X')
        s->x = 1;
    if (x - 1 >= 0 && s->map[i][x - 1] == 'X')
        s->y = 1;
}

void lets_dante(dante_t *s)
{
    int random = 0;

    for (int i = 0; i < s->max_y; i += 2) {
        s->x = 0;
        s->y = 0;
        for (int x = 0; x < s->max_x; x += 2) {
            algo_lets_dante(s, i, x);
            check_other_wall(s, i, x, random);
        }
    }
    if (s->map[s->base_y - 2][s->base_x - 1] == 'X'
    && s->map[s->base_y - 1][s->base_x - 2] == 'X')
        s->map[s->base_y - 1][s->base_x - 2] = '*';
}
