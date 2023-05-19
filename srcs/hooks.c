/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmedrano <lmedrano@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 17:08:37 by lmedrano          #+#    #+#             */
/*   Updated: 2023/05/19 17:41:03 by lmedrano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

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
