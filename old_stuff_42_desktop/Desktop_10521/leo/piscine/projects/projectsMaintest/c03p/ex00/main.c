/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvintila <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 22:34:15 by lvintila          #+#    #+#             */
/*   Updated: 2019/11/28 15:05:35 by lvintila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <string.h>

int	ft_strcmp(char *s1, char *s2);

int	main(void)
{
	char s1[] = "aac";
	char s2[] = "aaC";
	char s3[] = "aaC";
	ft_strcmp(s1, s2);
	printf("%d\n", ft_strcmp(s1, s2));
	printf("%d\n", strcmp(s1,s3));
	return (0);
}
