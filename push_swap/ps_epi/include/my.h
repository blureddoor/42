/*
** my.h for pushswap in /home/boulay_b/Rendu/CPE_2014_Pushswap/include
**
** Made by arnaud boulay
** Login   <boulay_b@epitech.net>
**
** Started on  Mon Dec  8 17:48:38 2014 arnaud boulay
** Last update Sat Dec 13 18:58:31 2014 arnaud boulay
*/

#ifndef	MY_H_
# define MY_H_

typedef struct	s_list
{
  int		nb;
  int		vflag;
  struct s_list	*back;
  struct s_list	*next;
}		t_list;

t_list		*create_list();
int		my_get_nbr(char *str);
int		is_nb(char *str);
int		fill_list(t_list *baseA, int size, int ac, char **av);
int		add_chain(t_list *chain, int nb);
void		pa(t_list *baseA, t_list *baseB);
void		pb(t_list *baseA, t_list *baseB);
void		rb(t_list *baseA, t_list *baseB);
void		rrb(t_list *baseA, t_list *baseB);
void		my_putstr(char *str);
void		my_putchar(char c);
void		rm_list(t_list *list);
void		my_putnbr(int nb);
void		disp_list(t_list *baseA, t_list *baseB);
void		sort_in_B(t_list *baseA, t_list *baseB, int size);
void		sort_in_A(t_list *baseA, t_list *baseB);

#endif /* !MY_H_ */
