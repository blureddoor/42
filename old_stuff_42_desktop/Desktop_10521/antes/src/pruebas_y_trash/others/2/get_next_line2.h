viroques

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <string.h>
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 100
# endif

int        get_next_line(int fd, char **line);
size_t    ft_strlen(char *s);
char    *ft_strjoin(char *s1, char *s2);
char    *ft_strnchr(char *s, int c, int n);
char    *ft_strndup(char *s);
char    *ft_substr(char *s, unsigned int start, size_t len);
#endif
