/*
** EPITECH PROJECT, 2019
** my h
** File description:
** my h
*/
#include <stdarg.h>
#include <SFML/Audio.h>
#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <SFML/Window.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <stddef.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <time.h>
#include <dirent.h>
#define EXIT_USAGE    84

#ifndef MATCH_H
#define MATCH_H

typedef struct stick {
    int le;
    int win;
    int t_l;
    int turn;
    int max;
    int line;
    int match;
    char **game;
    char *buffer;
    int s;
} stick;

void my_putchar(char c);
char *my_strcat(char *dest, char const *src);
int my_strlen(char const *str);
int my_put_nbr(int nb);
int my_putstr(char const *str);
char *my_strcpy(char *dest, char const *src);
char *my_revstr(char *str);
int my_atoi(char *str);
char *my_strdup(char const *src);
char *suppr_space(char *str);
int my_number(char *str);
char *my_realloc(char *str, char *fullstr, int len);
char *itoa(int n);
char *get_realloc(char *fullstr, int len);
char **chain_list_first(char **tab);
int my_strcmp(char const *s1, char const *s2);
char *my_strlowcase(char *str);
int start_tab(char **av);
int start_game(stick *game);
int call_player(stick *game);
int check_nbr(char *buffer, int x);
int call_ai(stick *game);
void launch_turn(stick *game, int p);
void put_ai(stick *game, int rem);
void check_matches_ai(stick *game);
void put_matchs(stick *game);
void fill_buff(stick *game);

#endif
