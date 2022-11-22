#include "main.h"
/**
* print_hex - prints a hex
* @args: list of arguments
* @buffer: buffer
* @buff_ind: buffer index
* @flags: flags
* @width: width
* @precision: precision
* @size: size
* @c: character
* Return: number of characters printed
*/
int print_hex(va_list args, char *buffer,
	      int *buff_ind, int flags, int width,
	      int precision, int size, char c)
{
	int i, j, len, num;
	char *hex = "0123456789abcdef";
	char *HEX = "0123456789ABCDEF";
	char *str;

	(void)precision;
	(void)size;
	(void)flags;
	(void)width;

	num = va_arg(args, int);
	if (num == 0)
	{
		buffer[*buff_ind] = '0';
		*buff_ind += 1;
		return (1);
	}
	str = malloc(sizeof(char) * 100);
	if (str == NULL)
		return (-1);
	for (i = 0; num > 0; i++)
	{
		if (c == 'x')
			str[i] = hex[num % 16];
		else
			str[i] = HEX[num % 16];
		num /= 16;
	}
	str[i] = '\0';
	len = _strlen(str);
	for (j = len - 1; j >= 0; j--)
	{
		buffer[*buff_ind] = str[j];
		*buff_ind += 1;
	}
	free(str);
	return (1);
}
