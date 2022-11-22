#include "main.h"

/**
 * get_width - Gets the width of the format.
 * @format: Format string.
 * @i: Index of the format string.
 * @list: List of arguments.
 * Return: Width of the format.
 */

int get_width(const char *format, int *i, va_list list)
{
	int width = 0;

	if (format[*i] == '*')
	{
		width = va_arg(list, int);
		(*i)++;
	}
	else
	{
		while (format[*i] >= '0' && format[*i] <= '9')
		{
			width = width * 10 + (format[*i] - '0');
			(*i)++;
		}
	}

	return (width);
}
