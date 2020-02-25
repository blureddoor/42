/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_aux.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvintila <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 14:44:09 by lvintila          #+#    #+#             */
/*   Updated: 2020/02/18 15:41:03 by lvintila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	(char **line, char *str)
{
	char *tmp;

	*line = ft_substr(str, 0, ft_strtab(str));
	tmp = str;
	str = ft_substr(str, ft_strtab(str) + 1, ft_strlen(str) - ft_strtab(str));
	free(tmp);
}
