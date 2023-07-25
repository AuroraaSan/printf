#include "main.h"
#include <stdarg.h>
#include <unistd.h> // For write function

#define BUF_SIZE 1024
/**
 * _putchar - print
 * @c: char
 * Return: bytes
*/

int _putchar(char c)
{
	static char buf[BUF_SIZE];
	static int index = 0;
	int bytes_written = 0;

	if (c == BUF_FLUSH || index >= BUF_SIZE - 1)
	{
		bytes_written = write(1, buf, index);
		index = 0;
	}

	if (c != BUF_FLUSH)
	{
		buf[index++] = c;
	}

	return bytes_written;
}
/**
 * _printf - print
 * @format: string
 * Return: bytes printed
*/
int _printf(const char *format, ...)
{
	int sum = 0;
	va_list ap;
	char *p, *start;
	params_t params = PARAMS_INIT;

	va_start(ap, format);

	if (!format || (format[0] == '%' && !format[1]))
		return (-1);
	if (format[0] == '%' && format[1] == ' ' && !format[2])
		return (-1);
	for (p = (char *)format; *p; p++)
	{
		init_params(&params, ap);
		if (*p != '%')
		{
			sum += _putchar (*p);
			continue;
		}
		start = p;
		p++;
		while (get_flag(p, &params))
		{
			p++;
		}
		p = get_width(p, &params, ap);
		p = get_precision(p, &params, ap);
		if (get_modifier(p, &params))
			p++;
		if (!get_specifier(p))
			sum += print_from_to(start, p, params.lmod || params.h_mod ? p - 1 : 0);
		else
			sum += get_print_func(p, ap, &params);
	}
	_putchar(BUF_FLUSH);
	va_end(ap);
	return (sum);
}
