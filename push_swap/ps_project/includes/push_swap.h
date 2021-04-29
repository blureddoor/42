/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvintila <lvintila@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/29 20:09:29 by lvintila          #+#    #+#             */
/*   Updated: 2021/04/29 20:52:55 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H

# define PUSH_SWAP_H

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

#endif
