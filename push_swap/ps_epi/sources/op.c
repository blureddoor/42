/*
** op.c for pushswap in /home/boulay_b/Rendu/CPE_2014_Pushswap
**
** Made by arnaud boulay
** Login   <boulay_b@epitech.net>
**
** Started on  Tue Dec  9 16:46:00 2014 arnaud boulay
** Last update Sun Dec 14 14:50:38 2014 arnaud boulay
*/

#include "my.h"

void	pa(t_list *baseA, t_list *baseB)
{
  if (baseA->vflag == 1)
    disp_list(baseA, baseB);
  if (baseB->next->next == baseB)
    my_putstr("pa\n");
  else
    my_putstr("pa ");
  baseB->next->next->back = baseB;
  baseA->next->back = baseB->next;
  baseB->next = baseB->next->next;
  baseA->next->back->back = baseA;
  baseA->next->back->next = baseA->next;
  baseA->next = baseA->next->back;
}

void	pb(t_list *baseA, t_list *baseB)
{
  if (baseA->vflag == 1)
    disp_list(baseA, baseB);
  my_putstr("pb ");
  baseA->next->next->back = baseA;
  baseB->next->back = baseA->next;
  baseA->next = baseA->next->next;
  baseB->next->back->back = baseB;
  baseB->next->back->next = baseB->next;
  baseB->next = baseB->next->back;
}

void	rb(t_list *baseA, t_list *baseB)
{
  if (baseA->vflag == 1)
    disp_list(baseA, baseB);
  my_putstr("rb ");
  baseB->back->next = baseB->next;
  baseB->next->next->back = baseB;
  baseB->next = baseB->next->next;
  baseB->back->next->back = baseB->back;
  baseB->back->next->next = baseB;
  baseB->back = baseB->back->next;
}

void	rrb(t_list *baseA, t_list *baseB)
{
  if (baseA->vflag == 1)
    disp_list(baseA, baseB);
  my_putstr("rrb ");
  baseB->next->back = baseB->back;
  baseB->back->back->next = baseB;
  baseB->back = baseB->back->back;
  baseB->next->back->next = baseB->next;
  baseB->next->back->back = baseB;
  baseB->next = baseB->next->back;
}
