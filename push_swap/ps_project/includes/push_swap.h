/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvintila <lvintila@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/29 20:09:29 by lvintila          #+#    #+#             */
/*   Updated: 2021/05/07 20:28:48 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H

# define PUSH_SWAP_H

# include "libft.h"
# include "structs.h"
# include <unistd.h>
# include <sys/types.h>
# include <sys/uio.h>

#define SA	0
#define SB	1
#define SS	2
#define PA	3
#define PB	4
#define RA	5
#define RB	6
#define RR	7
#define RRA	8
#define RRB	9
#define RRR	10

typedef struct	s_chunk
{
	int			stack_min;
	int			stack_max;
	int			chunk_min;
	int			chunk_max;
	int			interval;
	int			chunk_nb;
}				t_chunk

typedef struct	s_stack
{
	int			*tab;
	int			begin;
	int			size;
}				t_stack;

typedef	struct	s_struct
{
	t_stack		stack_a;
	t_stack		stack_b;
}				t_struct;

static void		apply_swap(t_stack *stack);
void			swap(t_struct *ps, int instr_nb, char write_it);
static void		apply_push(t_stack *stack);
void			push(t_struct *ps, int instr_nb, char write_it);
static void		apply_rot(t_stack *stack);
void			rotate(t_struct *ps, int instr_nb, char write_it);
static void		apply_rotate_rev(t_stack *stack);
void			rotate_rev(t_struct *ps, int instr_nb, char write_it);
void			init_struct(t_struct *ps);
int				free_and_return(t_struct *ps);
int				stack_size(t_stack *stack);
void			ft_swap(int *a, int *b);
int				get_max(t_stack stack);
int				get_min(t_stack stack);
int				get_min_index(t_stack stack);
int				get_max_index(t_stack stack);
int				check_order(t_stack stack_a);
static int		chunk_sort(t_struct *ps, t_chunk *ch, int nb, int instr);
static int		split_args(char ***agg_split, int argc, char **argv);
static int		check_args(char **agg_split, t_struct *ps);
int				check_line(t_struct *ps, char *arg, int *nb);
int				ft_realloc(t_stack *stack, int nb_to_add);
void			deal_args(int argc, char **argv, t_struct *ps);
#endif
