/*
** EPITECH PROJECT, 2020
** matchstick
** File description:
** ai func
*/
#include "include/my.h"

void put_matchs(stick *game)
{
    my_putstr("Error: you cannot remove more than ");
    my_put_nbr(game->max);
    my_putstr(" matches per turn\n");
}

void check_matches_ai(stick *game)
{
    int i = 0;
    int matches = 0;

    for (i = 0; i < my_strlen(game->game[0]); i++) {
        if (game->game[game->line][i] == '|')
            matches++;
    }
    if (matches < game->match) {
        call_ai(game);
    }
}

void fill_buff(stick *game)
{
    game->buffer = NULL;
    my_putstr("Line: ");
}
