/*
** EPITECH PROJECT, 2023
** my_strpcy
** File description:
** my_strcpy
*/
#include "../include/lib.h"

char *my_strcpy(char const *src)
{
    int i = 0;
    char *temp = malloc(sizeof(char) * my_strlen(src) + 1);

    while (src[i] != '\0') {
        temp[i] = src[i];
        i = i + 1;
    }
    temp[i] = '\0';
    return (temp);
}
