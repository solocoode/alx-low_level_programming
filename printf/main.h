#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <stddef.h>
#include <unistd.h>

/**
 * struct print_form - Define a struct to figure out how to print
 * @c: Character to check for
 * @f: Pointer to function to call
 */
typedef struct print_form
{
	char *c;
	int (*f)();
} print_form_t;

int _printf(const char *format, ...);
int function_pointer(va_list args, const char *format);
int print_char(va_list args);
int print_string(va_list args);
int print_percent(va_list args);
int print_int(va_list args);
int print_binary(va_list args);
int print_unsigned_int(va_list args);
int print_octal(va_list args);
int print_hex(va_list args);
int print_hex_upper(va_list args);
int print_string_non_printable(va_list args);
int print_pointer(va_list args);
int print_reversed(va_list args);
int print_rot13(va_list args);
int _putchar(char c);
#endif
