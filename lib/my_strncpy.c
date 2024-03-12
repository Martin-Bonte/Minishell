/*
** EPITECH PROJECT, 2023
** my_strncpy
** File description:
** my_strncpy
*/
#include "../include/lib.h"

char *my_strncpy(char *dest, char const *src, int n)
{
    for (int i = 0; i < n; i++) {
        dest[i] = src[i];
        dest[i + 1] = '\0';
    }
    return (dest);
}
