/*
** EPITECH PROJECT, 2024
** cd
** File description:
** cd
*/

#include "../../include/mysh.h"

char *findpath(char **env)
{
    char **buffer;
    char *path;

    for (int i = 0; env[i] != NULL; i++) {
        if (env[i][0] == 'P' && env[i][1] == 'A') {
            buffer = my_str_to_word_array(env[i], '/', '/', '/');
        }
    }
    if (buffer[1] == NULL)
        path = my_strcpy(buffer[0]);
    else if (buffer[2] == NULL)
        path = my_strcpy(buffer[1]);
    else
        path = my_strcpy(buffer[2]);
    free_env(buffer);
    return path;
}

static int first_cd(char **buffer, environ_t *envi)
{
    if (buffer[1] == NULL) {
        chdir(my_strcat("/home/", envi->path));
        freeforyou(buffer, NULL, NULL, NULL);
        return 1;
    }
    if (my_strcmp(buffer[1], "/root") == 0) {
        my_error_putstr("/root: Permission denied.\n");
        freeforyou(buffer, NULL, NULL, NULL);
        return 1;
    }
    return 0;
}

void my_cd(environ_t *envi, char *ask)
{
    char **buffer = my_str_to_word_array(ask, ' ', '\t', '\n');

    supprimer_null_strings(buffer);
    if (first_cd(buffer, envi) == 1)
        return;
    if (my_strcmp(buffer[1], "~") == 0) {
        if (chdir(my_strcat("/home/", envi->path)) == -1) {
            my_error_putstr(buffer[1]);
            my_error_putstr(": No such file or directory.\n");
        }
    } else if (chdir(buffer[1]) == -1) {
        my_error_putstr(buffer[1]);
        my_error_putstr(": No such file or directory.\n");
    }
    freeforyou(buffer, NULL, NULL, NULL);
    return;
}
