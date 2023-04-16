/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmedrano <lmedrano@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/16 14:39:45 by lmedrano          #+#    #+#             */
/*   Updated: 2023/04/16 15:49:33 by lmedrano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

/* define four corners of the window */
/* go through y axis and x axis and for each pixel, set offset */
/* is inside mandelbrot set, put certain color if not put another */

void	mandelbrot(t_mlx *mlx)
{
	double	min_real;
	double	max_real;
	double	min_imgnr;
	double	max_imgnr;
	double	real_factor;
	double	imgnr_factor;
	unsigned int		x;
	unsigned int		y;
	unsigned int		max_iter;
	double	c_real;
	double	c_imgnr;
	double	z_real;
	double	z_imgnr;
	double	z_real2;
	double	z_imgnr2;
	unsigned int	n;
	int	isInside;

	x = 0;
	y = 0;
	max_iter = 30;
	min_real = -2.0;
	max_real = 1.0;
	min_imgnr = -1.2;
	max_imgnr = min_imgnr + (max_real - min_real) * HEIGHT / WIDTH;
	/* calculate factor to make offset operation smaller */
	real_factor = (max_real - min_real) / (WIDTH - 1);
	imgnr_factor = (max_imgnr - min_imgnr) / (HEIGHT - 1);
	while (y < HEIGHT)
	{
		/* offset c imgnr */
		c_imgnr = max_imgnr - (y * imgnr_factor);
		while (x < WIDTH)
		{
			/* offset c real */
			c_real = min_real - (x * real_factor);
			isInside = 1;
			z_real = c_real;
			z_imgnr = c_imgnr;
			n = 0;
			while (n < max_iter)
			{
				z_real2 = z_real * z_real;
				z_imgnr2 = z_imgnr * z_imgnr;
				/* We must calculate the absolute value of a complex number. It is defined as its distance from the origin, that is, sqrt(Zr2+Zi2) */
				if ((z_real2 + z_imgnr2) > 4)
				{
					isInside = 0;
					break ;
				}
				/* we have to calculate z2 + c */
				/* (a +bi)2 = (a+bi)(a+bi) = a2 + abi + abi + (bi)2 = a2 - b2 + 2abi */
				/* a2 - b2 is real part and 2*a*b*i is imgnr part */
				z_imgnr = (2 * z_real * z_imgnr) + c_imgnr;
				z_real = z_real2 - z_imgnr2 + c_real;
				n++;
			}
			if (isInside == 1)
			{
				my_mlx_pixel_put(mlx, x, y, RED);
			}
			x++;
		}
		y++;
	}	
}
