/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmedrano <lmedrano@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 18:37:10 by lmedrano          #+#    #+#             */
/*   Updated: 2023/07/06 10:53:46 by lmedrano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int	close_esc(int keycode, t_fractal *fractal)
{
	if (keycode == 53)
	{
		mlx_destroy_window(fractal->mlx, fractal->mlx_win);
		exit(1);
	}
	return (0);
}

int	close_btn(t_fractal *fractal)
{
	mlx_destroy_window(fractal->mlx, fractal->mlx_win);
	exit(1);
	return (0);
}

int	mouse_hook(int keycode, int x, int y, t_fractal *fractal)
{
	(void)x;
	(void)y;
	if (keycode == 4)
		fractal->zoom /= 0.8;
	if (keycode == 5)
		fractal->zoom *= 0.8;
	mlx_clear_window(fractal->mlx, fractal->mlx_win);
	if (fractal->set == MANDELBROT)
		fractal_mandelbrot(fractal);
	if (fractal->set == JULIA)
		fractal_julia(fractal);
	mlx_put_image_to_window(fractal->mlx, fractal->mlx_win, fractal->img, 0, 0);
	return (0);
}
