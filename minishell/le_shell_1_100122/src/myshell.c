/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   myshell.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmontese <pmontese@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 18:55:41 by lvintila          #+#    #+#             */
/*   Updated: 2022/01/10 20:19:39 by pmontese         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/myshell.h"

void 	init_params(t_param *param)
{
	param->line			= NULL;
	param->token		= NULL;
	param->exec_count	= 0;
    param->dir			= 0;
    param->dir_cmd		= NULL;
	param->aux			= NULL;
	param->fd			= 0;
	param->indir		= 0;
}


int main(int ac, char *av[], char **env)
{
	t_param *param;
	int execution_coun = 1;
	int status = 0;
	(void)ac;

	if (ac > 1)
	{
		write(2, "Error: wrong number of arguments\n", 33);
		write(2, "Usage: ./minishell\n", 19);
		return (1);
	}
	param = malloc(sizeof(t_param));
//	param->dir_cmd = NULL;
//	param->line = NULL;
	printf("main 0\n");
//	init_params(param);
	printf("main 1\n");
	status = myshell_loop(param, av, execution_coun, env);
	printf("main 2\n");
	return (status);
}
