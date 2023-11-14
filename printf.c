#include <stdio.h>
#include <stdarg.h>
#include "main.h"

int _printf(const char *format, ...) {
  va_list args;
  int count = 0;

  va_start(args, format);
  while (*format != '\0') {
    if (*format != '%') {
      // Print a regular character.
      putchar(*format);
      count++;
    } else {
      // Handle a conversion specifier.
      switch (*(++format)) {
        case 'c':
          // Print a character.
          putchar(va_arg(args, int));
          count++;
          break;
        case 's':
          // Print a string.
          const char *str = va_arg(args, char *);
          while (*str != '\0') {
            putchar(*str);
            count++;
            str++;
          }
          break;
        case '%':
          // Print a literal `%` character.
          putchar('%');
          count++;
          break;
        default:
          // Unsupported conversion specifier.
          // TODO: Handle this error more gracefully.
          return -1;
      }
    }
    format++;
  }
  va_end(args);

  return count;
}
