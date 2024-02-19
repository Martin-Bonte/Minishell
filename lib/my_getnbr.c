/*
** EPITECH PROJECT, 2023
** my_getnbr
** File description:
** my_getnbr
*/
#include "../include/lib.h"

int veref_str(const char *str, int i, int telltale)
{
    if (str[i + 1] < '0' || str[i + 1] > '9')
        telltale = 1;
    return telltale;
}

int my_getnbr(char const *str)
{
    int i = 0;
    int telltale = 0;
    long number = 0;
    int isneg = 1;

    while (str[i] != '\0' && telltale == 0) {
        if (str[i] == '-')
            isneg = isneg * (-1);
        if (str[i] >= '0' && str[i] <= '9') {
            number = number * 10 + (str[i] - '0');
            telltale = veref_str(str, i, telltale);
        }
        i = i + 1;
    }
    number = number * isneg;
    if (number < -2147483648 || number > 2147483647)
        return 0;
    return (int)number;
}
