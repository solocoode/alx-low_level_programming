#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

int _putchar(char c);
int _printf(const char *format, ...);
void printchar(int n, ...);
int print_decimal(va_list args);
int print_binary(va_list args);
int handle_unsigned_decimal(va_list args);

#endif
