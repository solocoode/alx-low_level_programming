#include "main.h"

/**
 * _printf - produces output according to a format
 * @format: format string
 *
 * Return: the number of characters printed
 */
int _printf(const char *format, ...)
{
	int i = 0;
	va_list args;

	if (format == NULL)
		return (-1);
	va_start(args, format);

	while (*format != '\0')
	{
		if (*format == '%')
		{
			format++;
			i += function_pointer(args, format);
		}
		else
		{
			_putchar(*format);
			i++;
		}
		format++;
	}

	va_end(args);

	return (i);
}
