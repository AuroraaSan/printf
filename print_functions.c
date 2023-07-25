#include "main.h"
/**
 * print_char - print char
 * @ap: pointer
 * @params: struct
 * Return: bytes
*/
int print_char(va_list ap, params_t *params)
{
	char pad_char = ' ';
	unsigned int pad = 1, sum = 0, ch = va_arg(ap, int);

	if (params->minus_flag)
		sum += _putchar(ch);
	while (pad++ < params->wid)
		sum += _putchar(pad_char);
	if (!params->min)
		sum += _putchar(ch);
	return (sum);
}
/**
 * print_int - print int
 * @ap: pointer
 * @params: struct
 * Return: bytes
*/
int print_int(va_list ap, params_t *params)
{
	long l;

	if (params->l_mod)
		l = va_arg(ap, long);
	else if (params->h_mod)
		l = (short int)va_arg(ap, int);
	else
		l = (int)va_arg(ap, int);
	return (print_number(convert(1, 10, 0, params), params));
}
/**
 * print_string - print string
 * @ap: pointer
 * @params: struct
 * Return: bytes
*/
int print_string(va_list ap, params_t *params)
{
	char *str = va_arg(ap, char *), pad_char = ' ';
	unsigned int pad = 0, sum = 0, i = 0, j;

	(void)params;
	switch ((int)(!str))
		case 1:
			str = NULL_STRING;
	j = pad = _strlen(str);
	if (params->prec < pad)
		j = pad = params->prec;
	if (params->min)
	{
		if (params->prec != UNIT_MAX)
			for (i = 0; i < pad; i++)
				sum += _putchar(*str++);
		else
			sum += _puts(str);
	}
	while (j++ < params->wid)
		sum += _putchar(pad_char);
	if (!params->min)
	{
		if (params->prec != UNIT_MAX)
			for (i = 0; i < pad; i++)
				sum += _putchar(*str++);
		else
			sum += _puts(str);
	}
	return (sum);
}
/**
 * print_percent - print str
 * @ap: pointer
 * @params: struct
 * Retrun: str
*/
int print_percent(va_list ap, params_t *params)
{
	(void)ap;
	(void)params;
	return (_putchar('%'));
}
/**
 * print_S - specifier
 * @ap: pointer
 * @params: struct
 * Return: chars
*/
int print_S(va_list ap, params_t *params)
{
	char *str = va_arg(ap, char *);
	char *hex;
	int sum = 0;

	if ((int)(!str))
		return (_puts(NULL_STRING));
	for (; *str; str++)
	{
		if ((*str > 0 && *str < 32) || *str >= 127)
		{
			sum += _putchar('\\');
			sum += _putchar('x');
			hex = convert(*str, 16, 0, params);
			if (!hex[1])
				sum += _putchar('0');
			sum += _puts(hex);
		}
		else
			sum += _putchar(*str);
	}
	return (sum);
}
