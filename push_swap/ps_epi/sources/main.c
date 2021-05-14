/*
** main.c for pushswap in /home/boulay_b/Rendu/CPE_2014_Pushswap
**
** Made by arnaud boulay
** Login   <boulay_b@epitech.net>
**
** Started on  Mon Dec  8 17:44:39 2014 arnaud boulay
** Last update Sun Mar 22 15:55:09 2015 Boulay Arnaud
*/

#include <stdio.h>
#include <stdlib.h>
#include "my.h"

void		my_pushswap_core(t_list *baseA, t_list *baseB, int size)
{
  sort_in_B(baseA, baseB, --size);
  sort_in_A(baseA, baseB);
  if (baseA->vflag == 1)
    disp_list(baseA, baseB);
}

int		my_pushswap(t_list *baseA, t_list *baseB, int ac, char **av)
{
  int		size;

  size = 0;
  if (av[1][0] == '-' && av[1][1] == 'v' && av[1][2] == '\0')
    {
      baseA->vflag = 1;
      ++size;
      if ((size = fill_list(baseA, size, ac, av)) == 1)
	return (1);
      if (ac > 3)
	my_pushswap_core(baseA, baseB, size);
    }
  else if (ac > 2)
    {
      if ((size = fill_list(baseA, size, ac, av)) == 1)
	return (1);
      my_pushswap_core(baseA, baseB, size);
    }
  return (0);
}

int		main(int ac, char **av)
{
  t_list	*baseA;
  t_list	*baseB;

  if (((baseA = create_list()) == NULL) || ((baseB = create_list()) == NULL))
    {
      my_putstr("Error: Malloc fail.\n");
      return (1);
    }
  if (ac > 1)
    {
      if (my_pushswap(baseA, baseB, ac, av) == 1)
	{
	  my_putstr("Error: Invalid arguments.\n");
	  return (1);
	}
    }
  else
    my_putstr("./push_swap [-v] int1 int2 ... intn\n");
  rm_list(baseB);
  rm_list(baseA);
  return (0);
}
