/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvintila <lvintila@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/28 19:31:09 by lvintila          #+#    #+#             */
/*   Updated: 2020/10/08 22:35:34 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft.h"
# include <stdarg.h>
# include <unistd.h>
# include <limits.h>
# include <stdlib.h>
# include <stdint.h>

# define POSITIVE		1
# define NEGATIVE		2

# define CCONVERSIONS	"cspdiuxX%"
# define ALLSYMBOLS		"cspdiuxX%-.*0123456789"

typedef struct	s_struct
{
	char		*format;
	int			i;
	int			len;
	int			nprinted;
	int			minus;
	int			zero;
	int			width;
	int			precision;
	int			precision_t;
	int			length;
}				t_struct;

void			mods(const char *format, t_struct *f, va_list ap);
int				mods_converts(t_struct *f, int pos, const char *format,
				va_list ap);
int				select_format(const char *format, t_struct *list, va_list ap,
				int pos);
void			width_star(const char *format, t_struct *f, va_list ap);
void			converts(char c, va_list ap, t_struct *f);
int				unsigned_nbr_len(uintmax_t n, int base);
int				signed_nbr_len(intmax_t n, int base);
char			*ft_itoa_base(uintmax_t n, uintmax_t base);
char			*ft_itoa_base_upper(intmax_t n, intmax_t base);
void			print_char(t_struct *f, va_list ap);
void			print_u(t_struct *f, va_list ap);
void			print_str(t_struct *f, va_list ap);
void			print_nbr(t_struct *f, va_list ap, int sign, intmax_t n);
void			print_pointer(t_struct *f, va_list ap, int p);
void			print_hex(t_struct *f, va_list ap, char x);
void			print_percent(t_struct *f);
int				ft_printf(const char *format, ...);
void			write_zeros(int n);
void			write_blanks(int n);
void			write_error(void);
char			find_char(t_struct *f);

#endif
