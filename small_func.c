#include "main.h"

/**
* is_digit - Checks if a char is a digit
* @c: Char to check
* Return: 1 if digit, 0 if not
*/

int is_digit(char c)
{
	if (c >= '0' && c <= '9')
		return (1);

	return (0);
}

/**
* is_printable - Verifies if a char is printable
* @c: Char to be evaluated
* Return: 1 if c is printable, 0 otherwise
*/
int is_printable(char c)
{
	if (c >= 32 && c < 127)
		return (1);

	return (0);
}
