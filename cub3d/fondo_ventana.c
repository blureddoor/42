#include "mlx.h"

int main()
{
	void *mlx;
	void *win;
	int x;
	int y;


	mlx = mlx_init();
	win = mlx_new_window(mlx, 400, 400, "mlx 42");
	y = 0;
	while (y < 400)
	{
		x = 0;
		while (x < 400)
		{
			mlx_pixel_put(mlx, win, x, y, 0x222222);
			x++;
		}
		y++;
	}
//	mlx_pixel_put(mlx, win, 200, 200, 0xFFFFFF);
	mlx_loop(mlx);
}
