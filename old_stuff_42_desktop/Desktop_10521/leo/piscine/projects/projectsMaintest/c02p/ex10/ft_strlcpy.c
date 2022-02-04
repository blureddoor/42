/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvintila <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/22 00:53:41 by lvintila          #+#    #+#             */
/*   Updated: 2019/11/29 14:40:46 by lvintila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <string.h>


void	ft_putchar(char c);
unsigned int ft_strlcpy(char *dest, char *src, unsigned int size);

int main()
{
	unsigned int size;
	char dest[4];
	char src[] = "2 programming";
	size = sizeof(dest);
	ft_strlcpy(dest, src, size);
	printf("%d\n", ft_strlcpy(dest, src, size));
	printf("%s\n", dest);
	return (0);
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

unsigned int ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int 	i;
	unsigned int 	length;

	length = 0;
	i = 0;
	while (src[i] != '\0')
		i++;
	if (size == 0)
		return (i);
//	
//	length = 0;
//	if (size == 0)
//		return (length);
	while (src[length] != '\0' && length < (size - 1))
	{
		dest[length] = src[length];
//		ft_putchar(dest[i]);
		length++;
	}
	dest[length] = '\0';
	return (i);
//	while (src[length] != '\0')
//	{
//		length++;
//	}
//	return (length);
//	if (size == 0)
//		return (length);
}
