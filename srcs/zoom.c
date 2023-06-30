/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmedrano <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 17:24:23 by lmedrano          #+#    #+#             */
/*   Updated: 2023/06/30 16:41:05 by lmedrano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int	mouse_hook(int keycode, t_fractal *image)
{
	if (keycode == 4)
	{
		printf("up\n");
		printf("%f\n", image->c.real);
		image->c.real *= 0.5;
		image->c.imgnr *= 0.5;
	}
	else if (keycode == 5)
	{
		printf("down\n");
	}
	return (0);
}
