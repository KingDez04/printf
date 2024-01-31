#include "main.h"

/**
 * write_char - returns char
 * @character: list given
 * Return: number of char printed
 */
int write_char(va_list character)
{
	int c = va_arg(character, int);

	_putchar(c);
	return (1);
}
