#include "main.h"

int int_to_string(int int_arg, char *int_str);
/**
* print_int - prints an integer
* @args: list of arguments
* @buffer: buffer
* @buff_ind: buffer index
* @flags: flags
* @width: width
* @precision: precision
* @size: size
* Return: number of characters printed
*/
int print_int(va_list args, char *buffer,
	      int *buff_ind, int flags,
	      int width, int precision, int size)
{
	int int_arg = va_arg(args, int);
	char int_str[INT_STR_LEN];
	int int_len = 0, printed_chars = 0, i = 0;

	(void)size;
	(void)precision;
	(void)flags;
	(void)width;

	if (int_arg < 0)
	{
		buffer[(*buff_ind)++] = '-';
		printed_chars++;
		int_arg *= -1;
	}

	int_len = int_to_string(int_arg, int_str);

	if (precision == 0 && int_arg == 0)
		int_len = 0;

	if (precision > int_len)
	{
		for (i = 0; i < precision - int_len; i++)
		{
			buffer[(*buff_ind)++] = '0';
			printed_chars++;
		}
	}

	for (i = 0; i < int_len; i++)
	{
		buffer[(*buff_ind)++] = int_str[i];
		printed_chars++;
	}

	return (printed_chars);
}
