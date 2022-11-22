#include "main.h"

/**
 * get_flags - gets the flags
 * @format: character string
 * @i: index of format
 * Return: flags
 */

int get_flags(const char *format, int *i)
{
	int flags = 0;
	const char *flag_chars = "#0- +";

	while (format[*i] != '\0')
	{
		if (format[*i] == flag_chars[0])
			flags |= HASH_FLAG;
		else if (format[*i] == flag_chars[1])
			flags |= ZERO_FLAG;
		else if (format[*i] == flag_chars[2])
			flags |= MINUS_FLAG;
		else if (format[*i] == flag_chars[3])
			flags |= SPACE_FLAG;
		else if (format[*i] == flag_chars[4])
			flags |= PLUS_FLAG;
		else
			break;
		(*i)++;
	}

	return (flags);
}

/**
 * get_width - gets the width
 * @format: character string
 * @i: index of format
 * @args: list of arguments
 * Return: width
 */

int get_width(const char *format, int *i, va_list args)
{
	int width = 0;

	if (format[*i] == '*')
	{
		width = va_arg(args, int);
		(*i)++;
	}
	else
	{
		while (format[*i] != '\0' && format[*i] >= '0' && format[*i] <= '9')
		{
			width = width * 10 + (format[*i] - '0');
			(*i)++;
		}
	}

	return (width);
}

/**
 * get_precision - gets the precision
 * @format: character string
 * @i: index of format
 * @args: list of arguments
 * Return: precision
 */

int get_precision(const char *format, int *i, va_list args)
{
	int precision = -1;

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
			precision = 0;
			while (format[*i] != '\0' && format[*i] >= '0' && format[*i] <= '9')
			{
				precision = precision * 10 + (format[*i] - '0');
				(*i)++;
			}
		}
	}

	return (precision);
}

/**
 * get_size - gets the size
 * @format: character string
 * @i: index of format
 * Return: size
 */

int get_size(const char *format, int *i)
{
	int size = 0;
	const char *size_chars = "hlL";

	while (format[*i] != '\0')
	{
		if (format[*i] == size_chars[0])
			size |= SHORT_SIZE;
		else if (format[*i] == size_chars[1])
			size |= LONG_SIZE;
		else if (format[*i] == size_chars[2])
			size |= LONG_LONG_SIZE;
		else
			break;
		(*i)++;
	}

	return (size);
}
