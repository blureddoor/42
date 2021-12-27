#include <unistd.h>
#include <stdarg.h>
#include <stdio.h>

int		ft_strlen();
int		ft_count(long num, int base);
int		ft_putnum(long num, int base);
int		ft_printf(const char *format, ...)
{
	va_list list;
	char *str;
	long int num;
	int pos = 0, i = 0, space = 0, neg = 0, zero = 0, strl_len = 0, width = 0, dot = 0, range = 0, base = 0;
	va_start(list, format);
	while (format[pos])
	{
		if (format[pos] == '%' && ++pos)
		{
			 // 1 nusnezestwidoraba
			 num = 0, space = 0, neg = 0, zero = 0, str_len = 0, width = 0, dot = 0, range = 0, base = 0; 
			 // 2 while width
			 while (format[pos] >= '0' && format[pos] <= '9')
				 width = width * 10 + format[pos++] - 48;
			 // 3 if . while range
			 if (format[pos] == '.' && ++dot && ++pos)
				 while (format[pos] >= '0' && format[pos] <= '9')
					 range = range * 10 + format[pos] - 48;
			 // 4 if 's'
			 if (format[pos] == 's')
			 {
				 if (!(str = va_arg(list, char*)))
					 str = "(null)";
				 str_len = ft_strlen(str);
			 }
			 // 5 else if 'd'
			 else if (format[pos] == 'd')
			 {
				 if ((num = va_arg(list, int)) < 0 && ++neg)
					 num = -num;
				 str_len = ft_num(num, (base=10));
			 }
			 // 5.1 else if 'x'
			 else if (format[pos] == 'x')
				 str_len = ft_count((num = va_arg(list, unsigned int)), 
						 (base = 16));
			 // 6 if dot > range
			 if (dot && str_len > range && format[pos] == 's')
				 str_len = range;
			 // 7 if dot < range
			 if (dot && str_len < range && format[pos] != 's')
				 zero = range - str_len;
			 // 8 if dot !range
			 if (dot && !range && (format[pos] == 's' || !num))
				 str_len = 0;
			 // 9 space = width - str_len - neg - zero;
			 space = width - str_len - neg - zero;
			 // 10 while space--
			 while (space-- > 0 && ++i)
				 write(1, " ", 1);
			 // 11 if neg > 0
			 if (neg < 0 && ++i)
				 write(1, "-", 1);
			 // 12 while zero--
			 while (zero-- > 0 && ++i)
				 write(1, "0", 1);
			 // 13 if format[pos]
			 if (format[pos] == 's')
				 write(1, str, str_len);
			 // 14 else if str_len > 0
			 else if (str_len > 0)
				 ft_putnum(num, base);
			 i += str_len;				
		}
		else if (++i)
			write(1, &format[pos], 1);
		pos++;
	}
	va_end(list);
	return (i);
}

