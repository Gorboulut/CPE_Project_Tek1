/*
** EPITECH PROJECT, 2019
** suppr space
** File description:
** func for suppr space
*/

char *suppr_space(char *str)
{
    int count = 0;

    for (int i = 0; str[i]; i++)
        if (str[i] != ' ')
            str[count++] = str[i];
    str[count] = '\0';
    return (str);
}
