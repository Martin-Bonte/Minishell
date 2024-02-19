/*
** EPITECH PROJECT, 2024
** commend
** File description:
** command
*/

#include "../include/mysh.h"

int check_command_second(char **buffer, char *ask, environ_t *envi)
{
    int telltale = 0;

    if (my_strcmp(buffer[0], "cd") == 0) {
        telltale = 1;
        my_cd(ask, envi);
    }
    if (my_strcmp(buffer[0], "env") == 0) {
        telltale = 1;
        print_env(envi->env);
    }
    if (my_strcmp(buffer[0], "setenv") == 0) {
        telltale = 1;
        my_setenv(envi, buffer[1], ask);
    }
    if (my_strcmp(buffer[0], "unsetenv") == 0) {
        telltale = 1;
        my_usetenv(envi, ask);
    }
    return telltale;
}

void check_command(char *ask, environ_t *envi)
{
    char **buffer = my_str_to_word_array(ask, ' ', '\t', '\n');

    supprimer_null_strings(buffer);
    if (buffer[0] == NULL)
        return;
    if (my_strcmp(buffer[0], "exit") == 0) {
        mini_printf("exit\n");
        free(buffer);
        free_env(envi->env);
        free(envi);
        free(ask);
        exit(EXIT_SUCCESS);
    } else if (check_command_second(buffer, ask, envi) == 0) {
        execution(buffer, envi);
    }
}
