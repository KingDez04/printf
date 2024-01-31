#include "main.h"

/**
 * _strlen - gets string length
 * @string: string
 * Return: string length
 */
int _strlen(char *string)
{
	int count;
	int len = 0;

	if (string)
	{
		for (count = 0; string[count] != '\0'; count++)
		{
			_putchar(string[len]);
			len++;
		}
	}
	return (len);
}
