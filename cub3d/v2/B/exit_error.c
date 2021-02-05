#include "cub.h"

int     closer(t_game *game)
{
    mlx_destroy_window(game->mlx.ptr, game->mlx.win);
    exit(0);
}

int     error(const char *str)
{
    char *show_error;
    show_error = ft_strjoin(RED"Error\n"RESET, str);
    ft_printf(show_error);
    free(show_error);
    exit(1);
}
