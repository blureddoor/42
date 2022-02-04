/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   myshell.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmontese <pmontese@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/26 18:01:48 by lvintila          #+#    #+#             */
/*   Updated: 2022/02/03 20:41:54 by pmontese         ###   ########.fr       */
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
# include <dirent.h>
# include <readline/readline.h>
# include <readline/history.h>
# include "../gnl/get_next_line.h"
# include "../libft/libft.h"

# define STDIN 0
# define STDOUT 1

#define RL_BUFF_SIZE 1024
#define TK_BUFF_SIZE 64
#define TOK_DELIM " >\t\r\n\a"


/* Tokens */
#define TT_EMPTY 0
#define TT_OP 1
#define TT_WORD 2
#define TT_EOF 3

#define NOQUOTE 0
#define SQUOTE 1
#define DQUOTE 2

#define OT_PIPE 1
#define OT_IRED 2
#define OT_ORED 3
#define OT_ORED2 4
#define OT_HEREDOC 5
#define OT_NEWLINE 6

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

typedef struct	s_keyval
{
	char	*key;
	char	*val;
}				t_keyval;

typedef struct  s_param
{
	int		tmp_in;
	int		tmp_out;
	int		fd_in;
	int 	fd_out;
	char	*line;
	int		cmds; // num of commands
	t_keyval	*keyval;
	t_keyval	**env;
	int			envc; // num of env variables
	char	**o_env; // env tal cual te viene
	int		process_status;

}               t_param;

typedef struct s_command
{
	int		is_assignment;
	char*	name;
	int		argc;
	char**	argv;
	char*	filein;
	char*	fileout;
	int		append;
	char*	hdocword;
	int		piped;
}			t_command;

typedef struct s_token
{
	char*	cnt;
	int		type;
	int		op_type;
	int		delimited;
}			t_token;

/* Lexer */
t_token		*tokenizer(char *input, t_param *param);
int			expander(char **text, int pos, t_param *param);
char		*ft_strreplace(char *str, char *insert, int pos, int len);

/* Heredoc */
char 		*read_heredoc(char **str, int *pos);

/* parser */
t_command	**parser(t_token *tokens);
void		print_cmd(t_command *cmd);

/* Shell functions*/
int         myshell_loop(t_param *param, char **av);
int         new_process(t_command *commands, int execution_counter, char **env);
void		executer(char **env, t_token *tokens, t_command **cmd_lst);

/* Built ins*/
void		bi_exit(t_command *cmd, t_param *param);
void		bi_env(t_param *param);
void		bi_export(t_command *cmd, t_param *param);
void		bi_unset(t_command *cmd, t_param *param);
void		bi_cd(t_command *cmd, t_param *param);

/* diffrent utility functions */
char        *rl_gets();

char        space_tab(unsigned int i, char c);
char        **parse(char *buff);
int         get_cmd(t_param *param);
char        *rl_gets();
char        *find_path(char *cmd, char **envp);
void        check_str(char *str, char *cmd);
void        free_arr(char **arr);
int         found_char(char *str, char c);
void 		cmd_execute(t_command **cmd, t_param *param);
int			try_builtins(t_command *cmd, t_param *param);

/* environment */
t_keyval	*get_keyval(char *str);
void		set_env_var(t_keyval *var, t_param *param);
void		unset_env_var(char *name, t_param *param);
char		*mygetenv(char *name, t_param *param);
char		**make_envp(t_param *param);

/* signals */
void		reg_parent_signals();
void		reg_child_signals();

int	ft_arr_len(char **arr);
int	ft_strchr_i(const char *s, int c);
char	**ft_extend_arr(char **in, char *new_str);
char	**ft_dup_arr(char **arr);
char	**ft_arr_replace_in(char ***big, char **small, int n);
void	ft_free_arr(char ***arr);
int	ft_put_arr_fd(char **arr, int fd);

int		try_set_existing_var(t_keyval *var, t_param *param);
char	**my_setenv(char *var, char *value, char **envp, int n);
//char	*my_setenv(t_keyval *var, t_param *param);
char	**setenv_aux(t_keyval **kv_env, char *var, char *new_val, t_param *param);


#endif
