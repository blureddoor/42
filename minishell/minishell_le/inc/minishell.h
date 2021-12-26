/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvintila <lvintila@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/10 20:48:11 by lvintila          #+#    #+#             */
/*   Updated: 2021/12/22 20:52:22 by lvintila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H
# define _GNU_SOURCE
# include <readline/readline.h>
# include <readline/history.h>
# include <stdlib.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/wait.h>
# include <string.h>
# include <fcntl.h>
# include <errno.h>
# include "../gnl/get_next_line.h"
# include "../libft/libft.h"
# include <sys/types.h>
# include <sys/stat.h>
# define MAX_CMD 1024
char    *buff;


char    space_tab(unsigned int i, char c);
char    **parse(char *buff);
int     get_cmd();
void    redirect(char *buff);
int     execute(char *buff, char **envp);
char    *rl_gets();
char    *find_path(char *cmd, char **envp);
void    check_str(char *str, char *cmd);
void    free_arr(char **arr);
int     hsh_loop(char *av[], int execution_counter, char **env);
char    *check_file(char *full_path, char *file_name);
int     new_process(char **av, int exec_counter, char **env);
char    *_getenv(char *name, char **env);
void    print_env(char **env);
int     check_line_1(char **line, char **str);
int     check_path(char *av[], char **envp);
//void    init(t_data *data);

#endif
