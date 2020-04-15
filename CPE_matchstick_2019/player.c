/*
** EPITECH PROJECT, 2020
** matchstick
** File description:
** player function
*/
#include "include/my.h"

void put_player(stick *game, int rem)
{
    my_putstr("Player removed ");
    my_put_nbr(rem);
    my_putstr(" match(es) from line ");
    my_put_nbr(game->line);
    my_putchar('\n');
}

void launch_turn(stick *game, int p)
{
    int i = my_strlen(game->game[0]);
    int rem = game->match;

    if (p == 1)
        put_player(game, rem);
    if (p == 0)
        put_ai(game, rem);
    while (game->match > 0) {
        while (game->game[game->line][i] != '|')
            i--;
        game->game[game->line][i] = ' ';
        i--;
        game->match--;
    }
    for (int x = 0; game->game[x] != NULL; x++) {
        my_putstr(game->game[x]);
        my_putchar('\n');
    }
}

int get_matches(stick *game)
{
    char *buff = NULL;
    size_t len = 0;

    my_putstr("Matches: ");
    if (getline(&buff, &len, stdin) < 0)
        return (4);
    if (check_nbr(buff, 1) == 4)
        return (8);
    game->match = my_number(buff);
    if (game->match > game->max) {
        put_matchs(game);
        return (8);
    }
    if (game->match == 0) {
        my_putstr("Error : you have to remove at least one match\n");
        return (8);
    }
    free(buff);
    return (0);
}

int check_matches(stick *game)
{
    int i = 0;
    int matches = 0;

    for (i = 0; i < my_strlen(game->game[0]); i++) {
        if (game->game[game->line][i] == '|')
            matches++;
    }
    if (matches < game->match) {
        my_putstr("Error: not enough matches on this line\n");
        return (4);
    }
    return (0);
}

int call_player(stick *game)
{
    size_t len = 0;

    fill_buff(game);
    if (getline(&game->buffer, &len, stdin) < 0)
        return (4);
    if (check_nbr(game->buffer, 0) == 4)
        return (call_player(game));
    game->line = my_number(game->buffer);
    if (game->line == 0 || game->line > game->le) {
        my_putstr("Error: this line is out of range\n");
        return (call_player(game));
    }
    game->s = get_matches(game);
    if (check_matches(game) == 4 || game->s == 8)
        return (call_player(game));
    if (game->s == 4)
        return (4);
    free(game->buffer);
    game->turn = 0;
    return (0);
}
