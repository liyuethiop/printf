#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>
#include "main.h"

/**
 * _strrev - fr
 * @str:mk
 * Return: f
 */
char *_strrev(char *str)
{
	int i, len = 0;
	char c;

	if (!str)
		return (NULL);
	while (str[len] != '\0')
		len++;
	for (i = 0; i < (len / 2); i++)
	{
		c = str[i];
		str[i] = str[len - i - 1];
		str[len - i - 1] = c;
	}
	return (str);
}

/**
 * _itoa - fdf
 * @i:df
 * @strout:fdf
 * @base:fd
 * Return:w
 */

char *_itoa(int i, char *strout, int base)
{
	char *str = strout;
	int num, sign = 0;

	if (i < 0)
	{
		sign = 1;
		i *= -1;
	}
	while (i)
	{
		num = i % base;
		*str = (num > 9) ? ('A' + num - 10) : '0' + num;
		i = i / base;
		str++;
	}
	if (sign)
	{
		*str++ = '-';
	}
	*str = '\0';
	_strrev(strout);
	return (strout);
}

/**
 * _printf - dfsd
 * @format:fd
 * Return:fd
 */
int _printf(const char *format, ...)
{
	int i = 0, j = 0, k;
	char buf[100], ch[20];
	char *str;
	va_list ptr;

	va_start(ptr, format);

	while (format && format[i])
	{
		if (format[i] == '%')
		{
			i++;
			switch (format[i])
			{
				case 'c':
					{
						buf[j] = va_arg(ptr, int);
						j++;
						break;
					}
				case '%':
					{
						buf[j] = '%';
						j++;
						break;
					}
				case 's':
					{
						str = va_arg(ptr, char *);
						if (str == NULL)
							str = "(null)";
						strcpy(&buf[j], str);
						j += strlen(str);
						break;
					}
				case 'S':
					{
						str = va_arg(ptr, char *);
						if (str == NULL)
							str = "(null)";
						strcpy(&buf[j], str);
						j += strlen(str);
						break;
					}
				case 'd':
					{
						_itoa(va_arg(ptr, int), ch, 10);
						strcpy(&buf[j], ch);
						j += strlen(ch);
						break;
					}
				case 'i':
					{
						_itoa(va_arg(ptr, int), ch, 10);
						strcpy(&buf[j], ch);
						j += strlen(ch);
						break;
					}
				case 'o':
					{
						_itoa(va_arg(ptr, int), ch, 8);
						strcpy(&buf[j], ch);
						j += strlen(ch);
						break;
					}
				case 'x':
					{
						_itoa(va_arg(ptr, int), ch, 16);
						for (k = 0; ch[k] != '\0'; k++)
						{
							if (ch[k] >= 'A' && ch[k] <= 'Z')
									ch[k] += 32;
						}
						strcpy(&buf[j], ch);
						j += strlen(ch);
						break;
					}
				case 'X':
					{
						_itoa(va_arg(ptr, int), ch, 16);
						strcpy(&buf[j], ch);
						j += strlen(ch);
						break;
					}
				default:
					{
						if (format[i])
						{
							buf[j] = '%';
							j++;
							buf[j] = format[i];
							j++;
						}
					}
			}
		}
		else
		{
			buf[j] = format[i];
			j++;
		}
		format++;
	}
	fwrite(buf, j, 1, stdout);
	va_end(ptr);
	return (j);
}
