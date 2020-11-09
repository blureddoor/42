/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <@student.42madrid.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/02 19:49:02 by marvin            #+#    #+#             */
/*   Updated: 2020/10/02 20:58:15 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	my_printf(const char *src, ...)
{
	void	(*tab_function[8]) (va_list *) = {my_printf_char, my_printf_str,
		my_printf_p, my_printf_nbr, my_printf_nbr, my_printf_u, my_printf_hex,
		my_printf_uhex};
	char	tab_index[9] = {'c', 's', 'p', 'd', 'i', 'u', 'x', 'X', 0};
	va_list my_list;
	int i;
	int	tmp_index;

	i = 0;
	va_start(my_list, src);
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
	va_end(my_list);
	return (strlen(src));
}
