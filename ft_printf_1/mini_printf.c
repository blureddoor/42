/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_printf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvintila <lvintila@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/04 19:14:49 by lvintila          #+#    #+#             */
/*   Updated: 2020/09/30 19:47:44 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"
#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>


/*int		ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}
*/
char	*ft_strdup(const char *s1)
{
	char	*new;
	size_t	i;

	if(!(new = malloc(sizeof(char) * ft_strlen(s1) + 1)))
		return (NULL);
	i = 0;
	while (s1[i])
	{
		new[i] = s1[i];
		i++;
	}
	new[i] = '\0';
	return (new);
}

char    *ft_strjoin(char const *s1, char const *s2)
{
    char    *join;
    size_t  index_count;

    index_count = 0;
    if (!s1)
        return (NULL);
    if (!(join = (char*)malloc(sizeof(char) * ((ft_strlen(s1) +
                            ft_strlen(s2)) + 1))))
        return (NULL);
    while (*s1 != '\0')
    {
        *join = *s1;
        join++;
        s1++;
        index_count++;
    }
    while (*s2 != 0)
    {
        *join = *s2;
        join++;
        s2++;
        index_count++;
    }
    *join = '\0';
    return (join - index_count);
}
/*
char    *ft_itoa_base(long int n, char *base)
{
    int             	count;
    unsigned int	    tmp;
    char            	*res;
    unsigned int    	base_len;

    base_len = ft_strlen(base);
    count = (n < 0) ? 2 : 1;
    tmp = (n < 0) ? -n : n;
    while (tmp >= base_len && (tmp /= base_len))
        ++count;
    tmp = (n < 0) ? -n : n;
    if (!(res = (char*)malloc(sizeof(char) * (count + 1))))
        return (NULL);
    if (n < 0)
        res[0] = '-';
    res[count] = '\0';
    while (tmp >= base_len)
    {
        --count;
        res[count] = base[tmp % base_len];
        tmp /= base_len;
    }
    res[--count] = base[tmp % base_len];
    return (res);
}


void   *ft_ultoa_base(unsigned long long n, char *base)
{
    int					count;
    unsigned long long	tmp;
    char				*res;
    unsigned long long	base_len;

    base_len = ft_strlen(base);
    count = 1;
	tmp = n;
    while (tmp >= base_len && (tmp /= base_len))
        ++count;
	tmp = n;
    if (!(res = (char*)malloc(sizeof(char) * (count + 1))))
        return (NULL);
    res[count] = '\0';
    while (tmp >= base_len)
    {
        --count;
        res[count] = base[tmp % base_len];
        tmp /= base_len;
    }
    res[--count] = base[tmp % base_len];
    return (res);
}
*/
typedef enum
{
	P1 = 10,
	P2 = 100,
	P3 = 1000,
	P4 = 10000,
	P5 = 100000,
	P6 = 1000000,
}t_precision;
/*
void	put_long(long lg)
{
	if (lg < 0)
	{
		putchar('-');
		lg = -lg;
	}
	if (lg >= 10)
	{
		put_long(lg / 10);
	}
	putchar(lg % 10 + '0');
}

void	put_float(float f, t_precision p)
{
	long i;

	i = (long)f;
	put_long(i);
	f = (f - i) * p;
	i = labs((long)f);
	if (fabs(f) - i >= 0.5f)
		i++;
	putchar('.');
	put_long(i);
}
*/

void	my_printf_str(va_list *my_list)
{
	char	*src;

	src = va_arg(*my_list, char *);
	write(1, src, ft_strlen(src));
}

void	my_printf_char(va_list *my_list)
{
	unsigned char	c;
	int				num;
	
	num = 0;
	c = (unsigned char)va_arg(*my_list, int);
	if (f->width && f->minus == 0)
	{
		num = f->width - 1;
		if (f->zero != 0)
			write_zeros(num);
	}
	write(1, &c, 1);
}

void	ft_putnbr(int nb)
{
	int		y;
	long	z;

	z = nb;
	if (z < 0)
	{
		z *= -1;
		write(1, "-", 1);
		if (z >= 10)
			ft_putnbr(z / 10);
		y = z % 10 + '0';
		write(1, &y, 1);
	}
	else
	{
		if (z >= 10)
			ft_putnbr(z / 10);
		y = z % 10 + '0';
		write(1, &y, 1);
	}
}

void    ft_putnbr_ui(unsigned int nb)
{
    unsigned int     y;
    unsigned long    z;

    z = nb;
 
   	if (z >= 10)
		ft_putnbr(z / 10);
	y = z % 10 + '0';
	write(1, &y, 1);
}

void	my_printf_nbr(va_list *my_list)
{
	int num;

	num = va_arg(*my_list, int);
	ft_putnbr(num);
}

void	my_printf_p(va_list *my_list)
{
	char	*base;
/*	char	*str;
	char	*fix;
	char	*new;*/
	char	*res;
	unsigned long long p;

	p = (unsigned long long)va_arg(*my_list, void *);
	base = "0123456789abcdef";
	res = ft_ultoa_base(p, base);
/*	str = ft_strdup("");
	str = ft_strdup(res);
	fix = ft_strdup("");
	fix = ft_strdup("0x");
	new = ft_strjoin(fix, str);*/
	write(1, "0x", 2);
	write(1, res, ft_strlen(res));
	free (res);
}

