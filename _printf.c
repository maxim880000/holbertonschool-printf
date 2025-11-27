#include "main.h"
#include <unistd.h>
#include <stdarg.h>
// recursive function
int print_number(unsigned int num) 
{
	// count how many number we displayed
	int count = 0;
	// if num / 10 != 0 still number to display
	if (num / 10)
		count += print_number(num / 10);
	_putchar((num % 10) + '0');
	count++;
	return (count);
}

/**
 * _printf - Prints formatted output to the standard output
 * @format: String containing the format specifiers before the rest of argument ...
 *
 * Return: the number of characters printed
 */
int _printf(const char *format, ...)
{
	va_list args; // list of argument
	int count = 0; // count the total number characters displayed
	int i = 0; // position in the string format

	if (format == NULL)
		return (-1);

	va_start(args, format); // read the arguments

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
				// recup the list of arguments "args" and stock in char c
				char c = va_arg(args, int);
				_putchar(c);
				count++;
			}
			else if (format[i] == 's')
			{
				// recup the string and stock the adress of the strinf in s
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
				// recup the integer and stock it in num
				int num = va_arg(args, int);

				if (num < 0)
				{
					_putchar('-');
					count++;
					// make it positiv because print_number treat only positiv number 
					num = -num;
				}

				if (num == 0)
				{
					_putchar('0');
					count++;
				}
				else
				{
					// call the recursive function, convert in positive unsigned
					count += print_number((unsigned int)num);
				}
			}
			// we do not know what is unknow
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
