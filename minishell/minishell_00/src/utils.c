/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvintila <lvintila@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 19:51:12 by lvintila          #+#    #+#             */
/*   Updated: 2021/12/08 11:24:50 by lvintila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

void	check_str(char *str, char *cmd)
{
	if (access(str, F_OK) != 0)
	{
		write(2, "gasoil-sh: ", 11);
		write(2, "command not found: ", 19);
		write(2, cmd, ft_strlen(cmd));
		write(2, "\n", 1);
		exit(1);
	}
}

void	free_arr(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
		free(arr[i++]);
	free(arr);
}

char    space_tab(unsigned int i, char c)
{
    i = 0;
    if (c == '\t')
    {
        c = ' ';
        return (c);
    }
    return (c);
}

char    *rl_gets()
{
    /* 
     * A static variable for holding the line. 
     */
    static char *line_read;

    line_read = (char *)NULL;
    /* 
     * If the buffer has already been allocated, return the memory 
     * to the free pool.
     */
    if (line_read)
    {
        free (line_read);
        line_read = (char *)NULL;
    }

    /* 
     * Get a line from the user.
    */
    line_read = readline ("");

    /* 
     * If the line has any text in it, save it on the history.
     */
    if (line_read && *line_read)
        add_history (line_read);
    return (line_read);
}
