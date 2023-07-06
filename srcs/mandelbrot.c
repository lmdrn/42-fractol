/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmedrano <lmedrano@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 18:35:15 by lmedrano          #+#    #+#             */
/*   Updated: 2023/07/06 11:12:47 by lmedrano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int	mandelbrot_iter(t_fractal *fractal)
{
	fractal->c_real = (fractal->i - WIDTH / 1.45)
		* fractal->zoom / WIDTH + fractal->x;
	fractal->c_imgnr = (fractal->j - HEIGHT / 2.0)
		* fractal->zoom / HEIGHT + fractal->y;
	while (fractal->n < MAX_ITER && fractal->real * fractal->real
		+ fractal->imgnr * fractal->imgnr < 4)
	{
		fractal->tmp = fractal->real * fractal->real
			- fractal->imgnr * fractal->imgnr + fractal->c_real;
		fractal->imgnr = 2 * fractal->real * fractal->imgnr + fractal->c_imgnr;
		fractal->real = fractal->tmp;
		fractal->n++;
	}
	return (fractal->n);
}

void	fractal_mandelbrot(t_fractal *fractal)
{
	fractal->i = 0;
	while (fractal->i < WIDTH)
	{
		fractal->j = 0;
		while (fractal->j < HEIGHT)
		{
			fractal->n = 0;
			fractal->real = 0;
			fractal->imgnr = 0;
			if (fractal->n < MAX_ITER)
			{
				color_fractal(fractal, fractal->i, fractal->j,
					mandelbrot_iter(fractal) * 0x000f0f);
			}
			fractal->j++;
		}
		fractal->i++;
	}
}
