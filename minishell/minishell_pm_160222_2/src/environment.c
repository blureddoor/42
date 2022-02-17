/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   environment.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmontese <pmontes@student.42madrid.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/30 12:38:17 by pmontese          #+#    #+#             */
/*   Updated: 2022/02/12 23:18:05 by pmontese         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/myshell.h"

char	**make_envp(t_param *param)
{
	char	**envp;
	int		i;
	int		h;
	char	*tmp;

	envp = (char**)(malloc(sizeof(char*) * (param->envvalc + 1)));
	i = 0;
	h = 0;
	while (i < param->envc)
	{
		if (!param->env[i]->val)
		{
			i++;
			continue;
		}
		tmp = ft_strjoin(param->env[i]->key, "=");
		envp[h] = ft_strjoin(tmp, param->env[i]->val);
		free(tmp);
		i++;
		h++;
	}
	envp[h] = NULL;
	return (envp);
}

/* busca si hay una variable con el mismo nombre y cambia su valor,
si no lo hay devuelve 0 */
int		try_set_existing_var(t_keyval *var, t_param *param)
{
	int	i;

	i = 0;
	while (i < param->envc)
	{
		if (ft_strcmp(var->key, param->env[i]->key) == 0)
		{
			free(param->env[i]->key);
			free(param->env[i]->val);
			free(param->env[i]);
			param->env[i] = var;
			return (1);
		}
		i++;
	}
	return (0);
}

/* Damos por hecho que key y value están en el heap*/
void	set_env_var(t_keyval *var, t_param *param)
{
	int			i;
	t_keyval	**new_env;

	if (!try_set_existing_var(var, param)) // si no existe la variable
	{
		// actualiza env
		new_env = (t_keyval**)(malloc(sizeof(t_keyval*) * (param->envc + 1)));
		i = 0;
		while (i < param->envc)
		{
			new_env[i] = param->env[i];
			i++;
		}
		new_env[i] = var;
		if (param->env != NULL)
			free(param->env);
		param->env = new_env;
		param->envc++;
		if (var->val)
			param->envvalc++;
	}
}

// esta función presupone que la variable existe
void	unset_env_var(char *name, t_param *param)
{
	t_keyval	**new_env;
	int			i;
	int			j;

	new_env = (t_keyval**)(malloc(sizeof(t_keyval*) * (param->envc - 1)));
	i = 0;
	j = 0;
	while (i < param->envc)
	{
		if (ft_strcmp(name, param->env[i]->key) == 0)
		{
			free(param->env[i]->key);
			free(param->env[i]->val);
			free(param->env[i]);
			i++;
			break;
		}
		new_env[j] = param->env[i];
		i++;
		j++;
	}
	if (param->env != NULL)
		free(param->env);
	param->env = new_env;
	param->envc--;
}

char		*mygetenv(char *name, t_param *param)
{
	int i;

	if (name == NULL)
		return (NULL);
	i = 0;
	while (i < param->envc)
	{
		if (ft_strcmp(name, param->env[i]->key) == 0)
			return (param->env[i]->val);
		i++;
	}
	return (NULL);
}

/* Allocate memory for a new t_keyval. A str without '=' is allowd (value = 0) */
t_keyval	*get_keyval(char *str)
{
	int	len;
	int	len2;
	t_keyval	*pair;

	pair = (t_keyval*)(malloc(sizeof(t_keyval)));
	pair->val = NULL;
	len = 0;
	while (str[len] && str[len] != '=')
		len++;
	pair->key = ft_substr(str, 0, len);
	if (len != ft_strlen(str))
		pair->val = ft_strdup(&str[len + 1]);
	return (pair);
}

void	my_setenv(char *name, char *value, t_param *param)
{
	t_keyval	*pair;

	pair = (t_keyval*)(malloc(sizeof(t_keyval)));
	pair->key = ft_strdup(name);
	pair->val = ft_strdup(value);
	set_env_var(pair, param);
}