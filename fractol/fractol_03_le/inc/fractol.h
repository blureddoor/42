/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvintila <lvintila@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/07 19:21:17 by lvintila          #+#    #+#             */
/*   Updated: 2021/09/02 22:41:53 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <unistd.h>
# include "../minilibx/mlx.h"
# include "../libft/libft.h"
# include <math.h>
# include <stdio.h>

# define ANCHO 1400
# define ALTO 1000

# define RED            "\033[22;31m"
# define RESET          "\033[0m"
# define JULIA			"julia"
# define MANDELBROT		"mandelbrot"
# define SHIP			"ship"

# define MOTION_MASK	1
# define MOTION_NOTIFY	6

# define KEY_PRESS      2
# define KEY_EXIT       17

# define KEY_ESC        53

# define KEY_UP         126
# define KEY_DOWN       125
# define KEY_SHIFT      257
# define KEY_IZQ        123
# define KEY_DCH        124

typedef struct s_set
{
	long double	min_in;
	long double	max_in;
	long double	min_out;
	long double	max_out;
}				t_set;

typedef struct s_fract
{
	int			(*func)(struct s_fract *fr, int x, int y);
	void		*mlx;
	void		*win;
	void		*img;
	char		*data;
	int			bpp;
	int			endian;
	int			size_l;
	long double	c_re;
	long double	c_im;
	long double	min_x;
	long double	min_y;
	long double	max_x;
	long double	max_y;
	int			iter;
	int			red;
	int			green;
	int			blue;
	int			set_color;
	int			choose_fractal;
	long double	zoom;
	long double	infinity;
	int			mouse_move_mode;
	int			bonus;
	long long	sign;
}				t_fract;

int				ft_mouse_zoom(int key, int x, int y, t_fract *fr);
int				mouse_move(int x, int y, t_fract *fr);
void			set_color(t_fract *fr, int depth);
void			set_other_colors(t_fract *fr, int depth);
int				closer(void);
void			my_mlx_pixel_put(t_fract *fr, int x, int y, int color);
int				init_mlx(t_fract *fr);
void			init(t_fract *fr, int argc, char **argv);
int				julia_math(t_fract *fr, int x, int y);
int				mandelbrot_math(t_fract *fr, int x, int y);
int				burning_ship_math(t_fract *fr, int x, int y);
void			loop(t_fract *fr);
t_set			add_param(long double a, long double b, long double c,
					long double d);
int				press(int key, t_fract *fr);
int				key_draw(int key, t_fract *fr);
void			choose_color(int key, t_fract *fr);
long double		ft_map(long double x, t_set p);
void			init_bonus(t_fract *fr, int argc, char **argv);
void			julia_args(t_fract *fr, int argc, char **argv);
long double 	read_str(char *str);
int				str_is_float(char *str);

#endif
