/*
** EPITECH PROJECT, 2023
** my_putstr
** File description:
** my_putstr
*/
#include "../include/lib.h"

int my_putstr(char const *str)
{
    int i = 0;

    while (str[i] != ('\0')){
        my_putchar(str[i]);
        i++;
    }
    return (0);
}

int my_error_putstr(char const *str)
{
    int i = 0;

    while (str[i] != '\0') {
        write(2, &str[i], 1);
        i++;
    }
    return 0;
}
