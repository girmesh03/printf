#include "main.h"
void print_buffer(char buffer[], int *buff_ind);
/**
 * _printf - produces output according to a format
 * @format: character string
 * Return: number of characters printed
 */
int _printf(const char *format, ...)
{
	int i = 0, buff_ind = 0, printed = 0, printed_chars = 0;
	int flags = 0, width = 0, precision = 0, size = 0;
	char buffer[BUFFER_SIZE];

	va_list args;

	if (format == NULL)
		return (-1);

	va_start(args, format);

	for (i = 0; format[i] != '\0'; i++)
	{
		if (format[i] != '%')
		{
			buffer[buff_ind++] = format[i];
			printed++;
		}
		else
		{
			i++;
			flags = get_flags(format, &i);
			width = get_width(format, &i, args);
			precision = get_precision(format, &i, args);
			size = get_size(format, &i);
			if (format[i] == 'c')
			{
				printed_chars = print_char(args, buffer,
										   &buff_ind, flags,
										   width, precision, size);
				if (printed_chars == -1)
					return (-1);
				printed += printed_chars;
			}
			else if (format[i] == 's')
			{
				printed_chars = print_string(args, buffer,
											 &buff_ind, flags,
											 width, precision, size);
				if (printed_chars == -1)
					return (-1);
				printed += printed_chars;
			}
			else if (format[i] == '%')
			{
				printed_chars = print_percent(buffer, &buff_ind);
				if (printed_chars == -1)
					return (-1);
				printed += printed_chars;
			}
			else if (format[i] == 'i' || format[i] == 'd')
			{
				printed_chars = print_int(args, buffer,
										  &buff_ind, flags,
										  width, precision, size);
				if (printed_chars == -1)
					return (-1);
				printed += printed_chars;
			}
			else if (format[i] == 'b')
			{
				printed_chars = print_binary(args, buffer,
											 &buff_ind, flags,
											 width, precision, size);
				if (printed_chars == -1)
					return (-1);
				printed += printed_chars;
			}
			else if (format[i] == 'o')
			{
				printed_chars = print_octal(args, buffer,
											&buff_ind, flags,
											width, precision, size);
				if (printed_chars == -1)
					return (-1);
				printed += printed_chars;
			}
			else if (format[i] == 'u')
			{
				printed_chars = print_unsigned_int(args, buffer,
												   &buff_ind, flags,
												   width, precision, size);
				if (printed_chars == -1)
					return (-1);
				printed += printed_chars;
			}
			else if (format[i] == 'x' || format[i] == 'X')
			{
				printed_chars = print_hex(args, buffer,
										  &buff_ind, flags,
										  width, precision, size, format[i]);
				if (printed_chars == -1)
					return (-1);
				printed += printed_chars;
			}
			else if (format[i] == 'p')
			{
				printed_chars = print_pointer(args, buffer,
											  &buff_ind, flags,
											  width, precision, size);
				if (printed_chars == -1)
					return (-1);
				printed += printed_chars;
			}
			else if (format[i] == 'S')
			{
				printed_chars = print_non_printable(args, buffer,
													&buff_ind, flags,
													width, precision, size);
				if (printed_chars == -1)
					return (-1);
				printed += printed_chars;
			}
			else if (format[i] == 'r')
			{
				printed_chars = print_reverse(args, buffer,
											  &buff_ind, flags,
											  width, precision, size);
				if (printed_chars == -1)
					return (-1);
				printed += printed_chars;
			}
			else if (format[i] == 'R')
			{
				printed_chars = print_rot13string(args, buffer,
												  &buff_ind, flags,
												  width, precision, size);
				if (printed_chars == -1)
					return (-1);
				printed += printed_chars;
			}
			else
			{
				buffer[buff_ind] = '%';
				buff_ind++;
				buffer[buff_ind] = format[i];
				buff_ind++;
			}
		}
		if (buff_ind >= BUFFER_SIZE)
			print_buffer(buffer, &buff_ind);
	}
	print_buffer(buffer, &buff_ind);
	va_end(args);
	return (printed);
}

/**
 * print_buffer - prints buffer
 * @buffer: buffer
 * @buff_ind: buffer index
 * Return: number of characters printed
 */

void print_buffer(char buffer[], int *buff_ind)
{
	if (*buff_ind > 0)
		write(1, &buffer[0], *buff_ind);

	*buff_ind = 0;
}
