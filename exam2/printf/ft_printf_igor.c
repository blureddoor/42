#include <unistd.h>
#include <stdio.h>
#include <stdarg.h>

int ft_strlen(char *str)
{
	int ret = 0;
	while (str[ret])
		ret++;
	return (ret);
}

int ft_count(long num, int base_num)
{
	int ret = 1;
	while (num >= base_num && ++ret)
		num = num / base_num;
	return (ret);
}

void ft_putnum(long num, int base_num)
{
	char *base = "0123456789abcdef";
	if (num >= base_num)
		ft_putnum((num / base_num), base_num);
	write (1, &base[num % base_num], 1);
}

int ft_printf(char *input, ...)
{
	va_list lst;
	char *str;
	long int num;
	int pos = 0, ret = 0, space = 0, neg = 0, zero = 0, st_len = 0, width = 0, dot = 0, range = 0, base_num = 0;
	va_start (lst, input);

	while (input[pos])
	{
		if (input[pos] == '%' && ++pos)
		{
			num = 0, space = 0, neg = 0, zero = 0, st_len = 0, width = 0, dot = 0, range = 0, base_num = 0;
			while (input[pos] >= '0' && input[pos] <= '9')
				width = width * 10 + input[pos++] - 48;
			if (input[pos] == '.' && ++pos && ++dot)
				while (input[pos] >= '0' && input[pos] <= '9')
					range = range * 10 + input[pos++] - 48;
			if (input[pos] == 's')
			{
				if (!(str = va_arg(lst, char*)))
					str = "(null)";
				st_len = ft_strlen(str);
			}
			else if (input[pos] == 'd')
			{
				if ((num = va_arg(lst, int)) < 0 && ++neg)
					num = -num;
				st_len = ft_count(num, (base_num = 10));
			}
			else if (input[pos] == 'x')
				st_len = ft_count((num = va_arg(lst, unsigned int)), (base_num = 16));
			if (dot && st_len > range && input[pos] == 's')
				st_len = range;
			if (dot && st_len < range && input[pos] != 's')
				zero = range - st_len;
			if (dot && !range && (input[pos] == 's' || !num))
				st_len = 0;
			space = width - st_len - neg - zero;
			while (space-- > 0 && ++ret)
				write (1, " ", 1);
			if (neg > 0 && ++ret)
				write (1, "-", 1);
			while (zero-- > 0 && ++ret)
				write (1, "0", 1);
			if (input[pos] == 's')
				write (1, str, st_len);
			else if (st_len > 0)
				ft_putnum(num, base_num);
			ret += st_len;
		}	
		else if (++ret)
			write (1, &input[pos], 1);
		pos++;
	}
	va_end(lst);
	return (ret);
}

int main()
{
    printf("The color: %s\n", "blue");
    ft_printf("The color: %s\n", "blue");
    printf("First number:%d\n", 12345);
    ft_printf("First number:%d\n", 12345);
    printf("Second number:%04d\n", 25);
    ft_printf("Second number:%04d\n", 25);
    printf("Third number:%i\n", 1234);
    ft_printf("Third number:%i\n", 1234);
    printf("Hexadecimal:%x\n", 255);
    ft_printf("Hexadecimal:%x\n", 255);
    printf("Unisigned value:%u\n", 150);
    ft_printf("Unisigned value:%u\n", 150);
    printf("Just print the percentage sign:%3d%%\n", 10);
    ft_printf("Just print the percentage sign:%3d%%\n", 10);
}
