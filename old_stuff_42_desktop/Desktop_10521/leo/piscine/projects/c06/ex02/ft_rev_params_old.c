void	ft_putchar(char c);

void	ft_putstr(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		ft_putchar(str[i]);
		i++;
	}
}

int		main(int argc, char **argv)
{
	int i;

	i = argc - 1;
	while (i > 0)
	{
		ft_putstr(argv[i]);
		ft_putchar('\n');
		i--;
	}
	return (0);

=====


void	ft_putchar(char c);

int		main(int argc, char **argv)
{
	int i;
	int j;

	i = argc - 1;
	while (i > 0)
	{
		j = 0;
		while (argv[i][j] != '\0')
		{
			ft_putchar(argv[i][j]);
			j++;
		}
		ft_putchar('\n');
		i--;
	}
}

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_print_params(int argc, char **argv)
{
	int i;
	int x;

	i = 0;
	x = argc - 1;
	while (x > 0)
	{
		while (argv[x][i] != '\0')
		{
			ft_putchar(argv[x][i]);
			i++;
		}
		ft_putchar('\n');
		x--;
		i = 0;
	}
}

int		main(int argc, char **argv)
{
	ft_print_params(argc, argv);
	return (0);
}


}
