/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillaes <mvillaes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 16:11:56 by mvillaes          #+#    #+#             */
/*   Updated: 2020/08/19 19:19:13 by mvillaes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include "libft/libft.h"

typedef struct	s_flags
{
	int		star;
	int		width;
	int		zero;
	int		minus;
	int		type;
	int		dot;
}				t_flags;

char			*ft_itoatuning(unsigned int n);
int				ft_isdigit(int c);
int				ft_tolower(int c);
char			*ft_itoa(int n);
int				ft_putchar(char c);
char			*ft_strtolower(char *str);
char			*ft_strdup(const char *s1);
size_t			ft_strlen(const char *str);
int				ft_putsp(char *str, int precision);
char			*ft_utl(unsigned long long number, int base);
int				ft_isflag(int c);
int				ft_isconversion(int c);
int				ft_char(char c, t_flags flags);
t_flags			ft_minus_flag(t_flags flags);
t_flags			ft_digit_flag(char c, t_flags flags);
t_flags			ft_width_flag(va_list args, t_flags flags);
int				ft_dot_flag(const char *str, int start,
t_flags *flags, va_list args);
int				ft_hex(unsigned int number,
int lowercase, t_flags flags);
int				ft_int(int i, t_flags flags);
int				ft_percent(t_flags flags);
int				ft_pointer(unsigned long long num, t_flags flags);
int				ft_string(char *str, t_flags flags);
int				ft_uint(unsigned int number, t_flags flags);
int				ft_width(int width, int minus, int zero);
int				ft_parser(int c, t_flags flags, va_list args);
int				ft_printf(const char *fmt, ...);

#endif