void	my_printf_u(va_list *my_list)
{
	unsigned int ui;

	ui = va_arg(*my_list, unsigned int);
	ft_putnbr_ui(ui);
}

void	my_printf_hex(va_list *my_list)
{
	char			*base;
/*	char			*str;*/
	char			*hex;
	long int		li;

/*	li = va_arg(*my_list, long int);
	base = "0123456789abcdef";
	hex = ft_itoa_base(li, base);
	str = ft_strdup("");
	str = ft_strdup(hex);
	write(1, hex, ft_strlen(hex));*/
	li = va_arg(*my_list, long int);
	base = "0123456789abcdef";
	hex = ft_itoa_base(li, base);
	write(1, hex, ft_strlen(hex));
	free (hex);
}

void	my_printf_uhex(va_list *my_list)
{
	char			*base;
/*	char			*str;*/
	char			*hex;
	unsigned int				ll;

	ll = va_arg(*my_list, unsigned int);
	base = "0123456789ABCDEF";
	hex = ft_itoa_base(ll, base);
/*	str = ft_strdup("");
	str = ft_strdup(hex);*/
	write(1, hex, ft_strlen(hex));
	free (hex);
}

/*
void	my_printf_float(va_list *my_list)
{
	double fl;

	fl = va_arg(*my_list, double);
	put_float(fl, P6);
}
*/
int	find_index(char *arr, char element)
{
	int	index;

	index = 0;
	while (arr[index] != 0)
	{
		if (arr[index] == element)
			return (index);
		index++;
	}
	return (-1);
}

int	my_printf(const char *src, ...)
{



	void	(*tab_function[8]) (va_list *) = {my_printf_char, my_printf_str,
		my_printf_p, my_printf_nbr, my_printf_nbr, my_printf_u, my_printf_hex,
		my_printf_uhex};

	char			tab_index[9] = {'c', 's', 'p', 'd', 'i', 'u', 'x', 'X', 0};
	va_list 		ap;
	int 			i;
	int				tmp_index;
/*	t_struct		*s;*/
	int				format_len;

	i = 0;
	va_start(ap, src);
	while (src[i] != 0)
	{
		if (i != 0 && src[i - 1] == '%')
		{
			tmp_index = 0;
			tmp_index = find_index(tab_index, src[i]);
			if (tmp_index != -1)
				(*tab_function[tmp_index])(&ap);
		}
		else if (src[i] != '%')
			write(1, &src[i], 1);
		else if (src[i + 1] == '%')
			write(1, &src[i + 1], 1);
		i++;
	}
	return (ft_strlen(src));
}

/*int	main(void)

{
	int *ptr;
	int a;
	char *str;

	ptr = &a;
	str = "	ABC D587-ghettyo";

	my_printf("string:%s\n", "-&¬Leo");
	printf("string:%s\n", "-&¬Leo");
	my_printf("int:%i\n", 32);
	printf("int:%i\n", 32);
	my_printf("decimal:%d\n", -2147847);
	printf("decimal:%d\n", -2147847);
	printf("decimal:%d\n", 2147847);
	my_printf("decimal:%d\n", 2147847);
	my_printf("character:%c\n", 'k');
	printf("character:%c\n", 'k');
	my_printf("puntero a int:%p\n", ptr);
	printf("puntero a int:%p\n", ptr);
	my_printf("puntero a str:%p\n", str);
	printf("puntero a str:%p\n", str);
	my_printf("Unsigned value:%u\n", 1250);
	printf("Unsigned value:%u\n", 1250);
	my_printf("Unsigned value:%u\n", -1250);
	printf("Unsigned value:%u\n", -1250);
	my_printf("hexadecimal:%x\n", 529496730);
	printf("hexadecimal:%x\n", 529496730);
	my_printf("hexadecimal:%x\n", -529496730);
	printf("hexadecimal:%x\n", -529496730);
	my_printf("unsigned hexadecimal:%X\n", 34387584);
	printf("unsigned hexadecimal:%X\n", 34387584);
	my_printf("unsigned hexadecimal:%X\n", -34387584);
	printf("unsigned hexadecimal:%X\n", -34387584);
	my_printf("Just print the percentage sign:%%\n\n");
	printf("Just print the percentage sign:%%\n");
	my_printf("%d", ft_strlen(str));
}
*/

/*
int main (void) 
{
	int ch;
	
	for(ch = 33;ch <= 127;ch++)
	{
		printf("ASCII value = %d, Character = %c\n", ch , ch );
		my_printf("ASCII value = %d, Character = %c\n", ch , ch );
	}
	return(0);
}
*/

/*
int main()
{
	my_printf(":%s:\n", "Hello World!");
	printf(":%s:\n", "Hello World!");
	my_printf(":%15s:\n", "Hello World!");
	printf(":%15s:\n", "Hello World!");
	my_printf(":%.10s:\n", "Hello World!");
	printf(":%.10s:\n", "Hello World!");
	my_printf(":%-10s:\n", "HWorld!");
	printf(":%-10s:\n", "HWorld!");
	my_printf(":%-15s:\n", "Hello World!");
	printf(":%-15s:\n", "Hello World!");
	my_printf(":%.15s:\n", "Hello World!");
	printf(":%.15s:\n", "Hello World!");
	my_printf(":%15.10s:\n", "Hello World!");
	printf(":%15.10s:\n", "Hello World!");
	my_printf(":%-15.10s:\n", "Hello World!");
	printf(":%-15.10s:\n", "Hello World!");
}
*/

