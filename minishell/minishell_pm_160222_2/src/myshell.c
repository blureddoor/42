/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   myshell.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvintila <lvintila@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 18:55:41 by lvintila          #+#    #+#             */
/*   Updated: 2022/02/17 20:01:46 by lvintila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/myshell.h"

void	init_param(t_param *param, char **env)
{
	int			i;
	t_keyval	*keyval;
	char 		*str;

 	param->line				= NULL;
	param->default_in		= 0;
	param->default_out		= 0;
	param->fd_in			= 0;
	param->fd_out			= 0;
	param->cmdc				= 0;
	param->envc				= 0;
	param->envvalc			= 0;
	param->env				= NULL;
	// copiamos el environment
	i = 0;
	while (env[i] != NULL)
	{
		keyval = get_keyval(env[i]);
		set_env_var(keyval, param);
		i++;
	}
	param->tkn_lst = NULL;
	param->cmd_lst = NULL;
}

/**
 * * Disables CTRL hotkey(+c) from printing ^C
*/
static void	disable_ctrl_c_hotkey(void)
{
	struct termios	termios;
	int				rc;

	rc = tcgetattr(0, &termios);
	if (rc)
	{
		perror("tcgetattr");
		exit(1);
	}
	termios.c_lflag &= ~ECHOCTL;
	rc = tcsetattr(0, 0, &termios);
	if (rc)
	{
		perror("tcsetattr");
		exit(1);
	}
}

void	increment_shlvl(t_param *param)
{
	int		ilvl;
	char	*slvl;

	slvl = mygetenv("SHLVL", param);
	if (slvl)
	{
		ilvl = ft_atoi(slvl);
		slvl = ft_itoa(ilvl + 1);
		my_setenv("SHLVL", slvl, param);
		free(slvl);
	}
	else
		my_setenv("SHLVL", "1", param);
}

void	update_prompt(t_param *param)
{	
	char		*logname;
	char		*tmp;
	
	//char		*pwd;
	// tmp = ft_strdup(mygetenv("LOGNAME", param));
	// logname = ft_strjoin(tmp, ":");
	// free(tmp);
	// pwd = ft_strdup(mygetenv("PWD", param));
	// tmp = ft_strjoin(logname, pwd);
	// free(tmp);
	// free(pwd);
	// free(param->prompt);
	// param->prompt = ft_strjoin(tmp, "$ ");

	if (mygetenv("LOGNAME", param))
		logname = ft_strdup(mygetenv("LOGNAME", param));
	else
		logname = ft_strdup("");
	param->prompt = ft_strjoin(logname, "$ ");
	free(logname);
}

int main(int ac, char *av[], char **env)
{
	t_param *param;
	int execution_coun = 1;
	int status = 0;
	char *strlvl;
	int	intlvl;

	param = (t_param *)malloc(sizeof(t_param));
	init_param(param, env);
	increment_shlvl(param);
	disable_ctrl_c_hotkey();
	reg_parent_signals();
	printf("\n%s\n", "M I N I S H E L L\t\t\tby pmontese & lvintila\n");
	update_prompt(param);
	g_status = myshell_loop(param, av);
	cleanup(param);
	return (g_status);
}
