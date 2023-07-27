#ifndef _PRINTF_H
#define _PRINTF_H

#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>
#include <limits.h>
#include <stdlib.h>

#define OUTPUT_BUF_SIZE 1024
#define BUF_FLUSH -1
#define NULL_STRING "(null)"
#define PARAMS_INIT {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
#define CONVERT_LOWERCASE   1
#define CONVERT_UNSIGNED    2
/**
 * struct param - initiating a struct for parametrs flags
 * @uni: for unsigned values
 * @plus: for plus flag
 * @space: spaces flag
 * @hash: if flag
 * @zero: zero flag
 * @min: if flag
 * @wid: width flag
 * @prec: precision flag
 * @h_mod: h modifier flag
 * @l_mod: l modifier flag
*/
typedef struct param
{
	unsigned int uni : 1;
	unsigned int plus : 1;
	unsigned int space : 1;
	unsigned int hash : 1;
	unsigned int zero : 1;
	unsigned int min : 1;
	unsigned int wid;
	unsigned int prec;
	unsigned int h_mod : 1;
	unsigned int l_mod : 1;
} params_t
/**
 * struct specific - struct specifier
 * @specifier: format
 * @f: the function
*/
typedef struct specific
{
	char *specifier;
	int (*f)(va_list, params_t *);
} specifier_t;
/* for put.c module */
int _puts(char *str);
int _putchar(int c);
int print_char(va_list ap, params_t *params);
int print_int(va_list ap, params_t *params);
int print_string(va_list ap, params_t *params);
int print_percent(va_list ap, params_t *params);
int print_S(va_list ap, params_t *params);
char *convert(long int num, int base, int flags, params_t *params);
int print_unsigned(va_list ap, params_t *params);
int print_address(va_list ap, params_t *params);
/* for specifier.c module */
int (*get_specifier(char *s))(va_list, params_t *params);
int get_print_func(char *s, va_list ap, params_t *params);
int get_flag(char *s, params_t *params);
int get modifier(char *s, params_t *params);
char *get_width(char *s, params_t *params, va_list ap);
/* for number.c module */
int print_hex(va_list ap, params_t *params);
int print_HEX(va_list ap, params_t *params);
int print_binary(va_list ap, params_t *params);
int print_octal(va_list ap, params_t *params);
/* for printers.c */
int print_from_to(char *start, char *stop, char *except);
int print_rev(va_list ap, params_t *params);
int print_rot13(va_list ap, params_t *params);
/*for number.c */
int _isdigit(int c);
int _strlen(char *s);
int print_number(char *str, params_t *params);
int print_number_right_shift(char *str, params_t *params);
int print_number_left_shift(char *str, params_t *params);
/*for params.c, printf.c and string_fields.c*/
void init_params(params_t *params, va_list ap);
char *get_precision(char *p, params_t *params, va_list ap);
int _printf(const char *format, ...);

#endif
