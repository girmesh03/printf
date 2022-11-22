#include "main.h"
/**
* print_binary - prints a binary number
* @args: list of arguments
* @buffer: buffer
* @buff_ind: buffer index
* @flags: flags
* @width: width
* @precision: precision
* @size: size
* Return: number of characters printed
*/
int print_binary(va_list args, char *buffer,
		 int *buff_ind, int flags,
		 int width, int precision, int size)
{
	int i;
	unsigned int num = va_arg(args, unsigned int);
	(void)precision;
	(void)size;
	(void)flags;
	(void)width;

	if (num == 0)
	{
		buffer[*buff_ind] = '0';
		*buff_ind += 1;
		return (1);
	}
	for (i = 31; i >= 0; i--)
	{
		if (num & (1 << i))
			break;
	}
	for (; i >= 0; i--)
	{
		if (num & (1 << i))
			buffer[*buff_ind] = '1';
		else
			buffer[*buff_ind] = '0';
		*buff_ind += 1;
	}
	return (1);
}
