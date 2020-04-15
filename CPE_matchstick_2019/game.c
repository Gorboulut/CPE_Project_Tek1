/*
** EPITECH PROJECT, 2020
** matchstick
** File description:
** start of the game
*/
#include "include/my.h"

int check_win(stick *game)
{
    for (int i = 1; i <= game->le; i++)
        for (int x = 0; x < my_strlen(game->game[0]); x++)
            if (game->game[i][x] == '|')
                return (0);
    return (1);
}

void who_win(stick *game)
{
    if (game->turn == 1) {
        game->win = 1;
        my_putstr("I lost... snif... but I'll get you next time!!\n");
    }
    else
        my_putstr("You lost, too bad...\n");
}

int start_game(stick *game)
{
    int win = 0;

    while (win == 0) {
        if (game->turn == 1) {
            my_putchar('\n');
            my_putstr("Your turn:\n");
            if (call_player(game) == 4) {
                my_putchar('\n');
                game->win = 0;
                return (0);
            }
            else
                launch_turn(game, 1);
        }
        if (game->turn == 0)
            call_ai(game);
        win = check_win(game);
    }
    who_win(game);
    return (0);
}
