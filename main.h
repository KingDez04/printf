#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <string.h>
#include <unistd.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

/**
 * struct flags - flags passed to _printf()
 * @plus: '+' flag
 * @space: ' ' flag
 * @hash: '#' flag
 */

typedef struct flags
{
	int plus;
	int space;
	int hash;
} flags_test;

/**
 * struct printHandler - based on format specifier
 * @c: format specifier
 * @f: pointer
 */

typedef struct printHandler
{
	char c;
	int (*f)(va_list ap, flags_test *f);
} ph;

/**
 * struct fmt - holds format specifier
 * @type: string that represents the format specifier
 * @f: pointer
 */

typedef struct fmt
{
char *type;
int (*f)();
} fmt_t;

int _printf(const char *format, ...);
int print_int(va_list l, flags_test *f);
void print_number(int n);
int _printint(int n);
int print_unsigned(va_list l, flags_test *f);
int count_digit(int i);
int print_hex(va_list l, flags_test *f);
int print_hex_big(va_list l, flags_test *f);
int print_binary(va_list l, flags_test *f);
int print_octal(va_list l, flags_test *f);
char *convert(unsigned long int num, int base, int lowercase);
int (*get_print(char s))(va_list, flags_test *);
int get_flag(char s, flags_test *f);
int print_string(va_list l, flags_test *f);
int print_char(va_list l, flags_test *f);
int _putchar(char c);
int _puts(char *str);
int print_rot13(va_list l, flags_test *f);
int print_rev(va_list l, flags_test *f);
int print_bigS(va_list l, flags_test *f);
int print_address(va_list l, flags_test *f);
int print_percent(va_list l, flags_test *f);
int _binary(va_list bin);
int _int(va_list i);
int _hex_str(unsigned int n, unsigned int hex, char alpha);
int _hex_l(va_list hexa);
int _hex_u(va_list hexa);
int _rot13(va_list rot);
int _octal(va_list oct);
int _strlen(char *string);
int _uint(va_list unsign);
int write_char(va_list character);
int write_string(va_list string);
int _hex_str(unsigned int n, unsigned int hex, char alpha);

#endif
