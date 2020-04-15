/*
** EPITECH PROJECT, 2020
** matchstick
** File description:
** recreate matchsstick game
*/
#include "include/my.h"

int check_nbr(char *buffer, int x)
{
    for (int i = 0; buffer[i] != '\0'; i++) {
        if (x == 0)
            if ((buffer[i] < '0' || buffer[i] > '9') && buffer[i] != '\n') {
                my_putstr("Error: invalid input (positive number expected)\n");
                return (4);
            }
        if (x == 1)
            if ((buffer[i] < '0' || buffer[i] > '9') && buffer[i] != '\n') {
                my_putstr("Error: invalid input (positive number expected)\n");
                return (4);
            }
    }
    return (0);
}

int check_arg(char **av)
{
    for (int i = 1; i < 3; i++)
        for (int x = 0; av[i][x] != '\0'; x++)
            if (av[i][x] < '0' || av[i][x] > '9')
                return (84);
    if (my_number(av[1]) < 2 || my_number(av[1]) > 99)
        return (84);
    return (0);
}

int main(int ac, char **av)
{
    int win;

    if (ac != 3)
        return (84);
    if (check_arg(av) == 84)
        return (84);
    win = start_tab(av);
    return (win);
}
