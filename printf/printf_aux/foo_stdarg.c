/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   foo_stdarg.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <@student.42madrid.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/30 17:18:02 by marvin            #+#    #+#             */
/*   Updated: 2020/07/01 17:53:31 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	foo(char *fmt, ...)
{
	va_list ap, ap2;
	int d;
	char c, *s;

	va_start(ap, fmt);
	va_copy(ap2, ap);
	while(*fmt)
	{
		switch(*fmt++)
		{
			case 's':
				s = va_arg(ap, char *);
				printf("string %s\n", s);
				break;
			case 'd':
				d = va_arg(ap, int);
				printf("int %d\n", d);
				break;
			case 'c':
				c = va_arg(ap, int);
				printf("char %c\n", c);
				break;
		}
	}
	va_end(ap);
}
