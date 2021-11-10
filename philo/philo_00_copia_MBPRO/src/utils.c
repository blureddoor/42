/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvintila <lvintila@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/17 12:37:17 by lvintila          #+#    #+#             */
/*   Updated: 2021/11/04 20:28:31 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

int	ft_strlen(const char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

static int	ft_count_char(long long n)
{
	int		len;

	len = 1;
	if (n < 0)
	{
		len++;
		n = -n;
	}
	while (n > 9)
	{
		len++;
		n = n / 10;
	}
	return (len);
}

char		*ft_ltoa(long long n)
{
	char	*s;
	int		i;
	int		len;

	if ((long long)n < -9223372036854775807)
		return("-9223372036854775808");
	i = 0;
	len = ft_count_char(n);
	s = (char *)malloc(sizeof(char) * len + 1);
	if (s == NULL)
		return (NULL);
	s[len] = '\0';
	if (n < 0)
	{
		n = -n;
		s[0] = '-';
	}
	while (n > 9)
	{
		s[len - 1] = (n % 10) + '0';
		n = n / 10;
		len--;
	}
	s[len - 1] = n + '0';
	return (s);
}

 char    *ft_strjoin(char const *s1, char const *s2)
 {
    char    *join;
    size_t  index_count;

	index_count = 0;
	if (!s1)
		return (NULL);
	if (!(join = (char*)malloc(sizeof(char) * ((ft_strlen(s1)
		+ ft_strlen(s2)) + 1))))
		return (NULL);
	while (*s1 != '\0')
	{
		*join = *s1;
		join++;
		s1++;
		index_count++;
	}
	while (*s2 != 0)
	{
		*join = *s2;
		join++;
		s2++;
		index_count++;
	}
	*join = '\0';
	return (join - index_count);
 }

 char    *ft_strdup(const char *s1)
 {
	char    *new;
	size_t  i;

	if (!(new = malloc(sizeof(char) * ft_strlen(s1) + 1)))
		return (NULL);
	i = 0;
	while (s1[i])
	{
		new[i] = s1[i];
		i++;
	}
	new[i] = '\0';
	return (new);
}

char    *ft_itoa(int n)
{
	char    *str;

	if (!(str = (char *)malloc(sizeof(char) * 2)))
		return (NULL);
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (n < 0)
	{
		str[0] = '-';
 		str[1] = '\0';
 		str = ft_strjoin(str, ft_itoa(-n));
	}
	else if (n >= 10)
 		str = ft_strjoin(ft_itoa(n / 10), ft_itoa(n % 10));
	else if (n < 10 && n >= 0)
	{
		str[0] = n + '0';
		str[1] = '\0';
	}
	return (str);
}

int	ft_puterror(char *str)
{
	int		i;
	char	*s;

	s = str;
	i = 0;
	while (*s++)
		i++;
	write(2, str, i);
	return (1);
}

int	ft_atoi(const char *ptr)
{
	int	res;
	int	neg;

	res = 0;
	neg = 1;
	if (*ptr == '-')
		neg *= -1;
	while ('0' <= *ptr && *ptr <= '9')
	{
		res *= 10;
		res += *ptr++ - '0';
	}
	return (res * neg);
}

int	ft_malloc(void *str, size_t size)
{
	*(void **)str = malloc(size);
	if (*(void **)str == NULL)
		return (1);
	memset(*(void **)str, 0, size);
	return (0);
}

void	print_msg(t_philo *philo, char *str)
{
	unsigned long long	ms;
	struct timeval		time;

	pthread_mutex_lock(&philo->param->end_mutex);
	gettimeofday(&time, NULL);
	ms = get_my_time(time) - get_my_time(philo->param->timestamp);
	if (!philo->param->end)
	{
		write(1, ft_ltoa(ms), ft_strlen(ft_ltoa(ms)));
		write(1, "\t", 1);
		write(1, ft_itoa(philo->n + 1), ft_strlen(ft_itoa(philo->n + 1)));
		write(1, "\t", 1);
		write(1, str, ft_strlen(str));
		write(1, "\n", 1);
	}
		//printf("%lld\t%d\t %s\n", ms, philo->n + 1, str);
	//gettimeofday(&time, NULL);
	pthread_mutex_unlock(&philo->param->end_mutex);
}

