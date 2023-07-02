/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractals.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmedrano <lmedrano@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 17:55:07 by lmedrano          #+#    #+#             */
/*   Updated: 2023/07/02 14:24:37 by lmedrano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	render(t_fractal *image)
{
	if (image->set == MANDELBROT)
	{
		mandelbrot_init(image);
		fractal(image, 1);
	}
	else if (image->set == JULIA)
	{
		julia_init(image);
		fractal(image, 2);
	}
}

void	fractal(t_fractal *fractal, int set)
{
	double			z_real;
	double			z_imgnr;

	fractal->y = 0;
	while (++fractal->y < HEIGHT)
	{
		fractal->c_imgnr = fractal->max_imgnr - fractal->y
			* fractal->factor_imgnr;
		fractal->x = 0;
		while (++fractal->x < WIDTH)
		{
			fractal->c_real = fractal->min_real + fractal->x
				* fractal->factor_real;
			z_real = fractal->c_real;
			z_imgnr = fractal->c_imgnr;
			if (set == 1)
				mandelbrot_iter(fractal, z_real, z_imgnr);
			else if (set == 2)
				julia_iter(fractal, z_real, z_imgnr);
		}
	}
	mlx_put_image_to_window(fractal->mlx, fractal->mlx_win, fractal->img, 0, 0);
	mlx_string_put(fractal->mlx, fractal->mlx_win, 0,
		0, set_colors(1), "To exit press  : [ESC]");
}
