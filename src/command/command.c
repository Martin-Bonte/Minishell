/*
** EPITECH PROJECT, 2024
** commend
** File description:
** command
*/

#include "../../include/mysh.h"

static command_t command[] =
{
    {"env", print_env},
    {"cd", my_cd},
    {"setenv", my_setenv},
    {"unsetenv", my_usetenv},
    {0, NULL}
};

int process_command(char **buffer, char *arg, environ_t *envi)
{
    for (int i = 0; command[i].command_char; i++) {
        if (my_strcmp(command[i].command_char, buffer[0]) == 0) {
            command[i].fonction(envi, arg);
            return 1;
        }
    }
    return 0;
}

int check_command(char *ask, environ_t *envi)
{
    char **buffer = my_str_to_word_array(ask, ' ', '\t', '\n');
    static int returnvalue;

    supprimer_null_strings(buffer);
    if (buffer[0] == NULL)
        return 0;
    if (my_strcmp(buffer[0], "exit") == 0) {
        mini_printf("exit\n");
        free(envi->path);
        free(ask);
        freeforyou(buffer, envi->env, envi->oldpath, envi);
        exit(returnvalue);
    } else if (process_command(buffer, ask, envi) == 0) {
        returnvalue = execution(buffer, envi);
    }
    return returnvalue;
}
