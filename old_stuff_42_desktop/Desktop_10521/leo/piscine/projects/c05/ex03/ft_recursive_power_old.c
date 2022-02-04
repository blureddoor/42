

int		ft_recursive_power(int nb, int power)
{
	if (power < 0)
		return (0);
	else if (power < 1)
		return (1);
	else
		return (nb * ft_recursive_power(nb, power - 1));
}


int	ft_recursive_power(int nb, int power)
{
	if (power < 0)
		return (0);
	if (power > 0)
		return (nb * ft_recursive_power(nb, power - 1));
	else
		return (1);
}

int ft_recursive_power(int nb, int power)
{
  int count;
  if (power < 0)
    return (0);
  
  if (power > 0)
  {
    count = nb * ft_recursive_power(nb, power - 1);
    return (count);
  }
  else
  {
    return(1);
  }
  
}

int main()
{
  printf("%d",ft_recursive_power(2,3));
  return(0);
}
