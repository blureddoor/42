#include <unistd.h>
#include <stdio.h>

int	ft_sqrt(int nb)
{
	int i;
	int sq;

	i = 1;
	sq = 1;
	if(nb == 0)
		return(0);
	while (i * i < nb)
	{
		i++;
	}
	if ((nb % i) == 0)
		return (i);
	else
		return(0);
}


int	ft_sqrt(int nb)
{
	int	sqrt;

	if (nb < 0)
		return (0);
	sqrt = 1;
	while (sqrt * sqrt < nb)
		++sqrt;
	if (sqrt * sqrt == nb)
		return (sqrt);
	return (0);
}

#include <stdio.h>

int	ft_sqrt(int nb)
{
	int i;

	if (nb > 46340 * 46340)
		return (0);
	while (i < nb)
	{
		if ((i * i) == nb)
			return (i);
		i++;
	}
	return (0);
}
int main()
{
  printf("%d",ft_sqrt(100));
  return(0);
}


