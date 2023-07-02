/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmedrano <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 16:18:38 by lmedrano          #+#    #+#             */
/*   Updated: 2023/07/02 13:58:43 by lmedrano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	mandelbrot_init(t_fractal *fractal)
{
	int	x;

	x = 0;
	fractal->min_real = -2.0;
	fractal->min_imgnr = -1.5;
	fractal->max_real = 1.0;
	fractal->max_imgnr = fractal->min_imgnr
		+ (fractal->max_real - fractal->min_real) * HEIGHT / WIDTH;
	fractal->factor_real = (fractal->max_real - fractal->min_real)
		/ (WIDTH - 1);
	fractal->factor_imgnr = (fractal->max_imgnr - fractal->min_imgnr)
		/ (HEIGHT - 1);
	fractal->max_iter = 100;
	fractal->c_real = fractal->min_real + (x * fractal->factor_real);
	fractal->c_imgnr = fractal->max_imgnr
		- (fractal->max_imgnr * fractal->c_imgnr);
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
			break ;
		z_imgnr = 2 * z_real * z_imgnr + fractal->c_imgnr;
		z_real = z_real_squared - z_imgnr_squared + fractal->c_real;
	}	
	if (n == fractal->max_iter)
		img_pixel_put(fractal, fractal->x, fractal->y, set_colors(2));
	else
		img_pixel_put(fractal, fractal->x, fractal->y, rgb_to_int(n, fractal));
}
