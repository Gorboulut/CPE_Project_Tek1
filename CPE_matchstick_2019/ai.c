/*
** EPITECH PROJECT, 2020
** matchstick
** File description:
** ai function
*/
#include "include/my.h"

void put_ai(stick *game, int rem)
{
    my_putstr("AI removed ");
    my_put_nbr(rem);
    my_putstr(" match(es) from line ");
    my_put_nbr(game->line);
    my_putchar('\n');
}

int check_line(stick *game, int ran_l, int ran_m)
{
    int match = 0;

    for (int i = 0; i < my_strlen(game->game[game->line]); i++)
        if (game->game[ran_l][i] == '|')
            match++;
    if (match < ran_m)
        return (0);
    return (1);
}

int go_last_lign(stick *game, int w)
{
    int match = 0;

    for (int i = 0; game->game[w][i] != '\0'; i++)
        if (game->game[w][i] == '|')
            match++;
    game->line = w;
    if (match < game->max && match != 1)
        game->match = match - 1;
    else if (match == game->max)
        game->match = game->max - 1;
    else
        game->match = 1;
    launch_turn(game, 0);
    return (0);
}

int check_last_line (stick *game, int last)
{
    int match = 0;
    int w = 0;

    for (int i = 1; game->game[i] != NULL; i++) {
        for (int x = 1; game->game[i][x] != '\0'; x++)
            if (game->game[i][x] == '|')
                match++;
        if (match > 0) {
            w = i;
            match = 0;
            last++;
        }
    }
    if (last == 1) {
        my_putchar('\n');
        my_putstr("AI's turn...\n");
        go_last_lign(game, w);
        return (1);
    }
    return (0);
}

int call_ai(stick *game)
{
    int ran_l = random() % game->le + 1;
    int ran_m = random() % game->max + 1;
    int last = 0;

    if (check_last_line(game, last) == 1) {
        game->turn = 1;
        return (0);
    }
    if (ran_l == 0 || ran_m == 0)
        return (0);
    if (check_line(game, ran_l, ran_m) == 0)
        return (0);
    my_putchar('\n');
    my_putstr("AI's turn...\n");
    game->line = ran_l;
    game->match = ran_m;
    check_matches_ai(game);
    launch_turn(game, 0);
    game->turn = 1;
    return (0);
}
