
#include "main.h"
/**
* get_size - Gets the size of the format.
* @format: Format string.
* @i: Index of the format string.
* Return: length of the format.
*/
int get_size(const char *format, int *i)
{
	int size = 0;

	if (format[*i] == 'h' || format[*i] == 'l')
	{
		if (format[*i] == 'h')
		{
			size = HH_SIZE;
			(*i)++;
			if (format[*i] == 'h')
			{
				size = H_SIZE;
				(*i)++;
			}
		}
		else if (format[*i] == 'l')
		{
			size = LL_SIZE;
			(*i)++;
			if (format[*i] == 'l')
			{
				size = L_SIZE;
				(*i)++;
			}
		}
	}
	return (size);
}
