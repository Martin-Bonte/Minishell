/*
** EPITECH PROJECT, 2023
** my_strlen
** File description:
** Fonction who do the lenth of a string
*/

#include "../include/lib.h"

int my_strlen(const char *str)
{
    int i = 0;

    while (str[i] != '\0'){
        i++;
    }
    return (i);
}

int my_doublestrlen(char **str)
{
    int i = 0;

    while (str[i] != NULL){
        i++;
    }
    return (i);
}
