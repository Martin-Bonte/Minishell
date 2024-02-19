/*
** EPITECH PROJECT, 2024
** minishell
** File description:
** minishell
*/

#include "../include/mysh.h"

static void freeforyou(char **env, char **arg, char *process, environ_t *envi)
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

void my_loop(pid_t childpid, char *process, char **arg, char **env)
{
    int returnvalue;

    if (childpid < 0)
        exit(84);
    if (childpid == 0) {
        if (execve(process, arg, env) == -1) {
            mini_printf("%s: Command not found.\n", arg[0]);
            freeforyou(arg, NULL, process, NULL);
            exit(0);
        }
    } else {
        waitpid(childpid, &returnvalue, 0);
        if (__WCOREDUMP(returnvalue) != 0) {
            mini_printf("Segmentation fault (core dumped)\n");
            exit(139);
        }
        if (WEXITSTATUS(returnvalue) == 84)
            exit(84);
        freeforyou(arg, NULL, process, NULL);
    }
}

void free_env(char **env)
{
    for (int i = 0; env[i] != NULL; i++) {
        free(env[i]);
    }
    free(env);
}

void execution(char **arg, environ_t *envi)
{
    char *process;
    pid_t childpid = fork();

    supprimer_null_strings(arg);
    if (arg[0][0] == '.' && arg[0][1] == '/') {
        process = is_valid(arg[0]);
    } else {
        arg[0] = is_valid(arg[0]);
        process = my_strcat("/bin/", arg[0]);
    }
    my_loop(childpid, process, arg, envi->env);
}

int main(int argc, char **argv, char **env)
{
    char *ask = NULL;
    size_t n = 0;
    environ_t *envi = malloc(sizeof(environ_t));

    envi->env = do_my_env(env, 0, NULL);
    (void)argv;
    if (argc != 1)
        return 84;
    while (1) {
        my_putstr("#%> ");
        if (getline(&ask, &n, stdin) == -1) {
            freeforyou(envi->env, NULL, ask, envi);
            mini_printf("\n");
            exit(84);
        }
        ask[my_strlen(ask) - 1] = '\0';
        check_command(ask, envi);
    }
    freeforyou(envi->env, NULL, ask, envi);
    return 0;
}
