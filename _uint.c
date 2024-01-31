#include "main.h"

/**
 * _uint - unsigned int printed
 * @unsign: passed list
 * Return: char count
 */
int _uint(va_list unsign)
{
	unsigned int n;
	int res = 1;
	int len = 0;

	n = va_arg(unsign, unsigned int);

	while (n / res > 0)
		res *= 10;
	while (res != 0)
	{
		len += _putchar(n / res + '0');
		n %= res;
		res /= 10;
	}
	return (len);
}
