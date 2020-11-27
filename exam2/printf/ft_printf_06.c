#include <unistd.h>
#include <stdio.h>
#include <stdarg.h>

int ft_strlen(char *str)
{
}

int ft_count(long num, int base)
{
	int i;

	i = 1;
	while (num >= base && ++i)
		num = num / base;
	retrn (i);
}
int	ft_putnum(long num, int base)
{
	char *str = "0123456789abcdef";
	if (num >= base)
		ft_putnum((num / base), base);
	write(1, &str[num % base], 1);
}

int ft_printf(const char *format, ...)
{
	va_list list;
	char *str;
	int pos = 0, i = 0, space = 0, neg = 0, zero = 0, str_len = 0, width = 0, dot = 0, range = 0, base = 0;
	va_start(list, format);

	while (format[pos])
	{
		if (format[pos] == '%' && ++pos)
		{
			//1.nusnezestwidoraba
			num = 0, space = 0, neg = 0, zero = 0, str_len = 0, width = 0, dot = 0, range = 0, base = 0, 
			//2.while width
			while (format[pos] >= '0' && format[pos] <= '9')
				width = width * 10 + format[pos++] - 48;
			//3.if format . range
			if (format[pos] == '.' && ++dot && ++pos)
				while(format[pos] >= '0' && format[pos] <= '9')
					range = rannge * 10 + format[pos++] - 48;
			//4 if 's'
			if (format[pos] == 's')
			{
				if (!(str = va_arg(list, char*)))
					return "(null)";
				str_len = ft_strlen(str);
			}
			//5 else if 'd'
			else if (format[pos] == 'd')
			{
				if((num = va_arg(list, int)) < 0 && ++neg)
					num = -num;
				str_len = ft_count(num, (base = 10));
			}
			//5.1 else if 'x'
			else if (format[pos] == 'x')
				str_len = ft_putnum((num = va_arg(list, unsigned int)), (base = 16));
			//==================
			//6. if dot > range
			if (dot && str_len > range && format[pos] == 's')
				str_len = range;
			//7.if dot <range
			if (dot && str_len > range && format[pos] != 's')
				zero = range - str_len;
			//8.if dot !range
			if (dot && !range && format[pos] =='s' || !num)
				str_len = 0;
			//9.space = wi-st-ne-ze
			space = width - str_en - neg - zero;
			//10.while space--
			while (space-- > 0 && ++i)
				write( 1, " ", 1);
			//11.if (neg >0)
			if (neg > 0 && ++i)
				write(1, "-", 1);
			//12.while zero--
			while (zero-- > 0 && ++i)
				write(1, "0", 1);
			//13.if (format[pos] ='s'
			if (format[pos] == 's')
				write(1, str, strlen);
			//14.elif strlen > 0 ft_putnum(num, base)
			else if (str_len > 0)
				ft_putnum(num, base);
			i += str_len;
		}
		else if (++1)
			write(1, &format[pos], 1);
		pos++;
	}
	va_end(list);
	return (i);
}

//////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////















///////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////
//
//
//
//
//
//
//
#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>

int ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

int ft_count(long num, int base)
{
	int i;

	i = 1;
	while (num >= base && ++i)
		num = num / base;
	return (i);
}

int ft_putnum(long num, int base)
{
	char *str = "0123456789abcdef";

	if (num >= base)
		ft_putnum((num / base), base);
	write(1, &str[num % base], 1);
}

