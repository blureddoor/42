/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_color.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omercade <omercade@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 21:20:21 by omercade          #+#    #+#             */
/*   Updated: 2021/03/24 20:44:44 by omercade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int		create_rgb(int r, int g, int b)
{
	return(r << 16 | g << 8 | b);
}

int     get_rgb(t_data *gd, char *line, int *i)
{
    int r;
    int g;
    int b;

    if(!ft_isdigit(line[*i++]))
        return(1);
    r = get_ncolor();
    g = get_ncolor();
    b = get_ncolor();

}

int     ft_check_color(t_data *gd, t_check *this, char *line)
{
    int i;

    i = 0;
    i = space_skip(line, i);
    if (line[i] == 'S')
    {
        i = space_skip(line, i);
    }
    else
        return(1);
    if (get_rgb(gd, line, &i))
        return(1);
    i = space_skip(line, i);
    if (line[i] != "\0")
        return(1);
    return(check_flag(this, 'S'));
}
