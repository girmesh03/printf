#include "main.h"

int handle_write_char(char c, char buffer[]);

/**
* print_char - Prints a char
* @types: List a of arguments
* @buffer: Buffer array to handle print
* Return: Number of chars printed
*/
int print_char(va_list types, char buffer[])
{
	char c = va_arg(types, int);

	return (handle_write_char(c, buffer));
}

/**
* print_string - Prints a string
* @types: List a of arguments
* @buffer: Buffer array to handle print
* Return: Number of chars printed
*/
int print_string(va_list types, char buffer[])
{
	int length = 0;
	int i;
	char *str;
	modifier m;
	modifier *ptr = &m;

	(void)buffer;

	str = va_arg(types, char *);

	if (str == NULL)
	{
		str = "(null)";
		if (ptr->precision >= 6)
			str = "      ";
	}

	while (str[length] != '\0')
		length++;

	if (ptr->precision >= 0 && ptr->precision < length)
		length = ptr->precision;

	if (ptr->width > length)
	{
		if (ptr->flags & F_MINUS)
		{
			write(1, &str[0], length);
			for (i = ptr->width - length; i > 0; i--)
				write(1, " ", 1);
			return (ptr->width);
		}
		else
		{
			for (i = ptr->width - length; i > 0; i--)
				write(1, " ", 1);
			write(1, &str[0], length);
			return (ptr->width);
		}
	}

	return (write(1, str, length));
}

/**
* print_percent - Prints a percent sign
* @types: Lista of arguments
* @buffer: Buffer array to handle print
* Return: Number of chars printed
*/
int print_percent(va_list types, char buffer[])
{
	(void)types;
	(void)buffer;

	return (write(1, "%%", 1));
}
