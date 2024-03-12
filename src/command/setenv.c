/*
** EPITECH PROJECT, 2024
** setenv
** File description:
** setenv
*/

#include "../../include/mysh.h"

char *replace_env(char *a, char *ask, int info)
{
    char *r = my_malloc(sizeof(char) * (my_strlen(a) + 2) + 2);
    char **temp = my_str_to_word_array(ask, ' ', '\t', ' ');
    int i;

    if (info == 0)
        r = my_malloc(sizeof(char) * (my_strlen(a) + my_strlen(ask) + 2) + 2);
    for (i = 0; temp[1][i] != '\0'; i++) {
        r[i] = temp[1][i];
    }
    i++;
    r = my_strcat(r, "=");
    if (info == 1)
        return r;
    for (int j = 0; temp[2][j] != '\0'; j++) {
        r[i] = temp[2][j];
        i++;
    }
    r[i] = '\0';
    free(temp);
    return r;
}

int error_hand(char **buffer, environ_t *envi)
{
    if (my_doublestrlen(buffer) > 3) {
        my_error_putstr("setenv: Too many arguments.\n");
        free_env(buffer);
        return -1;
    }
    if (my_doublestrlen(buffer) == 1) {
        print_env(envi, buffer[1]);
        return 1;
    }
    return 2;
}

void my_setenv(environ_t *envi, char *ask)
{
    int i = 0;
    int telltale = 0;
    int info = 0;
    char **buffer = my_str_to_word_array(ask, ' ', '\t', ' ');
    int j = error_hand(buffer, envi);

    if (j == -1 || j == 1)
        return;
    if (my_doublestrlen(buffer) == 2)
        info = 1;
    for (i = 0; envi->env[i] != NULL; i++) {
        if (find_name(envi->env[i], buffer[1]) == 1) {
            envi->env[i] = replace_env(buffer[1], ask, info);
            telltale = 1;
        }
    }
    if (telltale == 0)
        envi->env = do_my_env(envi->env, 1, ask, info);
    free_env(buffer);
    return;
}

int find_name(char *env, char *ask)
{
    int i;

    for (i = 0; ask[i] != '\0' && env[i] != '\0'; i++) {
        if (env[i] != ask[i]) {
            return 0;
        }
    }
    return (ask[i] == '\0' && env[i] == '=');
}
