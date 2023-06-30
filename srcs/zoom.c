/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmedrano <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 17:24:23 by lmedrano          #+#    #+#             */
/*   Updated: 2023/06/30 12:01:44 by lmedrano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

/* fct to get mouse move + zoom in or out accordingly */
int	mouse_hook(int mouse_code, t_fractal *fractal)
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
	render(fractal);
	return (1);
}
