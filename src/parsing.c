/*
** EPITECH PROJECT, 2024
** parsing
** File description:
** parsing
*/
#include "../include/mysh.h"

static char *do_str(char **buffer, char *temp, int j)
{
    char *result = NULL;

    if (buffer[j - 1] != NULL) {
        temp = my_malloc(sizeof(char) * (my_strlen(buffer[j - 1]) + 1));
        if (temp != NULL) {
            temp = my_strcpy(buffer[j - 1]);
        }
    }
    result = my_strcpy(temp);
    free(temp);
    return result;
}

void supprimer_null_strings(char **liste)
{
    int i = 0;
    int j = 0;

    while (liste[i] != NULL) {
        if (liste[i][0] != '\0') {
            liste[j] = liste[i];
            j++;
        } else
            free(liste[i]);
        i++;
    }
    liste[j] = NULL;
}

char *is_valid(char *arg)
{
    char **buffer = my_str_to_word_array(arg, '/', '/', '/');
    char *temp = NULL;
    int j = 0;

    for (int i = 0; buffer[i] != NULL; i++) {
        if (my_strcmp(buffer[i], "bin") != 0
            && my_strcmp(buffer[i], "usr") != 0) {
            buffer[j] = buffer[i];
            j++;
        } else
            free(buffer[i]);
    }
    buffer[j] = NULL;
    temp = do_str(buffer, temp, j);
    for (int i = 0; buffer[i] != NULL; i++) {
        free(buffer[i]);
    }
    free(buffer);
    return temp;
}
