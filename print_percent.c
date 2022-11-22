#include "main.h"

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
