/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractals.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmedrano <lmedrano@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 17:55:07 by lmedrano          #+#    #+#             */
/*   Updated: 2023/06/30 12:00:56 by lmedrano         ###   ########.fr       */
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
			if (set == 1)
				mandelbrot_iter(fractal, z_real, z_imgnr);
			else if (set == 2)
				julia_iter(fractal, z_real, z_imgnr);
		}
	}
}
