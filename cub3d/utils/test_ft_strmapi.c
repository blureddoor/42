#include "../raycasting/printf/libft/libft.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

void	ft_change(char *c)
{
	ft_putendl_fd(c, 1);
}

void	ft_change2(unsigned int i, char *c)
{
	ft_putnbr_fd(i, 1);
	ft_putchar_fd(' ', 1);
	ft_putendl_fd(&c[i], 1);
}
char	ft_change3(char c)
{
	c = c + 1;
	return (c);
}

char	ft_change4(unsigned int i, char c)
{
	c = c + 1;
	ft_putnbr_fd(i, 1);
	ft_putchar_fd('\n', 1);
	return (c);
}

int		main(void)
{

/* striter
	ft_putendl_fd("--- striter ? --- ");
	char	str[] = "abcde";
	ft_striter(str, ft_change);


	ft_putendl("--- striter ? --- ");
	char	str2[] = "abcde";
	ft_striteri(str2, ft_change2);

	ft_putendl_fd("--- strmap ? --- ", 1);
	char	str3[] = "abcde";
	ft_putendl_fd(ft_strmap(str3, ft_change3));

strmapi */
	ft_putendl_fd("--- strmapi ? --- ", 1);
	char	str4[] = "abcde";
	ft_putendl_fd(ft_strmapi(str4, ft_change4), 1);

	return (0);
}
