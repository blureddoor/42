/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvintila <lvintila@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/28 19:31:09 by lvintila          #+#    #+#             */
/*   Updated: 2020/10/01 19:58:07 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft.h"
# include "stdarg.h"
# include "unistd.h"
# include "limits.h"
# include "stdlib.h"


# define POSITIVE		66
# define NEGATIVE		88

# define CCONVERSIONS	"cspdiuxX%"
# define CFLAGS			"+0.*"
# define ALLSYMBOLS		"cspdiuxX%+0.*"

typedef struct	s_struct
{
	char		*format;
	int			i;
	int			nprinted;
	int			minus;
	int			zero;
	int			width;
	int			precision;
}				t_struct;

void			mods();
void			converts(char c, va_list ap, t_struct *f);
int				unsigned_nbr_len(uintmax_t n, int base);
int				signed_nbr_len(intmax_t n, int base);
char			*ft_itoa_base(uintmax_t n, char *base);
char			*ft_itoa_base_upper(uintmax_t n, char *base);
void			my_printf_nbr(va_list *my_list);
void			my_printf_char(va_list *my_list);
void			my_printf_str(va_list *my_lsit);
int				my_printf(const char *src, ...);
void			write_zeros(int n);
void			write_blanks(int n);
void			*ft_ultoa_base(unsigned long long n, char *base);

#endif
