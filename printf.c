#include "main.h"
#include <unistd.h>

/**
 * _printf - Prints formatted output to the standard output
 * @format: String containing the format specifiers 
 * 
 * Return: the number of characters or -1 if string(format) is NULL
 */
int _printf(const char *format, ...);
{
	va_list argument; /* we'll need it to recup all arguments */
	int count; 		  /* to count all the caracters to display */

	count = 0; 
	if (!format) /* if format is NULL */	
		return (-1); /* in case of error */

	va_start(argument, format); /* start the list of arguments */

	while (*format != '\0')
	{
		
	}
}