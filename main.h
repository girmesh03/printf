#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>

#define BUFFER_SIZE 1024

#define ZERO_FLAG 1
#define MINUS_FLAG 2
#define PLUS_FLAG 4
#define SPACE_FLAG 8
#define HASH_FLAG 16

#define HH_SIZE 1
#define H_SIZE 2
#define LL_SIZE 3
#define L_SIZE 4

#define INT_STR_LEN 12

int _printf(const char *format, ...);

int print_char(va_list args, char *buffer,
	       int *buff_ind, int flags,
	       int width, int precision, int size);

int print_string(va_list args, char *buffer,
		 int *buff_ind, int flags,
		 int width, int precision, int size);

int print_percent(char buffer[], int *buff_ind);

int print_int(va_list args, char *buffer,
	      int *buff_ind, int flags,
	      int width, int precision, int size);

int print_unsigned_int(va_list args,
		       char *buffer, int *buff_ind, int flags,
		       int width, int precision, int size);
int print_binary(va_list args,
		 char *buffer, int *buff_ind, int flags,
		 int width, int precision, int size);

int print_octal(va_list args,
		char *buffer, int *buff_ind, int flags,
		int width, int precision, int size);

int print_hex(va_list args,
	      char *buffer, int *buff_ind, int flags,
	      int width, int precision, int size, char c);

int print_non_printable(va_list args,
			char *buffer, int *buff_ind, int flags,
			int width, int precision, int size);

int print_reverse(va_list args,
		  char *buffer, int *buff_ind, int flags,
		  int width, int precision, int size);

int print_rot13string(va_list args,
		      char *buffer, int *buff_ind, int flags,
		      int width, int precision, int size);

int print_pointer(va_list args,
		  char *buffer, int *buff_ind, int flags,
		  int width, int precision, int size);

int get_flags(const char *format, int *i);
int get_width(const char *format, int *i, va_list args);
int get_precision(const char *format, int *i, va_list args);
int get_size(const char *format, int *i);

int _strlen(char *s);
void print_buffer(char buffer[], int *buff_ind);
int int_to_string(int int_arg, char *int_str);

#endif
