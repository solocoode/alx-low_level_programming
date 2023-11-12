#include "main.h"

/**
 * print_char - Print character
 * @args: char
 *
 * Return: number of characters printed
 */
int print_char(va_list args)
{
	char c = va_arg(args, int);

	_putchar(c);

	return (1);
}

/**
 * print_string - Print string
 * @args: string args
 *
 *Return: the number of characters printed
 */
int print_string(va_list args)
{
	char *str, buffer[1024];
	int i = 0,  j = 0;

	str = va_arg(args, char *);
	while (str[i])
	{
		buffer[i % 1024] = (str[i]);

		if (i % 1024 == 1023)
		{
			write(1, buffer, 1024);
			j += 1024;
		}
		i++;
	}

	write(1, buffer, i - j);

	return (i);
}

/**
 * print_percent - Print character
 * @args: char
 *
 * Return: number of characters printed
 */
int print_percent(va_list __attribute__((__unused__)) args)
{
	_putchar('%');

	return (1);
}

/**
 * print_int - Print integer
 * @args: integer
 *
 * Return: number of characters printed
 */
int print_int(va_list args)
{
	char buffer[1024];
	int n = va_arg(args, int);
	unsigned int div = 1, i = 0;

	if (n < 0)
	{
		buffer[0] = '-';
		n *= -1;
		i++;
	}

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
 * print_binary - Print integer
 * @args: integer
 *
 * Return: number of characters printed
 */
int print_binary(va_list args)
{
	char buffer[1024];
	unsigned int n = va_arg(args, unsigned int);
	unsigned int div = 1, i = 0;

	while (n / div >= 2)
		div *= 2;

	while (div > 0)
	{
		buffer[i] = '0' + n / div;
		n %= div;
		div /= 2;
		i++;
	}

	write(1, buffer, i);

	return (i);
}
