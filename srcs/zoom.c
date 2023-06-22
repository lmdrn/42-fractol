/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmedrano <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 17:24:23 by lmedrano          #+#    #+#             */
/*   Updated: 2023/06/22 13:47:43 by lmedrano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

/* fct to get mouse move + zoom in or out accordingly */
int	mouse_hook(int mouse_code, t_fractal *fractal, int set)
{
	if (mouse_code == 4)
	{
		fractal->c.real *= fractal->zoom;
		fractal->c.imgnr *= fractal->zoom;
		printf("iseeu\n");
	}
	else if (mouse_code == 5)
	{
		fractal->c.real /= fractal->zoom;
		fractal->c.imgnr /= fractal->zoom;
		printf("iseeutoo\n");
	}
	if (set == 1)
		render_mandelbrot(fractal);
	else if (set == 2)
		render_julia(fractal);
	return (1);
}
