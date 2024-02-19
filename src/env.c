/*
** EPITECH PROJECT, 2024
** env
** File description:
** env
*/

#include "../include/mysh.h"

static char *prepare_str(char *arg)
{
    char **temp = my_str_to_word_array(arg, ' ', '\t', ' ');
    size_t result_size = my_strlen(temp[1]) + 1 + my_strlen(temp[2]) + 1;
    char *result = malloc(result_size);

    if (result == NULL) {
        free(temp);
        return NULL;
    }
    result = my_strcpy(temp[1]);
    result = my_strcat(result, "=");
    result = my_strcat(result, temp[2]);
    free(temp);
    return result;
}

void print_env(char **env)
{
    for (int i = 0; env[i] != NULL; i++) {
        mini_printf("%s\n", env[i]);
    }
}

static int find_name(char *env, char *ask)
{
    int i;

    for (i = 0; ask[i] != '\0' && env[i] != '\0'; i++) {
        if (env[i] != ask[i]) {
            return 0;
        }
    }
    return (ask[i] == '\0' && env[i] == '=');
}

char *replace_env(char *arg, char *ask)
{
    char *r = malloc(sizeof(char) * (my_strlen(arg) + my_strlen(ask) + 2) + 2);
    char **temp = my_str_to_word_array(ask, ' ', '\t', ' ');
    int i;
    int j;

    for (i = 0; temp[1][i] != '\0'; i++) {
        r[i] = temp[1][i];
    }
    i++;
    r[i] = '=';
    for (j = 0; temp[2][j] != '\0'; j++) {
        r[i] = temp[2][j];
        i++;
    }
    r[i] = '\0';
    free(temp);
    return r;
}

void my_setenv(environ_t *envi, char *arg, char *ask)
{
    int i = 0;
    int telltale = 0;

    if (my_doublestrlen(my_str_to_word_array(ask, ' ', '\t', ' ')) != 3)
        return;
    for (i = 0; envi->env[i] != NULL; i++) {
        if (find_name(envi->env[i], arg) == 1) {
            envi->env[i] = replace_env(arg, ask);
            telltale = 1;
        }
    }
    if (telltale == 0) {
        envi->env = do_my_env(envi->env, 1, ask);
    }
}

void my_usetenv(environ_t *envi, char *ask)
{
    int j = 0;
    char **temp = my_str_to_word_array(ask, ' ', '\t', ' ');

    if (temp[1] == NULL)
        return;
    for (int i = 0; envi->env[i] != NULL; i++) {
        if (my_strncmp(envi->env[i], temp[1], 2) != 0) {
            envi->env[j] = my_strdup(envi->env[i]);
            j++;
        } else {
            free(envi->env[i]);
        }
    }
    envi->env[j] = NULL;
}

char **do_my_env(char **env, int telltale, char *arg)
{
    char **my_env = malloc(sizeof(char **) * (my_doublestrlen(env) + 2) + 2);
    int i;

    if (my_env == NULL) {
        return NULL;
    }
    for (i = 0; env[i] != NULL; i++) {
        my_env[i] = my_strcpy(env[i]);
    }
    if (telltale == 1) {
        my_env[i] = prepare_str(arg);
        my_env[i + 1] = NULL;
    }
    if (telltale == 0) {
        my_env[i] = NULL;
    }
    return my_env;
}
