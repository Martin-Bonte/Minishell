/*
** EPITECH PROJECT, 2024
** mysh.h
** File description:
** mysh
*/

#ifndef MYSH_H_
    #define MYSH_H_

    #include "lib.h"

typedef struct enviro_s {
    char **env;
}environ_t;

void print_env(char **env);
void check_command(char *ask, environ_t *envi);
void my_cd(char *ask, environ_t *envi);
void my_setenv(environ_t *envi, char *arg, char *ask);
void supprimer_null_strings(char **liste);
void execution(char **arg, environ_t *envi);
void my_usetenv(environ_t *envi, char *ask);
char **do_my_env(char **env, int telltale, char *arg);
void free_env(char **env);
char *is_valid(char *arg);
int check_command_second(char **buffer, char *ask, environ_t *envi);

#endif /* !MYSH_H_ */
