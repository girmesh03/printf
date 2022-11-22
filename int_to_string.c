
#include "main.h"

/**
 * int_to_string - converts an integer to a string
 * @int_arg: integer to convert
 * @int_str: string to store the converted integer
 * Return: length of the converted integer
 */

int int_to_string(int int_arg, char *int_str)
{
	int int_len = 0, i = 0;
	char temp;

	while (int_arg != 0)
	{
		int_str[i] = (int_arg % 10) + '0';
		int_arg /= 10;
		i++;
		int_len++;
	}

	for (i = 0; i < int_len / 2; i++)
	{
		temp = int_str[i];
		int_str[i] = int_str[int_len - i - 1];
		int_str[int_len - i - 1] = temp;
	}

	return (int_len);
}
