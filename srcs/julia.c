/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmedrano <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 16:16:46 by lmedrano          #+#    #+#             */
/*   Updated: 2023/06/17 18:35:34 by lmedrano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"
#include <unistd.h>

void	julia_init(t_fractal *fractal)
{
	int	x;

	x = 0;
	fractal->min.real = -2.0;
	fractal->min.imgnr = -2.0;
	fractal->max.real = 2.0;
	fractal->max.imgnr = fractal->min.imgnr
		+ (fractal->max.real - fractal->min.real) * HEIGHT / WIDTH;
	fractal->factor.real = (fractal->max.real - fractal->min.real)
		/ (WIDTH - 1);
	fractal->factor.imgnr = (fractal->max.imgnr - fractal->min.imgnr)
		/ (HEIGHT - 1);
	fractal->max_iter = 30;
	fractal->c.real = fractal->min.real + (x * fractal->factor.real);
	fractal->c.imgnr = fractal->max.imgnr
		- (fractal->max.imgnr * fractal->c.imgnr);
	fractal->k.real = -0.2;
	fractal->k.imgnr = -0.7;
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
			break ;
		}
		z_imgnr = 2 * z_real * z_imgnr + fractal->k.imgnr;
		z_real = z_real_squared - z_imgnr_squared + fractal->k.real;
	}	
	if (n == fractal->max_iter)
		img_pixel_put(fractal, fractal->x, fractal->y, set_colors(3, n));
	else
		img_pixel_put(fractal, fractal->x, fractal->y, set_colors(1, n));
}
