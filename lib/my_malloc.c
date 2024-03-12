/*
** EPITECH PROJECT, 2024
** my_malloc
** File description:
** my_malloc
*/

#include "../include/mysh.h"

void *my_malloc(size_t size)
{
    void *ptr = malloc(size);

    if (ptr == NULL)
        return NULL;
    my_memset(ptr, 0, size);
    return ptr;
}
