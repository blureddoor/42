/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvintila <lvintila@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 21:29:00 by lvintila          #+#    #+#             */
/*   Updated: 2022/01/27 22:56:26 by lvintila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/myshell.h"

int	builtins(t_command *cmd, t_param *param, char **env)
{
	int	is_builtin;
	char *n;
	
	n = cmd->name;
	if (!ft_strcmp(n, "exit"))
	{
		exit(1);
	}
	else if (!ft_strcmp(n, "env"))
	{
		print_env(env);
		return (1);
	}
    else if (!ft_strcmp(n, "cd"))
    {
        my_cd(cmd, param);
        return (1);
    }
    else if (!ft_strcmp(n, "unset"))
    {
        my_unset(cmd, param);
        return (1);
    }
	return (0);
}

int my_cd(t_command *cmd, t_param *param)
{
    char    **str[2];
    char    *aux;
    DIR     *dir;

    dir = NULL;
    str[0] = cmd->argv;
    str[1] = NULL;
    aux = my_getenv("HOME", param->envp, 4);
    if (!aux)
        aux = ft_strdup("");
    free(aux);
    aux = getcwd(NULL, 0);
    str[1] = ft_extend_arr(str[1], aux);
    free(aux);
    if (str[0][1])
        dir = opendir(str[0][1]);
    if (str[0][1] && dir && access(str[0][1], F_OK) != -1)
		chdir(str[0][1]);
	else if (str[0][1] && access(str[0][1], F_OK) == -1)
		ft_putstr_fd("minishell: No such file or directory: ", 2);
	else if (str[0][1])
		ft_putstr_fd("minishell: Not a directory: ", 2);
    if (str[0][1] && dir)
        closedir(dir);
    printf("CHECK === >>>\n");
    ft_put_arr_fd(param->envp, 1);
    param->envp = my_setenv("OLDPWD", str[0][1], param->envp, 6);
    aux = getcwd(NULL, 0);
    str[1] = ft_extend_arr(str[1], aux);
    free(aux);
    param->envp = my_setenv("PWD", str[1][1], param->envp, 3);
    ft_free_arr(&str[1]);
    return (0);
}

/*
int my_export(t_command *cmd)
{
    
}

int my_unset(cmd)
{
    
} */
