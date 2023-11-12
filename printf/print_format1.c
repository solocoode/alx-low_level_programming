#include "main.h"

/**
 * print_unsigned_int - Print unsigned  integer
 * @args: integer
 *
 * Return: number of characters printed
 */
int print_unsigned_int(va_list args)
{
	char buffer[1024];
	unsigned int n = va_arg(args, unsigned int);
	unsigned int div = 1, i = 0;

	while (n / div >= 10)
		div *= 10;

	while (div > 0)
	{
		buffer[i] = '0' + n / div;
		n %= div;
		div /= 10;
		i++;
	}

	write(1, buffer, i);

	return (i);
}

/**
 * print_octal - Print octal integer
 * @args: integer
 *
 * Return: number of characters printed
 */
int print_octal(va_list args)
{
	char buffer[1024];
	unsigned int n = va_arg(args, unsigned int);
	unsigned int div = 1, i = 0;

	while (n / div >= 8)
		div *= 8;

	while (div > 0)
	{
		buffer[i] = '0' + n / div;
		n %= div;
		div /= 8;
		i++;
	}

	write(1, buffer, i);

	return (i);
}

/**
 * print_hex - Print octal integer
 * @args: integer
 *
 * Return: number of characters printed
 */
int print_hex(va_list args)
{
	char buffer[1024];
	unsigned int n = va_arg(args, unsigned int);
	unsigned int div = 1, i = 0;

	while (n / div >= 16)
		div *= 16;

	while (div > 0)
	{
		if (n / div < 10)
			buffer[i] = '0' + n / div;
		else
			buffer[i] = 'a' + n / div - 10;
		n %= div;
		div /= 16;
		i++;
	}

	write(1, buffer, i);

	return (i);
}

/**
 * print_hex_upper - Print octal integer
 * @args: integer
 *
 * Return: number of characters printed
 */
int print_hex_upper(va_list args)
{
	char buffer[1024];
	unsigned int n = va_arg(args, unsigned int);
	unsigned int div = 1, i = 0;

	while (n / div >= 16)
		div *= 16;

	while (div > 0)
	{
		if (n / div < 10)
			buffer[i] = '0' + n / div;
		else
			buffer[i] = 'A' + n / div - 10;
		n %= div;
		div /= 16;
		i++;
	}

	write(1, buffer, i);

	return (i);
}

/**
 * print_string_non_printable - Print string
 * @args: string args
 *
 *Return: the number of characters printed
 */
int print_string_non_printable(va_list args)
{
	char *str, buffer[1024];
	int i = 0,  j = 0, n = 0, h = 0;

	str = va_arg(args, char *);
	while (str[i])
	{
		if (str[i] < 32 || str[i] >= 127)
		{
			buffer[(i + n) % 1024] = 92;
			buffer[(i + n) % 1024 + 1] = 'x';
			h = str[i] / 16;

			if (h >= 10 && h < 16)
				buffer[(i + n + 2) % 1024] = 'A' + h - 10;
			else
				buffer[(i + n + 2) % 1024] = '0' + h;

			h = str[i] % 16;
			if (h >= 10)
				buffer[(i + n + 3) % 1024] = 'A' + h - 10;
			else
				buffer[(i + n + 3) % 1024] = '0' + h;

			n += 3;
			i++;
		}
		buffer[(i + n) % 1024] = (str[i]);

		if ((i + n) % 1024 == 1023)
		{
			write(1, buffer, 1024);
			j += 1024;
		}
		i++;
	}
	write(1, buffer, i + n - j);

	return (i + n);
}
