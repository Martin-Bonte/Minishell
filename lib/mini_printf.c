/*
** EPITECH PROJECT, 2023
** my_mini_printf
** File description:
** my_mini_printf
*/


#include "../include/lib.h"

int find_flag(char specifier, int nb, va_list ap)
{
    const char *values = "";
    char value = 0;

    switch (specifier) {
        case 's':
            my_putstr(values = va_arg(ap, char *));
            break;
        case 'c':
            my_putchar(value = va_arg(ap, int));
            break;
        default:
            break;
    }
    return nb + 1;
}

int find_flagi(char specifier, int nb, va_list ap)
{
    int valuei = 0;

    switch (specifier) {
        case 'i':
            my_put_nbr(valuei = va_arg(ap, int));
            break;
        case 'd':
            my_put_nbr(valuei = va_arg(ap, int));
            break;
        case '%':
            my_putchar('%');
            break;
        default:
            break;
    }
    return nb + 1;
}

int mini_printf(const char *format, ...)
{
    va_list ap;
    int i = 0;
    int nb = 0;

    if (format == 0) {
        my_putstr("error: invalid arguments");
        return (84);
    }
    va_start(ap, format);
    for (i = 0; format[i] != '\0'; i++) {
        if (format[i] == '%') {
            i++;
            nb = find_flagi(format[i], nb, ap);
            nb = find_flag(format[i], nb, ap);
        } else {
            my_putchar(format[i]);
        }
    }
    va_end(ap);
    return 0;
}
