#include "main.h"
/**
 * handle_print - function prints the type of argument
 * @fmt: string formating
 * @list: List of arguments
 * @ind: ind pointer
 * @buffer: this is the buffer array
 * @flags: performs flag calculation
 * @width: the argument width
 * @precision: specifies precision
 * @size: specifies size
 * Return: char success
 */
int handle_print(const char *fmt, int *ind, va_list list, char buffer[],
	int flags, int width, int precision, int size)
{
	int m, unknow_len = 0, printed_chars = -1;
	fmt_t fmt_types[] = {
		{'c', print_char}, {'s', print_string}, {'%', print_percent},
		{'m', print_int}, {'d', print_int}, {'b', print_binary},
		{'u', print_unsigned}, {'o', print_octal}, {'x', print_hexadecimal},
		{'X', print_hexa_upper}, {'p', print_pointer}, {'S', print_non_printable},
		{'r', print_reverse}, {'R', print_rot13string}, {'\0', NULL}
	};
	for (m = 0; fmt_types[m].fmt != '\0'; m++)
		if (fmt[*ind] == fmt_types[i].fmt)
			return (fmt_types[m].fn(list, buffer, flags, width, precision, size));

	if (fmt_types[m].fmt == '\0')
	{
		if (fmt[*ind] == '\0')
			return (-1);
		unknow_len += write(1, "%%", 1);
		if (fmt[*ind - 1] == ' ')
			unknow_len += write(1, " ", 1);
		else if (width)
		{
			--(*ind);
			while (fmt[*ind] != ' ' && fmt[*ind] != '%')
				--(*ind);
			if (fmt[*ind] == ' ')
				--(*ind);
			return (1);
		}
		unknow_len += write(1, &fmt[*ind], 1);
		return (unknow_len);
	}
	return (printed_chars);
}
