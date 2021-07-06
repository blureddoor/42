/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   createwindow.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillaes <mvillaes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/26 18:15:51 by mvillaes          #+#    #+#             */
/*   Updated: 2020/08/27 16:57:12 by mvillaes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>

int		main(void)
{
	void	*mlx;
	void	*mlx_win;

	mlx = mlx_init(); /*conecta con la libreria mlx */
	mlx_win = mlx_new_window(mlx, 800, 600, "hello"); /*comando para crear la ventana,
	le da un tamano y un titulo */

	mlx_loop(mlx); /* mantiene la ventana abierta */
}
