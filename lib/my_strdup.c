/*
** EPITECH PROJECT, 2023
** my_strdup
** File description:
** my_strdup
*/
#include "../include/lib.h"

char *my_strdup(char const *str)
{
    char *dest = malloc(sizeof(char) * (my_strlen(str) + 1));

    my_strncpy(dest, str, my_strlen(str));
    return (dest);
}
