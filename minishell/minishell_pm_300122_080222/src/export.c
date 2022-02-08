/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvintila <lvintila@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/30 12:38:17 by pmontese          #+#    #+#             */
/*   Updated: 2022/02/08 19:46:04 by lvintila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/myshell.h"

/* devuelve 1 si "s1 > s2" */
int	comparator(char *s1, char *s2)
{
	int	i;

	i = 0;
	// printf("comparando %s vs %s\n", s1, s2);
	while (s1[i] && s2[i])
	{
		if (s1[i] > s2[i])
		{
			// printf("%s > %s\n", s1, s2);
			return (1);
		}
		if (s1[i] < s2[i])
		{
			// printf("%s < %s\n", s1, s2);
			return (0);
		}
		i++;
	}
	if (s1[i])
	{
		// printf("%s > %s\n", s1, s2);
		return (1);
	}
	if (s2[i])
	{
		// printf("%s < %s\n", s1, s2);
		return (0);
	}
	printf("!! las dos cadenas son iguales!\n");
	return 0;
}

t_list *order_export(t_param *param)
{
	t_list	*first;
	t_list	*current;
	t_list	*prev;
	t_keyval	*kv;
	int		i;
int h;

	first = ft_lstnew(get_keyval("starting = order"));
	i = 0;
	while (i < param->envc)
	{
		current = first->next;
		prev = first;
		h = 0;
		while(current)
		{
			// printf("%d.%d\n", i, h);
			// sleep(1);
			kv = (t_keyval*)(current->content);
			if (comparator(kv->key, param->env[i]->key))
			{
				t_keyval *ckv = (t_keyval*)current->content;
				t_keyval *pkv = (t_keyval*)prev->content;
				// printf("current = %s, prev = %s\n", ckv->key, pkv->key);
				break;
			}
			prev = current;
			current = current->next;
			h++;
		}
		// añade a la lista
		if (current)
		{
			t_list *tmp;
			tmp = ft_lstnew(param->env[i]);
			tmp->next = current;
			prev->next = tmp;
			t_keyval *pkv = (t_keyval*)prev->content;
			t_keyval *tkv = (t_keyval*)tmp->content;
			t_keyval *ckv = (t_keyval*)current->content;
			// printf("prev = %s, tmp = %s, current = %s\n", pkv->key, tkv->key, ckv->key);
		}
		else
		{
			ft_lstadd_back(&first, ft_lstnew(param->env[i]));
			// printf("Añadido %s\n", param->env[i]->key);
		}
		i++;
	}
	return (first);
}

void    print_export(t_param *param)
{
    //TODO Ordenar alfabeticamente!!
    int			i;
	t_list		*first;
	t_list		*lst;
	t_keyval	*kv;

	first = order_export(param);
	lst = first->next;
	i = 0;
    while (i < param->envc)
	{
		printf("declare -x ");
		kv = (t_keyval*)(lst->content);
		printf("%s=\"%s\"\n", kv->key, kv->val);
		lst = lst->next;
		i++;
	}
}
