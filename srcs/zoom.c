/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmedrano <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 17:24:23 by lmedrano          #+#    #+#             */
/*   Updated: 2023/07/02 14:24:45 by lmedrano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	update_f(t_fractal *fractal, double zoom)
{
	fractal->max_real *= zoom;
	fractal->min_real *= zoom;
	fractal->min_imgnr *= zoom;
	fractal->max_imgnr = fractal->min_imgnr + (fractal->max_real
			- fractal->min_real) * HEIGHT / WIDTH;
}

int	mouse_hook(int keycode, int x, int y, t_fractal *fractal)
{
	(void)x;
	(void)y;
	if (keycode == 4)
	{
		update_f(fractal, 0.90);
		printf("up\n");
	}
	if (keycode == 5)
	{
		update_f(fractal, 1.10);
		printf("dwn\n");
	}
	render(fractal);
	return (0);
}
