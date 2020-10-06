/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_1_copy.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <@student.42madrid.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/02 19:49:02 by marvin            #+#    #+#             */
/*   Updated: 2020/10/06 19:44:43 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


int	find_index(char *arr, char element)
{
	int	index;

	index = 0;
	while (arr[index] != 0)
	{
		if (arr[index] == element)
			return (index);
		index++;
	}
	return (-1);
}

void	converts(const char *src, va_list my_list)
{
	void	(*tab_function[8]) (va_list *) = {my_printf_char, my_printf_str,
		my_printf_p, my_printf_nbr, my_printf_nbr, my_printf_u, my_printf_hex,
		my_printf_uhex};
	char	tab_index[9] = {'c', 's', 'p', 'd', 'i', 'u', 'x', 'X', 0};
	int i;
	int	tmp_index;

	i = 0;
	while (src[i] != 0)
	{
		if (i != 0 && src[i - 1] == '%')
		{
			tmp_index = 0;
			tmp_index = find_index(tab_index, src[i]);
			if (tmp_index != -1)
				(*tab_function[tmp_index])(&my_list);
		}
		else if (src[i] != '%')
			write(1, &src[i], 1);
		else if (src[i + 1] == '%')
			write(1, &src[i + 1], 1);
		i++;
	}
}
