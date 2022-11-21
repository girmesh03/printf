#include "main.h"

int print_char(va_list args, char *buffer,
	       int *buff_ind, int flags,
	       int width, int precision, int size);

int print_string(va_list args, char *buffer,
		 int *buff_ind, int flags,
		 int width, int precision, int size);

int print_percent(char buffer[], int *buff_ind);

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
	       int *buff_ind, int flags,
	       int width, int precision, int size)
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
		 int *buff_ind, int flags,
		 int width, int precision, int size)
{
	int length = 0, i = 0, printed_chars = 0;
	char *str = va_arg(args, char *);
	char padd = ' ';

	(void)size;
	(void)precision;

	if (str == NULL)
		str = "(null)";

	if (width > 0)
	{
		length = _strlen(str);
		if (length > width)
			length = width;
		if (flags & MINUS_FLAG)
		{
			for (i = 0; i < length; i++)
			{
				buffer[(*buff_ind)++] = str[i];
				if (*buff_ind == BUFFER_SIZE)
					print_buffer(buffer, buff_ind);
			}
			for (i = 0; i < width - length; i++)
			{
				buffer[(*buff_ind)++] = padd;
				if (*buff_ind == BUFFER_SIZE)
					print_buffer(buffer, buff_ind);
			}
		}
		else
		{
			for (i = 0; i < width - length; i++)
			{
				buffer[(*buff_ind)++] = padd;
				if (*buff_ind == BUFFER_SIZE)
					print_buffer(buffer, buff_ind);
			}
			for (i = 0; i < length; i++)
			{
				buffer[(*buff_ind)++] = str[i];
				if (*buff_ind == BUFFER_SIZE)
					print_buffer(buffer, buff_ind);
			}
		}
		printed_chars = width;
	}
	else
	{
		for (i = 0; str[i] != '\0'; i++)
		{
			buffer[(*buff_ind)++] = str[i];
			if (*buff_ind == BUFFER_SIZE)
				print_buffer(buffer, buff_ind);
		}
		printed_chars = i;
	}

	return (printed_chars + 1);
}

/**
 * print_percent - prints a percent sign
 * @buffer: buffer
 * @buff_ind: buffer index
 * Return: 1
 */

int print_percent(char buffer[], int *buff_ind)
{
	buffer[(*buff_ind)++] = '%';
	if (*buff_ind == BUFFER_SIZE)
		print_buffer(buffer, buff_ind);
	return (1);
}
