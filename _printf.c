#include "main.h"

/**
 * print_sp - checks which specifier to print
 * @format: char string
 * @print_arr: array of struct ops
 * @list: list of arguments to print
 * Return: number of char printed
 */
int print_sp(const char *format, fmt_t *print_arr, va_list list)
{
	char a;
	int count = 0, b = 0, c = 0;

	a = format[b];
	while (a != '\0')
	{
		if (a == '%')
		{
			c = 0;
			b++;
			a = format[b];
			while (print_arr[c].type != NULL &&
			       a != *(print_arr[c].type))
				c++;
			if (print_arr[c].type != NULL)
				count = count + print_arr[c].f(list);
			else
			{
				if (a == '\0')
					return (-1);
				if (a != '%')
					count += _putchar('%');
				count += _putchar(a);
			}
		}
		else
			count += _putchar(a);
		b++;
		a = format[b];
	}
	return (count);
}

/**
 * _printf - produces output according to a format.
 * @format: character string
 *
 * Return: number of characters printed (excluding '/0')
 */
int _printf(const char *format, ...)
{
	va_list list;
	int a = 0;

	fmt_t ops[] = {
		{"c", write_char},
		{"s", write_string},
		{"d", _int},
		{"i", _int},
		{"u", _uint},
		{"o", _octal},
		{"x", _hex_l},
		{"X", _hex_u},
		{"b", _binary},
		{"R", _rot13},
		{NULL, NULL}
	};

	if (format == NULL)
		return (-1);
	va_start(list, format);
	a = print_sp(format, ops, list);
	va_end(list);
	return (a);
}
