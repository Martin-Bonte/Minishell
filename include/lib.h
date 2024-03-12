/*
** EPITECH PROJECT, 2024
** lib h
** File description:
** lib
*/

#ifndef LIB_H_
    #define LIB_H_

    #include <stdarg.h>
    #include <stdio.h>
    #include <stdlib.h>
    #include <unistd.h>
    #include <fcntl.h>
    #include <string.h>
    #include <signal.h>
    #include <stdbool.h>
    #include <time.h>
    #include <sys/wait.h>
    #include <stddef.h>
    #include <errno.h>

int mini_printf(const char *format, ...);
int my_getnbr(char const *str);
int my_put_nbr(int nb);
void my_putchar(char c);
int my_putstr(char const *str);
char **my_str_to_word_array(char *str, char t, char t2, char t3);
char *my_strcpy(char const *src);
char *my_strdup(char const *str);
int my_strlen(const char *str);
char *my_strncpy(char *dest, char const *src, int n);
char *my_strcat(char *dest, char *src);
int my_strcmp(char *temp1, char *temp2);
int my_doublestrlen(char **str);
int my_strncmp(const char *str1, const char *str2, size_t n);
void *my_memset(void *data, int c, unsigned int len);
void *my_malloc(size_t size);

#endif /* !LIB_H_ */
