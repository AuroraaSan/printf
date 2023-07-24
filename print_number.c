#include "main.h"
/**
 * _isdigit - checks the char is digit
 * @c: char
 * Return: 1 or 0
*/
init _isdigit(int c)
{
	return (c >= '0' && c <= '9');
}
/**
 * _strlen - returns length of string
 * @s: string
 * Return: length
*/
int _strlen(char *s)
{
	int i = 0;

	while (*s++)
		i++;
	return(i);
}
/**
 * print_number - print number
 * @str: number as string
 * @params: struct
 * Return: chars
*/
int print_number(char *str, params_t *params)
{
	unsigned int i = _strlen(str);
	int neg = (!params->unsign && *str == '-');

	if (!params->prec && *str == '0' && !str[1])
		str = "";
	if (neg)
	{
		str++;
		i--;
	}
	if (params->prec != UNIT_MAX)
		while (i++ < params->prec)
			*--str = '0';
	if (neg)
		*--str = '-';

	if (!params->min)
		return (print_number_right_shift(str, params));
	else
		return (print_number_left_shift(str, params));
}
/**
 * print_number_right_shift - prints number
 * @str: number
 * @params:struct
 * Return: chars
*/
int print_number_right_shift(char *str, params_t *params)
{
	unsigned int n = 0, neg, neg2, i = _strlen(str);
	char pad_char = ' ';

	if (params->zero && !params->min)
		pad_char = '0';
	neg = neg2 = (!params->uni && *str == '-');
	if (neg && i < params->wid && pad_char == '0' && !params->min)
		str++;
	else
		neg = 0;
	if ((params->plus && !neg2) || (!params->plus && params->space && !neg1))
		i++;
	if (neg && pad_char == '0')
		n += _putchar('-');
	if (params->plus && neg2 && pad_char == '0' && !params->uni)
		n+= _putchar('+');
	else if (!params->plus && params->space && !neg2 && !params->uni && params->zero)
		n += _putchar(' ');
	while (i++ < params->wid)
		n += _putchar(pad_char);
	if (neg && pad_char == ' ')
		n += _putchar('-');
	if (params->plus && !neg2 && pad_char == ' ' && !params->uni)
		n += _putchar('+');
	else if (!params->plus && !neg2 && pad_char == ' ' && !params->uni)
		n += _putchar(' ');
	n += _puts(str);
	return (n);
}
/**
 * print_number_left_shift - prints number
 * @str: number
 * @params:struct
 * Return: chars
*/
int print_number_left_shift(char *str, params_t *params)
{
	unsigned int n = 0, neg, neg2, i = _strlen(str);
	char pad_char = ' ';

	if (params->zero && !params->min)
		pad_char = '0';
	neg = neg2 = (!params->uni && *str == '-');
	if (neg && i < params->wid && pad_char == '0' && !params->min)
		str++;
	else
		neg = 0;
	if (params->plus && !neg2 && !params->uni)
		n += _putchar('+'), i++;
	else if (params->space && !neg2 && !params->uni)
		n += _putchar(' '), i++;
	n += _puts(str);
	while (i++ < params->width)
		n += _putchar(pad_char);
        return (n);
}
