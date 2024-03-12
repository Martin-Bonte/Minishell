/*
** EPITECH PROJECT, 2024
** unsetenv
** File description:
** unsetenv
*/

#include "../../include/mysh.h"

static char *prepare_str(char *arg, int info)
{
    char **temp = my_str_to_word_array(arg, ' ', '\t', ' ');
    size_t result_size = my_strlen(temp[1]) + 2;
    char *result = NULL;

    if (info == 0)
        result_size = my_strlen(temp[1]) + 1 + my_strlen(temp[2]) + 1;
    result = my_malloc(result_size);
    if (result == NULL) {
        free_env(temp);
        return NULL;
    }
    result = my_strcpy(temp[1]);
    result = my_strcat(result, "=");
    if (info == 1) {
        free_env(temp);
        return result;
    }
    result = my_strcat(result, temp[2]);
    free_env(temp);
    return result;
}

char **do_my_env(char **env, int telltale, char *arg, int info)
{
    char **myenv = my_malloc(sizeof(char **) * (my_doublestrlen(env) + 2) + 2);
    int i;

    if (myenv == NULL)
        return NULL;
    for (i = 0; env[i] != NULL; i++) {
        myenv[i] = my_strcpy(env[i]);
    }
    if (telltale == 1) {
        myenv[i] = prepare_str(arg, info);
        myenv[i + 1] = NULL;
    }
    if (telltale == 0)
        myenv[i] = NULL;
    supprimer_null_strings(myenv);
    return myenv;
}

int second_unsetenv(int j, environ_t *envi, char **temp, int o)
{
    for (int i = 1; temp[i] != NULL; i++) {
        if (my_strncmp(envi->env[o], my_strcat(temp[i], "="),
            my_strlen(temp[i]) + 1) != 0) {
            envi->env[j] = my_strdup(envi->env[o]);
        } else {
            j--;
            free(envi->env[o]);
        }
    }
    j++;
    return j;
}

void my_usetenv(environ_t *envi, char *ask)
{
    int j = 0;
    char **temp = my_str_to_word_array(ask, ' ', '\t', ' ');

    if (temp[1] == NULL) {
        my_error_putstr("unsetenv: Too few argument.\n");
        return;
    }
    supprimer_null_strings(temp);
    for (int o = 0; envi->env[o] != NULL; o++) {
        j = second_unsetenv(j, envi, temp, o);
    }
    envi->env[j] = NULL;
    free_env(temp);
}
