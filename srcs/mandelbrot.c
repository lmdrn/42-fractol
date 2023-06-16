/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmedrano <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 16:18:38 by lmedrano          #+#    #+#             */
/*   Updated: 2023/06/16 17:32:43 by lmedrano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	mandelbrot_init(t_fractal *fractal)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	fractal->min.real = -2.0;
	fractal->min.imgnr = -1.2;
	fractal->max.real = 1.0;
	fractal->max.imgnr = fractal->min.imgnr
		+ (fractal->max.real - fractal->min.real) * HEIGHT / WIDTH;
	fractal->factor.real = (fractal->max.real - fractal->min.real)
		/ (WIDTH - 1);
	fractal->factor.imgnr = (fractal->max.imgnr - fractal->min.imgnr)
		/ (HEIGHT - 1);
	fractal->max_iter = 100;
	fractal->c.real = fractal->min.real + (x * fractal->factor.real);
	fractal->c.imgnr = fractal->max.imgnr
		- (fractal->max.imgnr * fractal->c.imgnr);
}

void	mandelbrot(t_fractal *fractal)
{
	double			z_real;
	double			z_imgnr;

	fractal->y = 0;
	while (++fractal->y < HEIGHT)
	{
		fractal->c.imgnr = fractal->max.imgnr - fractal->y
			* fractal->factor.imgnr;
		fractal->x = 0;
		while (++fractal->x < WIDTH)
		{
			fractal->c.real = fractal->min.real + fractal->x
				* fractal->factor.real;
			z_real = fractal->c.real;
			z_imgnr = fractal->c.imgnr;
			fractal->is_in = 1;
			mandelbrot_iter(fractal, z_real, z_imgnr);
		}
	}
}

void	mandelbrot_iter(t_fractal *fractal, double z_real, double z_imgnr)
{
	double			z_imgnr_squared;
	double			z_real_squared;
	unsigned int	n;

	n = 0;
	while (++n < fractal->max_iter)
	{
		z_real_squared = z_real * z_real;
		z_imgnr_squared = z_imgnr * z_imgnr;
		if ((z_real_squared + z_imgnr_squared) > 4)
		{
			fractal->is_in = 0;
			img_pixel_put(fractal, fractal->x, fractal->y, set_colors(5));
			if (n > 0 && n < ((fractal->max_iter / 2) - 1))
				img_pixel_put(fractal, fractal->x, fractal->y, set_colors(2));
			else if (n > fractal->max_iter / 2 && n < fractal->max_iter - 1)
				img_pixel_put(fractal, fractal->x, fractal->y, set_colors(3));
			break ;
		}
		z_imgnr = 2 * z_real * z_imgnr + fractal->c.imgnr;
		z_real = z_real_squared - z_imgnr_squared + fractal->c.real;
	}	
	if (fractal->is_in == 1)
		img_pixel_put(fractal, fractal->x, fractal->y, set_colors(5));
}
