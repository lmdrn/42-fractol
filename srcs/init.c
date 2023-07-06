/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmedrano <lmedrano@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 18:37:28 by lmedrano          #+#    #+#             */
/*   Updated: 2023/07/06 10:34:29 by lmedrano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	init_hooks(t_fractal *fractal)
{
	mlx_key_hook(fractal->mlx_win, close_esc, fractal);
	mlx_hook(fractal->mlx_win, 17, 0, close_btn, fractal);
	mlx_mouse_hook(fractal->mlx_win, mouse_hook, fractal);
}

void	init_window(t_fractal *fractal)
{
	fractal->mlx = mlx_init();
	fractal->mlx_win = mlx_new_window(fractal->mlx, WIDTH, HEIGHT, "fract-ol");
}

void	init_image(t_fractal *fractal)
{
	fractal->img = mlx_new_image(fractal->mlx, WIDTH, HEIGHT);
	fractal->addr = mlx_get_data_addr(fractal->img, &fractal->bits_per_pixel,
			&fractal->line_length, &fractal->endian);
}

void	set_fractal(int set, t_fractal *fractal)
{
	if (set == 1)
	{
		fractal->set = MANDELBROT;
		fractal_mandelbrot(fractal);
	}
	else if (set == 2)
	{
		fractal->set = JULIA;
		fractal_julia(fractal);
	}
	mlx_put_image_to_window(fractal->mlx, fractal->mlx_win, fractal->img, 0, 0);
}

int	main(int ac, char **av)
{
	t_fractal	fractal;

	fractal.zoom = 4.0;
	init_window(&fractal);
	init_image(&fractal);
	if (ac != 2)
	{
		no_input();
		exit(1);
	}
	if (!ft_strcmp(av[1], "mandelbrot"))
		set_fractal(1, &fractal);
	else if (!ft_strcmp(av[1], "julia"))
		set_fractal(2, &fractal);
	else
	{
		fractal_typo();
		exit(1);
	}
	init_hooks(&fractal);
	mlx_loop(fractal.mlx);
	return (0);
}
