/*
** EPITECH PROJECT, 2024
** parsing
** File description:
** parsing
*/
#include "../include/mysh.h"

static char *do_str(char **buffer, char *temp, int j)
{
    if (buffer[j - 1] != NULL) {
        temp = malloc(sizeof(char) * (my_strlen(buffer[j - 1]) + 1));
        if (temp != NULL) {
            temp = my_strcpy(buffer[j - 1]);
        }
    }
    return temp;
}

void supprimer_null_strings(char **liste)
{
    int i = 0;
    int j = 0;

    for (i = 0; liste[i] != NULL; i++) {
        if (liste[i][0] != '\0') {
            liste[j] = liste[i];
            j++;
        }
    }
    liste[j] = NULL;
}

char *is_valid(char *arg)
{
    char **buffer = my_str_to_word_array(arg, '/', '/', '/');
    char *temp = NULL;
    int j = 0;

    for (int i = 0; buffer[i] != NULL; i++) {
        if (my_strcmp(buffer[i], "bin") != 0) {
            buffer[j] = buffer[i];
            j++;
        }
    }
    buffer[j] = NULL;
    temp = do_str(buffer, temp, j);
    for (int i = 0; buffer[i] != NULL; i++) {
        free(buffer[i]);
    }
    free(buffer);
    return temp;
}
