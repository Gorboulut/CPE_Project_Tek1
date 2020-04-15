/*
** EPITECH PROJECT, 2020
** CPE_dante
** File description:
** maze solver
*/
#include "include/solver.h"

int main(int ac, char **av)
{
    solver_t *s = malloc(sizeof(solver_t));

    if (ac != 2)
        return (84);
    take_map(av, s);
    init_value(s);
    if (start_algo(s, 0, 0) == 0)
        for (int i = 0; i <= s->max_y; i++) {
            printf("%s", s->map[i]);
            if (i != s->max_y)
                printf("\n");
        }
    else
        printf("no solution found");
    return (0);
}
