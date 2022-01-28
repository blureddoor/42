/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   myshell.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvintila <lvintila@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 18:55:41 by lvintila          #+#    #+#             */
/*   Updated: 2022/01/27 22:47:12 by lvintila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/myshell.h"

static t_param	init_vars(t_param param, char *str, char **argv, char **envp)
{
	char	*num;

	str = getcwd(NULL, 0);
	param.envp = my_setenv("PWD", str, param.envp, 3);
	free(str);
	str = my_getenv("SHLVL", envp, 5);
	if (!str || ft_atoi(str) <= 0)
		num = ft_strdup("1");
	else
		num = ft_itoa(ft_atoi(str) + 1);
	free(str);
	param.envp = my_setenv("SHLVL", num, param.envp, 5);
	free(num);
	str = my_getenv("PATH", param.envp, 4);
	if (!str)
		param.envp = my_setenv("PATH", \
		"/usr/local/sbin:/usr/local/bin:/usr/bin:/bin", param.envp, 4);
	free(str);
	str = my_getenv("_", param.envp, 1);
	if (!str)
		param.envp = my_setenv("_", argv[0], param.envp, 1);
	
	free(str);
	printf("====////=====\n");
	return (param);
}

static t_param 	init_params(char **argv, char **envp)
{
	t_param				param;
	char				*str;

	str = NULL;
	param.line = NULL;
	param.cmds = 0;
	param.token = NULL;
	param.exec_count = 0;
    param.dir = 0;
    param.dir_cmd = NULL;
	param.aux = NULL;
	param.fd = 0;
	param.indir = 0;
	param.envp = ft_dup_arr(envp);
	param = init_vars(param, str, argv, envp);
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

	if (isdir(script))
	{
		printf("%s: is a directory \n", script);
		errno = 126;
		exit(126);
	}

	// TODO comprobar permisos

	doc = read_script(script);
	printf("file content:\n%s\n", doc);

	tokens = tokenizer(doc);
	commands = parser(tokens);
	//executer(env, tokens, commands);
	cmd_execute(commands, param, env);
	free(doc);
	// free tokens
	// free commands
	exit(0);
}

int main(int ac, char *av[], char **env)
{
	t_param param;
	int execution_coun = 1;
	int status = 0;

	if (ac > 2)
	{
		write(2, "Error: wrong number of arguments\n", 33);
		write(2, "Usage: './minishell' or './minishell file'\n", 43);
		return (1);
	}
	else if (ac == 2)
	{
		printf("Non interactive mode\n");
		myshell_nointerac(av[1], &param, env);
	}

	//param = malloc(sizeof(t_param));
	param = init_params(av, env);

	printf("Entering interactive mode\n");
//	ft_put_arr_fd(param.envp, 1);
//	param->dir_cmd = NULL;
//	param->line = NULL;
	// printf("main 0\n");
//	init_params(param);
	// printf("main 1\n");
	status = myshell_loop(&param, av, execution_coun, env);
	printf("main 2\n");
	return (status);
}
