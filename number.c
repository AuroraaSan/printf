#include "main.h"
/**
 * convert - function converter
 * @num: number
 * @base: base
 * @flags: flags
 * @params: struct
 * Return: string
*/
char *convert(long int num, int base, int flags, params_t *params)
{
	static char *array;
	static char buffer[50];
	char sign = 0;
	char *ptr;
	unsigned long n = num;
	(void)params;

	if (!(flags & CONVERT_UNSIGNED) && num < 0)
	{
		n = -num;
		sign = '-';
	}
	array = flags & CONVERT_LOWERCASE ? "0123456789abcdef" : "0123456789ABCDEF";
	ptr = &buffer[49];
	*ptr = '\0';

	do {
		*--ptr = array[n % base];
		n /= base;
	} while (n != 0);
	if (sign)
	{
		*--ptr = sign;
	}
	return (ptr);
}
/**
 * print_unsigned - printing
 * @ap: pointer
 * @params: struct
 * Return: bytes
*/
int print_unsigned(va_list ap, params_t *params)
{
	if (params->l_mod)
	       	return (print_number(convert((unsigned long)va_arg(ap, unsigned long), 10, CONVERT_UNSIGNED, params), params));
	else if (params->h_mod)
		return (print_number(convert((unsigned short int)va_arg(ap, unsigned int), 10, CONVERT_UNSIGNED, params), params));
	else
		return (print_number(convert((unsigned int)va_arg(ap, unsigned int), 10, CONVERT_UNSIGNED, params), params));
}
/**
 * print_address - address
 * @ap:pointer
 * @params: struct
 * Return: bytes
*/
int print_address(va_list ap, params_t *params)
{
	unsigned long int n = va_arg(ap, unsigned long int);
	char *str;

	if (!n)
		return (_puts("(nill)"));
	str = convert(n, 16, CONVERT_UNSIGNED | CONVERT_LOWERCASE, params);
	*--str = 'x';
	*--str = '0';
	return (print_number(str, params));
}
