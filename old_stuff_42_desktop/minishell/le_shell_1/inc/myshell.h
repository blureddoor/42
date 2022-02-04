/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   myshell.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvintila <lvintila@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/26 18:01:48 by lvintila          #+#    #+#             */
/*   Updated: 2022/01/09 23:40:26 by lvintila         ###   ########.fr       */
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

#define RL_BUFF_SIZE 1024
#define TK_BUFF_SIZE 64
#define TOK_DELIM " >\t\r\n\a"

/* 
ANSI Color codes
 */
#define RED   		"\033[0;31m"
#define YELLOW 		"\033[0;33m"
#define CYAN 		"\033[0;36m"
#define GREEN 		"\033[0;32m"
#define BLUE 		"\033[0;34m"
#define INVERT		"\033[0;7m"
#define RESET  		"\e[0m" 
#define BOLD		"\e[1m"
#define ITALICS		"\e[3m"

typedef struct  s_param
{
    char    **comandos;
    char    *token;
    char    *line;
    int     exec_count;
    int     dir;
    char    *dir_cmd;
    char    *dir_cmd2;
    char    *indir_cmd;
    char    *indir_cmd2;
    int     indir;
    int     status;
    int     process_status;
    int     dir_flag;
    char    *aux;
    char    *cmds[32]; // char *args[32];
    int     fd;
}               t_param;


// char *line;

/* Shell functions*/

int         myshell_loop(t_param *param, char **av, int execution_counter, char **env);
int         new_process(char *av[], int execution_counter, char **env);

/* diffrent utility functions */
void        print_env(char **env);
char        *rl_gets();

char        space_tab(unsigned int i, char c);
char        **parse(char *buff);
int         get_cmd(t_param *param);
void        redirect(char *buff);
int         execute(char *buff, char **envp);
char        *rl_gets();
char        *find_path(char *cmd, char **envp);
void        check_str(char *str, char *cmd);
void        free_arr(char **arr);
int     	redirection(t_param *param, char **env);
void        redirect(char *buff);
int     	exec_cmds(t_param *param, char **cmds, int exec_count, char **env);
int         found_char(char *str, char c);
int         check_redir(t_param *param, char **env);
int         found_op(char *str, char *op);
int         re_direction_and_pipe(char **args, char **env);
char        **split_line(char *line);
char        **split_pipes(char *input);
char        *trim_ws(char *str);

#endif