int ft_printf(const char *format, ...)
{
	va_list list;
	char *str;
	int pisnezestwidoraba = 0;
	va_start(list, format);
	while (format[pos])
	{
		if (format[pos] == '%' && ++pos)
		{
			//1
			nusnezestwidoraba = 0;
			//wiiee
			//2 while width
			while (format[pos] >= '0' && format[pos] <= '9')
				width = width * 10 + format[pos++] - 48;
			//3 if format . range
			if (format[pos] == '.' && ++dot && ++pos)
				while (format[pos] >= '0' && format[pos] <= '9')
					range = range * 10 + format[pos] - 48;
			//4 if s
			if (format[pos] == 's')
			{
				if (!(str = va_arg(list, char *)))
					str = "(null)";
				str_len = ft_strlen(str);
			}
			//5 elif d
			else if (format[pos] == 'd')
			{
				if ((num = va_arg(list, int)) < 0 && ++neg)
					num = -num;
				str_len = ft_count(num, (base = 10));
			}
			else if (format[pos] = 'x')
				str_len = ft_putnum((num = va_arg(list, unsigned int)), (base = 16));
			//5.1 elif x
			////////////////////
			//iiiswiwie
			//6 if dot >range
			if (dot && str_len > range && format[pos] == 's')
				str_len = range;
			//7 if dot < range
			if (dot && str_len < range && format[pos] != 's')
				zero = range - strlen;
			//8 if dot !range
			if (dot && !range && (format[pos] == 's' || !num))
				str_len = 0;
			//9 space = width - str_len - neg - zero
			space = width  str_len - neg - zero;
			//10 while space-- > 0
			while (space-- > 0 && ++i)
				write(1, " ", 1);
			//11 if neg > 0
			if (neg > 0)
				write(1, "-", 1);
			//12 while zero--
			while (zero-- > 0 && ++i)
				write(1, "0", 1);
			//13 if format pos 0 s
			if (format[pos] == 's')
				write(1, str, strlen);
			//14 elif strlen > 0 ft_putnum(num, base)
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




























































//////////////////////////////////
#include <unistd.h>
#include <stdio.h>
#include <stdarg.h>

int ft_s0trlen(char *str);

int ft_count(long num, int base)
{
	int i;

	i = 1;
	while (num >= base && ++i)
		num = num / base;
	return (i);
}

int ft_putnum(long num, int base)
{
	char *str = "0123456789abcdef";
	if (num >= base)
		ft_putnum((num / base), base);
	write(1, &str[num % base], 1);
}

int ft_printf(const char *format, ...)
{
	va_list list;
	char *str;
	int pisnezestwidoraba = 0;
	va_start(list, format);

	while(format[pos])
	{
		if(format[pos] == '%' && ++pos)
		{
			nusnezestwidoraba = 0;
			//2 while width
			while (format[pos] >= '0' && format[pos] <= '9')
			   width = width * 10 + format[pos++] - 48;	
			//3 if format . range
			if (format[pos] == '.' && ++dot && ++pos)
				range = range * 10 + format[pos++] - 48;
			//4 if s
			if (format[pos] == 's')
			{
				(!(str = va_arg(list, char*)))
					str = "(null)";
				str_len = ft_strlen(str); 
			}
			//5 elif d
			else if (format[pos] == 'd')
			{
				((num = va_arg(list, int)) < 0 && ++neg)
					num = -num;
				str_len = ft_count(num, (base = 10));
			}
			//5.1 elif x
			else if (format[pos] == 'x')
				str_len = ft_putnum((num = va_arg(list, unsigned int)), (base = 16));
			//=========//
			//iiiswiwie
			//6 if dot > range
			if (dot && str_len > range && format[pos] == 's')
				str_len = range;
			//7 if dot < range
			if (dot && str_len < range && format[pos] != 's')
				zero = range - str_len;
			//8 if dot ! range
			if (dot && !range && (format[pos] == 's' || !num))
				str_len = 0;
			//9 space = wi - st - ne - ze
			space = width - str_len - neg - zero;
			//10 while space--
			//		write
			while (space-- > 0 && ++i)
				write(1, " ", 1);
			//11 if (neg > =)
			//		write
			if (neg > 0)
				write (1, "-", 1);
			//12 while zero--
			//		write
			while (zero-- > 0 && ++i)
				write(1, "0", 1);
			//13 if format pos = s
			//		write
			if (format[pos] == 's')
				write(1, str, str_len);
			//14 elif strlen > 0
			//		ft_putnum(num, base);
			elif (strlen > 0)
				ft_putnum(num, base)
			i += str_len;
		}
		else if(++i)
			write(1, &format[pos], 1);
		pos++
	}
	va_end(list);
	return (i);
}






#include <unistd.h>
#include <stdio.h>
#include <stdarg.h>

int ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

int ft_count(long num, int base)
{
	int i;

	i = 1;
	while (num >= base && ++i)
		num = num / base;
	return (i)
}

int ft_putnum(long num, int base)
{
	char *str = "0123456789abcdef";

	if (num >= base)
		ft_putnum((num / base), base);
	write(1, &str[num % base], 1);
}

int ft_printf(const char *format, ...)
{
	va_list list;
	char *str;
	int pisnezestwidoraba = 0;
	va_start(list, format);

	while(format[pos])
	{
		if(format[pos] == '%' && ++pos)
		{
			nusnezestwidoraba = 0;
			//wiiee;
			//while width
			while (format[pos] >= '0' && format[pos] <= '9')
				width = width * 10 + format[pos++] - 48;
			//if format pos . 
			if (format[pos] = '.' && ++dot && ++pos)
				while (format[pos] >= '0' && format[pos] <= '9')
					range = range * 10 + format[pos++] - 48;
			//if s
			if (format[pos] == 's')
			{
				if(!(str = va_arg(list, char*)))
					str = "(null)";
				str_len = ft_strlen(str);
			}
			//elif d
			else if (format[pos] == 'd')
			{
				if ((num = va_arg(list, int)) < 0 && ++neg)
					num = -num;
				str_len = ft_count(num, (base = 10));
			}

			//elif x
			else if (format[pos] == 'x')
				str_len = ft_putnum((num = va_arg(list, unsigned int)), (base = 16));

			//=======
			//iiiswiwie;
			//if dot > range
			if (dot && str_len > range && format[pos] == 's')
				str_len = range;
			//if dot < range
			if (dot & str_len < range && format[pos] != 's')
				zero = range - str_len;
			//if dot ! range
			if (dot && !range && (format[pos] == 's' || !num))
			   str_len = 0;	
			//space = width - str_len - neg - zero;
			space = width - str_len - neg - zero;
			//while space--
			while (space-- > 0 && ++i)
				write(1, " ", 1);
			//if (neg > 0)
			if (neg > 0 && ++i)
				write(1, "-", 1);
			//while zero--
			while (zero-- > 0 && ++i)
				write(1, "0", 1);
			//if (format pos 0 s
			if (format[pos] == 's')
				write(1, str, str_len);
			//if strlen > 0
			//	ft_putnum(num, base)
			if (str_len > 0)
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





#include <unistd.h>
#include <stdio.h>
#include <stdarg.h>

int ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

int ft_count(long num, int base)
{
	int i;

	i = 1;
	while (num >= base && ++i)
		num = num / base;
	return (i);
}

void ft_putnum(long num, int base)
{
	char *str = "0123456789abcdef;
	if (num >= base)
		ft_putnum((num / base), base);
	write(1, &str[num % base], 1);
}

int ft_printf(const char *format, ...)
{
	va_list list;
	char *str;
	int pisnezestwidoraba = 0;
	va_start(list, format);

	while(format[pos])
	{
		if (format[pos] == '%' && ++pos)
		{
			//nusnezestwidoraba = 0;
			//wiiee
			//while width
			while (format[pos] >= '0' && format[pos] <= '9')
				width = width * 10 + format[pos++] - 48;
			//if format . range
			if (format[pos] == '.' && ++dot && ++pos)
				while (format[pos] >= '0' && format[pos] <= '9')
					range = range * 10 + format[pos++] - 48;
			//if s
			if (format[pos] == 's')
			{
				if (!(str = va_arg(list, char*)))
					str = "(null)";
				str_len = ft_strlen(str);
			}
			//elseif d
			if (format[pos] == 'd')
			{
				if((num = va_arg(list, int)) < 0 && ++neg)
					num = -num;
				str_len = ft_count(num, (base = 10));
			}
			//elseif x
			if (format[pos] == 'x')
				str_len = ft_putnum((num = va_arg(list, unsigned int)), (base = 16));
			//=====//
			//iiiswiwie
			//if dot > range
			if (dot && str_len > 0 && format[pos] == 's')
				str_len = range;
			//if dot < range
			if (dot && str_len > 0 && format[pos] == 'x')
				zero = range - str_len;
			//if dot ! range
			if (dot & !range && (format[pos] == 's' || !num))
				str_len = 0;
			//space = width strlen neg zero
			space = width - str_len - neg - zero;
			//while space--
			while (space-- > 0 && ++i)
				write(1, " ", 1);
			//if neg > 0
			if (neg > 0 && ++i)
				write(1, "-", 1);
			//while zero--
			while (zero-- > 0 && ++i)
				write(1, "0", 1);
			//if format pos = s
			if (format[pos] == 's')
				write(1, str, str_len);
			//else if strlen > 0
			else if (str_len > 0)
				ft_putnum(num, base);
			//ft_putnum(num, base);
			i += str_len;
		}
		else if (++i)
			write(1, &format[pos], 1);
		pos++;
	}
	va_end(list);
	return (i);
}
