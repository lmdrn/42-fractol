/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmedrano <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 16:16:46 by lmedrano          #+#    #+#             */
/*   Updated: 2023/06/16 16:59:01 by lmedrano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	julia_init(t_fractal *fractal)
{
	fractal->x = 0;
	fractal->y = 0;
	fractal->min.real = -2.0;
	fractal->min.imgnr = -1.2;
	fractal->max.real = 1.0;
	fractal->max.imgnr = fractal->min.imgnr
		+ (fractal->max.real - fractal->min.real) * HEIGHT / WIDTH;
	fractal->factor.real = (fractal->max.real - fractal->min.real)
		/ (WIDTH - 1);
	fractal->factor.imgnr = (fractal->max.imgnr - fractal->min.imgnr)
		/ (HEIGHT - 1);
	fractal->max_iter = 50;
	fractal->c.real = fractal->min.real + (fractal->x * fractal->factor.real);
	fractal->c.imgnr = fractal->max.imgnr
		- (fractal->max.imgnr * fractal->c.imgnr);
	fractal->k.real = fractal->min.real + fractal->x
		* (fractal->max.real) / WIDTH;
	fractal->k.imgnr = fractal->max.real + fractal->y
		* (fractal->max.imgnr) / HEIGHT;
}

void	julia(t_fractal *fractal)
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
		}
	}
}

void	julia_iter(t_fractal *fractal, double z_real, double z_imgnr)
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
			img_pixel_put(fractal, fractal->x, fractal->y, set_colors(0, 0, 0));
			break ;
		}
		z_imgnr = 2 * z_real * z_imgnr + fractal->k.imgnr;
		z_real = z_real_squared - z_imgnr_squared + fractal->k.real;
	}	
	if (fractal->is_in == 1)
	{
		img_pixel_put(fractal, fractal->x, fractal->y, set_colors(0, 0, 0));
	}
}
