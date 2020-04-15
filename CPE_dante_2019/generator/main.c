/*
** EPITECH PROJECT, 2020
** dante
** File description:
** main for dante
*/

#include "include/generator.h"

void print_maze(dante_t *s)
{
    int i = 0;

    if (s->map[s->base_y - 1 - s->w][s->base_x - 1] == 'X')
        s->map[s->base_y - 1 - s->w][s->base_x - 1] = '*';
    if (s->map[s->base_y - 2 - s->w][s->base_x - 1] == 'X' &&
        s->map[s->base_y - 1 - s->w][s->base_x - 2] == 'X')
        s->map[s->base_y - 2 - s->w][s->base_x - 1] = '*';
    for (i = 0; s->map[i + 1 + s->w] != NULL; i++)
        printf("%s\n", s->map[i]);
    printf("%s", s->map[i]);
}

void go_unperfect(dante_t *s)
{
    int x = 0;
    int y = 0;

        for (int i = 0; i < 10; i++) {
            x = rand() % s->max_x;
            y = rand() % s->max_y;
            if (s->map[y][x] == 'X')
                s->map[y][x] = '*';
            else if (s->base_x > 5 && s->base_y > 5)
                i--;
        }
    if (s->map[s->max_y - 1][s->max_x - 2] == 'X')
        s->map[s->max_y - 1][s->max_x - 2] = '*';
    else
        s->map[s->max_y - 2][s->max_x - 1] = '*';
}

void init_stru(dante_t *stru, int i, char **av)
{
    stru->max_x = atoi(av[1]);
    stru->base_x = atoi(av[1]);
    stru->map[0][0] = '*';
    stru->finished = 0;
    stru->w = i;
}

int main(int ac, char **av)
{
    dante_t *stru = malloc(sizeof(dante_t));
    int i = 0;

    srand(getpid() * time(NULL));
    stru->list = NULL;
    if (ac < 3 || ac > 5)
        return (84);
    if (atoi(av[2]) % 2 == 0)
        i++;
    stru->map = create_map(atoi(av[1]), atoi(av[2]) + i);
    init_stru(stru, i, av);
    stru->max_y = atoi(av[2]) + i;
    stru->base_y = atoi(av[2]) + i;
    if (stru->map == NULL)
        return (84);
    lets_dante(stru);
    if (ac == 3)
        go_unperfect(stru);
    print_maze(stru);
    return (0);
}
