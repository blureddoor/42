/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   myshell.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
<<<<<<< HEAD
/*   By: lvintila <lvintila@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 18:55:41 by lvintila          #+#    #+#             */
/*   Updated: 2022/01/11 17:56:41 by lvintila         ###   ########.fr       */
=======
/*   By: lvintila <lvintila@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 18:55:41 by lvintila          #+#    #+#             */
/*   Updated: 2022/01/11 21:40:44 by lvintila         ###   ########.fr       */
>>>>>>> e21cb8d67b0f61f2db14495b02fbf4a31f25a4bb
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
<<<<<<< HEAD
	param->indir		= 0;		
=======
	param->indir		= 0;
>>>>>>> e21cb8d67b0f61f2db14495b02fbf4a31f25a4bb
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
	status = myshell_loop(param, av, execution_coun, env);
	return (status);
}
