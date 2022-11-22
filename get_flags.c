
#include "main.h"

/**
 * get_flags - Gets the flags of the format.
 * @format: Format string.
 * @i: Index of the format string.
 * Return: Flags of the format.
 */

int get_flags(const char *format, int *i)
{
	int flags = 0;

	while (format[*i] == '#' || format[*i] == '0'
			|| format[*i] == '-' || format[*i] == ' '
			|| format[*i] == '+')
	{
		if (format[*i] == '#')
			flags |= HASH_FLAG;
		else if (format[*i] == '0')
			flags |= ZERO_FLAG;
		else if (format[*i] == '-')
			flags |= MINUS_FLAG;
		else if (format[*i] == ' ')
			flags |= SPACE_FLAG;
		else if (format[*i] == '+')
			flags |= PLUS_FLAG;
		(*i)++;
	}
	return (flags);
}
