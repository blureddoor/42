/*
** tools.c for pushswap in /home/boulay_b/Rendu/CPE_2014_Pushswap/sources
**
** Made by arnaud boulay
** Login   <boulay_b@epitech.net>
**
** Started on  Fri Dec 12 17:25:28 2014 arnaud boulay
** Last update Sun Dec 14 13:51:48 2014 arnaud boulay
*/

#include "unistd.h"

void	my_putchar(char c)
{
  write(1, &c, 1);
}

void	my_putstr(char *str)
{
  int	i;

  i = -1;
  while (str[++i] != '\0')
    my_putchar(str[i]);
}

int	my_get_nbr(char *str)
{
  int	nbr;
  int	isneg;
  int	i;

  i = 0;
  nbr = 0;
  isneg = 0;
  while (str[i] != '\0')
    {
      if (str[i] >= '0' && str[i] <= '9')
	{
	  if (str[i - 1] == '-')
	    isneg = 1;
	  if (str[i + 1] < '0' || str[i + 1] > '9')
	    {
	      nbr = nbr + (str[i] - 48);
	      nbr = (isneg == 1) ? -nbr : nbr;
	      return (nbr);
	    }
	  else
	    nbr = (nbr * 10) + ((str[i] - 48) * 10);
	}
      i = i + 1;
    }
  return (0);
}

void	my_putnbr(int nb)
{
  int	lenght;
  int	rslt;

  if (nb < 0)
    {
      my_putchar('-');
      nb = -nb;
    }
  lenght = 1;
  while (nb / lenght > 9)
    lenght = lenght * 10;
  while (lenght > 0)
    {
      rslt = (nb / lenght) % 10;
      my_putchar(rslt + '0');
      lenght = lenght / 10;
    }
}

int	is_nb(char *str)
{
  int	i;

  i = -1;
  while (str[++i] != '\0')
    if ((str[i] < '0') || (str[i] > '9'))
      if (str[i] != '-')
	return (0);
  return (1);
}
