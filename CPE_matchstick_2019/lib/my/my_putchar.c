/*
** EPITECH PROJECT, 2019
** my putchar
** File description:
** put char
*/
#include <unistd.h>

void my_putchar(char c)
{
    write(1, &c, 1);
}
