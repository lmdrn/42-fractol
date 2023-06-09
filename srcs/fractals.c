/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractals.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmedrano <lmedrano@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 15:22:32 by lmedrano          #+#    #+#             */
/*   Updated: 2023/06/09 15:59:24 by lmedrano         ###   ########.fr       */
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
	fractal->max_iter = 30;
	fractal->c.real = fractal->min.real + (x * fractal->factor.real);
	fractal->c.imgnr = fractal->max.imgnr
		- (fractal->max.imgnr * fractal->c.imgnr);
}

void	mandelbrot(t_fractal *fractal)
{
	unsigned int	x;
	unsigned int	y;
	double			z_real;
	double			z_imgnr;
	unsigned int	n;

	y = 0;
	while (++y < HEIGHT)
	{
		fractal->c.imgnr = fractal->max.imgnr - y * fractal->factor.imgnr;
		x = 0;
		while (++x < WIDTH)
		{
			fractal->c.real = fractal->min.real + x * fractal->factor.real;
			z_real = fractal->c.real;
			z_imgnr = fractal->c.imgnr;
			fractal->is_in = 1;
			n = 0;
			while (++n < fractal->max_iter)
			{
				if ((z_real * z_real) + (z_imgnr * z_imgnr) > 4)
				{
					fractal->is_in = 0;
					printf("noir\n");
					break ;
				}
				z_imgnr = 2 * z_real * z_imgnr + fractal->c.imgnr;
				z_real = (z_real * z_real) - (z_imgnr * z_imgnr) + fractal->c.real;
			}	
			printf("n is : %d\n", n);
			printf("is_in is:%d\n", fractal->is_in);
			if (fractal->is_in == 1)
			{
				img_pixel_put(fractal, x, y, set_colors(2));
				printf("lavande\n");
			}
		}
	}
}
