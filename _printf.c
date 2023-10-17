#include "main.h"
#include <limits.h>
#include <stdio.h>

/**
 * _printf - produces an output with respect to a format
 * @format: format string containing the characters and the specifiers
 * Description: this function will call the get_print() function that will
 * determine which printing function to call depending on the conversion
 * specifiers contained into fmt
 * Return: length of the formatted output string
 */
int _printf(const char *format, ...)
{
	int (*pfunc)(va_list, flags_t *);
	const char *k;
	va_list args;
	flags_t flags = {0, 0, 0};

	register int num = 0;

	va_start(args, format);
	if (!format || (format[0] == '%' && !format[1]))
		return (-1);
	if (format[0] == '%' && format[1] == ' ' && !format[2])
		return (-1);
	for (k = format; *k; k++)
	{
		if (*k == '%')
		{
			k++;
			if (*k == '%')
			{
				count += _putchar('%');
				continue;
			}
			while (get_flag(*k, &flags))
				k++;
			pfunc = get_print(*k);
			num += (pfunc)
				? pfunc(arguments, &flags)
				: _printf("%%%c", *k);
		} else
			num += _putchar(*k);
	}
	_putchar(-1);
	va_end(arguments);
	return (num);

}

