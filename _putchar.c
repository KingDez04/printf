#include <unistd.h>

/**
 * _putchar - writes the char to stdout
 * @c: printed character
 *
 * Return: 1 0r -1
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}
