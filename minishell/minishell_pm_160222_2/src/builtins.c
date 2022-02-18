#include "../inc/myshell.h"

void	bi_exit(t_command *cmd, t_param *param, int ischild)
{
	int num;

	if (param->cmdc > 1 || ischild)
		return;
	// TODO liberar memoria
	printf("exit\n");
	if (cmd->argc > 2)
	{
		printf("%s: exit: too many arguments\n", SHLNAME);
		exit(1);
	}
	else if (cmd->argc == 2)
	{
		if (ft_strlen(cmd->argv[1]) == 1 && cmd->argv[1][0] == '0')
			exit(0);
		num = ft_atoi(cmd->argv[1]);
		if (num == 0)
		{
			printf("%s: exit: arg: numeric argument required\n", SHLNAME);
			exit(2);
		}
		exit(num);
	}
	exit(0);
}

void	bi_env(t_param *param, int is_child)
{
	int i;

	if (!is_child)
		return;
	i = 0;
	while (i < param->envc)
	{
		if (param->env[i]->val)
			printf("%s=%s\n", param->env[i]->key, param->env[i]->val);
		i++;
	}
	param->process_status = 0;
}

int	is_valid_identifier(char *arg, int allow_equalsign)
{
	int i;

	if (isvalidchar4var(arg[0], 1))
	{
		i = 1;
		while (isvalidchar4var(arg[i], 0))
			i++;
		if (allow_equalsign && (arg[i] == '=' || arg[i == 0]))
			return (1);
		if (!allow_equalsign && arg[i] == 0)
			return (1);
	}
	return (0);
}

void	bi_export(t_command *cmd, t_param *param, int is_child)
{
	int i;
	int j;
	char	*arg;

	i = 1;
	if (cmd->argc == 1 && is_child)
	{
		print_export(param);
		return;
	}
	while (i < cmd->argc && !is_child && param->cmdc == 1)
	{
		arg = cmd->argv[i];
		//check identifier
		if (!is_valid_identifier(arg, 1))
		{
			printf("minishell: export: '%s': not a valid identifier\n", arg);
			errno = 1;
			i++;
			continue;
		}
		//TODO implementar expansión en export
		set_env_var(get_keyval(arg), param);
		i++;
	}
}

void	bi_unset(t_command *cmd, t_param *param, int ischild)
{
	int		i;
	int		j;
	char	*arg;

	i = 1;
	while (i < cmd->argc && param->cmdc == 1 && !ischild)
	{
		arg = cmd->argv[i];
		//check identifier
		if (!is_valid_identifier(arg, 0))
		{
			printf("minishell: unset: `%s': not a valid identifier\n", arg);
			errno = 1;
			i++;
			continue;
		}
		j = 0;
		while (j < param->envc)
		{
			if (ft_strcmp(arg, param->env[j]->key) == 0)
				unset_env_var(arg, param);
			j++;
		}
		i++;
	}
}

void	bi_cd(t_command *cmd, t_param *param)
{
	char		*pwd;
	char		*tmp;
	DIR			*dir;
	t_keyval	*kv;

	if (param->cmdc > 1)
		return;
	pwd = getcwd(NULL, 0);
	if (cmd->argc == 1) // if cd sin argumentos
	{
		// comprobar variable home q exista
		tmp = mygetenv("HOME", param);
		if (!tmp)
		{
			g_status = 1;
			perror("Error: Home not set");
			return;
		}
	}
	else
		tmp = cmd->argv[1];
	// comprobar q existe y q es un directorio
	if (access(tmp, F_OK) == -1)
	{
		//my_perror(param, NODIR, cmd->argv[1], 1);
		g_status = 1;
		free(pwd);
		perror("Error: not found");
		printf("errno es: %d\n", errno);
		g_status = errno;
		return;
	}
	dir = opendir(tmp);
	if (!dir)
	{		
		g_status = 1;
		free(pwd);
		perror("Error: not a directory");
		return;
	}
	// chdir a home
	chdir(tmp);
	// actualizar env oldpwd = env pwd
	my_setenv("OLDPWD", pwd, param);
	// actualizar env pwd = arg1
	my_setenv("PWD", tmp, param);
	if (dir)
		closedir(dir);
	free(pwd);
}

int	bi_pwd(int ischild)
{
	char	*buf;

	if (!ischild)
		return (0);
	buf = getcwd(NULL, 0);
	ft_putstr(buf);
	ft_putstr("\n");
	free(buf);
	return (0);
}

static int	is_n_option(char *argv)
{
	// ft_putstr("is_n: ");
	// ft_putstr(argv);
	// ft_putstr("\n");
	if (!argv)
		return (1);
	if (argv && *argv == '-')
	{
		argv++;
		while (*argv == 'n')
			argv++;
	}
	if (argv && *argv == '\0')
		return (1);
	return (0);
}

int	bi_echo(t_command *cmd, int ischild)
{
	int		new_l;
	int		i;
	int		flag;

	if (!ischild)
		return (0);
	i = 0;
	new_l = 1;
	flag = 0;
	while (i < cmd->argc && cmd->argv && cmd->argv[++i])
	{
		if (is_n_option(cmd->argv[i]) && flag == 0)
			new_l = 0;
		else
		{
			flag++;
			ft_putstr_fd(cmd->argv[i], 1);
			if (cmd->argv[i + 1])
				ft_putchar_fd(' ', 1);
		}
	//	ft_putchar_fd('\n', 1);
	}
	if (new_l)
		ft_putchar_fd('\n', 1);
	return (0);
}