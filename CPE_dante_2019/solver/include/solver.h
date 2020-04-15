/*
** EPITECH PROJECT, 2020
** include defender
** File description:
** include defender
*/

#ifndef INCLUDE_H_
#define INCLUDE_H_

#include <assert.h>
#include <ctype.h>
#include <errno.h>
#include <float.h>
#include <inttypes.h>
#include <limits.h>
#include <math.h>
#include <setjmp.h>
#include <stdarg.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <tgmath.h>
#include <time.h>
#include <wchar.h>
#include <wctype.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>

#endif /* !INCLUDE_H_ */


#ifndef STRUCT_H_
#define STRUCT_H_

typedef struct solver_s {
    int max_y;
    int max_x;
    int **alreadygo;
    char **winnable;
    char **map;
} solver_t;

#endif /* STRUCT_H_ */


#ifndef FUNCTION_H_
#define FUNCTION_H_

int start_algo(solver_t *s, int x, int y);
void init_value(solver_t *s);
int take_map(char **av, solver_t *s);
char **str_to_word_tab(char *board, char a);

#endif /* FUNCTION_H_ */
