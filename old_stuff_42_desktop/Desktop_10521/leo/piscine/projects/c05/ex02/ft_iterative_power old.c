
====================================================================
===================================================================

#include <unistd.h>
#include <stdio.h>

int         ft_iterative_power(int nb, int power)
{
    int     result;

    result = 1;
    if ((nb == 0 && power !=0) || power < 0)
        return (0);
    if ((power == 0) || (( nb < 0) && (power == 0)))
        return (1);
    else
    {
        while (power > 0)
        {
            result =  nb * result;
            power--;
        }
        return (result);
    }
}


======================================================================


int	ft_iterative_power(int nb, int power)
{
	int	result;

	result = 1;
	if (power < 0)
		return (0);
	if (power == 0)
		return (1)
	while (power)
	{
		result *= nb;
		power--;
	}
	return (result);
}

=====================================================================

int	ft_iterative_power(int nb, int power)
{
	int i;
	int count;

	if (power < 0)
		return (0);
	count = 1;
	i = 0;
	while (i < power)
	{
		count = count * nb;
		i++;
	}
	return (count);
}

int main()
{
  printf("%d",ft_iterative_power(2, 1));
  return(0);
}






