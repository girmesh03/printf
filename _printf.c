#include "main.h"

void print_buffer(char buffer[], int *buff_ind);

/**
* handle_print - Handles the printing of the format
* @fmt: Format string
* @i: Index of the format string
* @list: List of arguments
* @buffer: Buffer to print to
* Return: Number of chars printed
*/

int handle_print(const char *fmt, int *i, va_list list, char buffer[])
{
	int j, printed_chars = 0, unknow_len = 0;
	modifier m;
	modifier *ptr = &m;

	fmt_t function[] = {
		{'c', print_char},
		{'\0', NULL}
	};

	for (j = 0; function[j].fmt != '\0'; j++)
	{
		if (fmt[*i] == function[j].fmt)
		{
			return (function[j].fn(list, buffer));
		}
	}

	if (function[j].fmt == '\0')
	{
		if (fmt[*i] == '\0')
			return (-1);
		unknow_len += write(1, "%%", 1);
		if (fmt[*i - 1] == ' ')
			unknow_len += write(1, " ", 1);
		else if (ptr->width)
		{
			--(*i);
			while (fmt[*i] != ' ' && fmt[*i] != '%')
				--(*i);
			if (fmt[*i] == ' ')
				--(*i);
			return (1);
		}
		unknow_len += write(1, &fmt[*i], 1);
		return (unknow_len);
	}
	return (printed_chars);
}

/**
* _printf - Printf function
* @format: format.
* Return: Printed chars.
*/
int _printf(const char *format, ...)
{
	int i, printed = 0, printed_chars = 0, buff_ind = 0;
	char buffer[BUFF_SIZE];
	modifier m = {0, 0, 0, 0};
	modifier *ptr = &m;

	va_list list;

	if (format == NULL)
		return (-1);

	va_start(list, format);

	for (i = 0; format && format[i] != '\0'; i++)
	{
		if (format[i] != '%')
		{
			buffer[buff_ind++] = format[i];
			if (buff_ind == BUFF_SIZE)
				print_buffer(buffer, &buff_ind);

			printed_chars++;
		}
		else
		{
			print_buffer(buffer, &buff_ind);
			ptr->flags = get_flags(format, &i);
			ptr->width = get_width(format, &i, list);
			ptr->precision = get_precision(format, &i, list);
			ptr->size = get_size(format, &i);
			++i;

			printed = handle_print(format, &i, list, buffer);

			if (printed == -1)
				return (-1);
			printed_chars += printed;
		}
	}

	print_buffer(buffer, &buff_ind);
	va_end(list);

	return (printed_chars);
}

/**
* print_buffer - Prints the contents of the buffer if it exist
* @buffer: Array of chars
* @buff_ind: Index at which to add next char, represents the length.
*/
void print_buffer(char buffer[], int *buff_ind)
{
	if (*buff_ind > 0)
		write(1, &buffer[0], *buff_ind);

	*buff_ind = 0;
}
