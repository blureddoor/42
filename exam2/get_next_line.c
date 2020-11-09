#include "get_next_line.h"

size_t  ft_strlen(char *s)
{
    int i = 0;
    while (s[i] != '\0')
        i++;
    return (i);
}

char    *ft_strchr(char *s, int c)
{
    unsigned int    i = 0;
    if(!s || !c)
        return (NULL);
    while (s[i] != '\0')
    {
        if (s[i] == c)
            return (&s[i]);
        i++;
    }
    return (NULL);
}

char    *ft_strdup(char *s)
{
    char    *cpy;
    int     i = 0;
    if (!(cpy = malloc(ft_strlen(s) +1)))
        return (NULL);
    while (s[i] != '\0')
    {
        cpy[i] = s[i];
        i++;
    }
    cpy[i] = '\0';
    return (cpy);
}

char    *ft_strjoin(char *s1, char *s2)
{
    char    *join;
    int     i = 0;
    if (!(join = malloc(ft_strlen(s1) + ft_strlen(s2) + 1)))
        return (NULL);
    while (*s1 != '\0')
        join[i++] = *s1++;
    while (*s2 != '\0')
        join[i++] = *s2++;
    join[i] = '\0';
    return (join);
}

int     get_next_line(char **line)
{
    static char *gnl;
    char        buff[513];
    char        *aux, *aux2;
    int         n;

    if (!line)
        return (-1);
    while (ft_strchr(gnl, '\n') == NULL)
    {
        n = read(0, buff, 512);
        if (n < 0)
            return (-1);
        else if (!n)
            break;
        buff[n] = 0;
        if (!gnl)
            gnl = ft_strdup(buff);
        else
        {
            aux = ft_strjoin(gnl, buff);
            free(gnl);
            gnl = aux;
        }
    }
    if (!n && !gnl)
    {
        *line = ft_strdup("");
        return (0);
    }
    if ((aux = ft_strchr(gnl, '\n')))
    {
        *aux = 0;
        *line = ft_strdup(gnl);
        aux2 = ft_strdup(++aux);
        free(gnl);
        gnl = aux2;
    }
    else
    {
        *line = ft_strdup(gnl);
        free(gnl);
        gnl = NULL;
        return (0);
    }
    return (1);
}