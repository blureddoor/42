/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvintila <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/12 11:14:59 by lvintila          #+#    #+#             */
/*   Updated: 2020/01/21 20:23:52 by lvintila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*new;

	if ((new = (t_list*)malloc(sizeof(t_list))) == NULL)
		return (NULL);
	new->content = (void*)content;
	new->next = NULL;
	return (new);
}
