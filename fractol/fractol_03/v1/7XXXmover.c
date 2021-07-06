/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   7mover.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillaes <mvillaes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/27 17:13:35 by mvillaes          #+#    #+#             */
/*   Updated: 2020/09/08 16:41:12 by mvillaes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <stdio.h>
#include <stdlib.h>

#define KEY_PRESS	2
#define KEY_RELEASE	3

#define KEY_ESC		53
#define KEY_W		13
#define KEY_A		0
#define KEY_S		1
#define KEY_D		2
#define KEY_IZQ		123
#define KEY_DCH		124

#define ANCHO_VENTANA	850
#define ALTO_VENTANA	550
#define ANCHO_DIBUJO	50
#define ALTO_DIBUJO		50

//keypress

typedef struct s_param
{
	int		x;
	int		y;
	int		z;
	char	str[3];
}t_param;

void	param_init(t_param *param)
{
	param->x = 0;
	param->y = 0;
	param->z = 0;
}

int		imputkey(int key, t_param *param)
{
	static int a = 0;

	if (key == KEY_ESC)
		exit(0);
	else if (key == KEY_W)
		param->x++;
	else if (key == KEY_S)
		param->x--;
	else if (key == KEY_A)
		param->y++;
	else if (key == KEY_D)
		param->y--;
	else if (key == KEY_IZQ)
		param->z++;
	else if (key == KEY_DCH)
		param->z--;
	printf("frontal_x: %d\n", param->x);
	printf("lateral_y: %d\n", param->y);
	printf("camara__z: %d\n", param->z);
	return (0);
}

//fin keypress

//dibuja el punto

typedef struct	s_img
{
	void	*img_ptr;
	int		*data;
	int		size_l;
	int		bpp;
	int		endian;
}				t_img;

//fin dibujo punto

//ventana

typedef	struct	s_mlx
{
	void	*mlx_ptr;
	void	*mlx_win;
}				t_mlx;

//fin ventana

int		main(void)
{
	t_mlx		*mlx;
	int			count_w;
	int			count_h;
	t_param		param;
	t_img		img;
	void		*fondo;

	int			img_width;
	int			img_height;

	mlx->mlx_ptr = mlx_init();
	mlx->mlx_win = mlx_new_window(mlx->mlx_ptr, ANCHO_VENTANA, ALTO_VENTANA, "mu");
	fondo = mlx_xpm_file_to_image(mlx->mlx_ptr, "./texturas/cow.xpm", &img_width, &img_height);
	img.img_ptr = mlx_new_image(mlx->mlx_ptr, ANCHO_DIBUJO, ALTO_DIBUJO);
	img.data = (int *)mlx_get_data_addr(img.img_ptr, &img.bpp, &img.size_l, &img.endian);
	count_h = -1;
	while (++count_h < ALTO_DIBUJO)
	{
		count_w = -1;
		while (++count_w < ANCHO_DIBUJO)
		{
			if (count_w % 1)
				img.data[count_h * ANCHO_DIBUJO + count_w] = 0xFF0000;
			else
				img.data[count_h * ANCHO_DIBUJO + count_w] = 0xFF0000;
		}
	}

	mlx_put_image_to_window(mlx->mlx_ptr, mlx->mlx_win, fondo, 0, 0);
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->mlx_win, img.img_ptr, param.x, param.y); //donde cambia la posicion del punto
	// mlx_loop_hook(mlx->mlx_ptr, mlx->mlx_win, &param); //refresca la pantalla
	mlx_hook(mlx->mlx_win, KEY_PRESS, 0, &imputkey, &param);
	mlx_loop(mlx->mlx_ptr);
	return (0);
}
