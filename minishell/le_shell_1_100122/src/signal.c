/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvintila <lvintila@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 19:34:10 by marvin            #+#    #+#             */
/*   Updated: 2022/01/14 19:38:11 by lvintila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/myshell.h"

void	handle_sigint(int sig)
{
	int	err;
    t_param *param;

	if (sig == SIGINT)
	{
		err = 130;
		write(1, "\n", 1);
		close(param->a_fds[0][STDIN]);
		close(param->a_fds[0][STDOUT]);
		close(param->a_fds[1][STDIN]);
		write(param->a_fds[1][STDOUT], &err, sizeof(int));
		close(param->a_fds[1][STDOUT]);
		exit(0);
	}
}

void	handle_sigint_child(int sig)
{
	if (sig == SIGINT)
		write(1, "\n", 1);
}

void	handle_sigquit(int sig)
{
	if (sig == SIGQUIT)
		write(2, "Quit: 3\n", 8);
}