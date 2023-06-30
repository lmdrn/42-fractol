/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmedrano <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 17:24:23 by lmedrano          #+#    #+#             */
/*   Updated: 2023/06/30 14:47:33 by lmedrano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

double	new_rect(double start, double end, double interpolation)
{
	return (start + ((end - start) * interpolation));
}

void	zoom(t_fractal *fractal, double mouse_real, double mouse_imgnr,
		double zoom_factor)
{
	double	factor;

	factor = 1.0 / zoom_factor;
	fractal->min.real = new_rect(mouse_real, fractal->min.real, factor);
	fractal->min.imgnr = new_rect(mouse_imgnr, fractal->min.imgnr, factor);
	fractal->max.real = new_rect(mouse_real, fractal->max.real, factor);
	fractal->max.imgnr = new_rect(mouse_imgnr, fractal->max.imgnr, factor);
}

/* fct to get mouse move + zoom in or out accordingly */
/* TODO */
/* find out how to get x and y coordinates from mouse position */
int	mouse_hook(int mouse_code, t_fractal *fractal, t_mouse *mouse)
{
	/* if (mouse_code == 4) */
	/* { */
	/* 	printf("scrollup\n"); */
	/* } */
	/* else if (mouse_code == 5) */
	/* { */
	/* 	printf("scrolldown\n"); */
	/* } */
	if (mouse_code == 1)
	{
		mouse->real = (double)mouse->x / (WIDTH / (fractal->max.real
					- fractal->min.real)) + fractal->min.real;
		mouse->imgnr = (double)mouse->y / (HEIGHT / (fractal->max.imgnr
					- fractal->min.imgnr)) + fractal->min.imgnr;
		zoom(fractal, mouse->real, mouse->imgnr, 1.01);
		printf("leftclick\n");
	}
	/* else if (mouse_code == 2) */
	/* { */
	/* 	printf("rightclick\n"); */
	/* } */
	render(fractal);
	return (1);
}
