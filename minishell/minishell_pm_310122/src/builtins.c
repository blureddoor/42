#include "../inc/myshell.h"


void	bi_exit(t_command *cmd, t_param *param)
{
	int num;

	// TODO liberar memoria
	printf("exit\n");
	if (cmd->argc > 2)
	{
		printf("bash: exit: too many arguments\n");
		exit(1);
	}
	else if (cmd->argc == 2)
	{
		if (ft_strlen(cmd->argv[1]) == 1 && cmd->argv[1][0] == '0')
			exit(0);
		num = ft_atoi(cmd->argv[1]);
		if (num == 0)
		{
			printf("bash: exit: arg: numeric argument required\n");
			exit(2);
		}		
		exit(num);
	}
	exit(0);
}

void	bi_env(t_param *param)
{
	int i;

	i = 0;
	while (i < param->envc)
	{
		printf("%s=%s\n", param->env[i]->key, param->env[i]->val);
		i++;
	}
}

int is_valid_identifier(char *arg, int equalsign)
{
	int i;

	if (ft_isalpha(arg[0]))
	{
		i = 1;
		while (ft_isalnum(arg[i]))
			i++;
		if (equalsign && arg[i] == '=')
			return (1);
		if (!equalsign && arg[i] == 0)
			return (1);
	}
	return (0);
}

void	bi_export(t_command *cmd, t_param *param)
{
	int i;
	int j;
	char	*arg;

	i = 1;
	while (i < cmd->argc)
	{
		arg = cmd->argv[i];
		//check identifier
		if (!is_valid_identifier(arg, 1))
		{
			printf("bash: export: `%s': not a valid identifier\n", arg);
			//TODO set error to 1
			i++;
			continue;
		}
		set_env_var(get_keyval(arg), param);
		i++;
	}
}

void	bi_unset(t_command *cmd, t_param *param)
{
	int		i;
	int		j;
	char	*arg;

	i = 1;
	while (i < cmd->argc)
	{
		arg = cmd->argv[i];
		//check identifier
		if (!is_valid_identifier(arg, 0))
		{
			printf("bash: unset: `%s': not a valid identifier\n", arg);
			//TODO set error to 1
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


int my_cd(t_command *cmd, t_param *param, t_keyval *var)
{
    char    **str[2];
    char    *aux;
    DIR     *dir;

	param->process_status = 0;
    dir = NULL;
    str[0] = cmd->argv;
    //str[1] = NULL;
    aux = mygetenv("HOME", param);
    if (!aux)
        aux = ft_strdup("");
  //  free(aux);
    str[1] = ft_extend_arr(NULL, aux);
    free(aux);
    aux = getcwd(NULL, 0);
	str[1] = ft_extend_arr(str[1], aux);
	free(aux);
    if (str[0][1])
        dir = opendir(str[0][1]);
	if (!str[0][1] && str[1][0] && !str[1][0][0])
	{
		param->process_status = 1;
		ft_putstr_fd("myshell: HOME not set\n", 2);
	}
	if (str[1][0] && !str[0][1])
	{
		param->process_status = chdir(str[1][0]) == -1;
	}
	if (str[0][1] && dir && access(str[0][1], F_OK) != -1)
		chdir(str[0][1]);
	else if (str[0][1] && access(str[0][1], F_OK) == -1)
		ft_putstr_fd("minishell: No such file or directory: ", 2);
	else if (str[0][1])
		ft_putstr_fd("minishell: Not a directory: ", 2);
    if (str[0][1] && dir)
        closedir(dir);
    printf("CHECK === >>>\n");
   // ft_put_arr_fd(param->o_env, 1);
	if (!param->process_status)
    	param->o_env = try_set_existing_var("OLDPWD", param);
    aux = getcwd(NULL, 0);
    str[1] = ft_extend_arr(str[1], aux);
    free(aux);
    param->o_env = try_set_existing_var("PWD", param);
    ft_free_arr(&str[1]);
    return (param->process_status);
}