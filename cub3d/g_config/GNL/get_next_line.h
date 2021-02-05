/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillaes <mvillaes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 16:44:33 by mvillaes          #+#    #+#             */
/*   Updated: 2020/02/16 16:58:53 by mvillaes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 128
# endif

# include <unistd.h>
# include <limits.h>
# include <stdlib.h>

char	*ft_strjoin_endline(char *s1, char *s2, int i, int j);
int		get_next_line(int fd, char **line);
void	*buf_move(char *src);
int		find_endnull(const char *s);

#endif
