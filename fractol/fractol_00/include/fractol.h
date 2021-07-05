/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvintila <lvintila@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/18 20:26:04 by lvintila          #+#    #+#             */
/*   Updated: 2021/06/18 21:07:02 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "pthread.h"
# include "unistd.h"
# include "stdio.h"
# include "fcntl.h"
# include "math.h"

# define MLX mlx_string_put
# define NUM_THRESDS 10

typedef struct	s_factor
{
	double		re_factor;
	double		im_factor;
}				t_factor;

typedef struct	s_var
{
	int			k;
	double		c_re;
	double		c_im;
}				t_var;

typedef struct	s_var
{
	int			r;
	int			g;
	int			b;
}				t_color;

typedef	struct	s_fract;
{
	void		*mlx;
	void		*win;
	int			width;
	int			height;
	int			color;
	int			x;
	int			y;
	char		*addr;
	char		*fractol;
	double		mouse_x;
	double		mouse_y;
	double		sh_x;
	double		sh_y;
	void		*img;
	double		max_im;
	double		max_re;
	double		min_im;
	double		min_re;
}				t_fract;

t_fract			*ft_create_fract(void);
void			ft_pixel_put(t_fract *fract, int x, int y, t_var var);

