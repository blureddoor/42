/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   4keyimput.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillaes <mvillaes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/27 17:13:35 by mvillaes          #+#    #+#             */
/*   Updated: 2020/09/03 16:20:04 by mvillaes         ###   ########.fr       */
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

/*funcion para cerrar con el boton rojo*/

int		ft_stop(int key, void *param)
{
	(void)param;
	if (key == 0x35 || key == 0x00)
	{
		/*freeme();*/
		exit(EXIT_SUCCESS);
	}
	return (0);
}

/* key_press solo puede recibir un argumento,
asi que se guarda en una estructura */
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

int		main(void)
{
	void		*mlx;
	void		*mlx_win;
	t_param		param;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 800, 600, "hello");

	mlx_hook(mlx_win, KEY_PRESS, 0, &imputkey, &param);
	mlx_loop(mlx);
	return (0);
}
