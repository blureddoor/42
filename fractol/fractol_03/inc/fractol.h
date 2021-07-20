/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvintila <lvintila@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/07 19:21:17 by lvintila          #+#    #+#             */
/*   Updated: 2021/07/20 21:41:32 by lvintila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <stdio.h>
# include <unistd.h>
# include "../minilibx/mlx.h"
# include "../libft/libft.h"
# include <string.h>
# include <stdlib.h>
# include <math.h>

# define ANCHO 1400
# define ALTO 1000

# define RED            "\033[22;31m"
# define RESET          "\033[0m"
# define JULIA			"julia_set"
# define MANDELBROT		"mandelbrot_set" 

# define MOTION_MASK	1
# define MOTION_NOTIFY	6

# define KEY_PRESS      2
# define KEY_EXIT       17

# define KEY_ESC        53
# define W              13
# define A              0
# define S              1
# define D              2

# define KEY_UP         126
# define KEY_DOWN       125
# define KEY_SHIFT      257
# define KEY_IZQ        123
# define KEY_DCH        124

typedef struct	s_set
{
	long double	min_in;
	long double max_in;
	long double min_out;
	long double max_out;
}				t_set;

typedef struct	s_fract
{
	int			(*func)(struct s_fract *fr, int x, int y);
	void		*mlx;
	void		*win;
	void		*data;
	void		*img;
	char		*image;
	int			bpp;
	int			endian;
	int			size_l;
	long double	c_re;
	long double	c_im;
	long double	min_x;
	long double	min_y;
	long double max_x;
	long double max_y;
	int			iter;
	int			red;
	int			green;
	int			blue;
	int			set_color;
	int			choose_fractal;
	long double	zoom;
	long double	infinity;
	int			mouse_move_mode;
}				t_fract;

int				julia_mouse(int x, int y, t_fract *fr);
int				ft_mouse_zoom(int key, int x, int y, t_fract *fr);
int				mouse_move(int x, int y, t_fract *fr);
void			set_color(t_fract *fr, int depth);
void			my_mlx_pixel_put(t_fract *fr, int x, int y, int color);
int				julia_math(t_fract *fr, int x, int y);
int				mandelbrot_math(t_fract *fr, int x, int y);
int				ft_mouse_zoom(int key, int x, int y, t_fract *fr);
/* static int	mouse_zoom_out(int x, int y, t_fract *fr);
static int		mouse_zoom_in(int x, int y, t_fract *fr); */
void			loop(t_fract *fr);
t_set			add_param(long double a, long double b, long double c, long double d);
long double		ft_map(long double x, t_set p);

#endif
