/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvintila <lvintila@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/08 20:51:17 by lvintila          #+#    #+#             */
/*   Updated: 2021/09/20 22:13:03 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "../libft/libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <fcntl.h>
# include <sys/wait.h>

# define STDIN 0
# define STDOUT 1

char	*find_path(char *cmd, char **envp);
void	pipex(char *cmd1, char *cmd2, char **envp, char **argv);
int		closer(void);
int		pipex_usage(const int num);

#endif
