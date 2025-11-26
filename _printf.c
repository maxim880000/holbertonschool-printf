#include "main.h"
#include <unistd.h>
#include <stdarg.h>

/**
 * print_number - Helper function to print a number recursively
 * @num: The number to print
 * @count: Pointer to character count
 */
void print_number(int num, int *count)
{
	if (num / 10)
		print_number(num / 10, count);
	_putchar((num % 10) + '0');
	(*count)++;
}

/**
 * _printf - Prints formatted output to the standard output
 * @format: String containing the format specifiers
 *
 * Return: the number of characters printed, or -1 if format is NULL
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
			if (format[i] == '%')
			{
				_putchar('%');
				count++;
			}
			else if (format[i] == 'c')
			{
				char c = va_arg(args, int);
				_putchar(c);
				count++;
			}
			else if (format[i] == 's')
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
			}
			else if (format[i] == 'd' || format[i] == 'i')
			{
				int num = va_arg(args, int);

				if (num < 0)
				{
					_putchar('-');
					count++;
					num = -num;
				}

				if (num == 0)
				{
					_putchar('0');
					count++;
				}
				else
				{
					print_number(num, &count);
				}
			}
			else
			{
				_putchar('%');
				_putchar(format[i]);
				count += 2;
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
