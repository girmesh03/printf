#include "main.h"

/**
* get_precision - Gets the precision of the format.
* @format: Format string.
* @i: Index of the format string.
* @args: List of arguments.
* Return: Precision of the format.
*/

int get_precision(const char *format, int *i, va_list args)
{
	int precision = 0;

	if (format[*i] == '.')
	{
		(*i)++;
		if (format[*i] == '*')
		{
			precision = va_arg(args, int);
			(*i)++;
		}
		else
		{
			while (format[*i] >= '0' && format[*i] <= '9')
			{
				precision = precision * 10 + (format[*i] - '0');
				(*i)++;
			}
		}
	}

	return (precision);
}
