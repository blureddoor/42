/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimal_printf.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <@student.42madrid.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/30 20:08:15 by marvin            #+#    #+#             */
/*   Updated: 2020/09/15 15:49:03 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

void    ft_putchar(char c)
{
    write(1, &c, 1);
}

void minimal_printf(char *fmt, ...)
{
	va_list ap; /* points to each unnamed arg in turn */
	char *p, *sval;
	int ival;
	double dval;

	sval = NULL;
	va_start(ap, fmt); /* make ap point to 1st unnamed arg */
	for (p = fmt; *p; p++)
	{
		if (*p != '%')
		{
			ft_putchar(*p);
			continue;
		}
		switch (*++p)
		{
			case 'd':
				ival = va_arg(ap, int);
				printf("%d", ival);
				break;
			case 'f':
				dval = va_arg(ap, double);
				printf("%f", dval);
				break;
			case 's':
/*			while (sval == va_arg(ap, char *))
			{
				ft_putchar(*sval);
				sval++;
			}*/
				for (sval = va_arg(ap, char *); *sval; sval++)
					ft_putchar(*sval);
				break;
			default:
				ft_putchar(*p);
				break;
      }
   }
   va_end(ap); /* clean up when done */
}


int main()
{
//  char *str;
    char *nombre;
    int edad;

    nombre = "Mario";
    edad = 29;
    //str = "mi nombre es %5.2 leo";
    minimal_printf("mi printf --->mi nombre es: %s y mi edad es: %d años", nombre, edad);
    printf("\n");
    printf("printf ------>mi nombre es: %s y mi edad es: %d años", nombre, edad);
    return (0);
}
