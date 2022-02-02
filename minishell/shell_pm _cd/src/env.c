/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvintila <lvintila@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 21:15:59 by lvintila          #+#    #+#             */
/*   Updated: 2022/01/29 19:05:30 by lvintila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/myshell.h"

char	*my_getenv(char *var, char **envp, int n)
{
	int	i;
	int	n2;

	i = 0;
	if (n < 0)
		n = ft_strlen(var);
	while (!ft_strchr(var, '=') && envp && envp[i])
	{
		n2 = n;
		if (n2 < ft_strchr_i(envp[i], '='))
			n2 = ft_strchr_i(envp[i], '=');
		if (!ft_strncmp(envp[i], var, n2))
		{
			printf("##################\n");
			return (ft_substr(envp[i], n2 + 1, ft_strlen(envp[i])));
		}
		i++;
	}
	return (NULL);
}

char	**my_setenv(char *var, char *value, char **envp, int n)
{
	int		num[2];
	char	*aux[2];

	if (n < 0)
		n = ft_strlen(var);
	num[0] = -1;
	aux[0] = ft_strjoin(var, "=");
	aux[1] = ft_strjoin(aux[0], value);
	printf("check setenv ---->>> \n");
	free(aux[0]);
	while (!ft_strchr(var, '=') && envp && envp[++num[0]])
	{
		num[1] = n;
		if (num[1] < ft_strchr_i(envp[num[0]], '='))
			num[1] = ft_strchr_i(envp[num[0]], '=');
		if (!ft_strncmp(envp[num[0]], var, num[1]))
		{
			aux[0] = envp[num[0]];
			envp[num[0]] = aux[1];
			free(aux[0]);
			return (envp);
		}
	}
	envp = ft_extend_arr(envp, aux[1]);
	free(aux[1]);
	return (envp);
}

static int	var_in_envp(char *argv, char **envp, int num[2])
{
	int	pos;

	num[1] = 0;
	pos = ft_strchr_i(argv, '=');
	if (pos == -1)
		return (-1);
	while (envp[num[1]])
	{
		if (!ft_strncmp(envp[num[1]], argv, pos + 1))
			return (1);
		num[1]++;
	}
	return (0);
}


int	my_export(t_command *cmd, t_param *param)
{
	int		num[2];
	int		pos;
	char	**argv;

	argv = cmd->argv;
	if (ft_arr_len(argv) >= 2)
	{
		num[0] = 1;
		while (argv[num[0]])
		{
			pos = var_in_envp(argv[num[0]], param->envp, num);
			printf("%s\n",argv[num[0]]);
			if (pos == 1)
			{
				free(param->envp[num[1]]);
				param->envp[num[1]] = ft_strdup(argv[num[0]]);
			}
			else if (!pos)
				param->envp = ft_extend_arr(param->envp, argv[num[0]]);
			num[0]++;
		}
	}
	return (0);
}

int	my_unset(t_command *cmd, t_param *param)
{
	char	**argv;
	char	*aux;
	int		num[2];

	num[0] = 0;
	argv = cmd->argv;
	if (ft_arr_len(argv) >= 2)
	{
		while (argv[++num[0]])
		{
			if (argv[num[0]][ft_strlen(argv[num[0]]) - 1] != '=')
			{
				aux = ft_strjoin(argv[num[0]], "=");
				free(argv[num[0]]);
				argv[num[0]] = aux;
			}
			if (var_in_envp(argv[num[0]], param->envp, num))
				ft_arr_replace_in(&param->envp, NULL, num[1]);
		}
	}
	return (0);
}