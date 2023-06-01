/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractals.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmedrano <lmedrano@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 15:22:32 by lmedrano          #+#    #+#             */
/*   Updated: 2023/06/01 17:24:10 by lmedrano         ###   ########.fr       */
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
		/ (WIDTH - 1);
	fractal->max_iter = 50;
	fractal->c.real = fractal->min.real + (x * fractal->factor.real);
	fractal->c.imgnr = fractal->min.imgnr + (x * fractal->factor.imgnr);
}

void	mandelbrot(t_fractal *fractal)
{
	double			z_real;
	double			z_imgnr;
	double			z_real_squared;
	double			z_imgnr_squared;
	unsigned int	i;

	i = 0;
	z_real = fractal->c.real;
	z_imgnr = fractal->c.imgnr;
	while (i < fractal->max_iter)
	{
		z_real_squared = z_real * z_real;
		z_imgnr_squared = z_imgnr * z_imgnr;
		if ((z_real_squared + z_imgnr_squared) > 4)
		{
			fractal->is_in = 0;
			break ;
		}
		z_imgnr = 2 * z_real * z_imgnr + fractal->c.imgnr;
		z_real = 2 * z_real_squared * z_imgnr_squared + fractal->c.real;
		i++;
	}
}
