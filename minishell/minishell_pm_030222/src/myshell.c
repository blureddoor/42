/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   myshell.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvintila <lvintila@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 18:55:41 by lvintila          #+#    #+#             */
/*   Updated: 2022/02/03 18:57:02 by lvintila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/myshell.h"


void	init_params(t_param *param, char **env)
{
	int			i;
	t_keyval	*keyval;
	char 		*str;

 	param->line				= NULL;
	param->tmp_in			= 0;
	param->tmp_out			= 0;
	param->fd_in				= 0;
	param->fd_out			= 0;
	param->cmds				= 0; 
	param->envc				= 0;
	param->env				= NULL;
	// pasa el env a keyval pairs
/*	i = 0;
 	while (env[i] != NULL)
		i++;
	param->envc = i; */
	i = 0; 
	//keyval = (t_keyval*)malloc(sizeof(t_keyval));
	while (env[i] != NULL)
	{
		//printf("env[i] es: %s\n", env[i]);
		keyval = get_keyval(env[i]);
		set_env_var(keyval, param);
		i++;
	}			
	param->o_env			= env;
//	printf("param->o_env[0] en init_params es: %s\n", param->o_env[0]);
}

int	isdir(const char *path) {
	struct stat statbuf;
	if (stat(path, &statbuf) != 0)
		return 0;
	return S_ISDIR(statbuf.st_mode);
}

char	*read_script(char *script)
{
	int		fd;
	char	*tmp;
	char	*total;
	char	*line;

	if ((fd = open(script, O_RDONLY)) < 0)
	{
		perror("error: ");
		exit (fd);	// TODO comprobar que error devuelve bash en este caso
	}
	ft_putstr("-----------");
	if (get_next_line(fd, &line))
	{	
		tmp = ft_strdup("");
		total = ft_strjoin(tmp, line);
		free(tmp);
		free(line);
	}
	while (get_next_line(fd, &line))
	{
		tmp = total;
		total = ft_strjoin(total, "\n");
		free(tmp);
		tmp = total;
		total = ft_strjoin(tmp, line);
		free(tmp);
		free(line);
	}
	return total;
}

void	myshell_nointerac(char *script, t_param *param, char **env)
{
	int		fd;
	char	*doc;
	t_token		*tokens;
	t_command	**commands;
	t_keyval	*keyval;

	if (isdir(script))
	{
		printf("%s: is a directory \n", script);
		errno = 126;
		exit(126);
	}

	// TODO comprobar permisos
	doc = read_script(script);
	printf("file content:\n%s\n", doc);

	tokens = tokenizer(doc, param);
	commands = parser(tokens);
	// executer(env, tokens, commands);
	cmd_execute(commands, param);
	free(doc);
	// free tokens
	// free commands
	exit(0);
}

int main(int ac, char *av[], char **env)
{
	t_param *param;
	int execution_coun = 1;
	int status = 0;

	param = (t_param *)malloc(sizeof(t_param));
	init_params(param, env);
	//init_params(av, env);
	if (ac > 2)
	{
		write(2, "Error: wrong number of arguments\n", 33);
		write(2, "Usage: './minishell' or './minishell file'\n", 43);
		free(param);
		return (1);
	}
	else if (ac == 2)
	{
		printf("Non interactive mode\n");
		myshell_nointerac(av[1], param, env);
	}
	
	reg_parent_signals();
	status = myshell_loop(param, av);
	free(param);
	return (status);
}
