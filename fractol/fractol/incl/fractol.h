/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmieshko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/06 11:38:05 by kmieshko          #+#    #+#             */
/*   Updated: 2021/06/18 21:59:14 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <pthread.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <math.h>
# include "../libft/libft.h"
# include "mlx.h"

# define MLX mlx_string_put
# define NUM_THREADS 10

typedef	struct	s_facrot
{
	double		re_factor;
	double		im_factor;
}				t_factor;

typedef	struct	s_var
{
	int			k;
	double		c_im;
	double		c_re;
	double		z_i_new;
	double		z_re_new;
	double		z_i;
	double		z_re;
}				t_var;

typedef	struct	s_color
{
	int			r;
	int			g;
	int			b;
}				t_color;

typedef	struct	s_frct
{
	void		*mlx;
	void		*win;
	int			width;
	int			height;
	int			iter;
	double		sh_x;
	double		sh_y;
	int			color;
	void		*img;
	int			size_line;
	int			bits_per_pixel;
	int			endian;
	char		*addr;
	char		*fractol;
	double		mouse_x;
	double		mouse_y;
	int			flag_mouse;
	int			depth;
	double		min_re;
	double		max_re;
	double		min_im;
	double		max_im;
	int			x;
	int			y;
	int			y_max;
}				t_frct;

t_frct			*ft_create_frct(void);
void			ft_pixel_put(t_frct *frct, int x, int y, t_var var);
t_color			ft_get_color(t_frct *frct, t_var var, int index);
int				ft_mouse_zoom(int key, int x, int y, t_frct *frct);
int				ft_manage(int key, t_frct *frct);
void			ft_print_text(t_frct *frct);
t_factor		ft_get_factor(t_frct *frct);
int				ft_expose(t_frct *frct);
void			ft_pthread(t_frct *frct);
void			ft_paint_up(t_frct *frct, t_var var);
void			ft_draw_tricorn(t_frct *frct);
void			ft_draw_julia(t_frct *frct);
void			ft_draw_burning_ship(t_frct *frct);
void			ft_draw_newton(t_frct *frct);
void			ft_draw_spyder(t_frct *frct);

#endif
