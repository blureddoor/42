/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   createandclose.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillaes <mvillaes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/27 17:13:35 by mvillaes          #+#    #+#             */
/*   Updated: 2020/09/02 18:53:47 by mvillaes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <stdio.h>
#include <stdlib.h>

#define KEY_PRESS	2

#define KEY_ESC		53

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
	char	str[3];
}t_param;

int		imputkey(int key, t_param *param)
{
	static int a = 0;

	if (key == KEY_ESC)
		exit(0);
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
