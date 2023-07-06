/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmedrano <lmedrano@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 18:37:43 by lmedrano          #+#    #+#             */
/*   Updated: 2023/07/06 11:24:26 by lmedrano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

/* others colors to test : 0x8d7bac */

int	julia_iter(t_fractal *fractal)
{
	fractal->c_real = 0.01;
	fractal->c_imgnr = 0.285;
	while (fractal->n < 100 && fractal->real * fractal->real + fractal->imgnr
		* fractal->imgnr < 4)
	{
		fractal->tmp = fractal->real * fractal->real - fractal->imgnr
			* fractal->imgnr;
		fractal->imgnr = 2 * fractal->real * fractal->imgnr + fractal->c_real;
		fractal->real = fractal->tmp + fractal->c_imgnr;
		fractal->n++;
	}
	return (fractal->n);
}

void	fractal_julia(t_fractal *fractal)
{
	fractal->i = 0;
	while (fractal->i < WIDTH)
	{
		fractal->j = 0;
		while (fractal->j < HEIGHT)
		{
			fractal->n = 0;
			fractal->real = (fractal->i - WIDTH / 2.0)
				* (fractal->zoom / WIDTH) + fractal->x;
			fractal->imgnr = (fractal->j - HEIGHT / 2.0)
				* (fractal->zoom / HEIGHT) + fractal->y;
			if (fractal->n < MAX_ITER)
			{
				color_fractal(fractal, fractal->i, fractal->j,
					julia_iter(fractal) * 0x0F0F0F);
			}
			fractal->j++;
		}
		fractal->i++;
	}
}
