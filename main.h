#ifndef MAIN_H
#define MAIN_H

/* library that we need to use variadic functions, write and malloc, free */
#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>

/**
 * struct format - Struct format
 * @specifier: The format specifier character (c, s, %)
 * @f: Pointer to the function that handles this specifier
 *
 * Description: Structure that associates a format specifier
 * with its corresponding handler function
 */
typedef struct format
{
	char *format;
	int (*f)(va_list argument);
} format_t;

int _printf(const char *format, ...);
int print_char(va_list, argument);
int print_string(va_list, argument);
int print_%(va_list, argument);

#endif
