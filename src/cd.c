/*
** EPITECH PROJECT, 2024
** cd
** File description:
** cd
*/

#include "../include/mysh.h"

char *findpath(char **env)
{
    char **buffer;
    char *path;

    for (int i = 0; env[i] != NULL; i++) {
        if (env[i][0] == 'P' && env[i][1] == 'A') {
            buffer = my_str_to_word_array(env[i], '/', '/', '/');
            path = buffer[2];
        }
    }
    return path;
}

void my_cd(char *ask, environ_t *envi)
{
    char **buffer = my_str_to_word_array(ask, ' ', '\t', '\n');
    char *path = findpath(envi->env);

    supprimer_null_strings(buffer);
    if (buffer[1] == NULL) {
        chdir(my_strcat("/home/", path));
        return;
    }
    if (my_strcmp(buffer[1], "~") == 0) {
        if (chdir(my_strcat("/home/", path)) == -1) {
            mini_printf("%s: No such fille or directory.\n", buffer[1]);
        }
    } else if (chdir(buffer[1]) == -1) {
        mini_printf("%s: No such file or directory.\n", buffer[1]);
    }
    return;
}
