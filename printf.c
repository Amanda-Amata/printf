#include "main.h"
#include <stdarg.h>

/**
 * _printf - function that produces output according to a format
 *@format:character string
 *Return: char string
 */

int _printf(const char *format, ...)
{
	va_list args;
	int i, j, c;
	char *s;
	int count = 0;

	va_start(args, format);

	for (i = 0; format[i] != '\0'; i++)
	{
		if (format[i] == %)
		{
			i++;
			if (format[i] == 'c')
			{
				c = va_arg(args, int);
				 _putchar(c);
				 count++;
			}
			else if (format[i] == 's')
			{
				*s = va_arg(args, char*);
				for (j = 0; s[j] != '\0'; j++)
				{
					_putchar(s[j]);
					count++;
				}
			}
			else if (format[i] == '%')
				{
					_putchar('%');
					count++;
				}
		}
		else
		{
			_putchar(format[i]);
			count++;
		}
	}
	va_end(args);
	return (count);
}
