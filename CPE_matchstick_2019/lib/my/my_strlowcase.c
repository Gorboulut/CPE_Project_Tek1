/*
** EPITECH PROJECT, 2019
** my_strlowcase
** File description:
** print all case in low case
*/

char *my_strlowcase(char *str)
{
    int i = 0;

    while (str[i] != '\0') {
        while (str[i] < 91 && str[i] > 64) {
            str[i] = str[i] + 32;
            i++;
        }
        i++;
    }
    return (str);
}
