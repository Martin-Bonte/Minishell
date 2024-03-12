/*
** EPITECH PROJECT, 2024
** env
** File description:
** env
*/

#include "../../include/mysh.h"

void print_env(environ_t *envi, __attribute__((unused)) char *ask)
{
    for (int i = 0; envi->env[i] != NULL; i++) {
        mini_printf("%s\n", envi->env[i]);
    }
}
