#include "../inc/myshell.h"

char	*ft_strreplace(char *str, char *insert, int pos, int len)
{
	char	*s1;
	char	*s2;
	char	*new;

	printf("replace:\n");
	s1 = calloc(pos + 1, sizeof(char));
	s1 = ft_strncpy(s1, str, pos);
	printf("s1 is: %s\n", s1);
	if (insert == NULL)
		s2 = ft_strdup(s1);
	else
		s2 = ft_strjoin(s1, insert);
	new = ft_strjoin(s2, &(str[pos + len + 1]));
	printf("s2 is: %s\n", s2);
	free(s1);
	free(s2);
	printf("new in ft_strreplace is: %s\n", new);
	return (new);
}

int	expander(char **text, int pos)
{
	t_param *param;

	printf("Expander:\n");
	char	var_name[ft_strlen(*text) + 1];
	int		len;
	char	*str;

	str = &(*text)[pos];
	len = 0;
	if (str[1] == '?')
	{
		printf("TODO $? value\n");
		char *serror = ft_itoa(errno);
		*text = ft_strreplace(*text, serror, pos, ft_strlen(serror));
		free(serror);
		return(0);
	}
	if (!ft_isalpha(str[1]))
	{
		printf("No alpha after $ (%c)\n", str[1]);
		return (-1);
	}
	while (str[len + 1] && ft_isalnum(str[len + 1]))
	{
		printf("str in while expander is: %s\n", &str[len + 1]);
		var_name[len] = str[len + 1];
		len++;
	}
	var_name[len] = 0;

	printf("len is: %d\n", len);
	printf("env var %s = ", var_name);
	printf("--->%s\n", my_getenv(var_name, param->envp, ft_strlen((*text) + 1)));
	// TODO esto está bien así o tenemos que cogerlo del char **env?
	if (my_getenv(var_name, param->envp, len) != NULL)
		printf("---**--->%s\n", my_getenv(var_name, param->envp, ft_strlen((*text) + 1)));
	else
		printf("----->>-->>-->>\n");
	char *tmp = *text;
	printf("text is: %s\n", *text);
	*text = ft_strreplace(*text, my_getenv(var_name, param->envp, ft_strlen((*text) + 1)),
		pos, len);
	printf("text after is: %s\n", *text);
	free (tmp);
	return (0);
}