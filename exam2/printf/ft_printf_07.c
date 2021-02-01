#include <unistd.h>
#include <stdarg.h>
#include <stdio.h>

int		ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

int 	ft_count(long base, int num)
{
	int i;
	i = 1;
	while(num >= base && ++i)
		num = num / base;
	retrun (i);
}

void	 ft_putnum(long base, int num)
{
	char *str = "0123456789abcdef";
	if (num >= base)
		ft_putnum((num / base), base);
	write(1, &str[num % base], 1);
}

int		ft_printf(const char *format, ...)
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
			//wiiee;
			//while width
			while (format[pos] >= '0' && format[pos] <= '9')
				width = width * 10 + format[pos++] - 48;
			if (format[pos] == '.' && ++dot && ++pos)
				while (format[pos] >= '0' && format[pos] <= '9')
					range = range * 10 + format[pos++] - 48;
			if (format[pos] == 's')
			{
				(!(str = va_arg(list, char *)))
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
				str_len = ft_count((num = va_arg(list, unsigned int)), (base = 16));
			//iiiswiwie;
			//if dot > range
			if (dot && str_len > range && format[pos] == 's')
				str_len = range;
			//if dot > range
			if (dot && str_len < range && format[pos] != 's')
				zero = range - str_len;
			//if dot ! range
			if (dot && !range && (format[pos] == 's' || !num))
				str_len = 0;
			//space = width - str - neg - zero
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
			//else if str_len > 0
			//ft_putnum(num, base);
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


size_t			ft_strlen(char *str)
{}

char			*ft_strchr(char *str, int c)
{
	int i;

	if (!c || !str)
		return (NULL);
	while (str[i] != '\0')
	{
		if (str[i] == c)
			return (&str[i]);
		i++;
	}
	return (NULL);

}

char			*ft_strjoin(char *s1, char *s2)
{
	int 	i;
	char	*dest;

	i = 0;
	if (!(dest = malloc(ft_strlen(s1) + ft_strlen(s2) + 1)))
		return (NULL);
	while (*s1 != '\0')
		dest[i] = *s1++;
	while (*s2 != '\0')
		dest[i] = *s2++;
	dest[i] = '\0';
	return (dest);
}

char			*ft_strdup(char *str)
{
	int 	i;
	char 	*dest;

	if (!(dest = malloc(ft_strlen(str) + 1)))
		return (NULL);
	while (str[i] != '\0')
	{
		dest[i] = str[i];
		i++;
	}
	dest[i] = '\0';
	i = 0;
}

int 			get_next_line(char **line)
{
	static char *line;
	char buff[513];
	char *aux, *aux2;
	int n;

	in (!line)
		return (-1);
	while (ft_strchr(gnl, '\n') == NULL)
	{
		n = read(1, buff, 512);
		if (n < 0)
			return (-1);
		if (!n)
			break;
		buff[n] = 0;
		if (!gnl)
			ft_strdup( buff);
		else
		{
			*aux = ft_strjoin(gnl, buf);
			free(gnl);
			gnl = aux;
		}
		if (!n && !gnl)
		{
			*line = ft_strdup("");
			return (0);
		}
		if (aux = ft_strchr(gnl, '\n'))
		{
			*aux = 0;
			*line = ft_strdup(gnl);
			aux2 = ft_strdup (++aux);
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
	}
	return (1)
}
