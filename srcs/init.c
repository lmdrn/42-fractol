/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmedrano <lmedrano@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 15:10:29 by lmedrano          #+#    #+#             */
/*   Updated: 2023/07/02 14:24:36 by lmedrano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	init_window(int fractal, t_fractal *image)
{
	image->mlx = mlx_init();
	image->mlx_win = mlx_new_window(image->mlx, WIDTH, HEIGHT, "FRACT'OL");
	image->img = mlx_new_image(image->mlx, WIDTH, HEIGHT);
	image->addr = mlx_get_data_addr(image->img, &image->bits_per_pixel,
			&image->line_length, &image->endian);
	image->set = fractal;
	image->max_real = 2.0;
	image->min_real = -2.0 * ((double)WIDTH / (double)HEIGHT);
	image->min_imgnr = -2.0;
	image->max_imgnr = image->min_imgnr + (image->max_real - image->min_real)
		* HEIGHT / WIDTH;
	image->x = 0;
	image->y = 0;
	image->color_r = 1;
	image->color_g = 0;
	image->color_b = 1;
}	

int	ft_strncmp(const char *s1, const char *s2, size_t nbytes)
{
	size_t	i;

	i = 0;
	while ((i < nbytes) && ((s1[i] != '\0') || (s2[i] != '\0')))
	{
		if (s1[i] > s2[i])
			return ((((unsigned char *)s1)[i]) - ((unsigned char *)s2)[i]);
		if (s1[i] < s2[i])
			return ((((unsigned char *)s1)[i]) - ((unsigned char *)s2)[i]);
		i++;
	}
	return (0);
}

void	fractal_typo(void)
{
	write(1, "------------------------------------------------\n", 50);
	write(1, "it looks ike you've got a typo bro... try again.\n", 50);
	write(1, "Launch the command <make ./fractol> followed by:\n", 50);
	write(1, "------------- [mandelbrot] [julia] -------------\n", 50);
	write(1, "------------------------------------------------\n", 50);
}

void	no_input(void)
{
	write(1, "------------------------------------------------\n", 50);
	write(1, "------------------ Wrong input -----------------\n", 50);
	write(1, "------- Usage: ./fractol [FractalNameHere] -----\n", 50);
	write(1, "------------- [mandelbrot] [julia] -------------\n", 50);
	write(1, "------------------------------------------------\n", 50);
}

/* mlx_new_image is fct used x mem allocation x img; */
int	main(int ac, char **av)
{
	t_fractal	fractal;

	if (ac != 2)
	{
		no_input();
		exit(0);
	}
	else
	{
		if (ft_strncmp(av[1], "mandelbrot", 10) == 0)
			init_window(1, &fractal);
		else if (ft_strncmp(av[1], "julia", 5) == 0)
			init_window(2, &fractal);
		else
		{
			fractal_typo();
			exit(0);
		}
	}
	render(&fractal);
	mlx_key_hook(fractal.mlx_win, close_esc, &fractal);
	mlx_mouse_hook(fractal.mlx_win, mouse_hook, &fractal);
	mlx_hook(fractal.mlx_win, 17, 0, close_btn, &fractal);
	mlx_loop(fractal.mlx);
	return (0);
}
