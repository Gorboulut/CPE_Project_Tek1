/*
** EPITECH PROJECT, 2020
** init all
** File description:
** init all
*/

#include "include/solver.h"

void init_value(solver_t *s)
{
    for (s->max_y = 0; s->map[s->max_y]; s->max_y++);
    for (s->max_x = 0; s->map[0][s->max_x] != '\0'; s->max_x++);
    s->max_x--;
    s->max_y--;
}

int take_map(char **av, solver_t *s)
{
    char *map = NULL;
    struct stat stat_t;
    int fd;

    stat(av[1], &stat_t);
    fd = open(av[1], O_RDONLY);
    if (fd == -1)
        return (84);
    map = malloc(sizeof(char) * stat_t.st_size + 1);
    if (map == NULL)
        return (84);
    read(fd, map, stat_t.st_size);
    map[stat_t.st_size] = '\0';
    s->map = str_to_word_tab(map, '\n');
    free(map);
}
