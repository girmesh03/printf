#include "main.h"

/**
 * print_char - Prints a character.
 * @args: List of arguments.
 * @buffer: Buffer to store the character.
 * @buff_ind: Index of the buffer.
 * @flags: Flags of the format.
 * @width: Width of the format.
 * @precision: Precision of the format.
 * @size: Size of the format.
 * Return: Number of characters printed.
 */

int print_char(va_list args, char *buffer,
			int *buff_ind, int flags, int width,
			int precision, int size)
{
	char c = va_arg(args, int);
	char padd = ' ';
	int i = 0;

	(void)size;
	(void)precision;

	if (flags & ZERO_FLAG)
		padd = '0';

	if (flags & MINUS_FLAG)
	{
		buffer[(*buff_ind)++] = c;
		if (*buff_ind == BUFFER_SIZE)
			print_buffer(buffer, buff_ind);
		for (i = 0; i < width - 1; i++)
		{
			buffer[(*buff_ind)++] = padd;
			if (*buff_ind == BUFFER_SIZE)
				print_buffer(buffer, buff_ind);
		}
	}
	else
	{
		for (i = 0; i < width - 1; i++)
		{
			buffer[(*buff_ind)++] = padd;
			if (*buff_ind == BUFFER_SIZE)
				print_buffer(buffer, buff_ind);
		}
		buffer[(*buff_ind)++] = c;
		if (*buff_ind == BUFFER_SIZE)
			print_buffer(buffer, buff_ind);
	}

	return (width);
}
