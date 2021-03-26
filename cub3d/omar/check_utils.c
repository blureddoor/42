/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omercade <omercade@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 17:41:29 by omercade          #+#    #+#             */
/*   Updated: 2021/03/24 20:44:51 by omercade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int     space_skip(char *line, int i)
{
	while (ft_isspace(line[i]))
		i++;
	return(i);
}

int    check_flag(t_check *this, char c)
{
    int i;

    i = 0;
    if(ft_strchr(this->flag, c))
        return(1);
    else
    {
        while (this->flag[i] != '\0')
            i++;
        this->flag[i++] = c;
        this->flag[i] = "\0";
        return(0);
    }
}