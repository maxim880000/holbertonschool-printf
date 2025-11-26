#include "main.h"
#include <unistd.h>
#include <stdarg.h>

/**
 * _printf - Prints formatted output to the standard output
 * @format: String containing the format specifiers 
 * 
 * Return: the number of characters or -1 if string(format) is NULL
 */
int _printf(const char *format, ...)
{
	va_list argument; 	   /* we'll need it to recup all arguments */
	int count = 0; 		  /* to count all the characters to display */

	if (!format) 	  /* if format is NULL */	
		return (-1); /* in case of error */

	va_start(argument, format); /* start the list of arguments */

	while (*format != '\0') /* we continue format until we find '\0' */
	{
		if (*format != '%') 	 /* if we % is invalid */
		{
			_putchar (*format); /* print *format */
			count++; 		   /* iterate +1 characters */
			format++;
		}
		else
		{
			format++; /* we pass to the next (second) character (after %) */
			
			if (*format == '\0') /* when it's the end just stop */
				break;
				
			if (*format == 'c') /* resolve the 'c' case */
			{
				_putchar(va_arg(argument, int)); /* va_arg recup the next argument as an int */
												/* and print it with putchar */
				count++;
				format++;
			}

			else if (*format == 's') /* resolve the 's' case */
			{
				char *ptr = va_arg(argument, char *); /* define a pointer which is egal */
													 /* to the string that we just recuped */
				if (ptr == NULL) /* nothing in ptr */
					ptr = "(null)"; /* dislpay "(null)" */

				while (*ptr != '\0')
				{
					_putchar(*ptr);
					count++; /* pass to the next character */
					ptr++; /* print the next character */
				}
				format++;
			}
			
			else if (*format == '%') /* resolve the %% case */
			{
				_putchar('%');                  /* print just one % */
				count++;                        /* we printed 1 character */
				format++;                       /* move to next char */
				continue;                       /* skip the final format++ */
			}

			else /* resolve th e '%' case */
			
			{
				_putchar('%'); /* print the % that we skipped earlier */
				_putchar(*format);  /* print the unknown letter (k, r, n...) */
				count += 2; /* we printed 2 characters */
				format++;
			}
		}	
	}
	va_end(argument);   /* close the list of arguments */
	return (count);     /* return the numbers of characters displayed */
}
