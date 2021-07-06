/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   creaclose_img.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillaes <mvillaes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/28 17:34:43 by mvillaes          #+#    #+#             */
/*   Updated: 2020/08/28 18:52:04 by mvillaes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <stdio.h>
#include <stdlib.h>

#define X_EVENT_KEY_PRESS	2

#define KEY_ESC				53

typedef struct s_param
{
	int		x;
	int		y;
	char	str[3];
}t_param;

int		imputkey(int keycode, t_param *param)
{
	static int a = 0;

	if (keycode == KEY_ESC)
		exit(0);
	return (0);
}

int		main(void)
{
	void		*mlx;
	void		*mlx_win;
	t_param		param;
	void		*img;

	int	img_width;
	int	img_height;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 500, 500, "hello");
	img = mlx_xpm_file_to_image(mlx, "../texturas/wall.xpm", &img_width, &img_height);
	mlx_put_image_to_window(mlx, mlx_win, img, 50, 50);

	mlx_hook(mlx_win, X_EVENT_KEY_PRESS, 0, &imputkey, &param);
	mlx_loop(mlx);
	return (0);
}
