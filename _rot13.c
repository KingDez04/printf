#include "main.h"

/**
 * _rot13 - prints rot13 version
 * @rot: passed list
 * Return: char counts
 */
int _rot13(va_list rot)
{
	int a, count;
	char *s;

	a = count = 0;
	s = va_arg(rot, char *);

	if (s == NULL)
		return (-1);
	while (s[a] != '\0')
	{
		if ((s[a] >= 'a' && s[a] <= 'z') || (s[a] >= 'A' && s[a] <= 'Z'))
		{
			if ((s[a] >= 'n' && s[a] <= 'z') || (s[a] >= 'N' && s[a] <= 'Z'))
				count += _putchar(s[a] - 13);
			else
				count += _putchar(s[a] + 13);
		}
		else
			count += _putchar(s[a]);
		a++;
	}
	return (count);
}
