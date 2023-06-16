/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmedrano <lmedrano@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 17:08:37 by lmedrano          #+#    #+#             */
/*   Updated: 2023/06/16 17:24:10 by lmedrano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"
#include <unistd.h>

/* fct to close window with esc key*/
int	close_esc(int keycode, t_fractal *fractal)
{
	if (keycode == 53)
	{
		mlx_destroy_image(fractal->mlx, fractal->img);
		mlx_destroy_window(fractal->mlx, fractal->mlx_win);
		exit(0);
	}
	return (0);
}

/* fct to close window with close btn */
int	close_btn(t_fractal *fractal)
{
	mlx_destroy_image(fractal->mlx, fractal->img);
	mlx_destroy_window(fractal->mlx, fractal->mlx_win);
	exit(0);
	return (0);
}

/* fct to print mouse event */
int	mouse_hook(int mouse_code)
{
	if (mouse_code == 4)
		printf("zoom in!");
	else if (mouse_code == 5)
		printf("zoom out!");
	else if (mouse_code == 1)
		printf("left click!");
	else if (mouse_code == 5)
		printf("right click!");
	return (0);
}
