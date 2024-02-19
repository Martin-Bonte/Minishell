/*
** EPITECH PROJECT, 2023
** my_strcmp
** File description:
** my_strcmp
*/
#include "../include/lib.h"

int my_strcmp(char *temp1, char *temp2)
{
    int i = 0;

    while (temp1[i]) {
        if (temp1[i] < temp2[i])
            return -1;
        if (temp1[i] > temp2[i])
            return 1;
        i++;
    }
    if (temp1[i] < temp2[i])
        return -1;
    if (temp1[i] > temp2[i])
        return 1;
    return 0;
}

int my_strncmp(const char *str1, const char *str2, size_t n)
{
    for (size_t i = 0; i < n; i++) {
        if (str1[i] != str2[i]) {
            return str1[i] - str2[i];
        }
        if (str1[i] == '\0' || str2[i] == '\0') {
            return 0;
        }
    }
    return 0;
}
