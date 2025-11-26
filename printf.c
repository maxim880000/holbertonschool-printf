#include <stdio.h>
#include <stdarg.h>
#include <string.h>
#include "main.h"

/**
 * _printf - Produces output according to a format
 * @format: Character string with format specifiers
 * @...: Variable arguments to be printed
 *
 * Return: Number of characters printed (excluding null byte)
 */
int _printf(const char *format, ...)
{
	va_list args;
	int count = 0;
	int i = 0;

	if (format == NULL)
		return (-1);

	va_start(args, format);

	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			switch (format[i])
			{
				case '%':
					_putchar('%');
					count++;
					break;
				case 'c':
				{
					char c = va_arg(args, int);
					_putchar(c);
					count++;
					break;
				}
				case 's':
				{
					char *s = va_arg(args, char *);
					if (s == NULL)
						s = "(null)";
					while (*s)
					{
						_putchar(*s);
						count++;
						s++;
					}
					break;
				}
				default:
					_putchar('%');
					_putchar(format[i]);
					count += 2;
					break;
			}
		}
		else
		{
			_putchar(format[i]);
			count++;
		}
		i++;
	}

	va_end(args);
	return (count);
}
