

int	ft_is_prime(int nb)
{
	int	i;

	i = 2;
	if (nb <= 1)
		return (0);

	while (i <= nb / i)
	{
		if (nb % i == 0)
			return (0);
		i++;
	}
	return (1);
}

int		ft_is_prime(int nb)
{
	int i;

	i = 2;
	if (nb < 2)
		return (0);
	while (nb % i != 0)
	{
		while (i < nb)
			i++;
	}
	if (i == nb)
		return (1);
	else
		return (0);
}


#include "j04.h"

int ft_is_prime(int nb) {
    
    int div;
    
    div = 2;
    
    if (nb == 0 || nb == 1) {
        return (0);
    }
    
    while (div < nb) {
        if (nb % div == 0) {
            return (0);
        }
        ++div;
    }
    
    return (1);
    
}

