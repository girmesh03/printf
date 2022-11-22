#include "main.h"

/**
* print_string - prints a string
* @args: argument list
* @buffer: buffer
* @buff_ind: buffer index
* @flags: flags
* @width: width
* @precision: precision
* @size: size
* Return: number of characters printed
*/

int print_string(va_list args, char *buffer,
		 int *buff_ind, int flags, int width,
		 int precision, int size)
{
	char *str = va_arg(args, char *);
	int printed_chars = 0, i = 0;

	(void)size;
	(void)flags;
	(void)width;

	if (str == NULL)
		str = "(null)";

	if (precision == -1)
		precision = _strlen(str);

	for (i = 0; i < precision; i++)
	{
		buffer[(*buff_ind)++] = str[i];
		printed_chars++;
	}

	return (printed_chars);
}
