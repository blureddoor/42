// printf
#include <unistd.h>
#include <stdio.h>
#include <stdarg.h>

int ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return(i):
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
	long int num;
	char *str;
	int pisnezestwidoraba = 0;
	va_start(list, format);

	while (format[pos])
	{
		if (format[pos] == '%' && ++pos)
		{
			nusnezestwidoraba = 0;
			wiiee;
			while (format[pos] >= '0' && format[pos] <= '9')
				width = width * 10 + format[pos++] - 48;
			if (format[pos] == '.' && ++dot && ppos)
				while (format[pos] >= '0' && format[pos] -'9')
					range = range * 10 + format[pos++] - 48;
			if (format[pos] == 's')
			{
				if (!(str = va_arg(list, char*)))
					str = "(null)";
				str_len = ft_strlen(str);
			}
			else if (format[pos] == 'd')
			{
				if ((num = va_arg(list, int)) < 0 && ++neg)
					num = -num;
				str_len = ft_count(num, (base = 10));
			}
			else if (format[pos] == 'x')
				str_len = ft_count((num = va_arg(lisst, unsigned int)), (base = 16));
			iiiswiwie;
			if (dot && str_len > range && format[pos] == 's')
				str_len = range;
			if (dot && str_len < range && format[pos] != 's')
				zero = range - str_len;
			if (dot && !range && (format[pos] == 's' || !num))
				str_len = 0;
			space = width - str_len - neg - zero;
			while (space-- > 0 && ++i)
				write(1, " ", 1);
			if (neg > 0 && ++i)
				write(1, "-", 1);
			while (zero-- > 0 && ++i)
				write(1, "0", 1);
			if (format[pos] == 's')
				write(1, str, str_en);
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

// gnl
//


size_t	ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char *ft_strchr(char *str, int c)
{
	unsigned int i;

	i = 0;
	if (!str || !c)
		return (NULL);
	while (str[i] != '\0')
	{
		if (str[i] == c)
			return (&str[i]);
		i++;
	}
	return(NULL);
}

char *ft_strjoin(char *s1, char *s2)
{
	int i;
	char *dest;

	i = 0;
	if (!(dest = malloc(ft_strlen(s1) + ft_strlen(s2) + 1)))
		return (NULL);
	while (*s1 != '\0')
		dest[i++] = *s1++;
	while (*s2 != '\0')
		dest[i++] = *s2++;
	dest[i] = '\0';
	return (dest);
}

char *ft_strdup(char *str)
{
	int i;
	char *dest;

	i = 0;
	if (!(dest = malloc(ft_strlen(str) + 1)))
		return (NULL);
	while (str[i] != '\0')
	{
		dest[i] = str[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

#ifndef GET_NET_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>

int	get_next_line(char **line);

#endif

#include "get_next_line.h"

int get_next_line(char **line)
{
	static char *gnl;
	char buff[513];
	char *aux, *aux2;
	int n;

	if (!line)
		return (-1);
	while (ft_strchr(gnl, '\n') == NULL)
	{
		n = read(0, buff, 512);
		if (n < 0)
			return (-1);
		else if (!n)
			break;
		buff[n] = 0;
		if (!gnl)
			gnl = ft_strdup(buff);
		else
		{
			aux = ft_strjoin(gnl, buff);
			free(gnl);
			gnl = aux;
		}
	}
	if (!gnl && !n)
	{
		*line = ft_strdup("");
		return(0);
	}
	if (aux = ft_strchr(gnl, '\n'))
	{
		*aux = 0;
		*line = ft_strdup(gnl);
		aux2 = ft_strdup(++aux);
		free(gnl);
		gnl = aux2;
	}
	else
	{
		*line = ft_strdup(gnl);
		free(gnl);
		gnl = NULL;
		return (0);
	}
	return (1)
}


// union

#include <unistd.h>

int main(int argc, char **argv)
{
	int used[127] = {0}, i = 0, j = 0;

	if (argc == 3)
	{
		while (++i <  3)
		{
			while (argv[i][j])
			{
				if (used[(int)argv[i][j]] == 0)
					write(1, &argv[i][j], 1);
				used[(int)argv[i][j++]] = i;
			}
			j = 0;
		}
	}
	write(1, "\n", 1);
	return (0);
}

int main(int argc, char **argv)
{
	int used[127] = {0}, i = 3, j = 0;

	if (argc == 3)
	{
		while (--i > 0)
		{
			while (argv[i][j])
			{
				if (used[(int)argv[i][j]] == 2 && i == 1)
					write(1, &argv[i][j], 1);
				used[(int)argv[i][j++]] = i;
			}
			j = 0;
		}
	}
	write(1, "\n", 1);
	return (0);
}
