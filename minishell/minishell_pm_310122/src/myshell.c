/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   myshell.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvintila <lvintila@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 18:55:41 by lvintila          #+#    #+#             */
/*   Updated: 2022/02/02 23:59:42 by lvintila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/myshell.h"


 static t_param	*init_vars(t_param *param, char *str, char **argv, char **envp)
{
	char		*num;
	t_keyval	*kv_env;

	str = getcwd(NULL, 0);
	param->o_env = setenv_aux(param->env, "PWD", str, param);
	//free(str);
    printf("HHHHHHHHHHH\n");
	str = mygetenv("SHLVL", param);
	if (!str || ft_atoi(str) <= 0)
		num = ft_strdup("1");
	else
		num = ft_itoa(ft_atoi(str) + 1);
	//free(str);
	param->o_env = setenv_aux(param->env, "SHLVL", num, param);
	free(num);
	str = mygetenv("PATH", param);
	if (!str)
		param->o_env = setenv_aux(param->env, "PATH", \
		"/usr/local/sbin:/usr/local/bin:/usr/bin:/bin", param);
	//free(str);
	str = mygetenv("_", param);
	if (!str)
		param->o_env = setenv_aux(param->env, "_", argv[0], param);
	//free(str);
	return (param);
}

static t_param	*init_params(char **argv, char **env)
{
	int			i;
	t_keyval	**keyval;
	char 		*str;
	t_param		*param;

	str = NULL;
	param = malloc(sizeof(t_param));
 	//param->line				= NULL;
	param->tmp_in			= 0;
	param->tmp_out			= 0;
	param->fd_in				= 0;
	param->fd_out			= 0;
	param->cmds				= 0; 
	// pasa el env a keyval pairs
	i = 0;
	while (env[i] != NULL)
		i++;
	param->envc = i;
	printf("param.envc_1 es: %d\n", param->envc);
	i = 0;
	keyval = malloc(sizeof(t_keyval*) + 1);
	while (env[i] != NULL)
	{
		keyval[i] = get_keyval(env[i]);
		//set_env_var(keyval[i], &param);
		i++;
	}
	keyval[i] = NULL;
	param->env			= keyval; 			
	param->o_env			= env;
	param = init_vars(param, str, argv, env);
	return (param);
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
	cmd_execute(commands, param, env);
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

	//param = malloc(sizeof(t_param));
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
	param = init_params(av, env);
	printf("Entering interactive mode\n");
	status = myshell_loop(param, av, execution_coun, env);
	free(param);
	return (status);
}
