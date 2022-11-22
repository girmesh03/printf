#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

#define BUFF_SIZE 1024

/* FLAGS */
#define F_MINUS 1
#define F_PLUS 2
#define F_ZERO 4
#define F_HASH 8
#define F_SPACE 16

/* SIZES */
#define S_LONG 2
#define S_SHORT 1

/**
* struct fmt - format specifier
* @fmt: character
* @fn: function pointer
*/
struct fmt
{
	char fmt;
	int (*fn)(va_list, char[]);
};

/*fmt_t type of fmt*/
typedef struct fmt fmt_t;

/**
* struct mod - modifier of the format
* @flags: flags
* @width: width
* @precision: precision
* @size: size
*/
struct mod
{
	int flags;
	int width;
	int precision;
	int size;
};

/*mod format modifier*/
typedef struct mod modifier;

int _printf(const char *format, ...);
int handle_print(const char *fmt, int *i,
		 va_list list, char buffer[]);

int print_char(va_list types, char buffer[]);
int print_string(va_list types, char buffer[]);
int print_percent(va_list types, char buffer[]);

int get_flags(const char *fmt, int *i);
int get_width(const char *fmt, int *i, va_list list);
int get_precision(const char *fmt, int *i, va_list list);
int get_size(const char *fmt, int *i);

int is_digit(char c);
int is_printable(char c);

#endif /* MAIN_H */
