#include "main.h"

/**
 * _printf - a function that produces output according to a format.
 * @format: character string
 *
 * Return: number of characters printed (excluding '/0')
 */
int _printf(const char *format, ...)
{
	int count = 0;

	va_list(list);

	va_start(list, format);

	if (!format || (format[0] == '%' && !format[1]))
		return (-1);
	if (format[0] == '%' && format[1] == ' ' && !format[2])
		return (-1);

	while (*format)
	{
		if (*format != '%')
		{
			write(1, format, 1);
			count++;
		}
		else
		{
			format++;

			if (*format == 'c')
			{
				char i = va_arg(list, int);

				write(1, &i, 1);
				count++;
			}
			else if (*format == 's')
			{
				char *j = va_arg(list, char *);

				count += write(1, j, strlen(j));
			}
			else if (*format == '%')
			{
				char k = '%';

				write(1, &k, 1);
				count++;
			}
			else if (*format == 'd' || *format == 'i')
			{
				int num = va_arg(list, int);

				write_int(1, num);
				count++;
			}
		}
		format++;
	}
	va_end(list);
	return (count);
}
