#include "fractol.h"

static int  ft_usage(t_fract *fract)
{
    ft_putendl("Error");
    ft_putendl("You must choose one of this parameters:");
    ft_putendl("· Mandelbrot");
    ft_putendl("· Julia");
    ft_putendl("· Newton");
    free(frct);
    exit(0);
}

static int  ft_exit_mouse(void)
{
    exit(0);
}

static int  ft_check_fractol(t_fract *fract)
{
    if (ft_strcmp(fract->fractol, "Julia") != 0 &&
        ft_strcmp(fract->fractol, "Mandelbrot") != 0 &&
        ft_strcmp(fract->fractol, "Newton") != 0)
        return (1);
    return (0);
}

int main(int arrgc, char **argv)
{
    t_fract *fract;

    fract = ft_create_fract();
    if (argc != 2)
        ft_engage(fract);
    fract->fractol = argv[1];
}
