#include "main.h"
/**
* print_non_printable - prints non printable characters
* @args: list of arguments
* @buffer: buffer
* @buff_ind: buffer index
* @flags: flags
* @width: width
* @precision: precision
* @size: size
* Return: number of characters printed
*/
int print_non_printable(va_list args, char *buffer,
			int *buff_ind, int flags,
			int width, int precision, int size)
{
	int i, j, printed_chars = 0;
	char *str = va_arg(args, char *);
	char *hex = "0123456789abcdef";
	char *hex_str = malloc(sizeof(char) * 2);
	(void)precision;
	(void)size;
	(void)flags;
	(void)width;
	if (str == NULL)
	{
		str = "(null)";
	}
	for (i = 0; str[i] != '\0'; i++)
	{
		if (str[i] < 32 || str[i] >= 127)
		{
			buffer[*buff_ind] = '\\';
			*buff_ind += 1;
			buffer[*buff_ind] = 'x';
			*buff_ind += 1;
			for (j = 0; j < 2; j++)
			{
				hex_str[j] = hex[(str[i] >>
						  (4 * (1 - j))) & 0xf];
			}
			for (j = 0; j < 2; j++)
			{
				buffer[*buff_ind] = hex_str[j];
				*buff_ind += 1;
			}
			printed_chars += 4;
		}
		else
		{
			buffer[*buff_ind] = str[i];
			*buff_ind += 1;
			printed_chars += 1;
		}
	}
	free(hex_str);
	return (printed_chars);
}
