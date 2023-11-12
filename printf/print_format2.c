#include "main.h"

/**
 * print_pointer - Print octal integer
 * @args: integer
 *
 * Return: number of characters printed
 */
int print_pointer(va_list args)
{
	char buffer[1024];
	unsigned long int n = va_arg(args, unsigned long int);
	unsigned long int div = 1;
	int i = 0;

	buffer[0] = '0';
	buffer[1] = 'x';
	i = 2;

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
 * print_reversed - Print string
 * @args: string args
 *
 *Return: the number of characters printed
 */
int print_reversed(va_list args)
{
	char *str, buffer[1024];
	int i = 0,  j = 0, k = 0;

	str = va_arg(args, char *);

	while (str[k])
		k++;

	while (str[i])
	{
		buffer[i % 1024] = (str[k - 1]);

		if (i % 1024 == 1023)
		{
			write(1, buffer, 1024);
			j += 1024;
		}
		i++;
		k--;
	}

	write(1, buffer, i - j);

	return (i);
}

/**
 * print_rot13 - Print string
 * @args: string args
 *
 *Return: the number of characters printed
 */
int print_rot13(va_list args)
{
	char *str, buffer[1024];
	int i = 0,  j = 0;

	str = va_arg(args, char *);
	while (str[i])
	{
		if ((str[i] >= 'A' && str[i] < 'N') ||
				(str[i] >= 'a' && str[i] < 'n'))
			buffer[i % 1024] = (str[i]) + 13;
		else if ((str[i] >= 'N' && str[i] <= 'Z') ||
				(str[i] >= 'n' && str[i] <= 'z'))
			buffer[i % 1024] = (str[i]) - 13;
		else
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
