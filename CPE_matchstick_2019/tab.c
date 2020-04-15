/*
** EPITECH PROJECT, 2020
** matchstick
** File description:
** game
*/
#include "include/my.h"

void add_stick(stick *match)
{
    int stick = 1;
    int rem_s = stick;
    int i = 0;
    int x = 0;

    for (i = 1; i <= match->le; i++) {
        for (x = 0; x < match->t_l / 2 + stick; x++) {
            if (x + stick >= match->t_l / 2 + stick)
                match->game[i][x] = '|';
        }
        while (stick > 0) {
            match->game[i][match->t_l / 2 - stick + 1] = '|';
            stick--;
        }
        stick = rem_s + 1;
        rem_s = stick;
    }
}

void fill_tab(stick *match)
{
    int x = 0;

    for (int i = 0; i <= match->le + 1; i++) {
        for (x = 0; x < match->t_l; x++) {
            if (i == 0 || i == match->le + 1 || x == 0 || x == match->t_l - 1)
                match->game[i][x] = '*';
            else
                match->game[i][x] = ' ';
        }
    match->game[i][x] = '\0';
    }
    add_stick(match);
    for (int i = 0; i <= match->le + 1; i++) {
        my_putstr(match->game[i]);
        my_putchar('\n');
    }
    match->win = 2;
    match->turn = 1;
}

int start_tab(char **av)
{
    stick *match = malloc(sizeof(stick));
    int i = 0;
    int win;

    match->max = my_number(av[2]);
    match->le = my_number(av[1]);
    match->s = 0;
    match->t_l = match->le * 2 + 1;
    match->game = malloc(sizeof(char *) * (match->le + 3));
    for (i = 0; i < match->le + 2; i++)
        match->game[i] = malloc(sizeof(char) * (match->t_l + 4));
    match->game[i] = NULL;
    fill_tab(match);
    start_game(match);
    win = match->win;
    for (i = 0; i < match->le + 3; i++)
        free(match->game[i]);
    free(match->game);
    free(match);
    return (win);
}
