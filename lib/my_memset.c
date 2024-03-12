/*
** EPITECH PROJECT, 2024
** my_memset
** File description:
** my_memset
*/
#include "../include/lib.h"

void *my_memset(void *data, int c, unsigned int len)
{
    unsigned char *p = data;

    while (len) {
        *p = (unsigned char)c;
        p++;
        len--;
    }
    return data;
}
