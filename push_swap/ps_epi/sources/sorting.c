/*
** sorting.c for pushswap in /home/boulay_b/Rendu/CPE_2014_Pushswap/sources
**
** Made by arnaud boulay
** Login   <boulay_b@epitech.net>
**
** Started on  Sat Dec 13 17:36:39 2014 arnaud boulay
** Last update Sun Dec 14 14:47:25 2014 arnaud boulay
*/

#include "my.h"

void	sort(t_list *baseA, t_list *baseB, int size)
{
  while ((size-- > 0) && (baseA->next != baseA))
    if (baseB->next == baseB || baseB->next->next == baseB)
      pb(baseA, baseB);
    else
      {
	while (baseB->back->nb >= baseB->next->nb)
	  rrb(baseA, baseB);
	if (baseA->next->nb >= baseB->next->nb || baseB->back->nb >=
	    baseA->next->nb)
	  pb(baseA, baseB);
	else
	  {
	    while (baseA->next->nb <= baseB->next->nb)
	      rb(baseA, baseB);
	    pb(baseA, baseB);
	  }
      }
}

void	sort_in_B(t_list *baseA, t_list *baseB, int size)
{
  if (size > 2)
    {
      sort_in_B(baseA, baseB, size / 2);
      sort_in_B(baseA, baseB, size / 2);
      sort(baseA, baseB, size);
    }
  else
    sort(baseA, baseB, size);
}

void	sort_in_A(t_list *baseA, t_list *baseB)
{
  while (baseB->back->nb >= baseB->next->nb)
    rrb(baseA, baseB);
  while (baseB->next != baseB)
    pa(baseA, baseB);
}
