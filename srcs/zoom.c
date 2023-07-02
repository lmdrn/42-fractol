/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmedrano <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 17:24:23 by lmedrano          #+#    #+#             */
/*   Updated: 2023/07/02 15:03:55 by lmedrano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int	mouse_hook(int keycode, int x, int y, t_fractal *image)
{
	(void)x;
	(void)y;
	if (keycode == 4)
	{
		printf("up\n");
		printf("%f\n", image->c.real);
		image->c.real *= 0.5;
		printf("%f\n", image->c.real);
		image->c.imgnr *= 0.5;
	}
	else if (keycode == 5)
	{
		printf("down\n");
		printf("%f\n", image->c.real);
		image->c.real /= 0.5;
		printf("%f\n", image->c.real);
		image->c.imgnr /= 0.5;
	}
	return (0);
}
