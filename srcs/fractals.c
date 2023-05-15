/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractals.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmedrano <lmedrano@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 15:22:32 by lmedrano          #+#    #+#             */
/*   Updated: 2023/05/15 08:44:12 by lmedrano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

t_complex	init_complex(double real, double imgnr)
{
	t_complex	complex;
	complex.real = real;
	complex.imgnr = imgnr;
	return (complex);
}

void	mandelbrot(t_fractal *fractal)
{
	t_complex	z;
	t_complex	tmp;
	int		iterations;

	iterations = 0;
	z = init_complex(fractal->c.real, fractal->c.imgnr);
}


