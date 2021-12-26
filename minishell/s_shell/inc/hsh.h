/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hsh.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvintila <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/26 18:01:48 by lvintila          #+#    #+#             */
/*   Updated: 2021/12/26 18:44:28 by lvintila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HSH_H
# define HSH_H
# define _GNU_SOURCE
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

char *line;

/* Shell functions*/
int hsh_loop(char *av[], int execution_counter, char **env);
int new_process(char *av[], int execution_counter, char **env);

/* diffrent utility functions */
char *_strdup(char *str);
char *_strcat(char *dest, char *src);
char *_strcpy(char *dest, char *src);
char *_getenv(char *name, char **env);
char *_memset(char *s, char b, unsigned int n);
void *_calloc(unsigned int nmemb, int size);
void print_env(char **env);
int _strcmp(char *s1, char *s2);
int _strncmp(const char *s1, const char *s2, size_t n);
int _strlen(const char *s);
char    *rl_gets();

char    space_tab(unsigned int i, char c);
char    **parse(char *buff);
int     get_cmd();
void    redirect(char *buff);
int     execute(char *buff, char **envp);
char    *rl_gets();
char    *find_path(char *cmd, char **envp);
void    check_str(char *str, char *cmd);
void    free_arr(char **arr);
char    *check_file(char *full_path, char *file_name);

#endif /* HSH_H */
