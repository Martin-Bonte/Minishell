/*
** EPITECH PROJECT, 2024
** minishell
** File description:
** minishell
*/

#include "../include/mysh.h"

static void error_h(int childpid)
{
    if (childpid < 0)
        exit(84);
}

static environ_t *do_my_struct(environ_t *envi, char **env)
{
    envi->env = do_my_env(env, 0, NULL, 0);
    envi->path = findpath(envi->env);
    return envi;
}

void freeforyou(char **env, char **arg, char *process, environ_t *envi)
{
    if (env != NULL)
        free_env(env);
    if (arg != NULL)
        free_env(arg);
    if (process != NULL)
        free(process);
    if (envi != NULL)
        free(envi);
}

int my_loop(pid_t childpid, char *process, char **arg, char **env)
{
    int returnvalue;

    error_h(childpid);
    if (childpid == 0) {
        if (execve(process, arg, env) == -1) {
            my_error_putstr(arg[0]);
            my_error_putstr(": Command not found.\n");
            freeforyou(arg, NULL, process, NULL);
            exit(1);
        }
    } else {
        waitpid(childpid, &returnvalue, 0);
        if (__WCOREDUMP(returnvalue) != 0) {
            my_error_putstr("Segmentation fault\n");
            freeforyou(arg, NULL, process, NULL);
            exit(139);
        }
        freeforyou(arg, NULL, process, NULL);
    }
    return (WEXITSTATUS(returnvalue));
}

void free_env(char **env)
{
    for (int i = 0; env[i] != NULL; i++) {
        free(env[i]);
    }
    free(env);
}

int execution(char **arg, environ_t *envi)
{
    char *process;
    pid_t childpid = fork();
    int returnvalue;

    supprimer_null_strings(arg);
    if (arg[0][0] == '.' && arg[0][1] == '/') {
        process = is_valid(arg[0]);
    } else {
        arg[0] = is_valid(arg[0]);
        process = my_strcat("/bin/", arg[0]);
    }
    returnvalue = my_loop(childpid, process, arg, envi->env);
    return returnvalue;
}

int main(int argc, __attribute__((unused)) char **argv, char **env)
{
    char *ask = NULL;
    size_t n = 0;
    environ_t *envi = my_malloc(sizeof(environ_t));
    int returnvalue;

    envi = do_my_struct(envi, env);
    if (argc != 1)
        return 84;
    while (1) {
        if (isatty(0) == 1)
            my_putstr("#%> ");
        if (getline(&ask, &n, stdin) == -1) {
            freeforyou(envi->env, NULL, ask, envi);
            exit(0);
        }
        ask[my_strlen(ask) - 1] = '\0';
        returnvalue = check_command(ask, envi);
    }
    freeforyou(envi->env, NULL, ask, envi);
    return returnvalue;
}
