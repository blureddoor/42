/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   myshell.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvintila <lvintila@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 18:55:41 by lvintila          #+#    #+#             */
/*   Updated: 2022/01/09 23:40:23 by lvintila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/myshell.h"

int main(int ac, char *av[], char **env)
{
	t_param *param;
	int execution_coun = 1;
//	int status = 0;
	(void)ac;

	if (ac > 1)
	{
		write(2, "Error: wrong number of arguments\n", 33);
		write(2, "Usage: ./minishell\n", 19);
		return (1);
	}

	myshell_loop(param, av, execution_coun, env);
	return (0);
}
