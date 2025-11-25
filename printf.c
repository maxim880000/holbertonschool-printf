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

	while (*(format + count) != '\0') /* we continue format until we find '\0' */
	{
		if (*(format + count) != '%') 	 /* if we % is invalid */
		{
			_putchar (*format); /* print *format */
			count ++; 		   /* iterate +1 characters */
		}

		else
		{
			format++; /* we pass to the next (second) character (after %) */
			
		}	
	}
}
