#include "main.h"
/**
 * get_specifier: finds the format
 * @s: string
 * Return: #bytes printed
*/
int (*get_specifier(char *s))(va_list ap, params_t *params)
{
	specifier_t specifiers[] = {
		{"c", print_char},
		{"d", print_int},
		{"i", print_int},
		{"s", print_string},
		{"%", print_percent},
		{"b", print_binary},
		{"o", print_octal},
		{"u", print_unsigned},
		{"x", print_hex},
		{"X", print_HEX},
		{"p", print_address},
		{"S", print_S},
		{"r", print_rev},
		{"R", print_rot13},
		{NULL, NULL}
	};
	int i = 0;

	while (specifiers[i].specifier)
	{
		if (*s == specfiers[i].specifier[0])
		{
			return (specifiers[i].f);
		}
		i++;
	}
	return (NULL);
}
/**
 * get_print_func - find the format func
 * @s: the format string
 * @ap: pointer
 * @params: struct
 * Return: number of bytes
 */
int get_print_func(char *s, va_list ap, params_t *params)
{
	int (*f)(va_list, params_t *) = get_specifier(s);

	if (f)
		return (f(ap, params));
	return (0);
}
/**
 * get_flag - finds the flag func
 * @s: format string
 * @params: struct
 * Return: valid or not flag
 */
int get_flag(char *s, params_t *params)
{
	int i = 0;
	switch (*s)
	{
		case '+':
			i = params->plus = 1;
			break;
		case ' ':
			i = params->space = 1;
			break;
		case '#':
			i = params->hash = 1;
			break;
		case '-':
			i = params->min = 1;
			break;
		case '0':
			i = params->zero = 1;
			break;
	}
	return (i);
}
/**
 * get_modifier - to get the modifier function
 * @s: format string
 * @params: struct
 * Return: the modifier valid or not
 */
int get_modifier(char *s, params_t *params)
{
	int i = 0;
	switch (*s)
	{
		case 'h':
			i = params->h_mod = 1;
			break;
		case 'l':
			i = params->l_mod = 1;
			break;
	}
	return (i);
}
/**
 * get_width - width of string
 * @s: string format
 * @params: struct
 * @ap: pointer
 * Return: pointer
*/
char *get_width(char *s, params_t *params, va_list ap)
{
	int d = 0;

	if (*s == '*')
	{
		d = va_arg(ap, int);
		s++;
	}
	else
	{
		while (_isdigit(*s))
			d = d * 10 + (*s++ - '0');
	}
	params->width = d;
	return (s);
}

