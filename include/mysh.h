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
    char *path;
    char *oldpath;
}environ_t;

/* Begin of Command */

typedef struct command_s {
    char *command_char;
    void (*fonction)(environ_t *envi, char *arg);
} command_t;

void print_env(environ_t *envi, __attribute__((unused)) char *ask);
void my_cd(environ_t *envi, char *ask);
void my_setenv(environ_t *envi, char *ask);
void my_usetenv(environ_t *envi, char *ask);

int check_command(char *ask, environ_t *envi);
char **do_my_env(char **env, int telltale, char *arg, int info);
void free_env(char **env);
int check_command_second(char **buffer, char *ask, environ_t *envi);

/* End of Command */
void supprimer_null_strings(char **liste);
int execution(char **arg, environ_t *envi);
char *is_valid(char *arg);
char *findpath(char **env);
void freeforyou(char **env, char **arg, char *process, environ_t *envi);
int find_name(char *env, char *ask);
int my_error_putstr(char const *str);
int my_loop(pid_t childpid, char *process, char **arg, char **env);

#endif /* !MYSH_H_ */
