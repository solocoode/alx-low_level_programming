#include "main.h"

/**
 * function_pointer - produces output according to a format
 * @args: va_list
 * @format: format string
 *
 * Return: the number of characters printed
 */
int function_pointer(va_list args, const char *format)
{
	int i = 0, j = 0;

	print_form_t print_form[] = {
		{"c", print_char},
		{"s", print_string},
		{"%", print_percent},
		{"d", print_int},
		{"i", print_int},
		{"b", print_binary},
		{"u", print_unsigned_int},
		{"o", print_octal},
		{"x", print_hex},
		{"X", print_hex_upper},
		{"S", print_string_non_printable},
		{"p", print_pointer},
		{"r", print_reversed},
		{"R", print_rot13}
	};

	while (j < 14)
	{
		if (*print_form[j].c == *format)
		{
			i += print_form[j].f(args);

			return (i);
		}
		j++;
	}

	_putchar('%');
	_putchar(*format);

	return (2);
}
