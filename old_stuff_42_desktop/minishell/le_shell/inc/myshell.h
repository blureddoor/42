/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   myshell.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvintila <lvintila@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/26 18:01:48 by lvintila          #+#    #+#             */
/*   Updated: 2022/01/09 22:52:15 by lvintila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MYSHELL_H
# define MYSHELL_H
# include <stdio.h>
# include <sys/types.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <string.h>
# include <errno.h>
# include <readline/readline.h>
# include <readline/history.h>
# include "../gnl/get_next_line.h"
# include "../libft/libft.h"

# define STDIN 0
# define STDOUT 1

//char *line;

typedef struct s_param
{
    char    *line;
    char    *token;
}               t_param;


/* Shell functions*/
int myshell_loop(t_param *param, char *av[], int execution_counter, char **env);
int new_process(char *av[], int execution_counter, char **env);

/* diffrent utility functions */
void print_env(char **env);
char    *rl_gets();

char    space_tab(unsigned int i, char c);
char    **parse(char *buff);
int     get_cmd(t_param *param);
void    redirect(char *buff);
int     execute(char *buff, char **envp);
char    *rl_gets();
char    *find_path(char *cmd, char **envp);
void    check_str(char *str, char *cmd);
void    free_arr(char **arr);

#endif
