#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>

<<<<<<< HEAD
/**
 * struct format - Struct format
 * @format: The format specifier character (c, s, % etc)
 * @f: Pointer to the function that handles this specifier
 *
 * Description: Structure that associates a format specifier
 * with its corresponding handler function
 */
typedef struct format
{
	char *format;
	int (*f)(va_list);
} format_t;

int _printf(const char *format, ...);
int _putchar(char c);

int print_char(va_list args);
int print_string(va_list args);
int print_percent(va_list args);

=======
int _printf(const char *format, ...);
int _putchar(char c);

>>>>>>> testprintf
#endif
