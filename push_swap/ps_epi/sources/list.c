/*
** list.c for pushswap in /home/boulay_b/Rendu/CPE_2014_Pushswap
**
** Made by arnaud boulay
** Login   <boulay_b@epitech.net>
**
** Started on  Mon Dec  8 17:52:48 2014 arnaud boulay
** Last update Sat Dec 13 19:20:04 2014 arnaud boulay
*/

#include <stdlib.h>
#include "my.h"

t_list		*create_list()
{
  t_list	*base;

  if ((base = malloc(sizeof(t_list *))) == NULL)
    return (NULL);
  base->back = base;
  base->next = base;
  base->vflag = 0;
  return (base);
}

void		rm_list(t_list *list)
{
  t_list	*chain;
  t_list	*tmp;

  chain = list->next;
  while (chain != list)
    {
      tmp = chain->next;
      free(chain);
      chain = tmp;
    }
  free(list);
}

int		add_chain(t_list *chain, int nb)
{
  t_list	*new_chain;

  if ((new_chain = malloc(sizeof(t_list *))) == NULL)
    return (1);
  new_chain->nb = nb;
  new_chain->back = chain->back;
  new_chain->next = chain;
  chain->back->next = new_chain;
  chain->back = new_chain;
  return (0);
}

void		disp_list(t_list *baseA, t_list *baseB)
{
  t_list	*tmp;

  tmp = baseA->next;
  if (baseB->next != baseB)
    my_putstr("\nl_a : ");
  else
    my_putstr("l_a : ");
  while (tmp != baseA)
    {
      my_putnbr(tmp->nb);
      if (tmp->next != baseA)
	my_putchar(' ');
      tmp = tmp->next;
    }
  tmp = baseB->next;
  my_putstr("\nl_b : ");
  while (tmp != baseB)
    {
      my_putnbr(tmp->nb);
      if (tmp->next != baseB)
	my_putchar(' ');
      tmp = tmp->next;
    }
  my_putchar('\n');
}

int		fill_list(t_list *baseA, int size, int ac, char **av)
{
  while (++size < ac)
    {
      if (is_nb(av[size]) == 0)
	return (1);
      if ((add_chain(baseA, my_get_nbr(av[size])) == 1))
	return (1);
    }
  return (size);
}
