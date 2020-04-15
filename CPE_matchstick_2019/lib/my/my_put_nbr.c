/*
** EPITECH PROJECT, 2018
** my_put_nbr
** File description:
** my_put_nbr
*/

#include <unistd.h>
#include "../../include/my.h"

void display(int nb, int border, int big, int cpy_nb)
{
    if (big == 1) {
        cpy_nb = nb;
        cpy_nb = cpy_nb % 10;
        if (border == 0)
            my_putchar(cpy_nb + '0');
        else
            my_putchar(cpy_nb + '1');
    }
}

void copy_fac2(int nb, int factor, int border, int big)
{
    int cpy_nb = nb;
    int cpy_factor = factor;

    while (cpy_factor != 0) {
        cpy_nb = nb;
        cpy_nb = cpy_nb / cpy_factor;
        if (big == 1)
            cpy_nb = cpy_nb / 10;
        cpy_nb = cpy_nb % 10;
        my_putchar(cpy_nb + '0');
        cpy_factor /= 10;
    }
    display(nb, border, big, cpy_nb);
}

int copy_fac(int nb, int negative, int big, int border)
{
    int factor = 1;
    int cpy_nb = nb;
    while (cpy_nb != 0) {
        cpy_nb /= 10;
        if (factor < 1000000000)
            factor *= 10;
    }
    if (nb != 0)
        factor /= 10;
    if (negative == 1)
        my_putchar('-');
    while (cpy_nb != 0) {
        cpy_nb /= 10;
        if (factor < 1000000000)
            factor *= 10;
    }
    copy_fac2(nb, factor, border, big);
    return (0);
}

int my_put_nbr(int nb)
{
    int cpy_nb = nb;
    int negative = 0;
    int big = 0;
    int border = 0;

    if (nb > 1000000000 || nb < -1000000000)
        big = 1;
    if (nb == -2147483648) {
        nb += 1;
        border = 1;
    }
    if (nb < 0) {
        negative = 1;
        nb = -nb;
        cpy_nb = nb;
    }
    copy_fac(nb, negative, big, border);
    return (0);
}
