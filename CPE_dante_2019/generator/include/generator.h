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
#include <unistd.h>

#endif /* !INCLUDE_H_ */


#ifndef STRUCT_H_
#define STRUCT_H_

typedef struct list_s {
    int x;
    int y;
    struct list_s *next;
    struct list_s *prev;
} list_t;

typedef struct dante_s {
    char **map;
    int x;
    int y;
    int max_y;
    int max_x;
    int base_x;
    int base_y;
    int finished;
    int w;
    list_t *list;
} dante_t;

#endif /* STRUCT_H_ */


#ifndef FUNCTION_H_
#define FUNCTION_H_

int start_dante(dante_t *stru);
char **create_map(int x, int y);
int move(dante_t *stru);
list_t *push_path(dante_t *stru, int x, int y);
void lets_dante(dante_t *s);
int go_right(dante_t *stru);
int go_left(dante_t *stru);
int go_top(dante_t *stru);
int go_bot(dante_t *stru);

#endif /* FUNCTION_H_ */
