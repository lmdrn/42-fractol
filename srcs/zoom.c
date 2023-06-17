/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmedrano <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 17:24:23 by lmedrano          #+#    #+#             */
/*   Updated: 2023/06/17 18:00:12 by lmedrano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

/* fct to get mouse move + zoom in or out accordingly */
int	mouse_hook(int mouse_code, t_fractal *fractal)
{
	if (mouse_code == 4 || mouse_code == 1)
	{
		fractal->zoom /= 0.8;
		printf("iseeu\n");
	}
	else if (mouse_code == 5 || mouse_code == 2)
	{
		fractal->zoom *= 0.8;
		printf("iseeutoo\n");
	}
	return (1);
}
