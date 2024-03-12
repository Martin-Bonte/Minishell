/*
** EPITECH PROJECT, 2023
** my_strcat
** File description:
** my_strcat
*/
#include "../include/lib.h"

char *my_strcat(char *dest, char *src)
{
    int i;
    int j;
    char *result = (char *)malloc(my_strlen(dest) + my_strlen(src) + 1);

    if (result == NULL) {
        return NULL;
    }
    for (i = 0; dest[i] != '\0'; i++) {
        result[i] = dest[i];
    }
    for (j = 0; src[j] != '\0'; j++) {
        result[i + j] = src[j];
    }
    result[i + j] = '\0';
    return result;
}
