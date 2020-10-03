/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvintila <lvintila@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/22 19:25:19 by lvintila          #+#    #+#             */
/*   Updated: 2020/09/30 19:38:37 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft.h"
# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdint.h>
# include <limits.h>

# define H				1
# define HH				2
# define L				3
# define LL				4
# define J				5
# define Z				6
# define BIGL			7

# define POSITIVE		66
# define NEGATIVE		88

# define CCONVERSIONS	"cspdiuxX%"
# define CFLAGS			"#-+ .*0123456789hljz"
# define ALLSYMBOLS		"cspdiuxX%#-+ .*0123456789hLljz"

typedef struct			s_struct
{
	char				*format;
	int					nprinted;
	int					i;
	int					len;
	int					minus;
	int					plus;
	int					space;
	int					zero;
	int					hash;
	int					width;
	int					precisiontf;
	int					precision;
	int					length;
}						t_struct;

typedef struct			s_fstruct
{
	char				*str1;
	char				*str2;
	int					precision;
	long double			i;
	int					zeros;
	int					precisionaddon;
	int					padding;
	int					beforedecimalnbr;
	char				c;
	char				sign;
	int					sign_int;
	int					hash;
	int					dot;
}						t_fstruct;

void					mods();
void					converts(char c, va_list ap, t_struct *f);
void					write_char(t_struct *f, va_list ap);
void					write_percent();
void					write_string();
void					write_pointer();
void					write_blanks(int n);
void					write_int(t_struct *f, va_list ap, int sign, intmax_t n);
char					*ft_itoa_base(uintmax_t value, uintmax_t base);
int						unsigned_nbr_len(uintmax_t n, int base);
void					write_hex(t_struct *f, va_list ap, char c);
void					write_zeros(int n);
void					write_udecint(t_struct *f, va_list ap);
char					*ft_stradd(char *a, char *b);
void					write_error();
void					width_star(const char *format, t_struct *f, va_list ap);
char					*ft_itoa_base_upper(intmax_t value, intmax_t base);
int						signed_nbr_len(intmax_t n, int base);
char					find_char(t_struct *f);
void					right_aligned_f(t_struct *f, t_fstruct g);
void					left_aligned_f(t_struct *f, t_fstruct g);
int						ft_printf(const char *format, ...);

#endif
