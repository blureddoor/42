/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvintila <lvintila@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/20 20:22:27 by lvintila          #+#    #+#             */
/*   Updated: 2022/02/19 18:39:52 by lvintila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/myshell.h"

int g_status;

void	check_str(char *str, char *cmd, t_param *param)
{
	if (access(str, F_OK) != 0 || access(str, X_OK) != 0)
	{
		my_perror(param, NOCMD, str, 127);
		if (*cmd != 36)
			write(1, cmd, ft_strlen(cmd));
		write(1, "\n", 1);
		//TODO limpiar memoria
		cleanup(param);
		exit (g_status);
	}
}

char	*find_path(char *cmd, char **envp)
{
	int		i;
	char	*str;
	char	*tmp;
	char	**tab;

 	//TODO cambiar la función para que no utilize envp, si no directamente param->env
	if (ft_strchr(cmd, '/') && access(cmd, F_OK) == 0)
		return (cmd);
	else
		return ("");
		
	i = -1;
	while (envp[++i])
	{
		if (!ft_strncmp(envp[i], "PATH=", 5))
	 	{
	 		tab = ft_split(ft_strchr(envp[i], '/'), ':');
	 		break ;
	 	}
	}
	i = -1;
	while (tab[++i])
	{
		tmp = ft_strjoin(tab[i], "/");
		str = ft_strjoin(tmp, cmd);
		free(tmp);
		if (access(str, F_OK) == 0)
		{
			free_arr(tab);
			return (str);
		}
		free(str);
	}
	free_arr(tab);
	return (NULL);
}

void	free_arr(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
		free(arr[i++]);
	free(arr);
}

char	*rl_gets(t_param *param)
{
	/*
	 * * A static variable for holding the line.
	 */
	static char *line_read;


	line_read = (char *)NULL;
	/*
    ¦* If the buffer has already been allocated, return the memory
    ¦* to the free pool.
	 */
	if (line_read)
	{
		free (line_read);
		line_read = (char *)NULL;
	}
	/*
	 * Get a line from the user.
	 */

	line_read = readline (param->prompt);

	/*
	 * If the line has any text in it, save it on the history.
	 */
    if (line_read && *line_read)
		add_history (line_read);
    return (line_read);
}


int	found_op(char *str, char *op)
{
	int i;

	i = 0;
	while (*str++ != '\0')
	{
		if (str == op)
		{
			printf("found_op say: \"found op\" ...\n");
			return (0);
		}
	}
	return (1);
}

int	found_char(char *str, char c)
{
	int i;

	i = 0;
	while (str[++i] != '\0')
	{
		if (str[i] == c)
		{
			printf("found_char say: \"found\" > ...\n");
			return (0);
		}
	}
	return (1);
}

/* void    update_prompt(t_param *param)
{  
    char        *logname;
    char        *pwd;
    char        *tmp;
    if (mygetenv("LOGNAME", param))
    {
        logname = ft_strdup(mygetenv("LOGNAME", param));
        tmp = logname;
        logname = ft_strjoin(logname, ":");
        free(tmp);
    }
    else
        logname = ft_strdup("");
    if (mygetenv("PWD", param))
        pwd = ft_strdup(mygetenv("PWD", param));
    else
        pwd = ft_strdup("");
    tmp = ft_strjoin(logname, pwd);
    free(pwd);
    free(param->prompt);
    param->prompt = ft_strjoin(tmp, "$ ");
    free(tmp);
    free(logname);
} */

/* void	wait_for(t_param *param)
{
	int	status;
	pid_t	pid;


} */

int	check_str_permissions(char **str)
{
	int i;

	i = 0;
	while (str[i] && str[i] != NULL)
	{
		if (access (str[i], X_OK) != 0)
			return (1);
		i++;
	}
	return (0);
}